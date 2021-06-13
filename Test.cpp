/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Aviem Hadar
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
#include <string>
#include <algorithm>
using namespace ariel;
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input)
{
	erase(input, ' ');
	erase(input, '\t');
	erase(input, '\n');
	erase(input, '\r');
	return input;
}


TEST_CASE("Good snowman code - Hat Check")
{
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(21114411)) == nospaces(" ___ \n.....\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(31114411)) == nospaces(" _ \n /_\\\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(41114411)) == nospaces(" ___ \n(_*_)\n(.,.)\n( : )\n( : )"));
}

TEST_CASE("Good snowman code - Nose Check")
{
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(12114411)) == nospaces("_===_\n(...)\n( : )\n( : )"));
	CHECK(nospaces(snowman(13114411)) == nospaces("_===_\n(._.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(14114411)) == nospaces("_===_\n(.\0.)\n( : )\n( : )"));
}

TEST_CASE("Good snowman code - left eye Check")
{
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(11214411)) == nospaces("_===_\n(o,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(11314411)) == nospaces("_===_\n(O,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(11414411)) == nospaces("_===_\n(-,.)\n( : )\n( : )"));
}

TEST_CASE("Good snowman code - right eye Check")
{
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(11124411)) == nospaces("_===_\n(.,o)\n( : )\n( : )"));
	CHECK(nospaces(snowman(11134411)) == nospaces("_===_\n(.,O)\n( : )\n( : )"));
	CHECK(nospaces(snowman(11144411)) == nospaces("_===_\n(.,-)\n( : )\n( : )"));
}

TEST_CASE("Good snowman code - left arm Check")
{
	CHECK(nospaces(snowman(11111411)) == nospaces("_===_\n(.,.)\n<( : )\n( : )"));
	CHECK(nospaces(snowman(11112411)) == nospaces("_===_\n\\(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(11113411)) == nospaces("_===_\n(.,.)\\\n( : )\n( : )"));
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
}

TEST_CASE("Good snowman code - right arm Check")
{
	CHECK(nospaces(snowman(11114111)) == nospaces("_===_\n(.,.)\n( : )>\n( : )"));
	CHECK(nospaces(snowman(11114211)) == nospaces("_===_\n(.,.)/\n( : )\n( : )"));
	CHECK(nospaces(snowman(11114311)) == nospaces("_===_\n(.,.)\n( : )\\\n( : )"));
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
}

TEST_CASE("Good snowman code - Torso Check")
{
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(11114421)) == nospaces("_===_\n(.,.)\n(] [)\n( : )"));
	CHECK(nospaces(snowman(11114431)) == nospaces("_===_\n(.,.)\n(> <)\n( : )"));
	CHECK(nospaces(snowman(11114441)) == nospaces("_===_\n(.,.)\n(\0)\n( : )"));
}

TEST_CASE("Good snowman code - Base Check")
{
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
	CHECK(nospaces(snowman(11114412)) == nospaces("_===_\n(.,.)\n( : )\n(" ")"));
	CHECK(nospaces(snowman(11114413)) == nospaces("_===_\n(.,.)\n( : )\n(___)"));
	CHECK(nospaces(snowman(11114414)) == nospaces("_===_\n(.,.)\n( : )\n(\0)"));
}

TEST_CASE("wrong characters")
{
	CHECK_THROWS(snowman(1));		  // only one number.
	CHECK_THROWS(snowman(22));		  // only two numbers.
	CHECK_THROWS(snowman(333));		  // only three numbers.
	CHECK_THROWS(snowman(4444));	  // only four numbers.
	CHECK_THROWS(snowman(55555));	  // only five numbers.
	CHECK_THROWS(snowman(666666));	  // only six numbers.
	CHECK_THROWS(snowman(7777777));	  // only seven numbers.
	CHECK_THROWS(snowman(111111111)); // 9 characters, more than 8 needed.
	CHECK_THROWS(snowman(11111115));  // one of the numbers is greater than 4.
	CHECK_THROWS(snowman(11111151));  // one of the numbers is greater than 4.
	CHECK_THROWS(snowman(11111511));  // one of the numbers is greater than 4.
	CHECK_THROWS(snowman(11111110));  // one of the numbers is 0 - illegal.
	CHECK_THROWS(snowman(-12345678)); // negative 8 characters number.
}
