//
// Created by aleksei on 1/21/23.
//
#include "main.h"
#include <optional>

std::istream &operator>>(std::istream &iss, Data &data) {
    NumType current;
    std::cin >> data.total;
    data.numbers.reserve(data.total);
    for (size_t i = 0; i < data.total; ++i) {
        std::cin >> current;
        data.numbers.push_back(current);
    }
    return iss;

}

NumType Solve(const Data &data) {
    std::optional<size_t> first_max, second_max;
    for (size_t i = 0; i < data.numbers.size(); ++i) {
        NumType v = data.numbers[i];
        if (i == 0) {
            first_max = i;
            continue;
        }
        if (i == 1) {
            second_max = i;
            if (data.numbers[first_max.value()] < data.numbers[second_max.value()]) {
                std::swap(first_max, second_max);
            }
            continue;
        }
        if (v > data.numbers[first_max.value()]) {
            second_max = first_max;
            first_max = i;
        } else if (i != first_max.value() && v > data.numbers[second_max.value()]) {
            second_max = i;
        }
    }
    return data.numbers[first_max.value()] * data.numbers[second_max.value()];
}

void PrintAnswer(const NumType result) {
    std::cout << result;
}

#ifndef IS_TEST

int main() {
    Data data;
    std::cin >> data;
    PrintAnswer(Solve(data));
    return 0;
}

#endif
