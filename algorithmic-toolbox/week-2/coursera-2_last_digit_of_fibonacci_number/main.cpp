//
// Created by aleksei on 1/21/23.
//
#ifdef MY_COMPILATION

#include "main.h"

#endif

#include <vector>

std::istream &operator>>(std::istream &iss, Data &data) {
    iss >> data.n;
    return iss;
}

NumType Solve(const Data &data) {
    // write your code here
    if (data.n == 0) {
        return 0;
    }
    if (data.n < 3) {
        return 1;
    }
    int current = 1; // Fib(2) % 10
    int prev = 1;    // Fib(1) % 10
    int tmp;
    for (NumType i = 2; i < data.n; ++i) {
        tmp = current;
        current = (current + prev) % 10;
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
