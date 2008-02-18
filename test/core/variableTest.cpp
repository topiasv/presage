
/******************************************************************************\
 *                                                                            *
 * Soothsayer, an extensible predictive text entry system                     *
 * ------------------------------------------------------                     *
 *                                                                            *
 * Copyright (C) 2004  Matteo Vescovi <matteo.vescovi@yahoo.co.uk>             *
 *                                                                            *
 * This program is free software; you can redistribute it and/or              *
 * modify it under the terms of the GNU General Public License                *
 * as published by the Free Software Foundation; either version 2             *
 * of the License, or (at your option) any later version.                     *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              *
 * GNU General Public License for more details.                               *
 *                                                                            *
 * You should have received a copy of the GNU General Public License          *
 * along with this program; if not, write to the Free Software                *
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.*
 *                                                                            *
\******************************************************************************/        


#include "variableTest.h"

CPPUNIT_TEST_SUITE_REGISTRATION( VariableTest );

void VariableTest::setUp()
{
}

void VariableTest::tearDown()
{
}

void VariableTest::test_string_to_variable()
{
    std::cout << "void VariableTest::test_string_to_variable()" << std::endl;

    Variable* variable = new Variable("");
    size_t expected_size = 0;
    CPPUNIT_ASSERT_EQUAL(expected_size, variable->size());
    delete variable;

    variable = new Variable("foo");
    expected_size = 1;
    CPPUNIT_ASSERT_EQUAL(expected_size, variable->size());
    CPPUNIT_ASSERT_EQUAL(static_cast<std::string>("foo"), (variable->variable())[0]);
    delete variable;

    variable = new Variable("foo.bar");
    expected_size = 2;
    CPPUNIT_ASSERT_EQUAL(expected_size, variable->size());
    CPPUNIT_ASSERT_EQUAL(static_cast<std::string>("foo"), (variable->variable())[0]);
    CPPUNIT_ASSERT_EQUAL(static_cast<std::string>("bar"), (variable->variable())[1]);
    delete variable;

    variable = new Variable("foo.bar.foobar");
    expected_size = 3;
    CPPUNIT_ASSERT_EQUAL(expected_size, variable->size());
    CPPUNIT_ASSERT_EQUAL(static_cast<std::string>("foo"), (variable->variable())[0]);
    CPPUNIT_ASSERT_EQUAL(static_cast<std::string>("bar"), (variable->variable())[1]);
    CPPUNIT_ASSERT_EQUAL(static_cast<std::string>("foobar"), (variable->variable())[2]);
    delete variable;
}

void VariableTest::test_variable_to_string()
{
    std::cout << "void VariableTest::test_variable_to_string()" << std::endl;

    std::vector<std::string>* expected = new std::vector<std::string>();
    Variable* var = new Variable(*expected);
    CPPUNIT_ASSERT_EQUAL(static_cast<std::string>(""), var->string());
    delete expected;
    delete var;

    expected = new std::vector<std::string>();
    expected->push_back("foo");
    var = new Variable(*expected);
    CPPUNIT_ASSERT_EQUAL(static_cast<std::string>("foo"), var->string());
    delete expected;
    delete var;

    expected = new std::vector<std::string>();
    expected->push_back("foo");
    expected->push_back("bar");
    var = new Variable(*expected);
    CPPUNIT_ASSERT_EQUAL(static_cast<std::string>("foo.bar"), var->string());
    delete expected;
    delete var;

    expected = new std::vector<std::string>();
    expected->push_back("foo");
    expected->push_back("bar");
    expected->push_back("foobar");
    var = new Variable(*expected);
    CPPUNIT_ASSERT_EQUAL(static_cast<std::string>("foo.bar.foobar"), var->string());
    delete expected;
    delete var;
}
