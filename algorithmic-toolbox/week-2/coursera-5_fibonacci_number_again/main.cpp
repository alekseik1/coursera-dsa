//
// Created by aleksei on 1/21/23.
//
#ifdef MY_COMPILATION

#include "main.h"

#endif

std::istream &operator>>(std::istream &iss, Data &data) {
    iss >> data.number >> data.modulo;
    return iss;
}

NumType GetPisanoPeriod(const Data &data) {
    NumType prev = 0, current = 1;
    NumType rv = 0;
    NumType tmp;
    for (NumType i = 0; i < data.modulo * data.modulo; ++i) {
        tmp = current;
        current = (current + prev) % data.modulo;
        prev = tmp;

        // Pisano cycle always starts with [0, 1, ...] - there's some maths with it :)
        if (prev == 0 && current == 1) {
            rv = i + 1;
        }
    }
    return rv;
}

NumType Solve(const Data &data) {
    /**
     * Using Pisano period https://en.wikipedia.org/wiki/Pisano_period.
     *
     * 1. Find Pisano period.
     * 2. Find F(n % pisano_period) % modulo and return it as the answer.
     */

    if (data.number < 3) {
        return 1;
    }
    auto period = GetPisanoPeriod(data);
    auto target_number = data.number % period;
    if (target_number == 0) {
        return 0;
    }
    NumType current = 1, prev = 1; // Fib(1), Fib(2) % modulo == 1
    NumType tmp;
    for (NumType i = 2; i < target_number; ++i) {
        tmp = current;
        current = (current + prev) % data.modulo;
        prev = tmp;
    }
    return current;
}

void PrintAnswer(const NumType answer) {
    std::cout << answer;
}

#ifndef IS_TEST

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Data data;
    std::cin >> data;
    PrintAnswer(Solve(data));
    return 0;
}

#endif
