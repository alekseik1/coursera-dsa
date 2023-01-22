//
// Created by aleksei on 1/21/23.
//
#include <catch2/catch_test_macros.hpp>
#include "main.h"

int GetFibonacciLastDigitNaive(int n) {
    if (n <= 1) {
        return n;
    }

    int previous = 0;
    int current = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}

TEST_CASE("Samples") {
    REQUIRE(Solve({3}) == 2);
    REQUIRE(Solve({139}) == 1);
    REQUIRE(Solve({91239}) == 6);
}

TEST_CASE("Same as naive") {
    for (NumType i = 0; i < 40; ++i) {
        REQUIRE(Solve({i}) == GetFibonacciLastDigitNaive(i));
    }
}

TEST_CASE("No overflows on huge input") {
    for (NumType i = 100; i < 300; ++i) {
        auto result = Solve({i});
        REQUIRE(((result >= 0) && (result < 10)));
    }
}

TEST_CASE("Stress test") {
    for (NumType i = 100'000; i < 1'000'000; i += 50'000) {
        auto result = Solve({i});
        REQUIRE(((result >= 0) && (result < 10)));
    }
}