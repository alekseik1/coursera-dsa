//
// Created by aleksei on 1/21/23.
//
#ifdef MY_COMPILATION

#include "main.h"

#endif


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
    NumType first_max, second_max;
    for (size_t i = 0; i < data.numbers.size(); ++i) {
        NumType v = data.numbers[i];
        if (i == 0) {
            first_max = i;
            continue;
        }
        if (i == 1) {
            second_max = i;
            if (data.numbers[first_max] < data.numbers[second_max]) {
                std::swap(first_max, second_max);
            }
            continue;
        }
        if (v > data.numbers[first_max]) {
            second_max = first_max;
            first_max = i;
        } else if (i != first_max && v > data.numbers[second_max]) {
            second_max = i;
        }
    }
    return data.numbers[first_max] * data.numbers[second_max];
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
