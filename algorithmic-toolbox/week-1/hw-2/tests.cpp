//
// Created by aleksei on 1/21/23.
//
#include <catch2/catch_test_macros.hpp>
#include <cstdlib>
#include "main.h"

TEST_CASE("Basic") {
    REQUIRE(Solve({{1, 3, 1}, 3}) == 3);
}

TEST_CASE("Simple") {
    REQUIRE(Solve({{1, 2, 3}, 3}) == 6);
}

TEST_CASE("All similar") {
    REQUIRE(Solve({{4, 4, 4, 4}, 4}) == 16);
}

TEST_CASE("Two numbers") {
    REQUIRE(Solve({{5, 7}, 2}) == 35);
}

NumType NaiveSolution(const Data &data) {
    NumType rv = 0;
    for (size_t i = 0; i < data.numbers.size(); ++i) {
        for (size_t j = i + 1; j < data.numbers.size(); ++j) {
            auto tmp = data.numbers[i] * data.numbers[j];
            if (tmp > rv) {
                rv = tmp;
            }
        }
    }
    return rv;
}

TEST_CASE("Many with naive") {
    Data data;
    for (size_t test_number = 0; test_number < 100; ++test_number) {
        data.total = rand() % 10 + 2;
        data.numbers.reserve(data.total);
        for (size_t i = 0; i < data.total; ++i) {
            data.numbers.push_back(rand() % 100'000);
        }
        REQUIRE(Solve(data) == NaiveSolution(data));
    }
}