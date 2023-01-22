//
// Created by aleksei on 1/21/23.
//
#include <catch2/catch_test_macros.hpp>
#include "main.h"
#include <ctime>

int64_t GetFibonacciPartialSumNaive(int64_t from, int64_t to) {
    int64_t sum = 0;

    int64_t current = 0;
    int64_t next = 1;

    for (int64_t i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        int64_t new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

TEST_CASE("Samples") {
    REQUIRE(Solve({3, 7}) == 1);
    REQUIRE(Solve({10, 10}) == 5);
}

TEST_CASE("Same as naive") {
    for (NumType from = 0; from <= 60; ++from) {
        for (NumType to = from; to <= 60; ++to) {
            REQUIRE(Solve({from, to}) == GetFibonacciPartialSumNaive(from, to));
        }
    }
}

TEST_CASE("Edge cases") {
    REQUIRE(Solve({0, 0}) == 0);
    REQUIRE(Solve({0, 4}) == 7);
    REQUIRE(Solve({4, 4}) == 3);
    auto result = Solve({100'000'000'000'000});
    REQUIRE(result >= 0);
    REQUIRE(result < 10);
}

TEST_CASE("Stress & Overflows & TL") {
    for (NumType n = 1'000'000'000'000; n <= 100'000'000'000'000; n += 1'000'000'000'000) {
        auto start = std::clock();
        auto result = Solve({n});
        auto elapsed = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);
        REQUIRE(elapsed < 1);
        REQUIRE(result >= 0);
        REQUIRE(result < 10);
    }
}

TEST_CASE("Hand-made cases") {

}