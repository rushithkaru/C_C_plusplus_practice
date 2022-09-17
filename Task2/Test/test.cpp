/*Unit test using catch2 framweork
* Author: Rushith Karunaratne
* Compiled on Mac with: g++ -std=c++11 test.cpp
*/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/Task2.cpp"

TEST_CASE("Check input validity", "Valid inputs"){
    //Negative input
    Task2 test1(-3);
    REQUIRE_THROWS(test1.AtoThePowerB());
    //Over 99999
    Task2 test2(101001);
    REQUIRE_THROWS(test2.AtoThePowerB());
}

TEST_CASE("Check if reverse digit function works", "Reverse"){
    Task2 test1(39);
    REQUIRE(test1.getB() == 93);
    Task2 test2(91);
    REQUIRE(test2.getB() == 19);
    Task2 test3(1);
    REQUIRE(test3.getB() == 1);
}


TEST_CASE("Test A to the power B is correct", "[A^B]"){
    Task2 test1(3);
    REQUIRE(test1.AtoThePowerB() == "27");
    Task2 test2(9);
    REQUIRE(test2.AtoThePowerB() == "387420489");
}