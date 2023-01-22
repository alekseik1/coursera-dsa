//
// Created by aleksei on 1/21/23.
//
#ifdef MY_COMPILATION

#include "main.h"

#endif

std::istream &operator>>(std::istream &iss, Data &data) {
    iss >> data.first_number >> data.second_number;
    return iss;
}

NumType Gcm(Data data) {
    if (data.first_number < data.second_number) {
        std::swap(data.first_number, data.second_number);
    }
    if (data.second_number == 0) {
        return data.first_number;
    }
    return Gcm({data.first_number % data.second_number, data.second_number});
}

NumType Solve(Data data) {
    // LCM(a, b) = a * b / GCM(a, b);
    return data.first_number * data.second_number / Gcm(data);
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
