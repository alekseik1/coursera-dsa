//
// Created by aleksei on 1/21/23.
//
#include <catch2/catch_test_macros.hpp>
#include "main.h"
#include <ctime>

int64_t LcmNaive(int a, int b) {
    for (int64_t l = 1; l <= static_cast<int64_t>(a) * b; ++l) {
        if (l % a == 0 && l % b == 0) {
            return l;
        }
    }

    return static_cast<int64_t>(a) * b;
}

TEST_CASE("Samples") {
    REQUIRE(Solve({8, 6}) == 24);
    REQUIRE(Solve({15, 8}) == 120);
    REQUIRE(Solve({6, 15}) == 30);
    REQUIRE(Solve({761457, 614573}) == 467970912861);
}

TEST_CASE("Same as naive") {
    for (NumType i = 1; i < 100; ++i) {
        for (NumType j = i; j < 100; ++j) {
            auto expected = LcmNaive(i, j);
            REQUIRE(Solve({i, j}) == expected);
        }
    }
}

TEST_CASE("Same if invert") {
    for (NumType i = 1; i < 200; ++i) {
        for (NumType j = i; j < 200; ++j) {
            REQUIRE(Solve({i, j}) == Solve({j, i}));
        }
    }
}

TEST_CASE("No overflows") {
    for (NumType i = 1'000'000; i < 10'000'000; i += 100'000) {
        for (NumType j = 1'000'000; j < 10'000'000; j += 100'000) {
            REQUIRE(Solve({i, j}) >= 0);
        }
    }
}

TEST_CASE("Time limit") {
    NumType a = 10'000'000;
    for (NumType b = a; b > 1'000'000; b -= 100'000) {
        auto start = std::clock();
        Solve({a, b});
        auto elapsed = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);
        REQUIRE(elapsed < 1);
    }
    auto start = std::clock();
    Solve({714552, 374513});
    auto elapsed = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);
    REQUIRE(elapsed < 1);
}
