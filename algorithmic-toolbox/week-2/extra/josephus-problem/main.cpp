//
// Created by aleksei on 1/21/23.
//
#ifdef MY_COMPILATION

#include "main.h"

#endif

std::istream &operator>>(std::istream &iss, Data &data) {
    iss >> data.n >> data.k;
    return iss;
}

NumType Solve(const Data &) {
    // Just google "Josephus problem" and some leetcode problem (for testing)
    return 0;
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
