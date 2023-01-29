//
// Created by aleksei on 1/21/23.
//
#include <catch2/catch_test_macros.hpp>
#include "main.h"
#include <ctime>


inline bool AreClose(double first_number, double second_number) {
    return std::abs(first_number - second_number) <= 1e-3;
}

TEST_CASE("Basic template") {

}

TEST_CASE("Samples") {
    REQUIRE(AreClose(Solve({3, 50, {{60, 20}, {100, 50}, {120, 30}}}), 180));
}

TEST_CASE("Same as naive") {
}

// TEST_CASE("Same if invert") {
// }

TEST_CASE("No overflows") {
}

TEST_CASE("Edge cases") {

}

TEST_CASE("Time limit") {
//    auto start = std::clock();
//    Solve({714552, 374513});
//    auto elapsed = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);
//    REQUIRE(elapsed < 1);
}

TEST_CASE("Stress test") {

}

TEST_CASE("Hand-made cases") {
    REQUIRE(Solve({100}) == 10);
    REQUIRE(Solve({101}) == 11);
    REQUIRE(Solve({110}) == 11);
    REQUIRE(Solve({111}) == 12);
}