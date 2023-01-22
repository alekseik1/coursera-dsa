//
// Created by aleksei on 1/21/23.
//
#include <catch2/catch_test_macros.hpp>
#include "main.h"
#include <ctime>

int64_t GetFibonacciHugeNaive(int64_t n, int64_t m) {
    if (n <= 1) {
        return n;
    }

    int64_t previous = 0;
    int64_t current = 1;

    for (int64_t i = 0; i < n - 1; ++i) {
        int64_t tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

TEST_CASE("Samples") {
    REQUIRE(Solve({1, 239}) == 1);
    REQUIRE(Solve({115, 1000}) == 885);
    REQUIRE(Solve({2816213588, 239}) == 151);
}

TEST_CASE("Edge case small") {
    REQUIRE(Solve({1, 2}) == 1);
    REQUIRE(Solve({1, 1'000}) == 1);
}

TEST_CASE("Same as naive") {
    for (NumType n = 1; n <= 60; ++n) {
        for (NumType m = 2; m <= 1'000; m += 123) {
            REQUIRE(Solve({n, m}) == GetFibonacciHugeNaive(n, m));
        }
    }
}

TEST_CASE("No overflows & Stress & TL") {
    for (NumType i = 1'000'000'000'000; i <= 100'000'000'000'000; i += 1'000'000'000'000) {
        for (NumType j = 100; j <= 1'000; j += 100) {
            auto start = std::clock();
            auto actual = Solve({i, j});
            auto elapsed = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);
            REQUIRE(elapsed < 1);

            REQUIRE(actual >= 0);
        }
    }
}

TEST_CASE("Hand-made cases") {
    REQUIRE(Solve({3, 2}) == 0);
}