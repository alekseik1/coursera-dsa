//
// Created by aleksei on 1/21/23.
//
#include <catch2/catch_test_macros.hpp>
#include "main.h"
#include <ctime>

int gcd_naive(int a, int b) {
    int current_gcd = 1;
    for (int d = 2; d <= a && d <= b; d++) {
        if (a % d == 0 && b % d == 0) {
            if (d > current_gcd) {
                current_gcd = d;
            }
        }
    }
    return current_gcd;
}

TEST_CASE("Samples") {
    REQUIRE(Solve({28851538, 1183019}) == 17657);
}

TEST_CASE("Same as naive") {
    for (NumType a = 1; a < 100; ++a) {
        for (NumType b = 1; b < 100; ++b) {
            REQUIRE(Solve({a, b}) == gcd_naive(a, b));
        }
    }
}

TEST_CASE("Stress test") {
    NumType result;
    for (NumType i = 1'000'000; i <= 2'000'000'000; i += 1'000'000) {
        for (NumType j = 1'000'000; j <= 2'000'000'000; j += 1'000'000) {
            result = Solve({i, j});
            REQUIRE(result >= 0);
            REQUIRE(i % result == 0);
            REQUIRE(j % result == 0);
        }
    }
}

TEST_CASE("Time limits") {
    auto start = std::clock();
    Solve({2'000'000'000 - 1, 2'000'000'000});
    auto duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    REQUIRE(duration < 1);
}

TEST_CASE("Found errors") {
    REQUIRE(Solve({18, 35}) == 1);
    REQUIRE(Solve({35, 18}) == 1);
}