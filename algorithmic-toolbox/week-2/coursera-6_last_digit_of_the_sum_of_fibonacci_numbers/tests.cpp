//
// Created by aleksei on 1/21/23.
//
#include <catch2/catch_test_macros.hpp>
#include "main.h"
#include <ctime>

int FibonacciSumNaive(int64_t n) {
    if (n <= 1) {
        return n;
    }

    int64_t previous = 0;
    int64_t current = 1;
    int64_t sum = 1;

    for (int64_t i = 0; i < n - 1; ++i) {
        int64_t tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

TEST_CASE("Samples") {
    REQUIRE(Solve({3}) == 4);
    REQUIRE(Solve({100}) == 5);
}

TEST_CASE("Same as naive") {
    for (NumType n = 0; n <= 50; ++n) {
        REQUIRE(Solve({n}) == FibonacciSumNaive(n));
    }
}

TEST_CASE("Edge cases") {
    REQUIRE(Solve({100'000'000'000'000}) >= 0);
    REQUIRE(Solve({0}) == 0);
}

TEST_CASE("Stress test & Overflows & TL") {
    for (NumType n = 1'000'000'000'000; n <= 100'000'000'000'000; n += 1'000'000'000'000) {
        auto start = std::clock();
        auto result = Solve({n});
        auto elapsed = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);
        REQUIRE(elapsed < 1);
        REQUIRE(result >= 0);
    }
}

//TEST_CASE("Hand-made cases") {
//
//}