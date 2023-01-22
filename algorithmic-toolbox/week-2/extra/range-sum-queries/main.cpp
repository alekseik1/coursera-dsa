//
// Created by aleksei on 1/21/23.
//
#ifdef MY_COMPILATION

#include "main.h"

#endif

std::istream &operator>>(std::istream &iss, Data &data) {
    iss >> data.total_numbers;
    data.numbers.resize(data.total_numbers);
    for (NumType i = 0; i < data.total_numbers; ++i) {
        iss >> data.numbers[i];
    }
    iss >> data.total_queries;
    data.queries.resize(data.total_queries);
    for (NumType i = 0; i < data.total_queries; ++i) {
        iss >> data.queries[i].first >> data.queries[i].second;
    }
    return iss;
}

std::vector<NumType> Solve(const Data &) {
    // google "range sum queries problem" and some leetcode problem (for testing)
    return {};
}

void PrintAnswer(const std::vector<NumType> &answers) {
    for (const auto v: answers) {
        std::cout << v << '\n';
    }
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
