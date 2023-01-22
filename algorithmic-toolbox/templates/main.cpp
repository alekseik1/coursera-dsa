//
// Created by aleksei on 1/21/23.
//
#ifdef MY_COMPILATION

#include "main.h"

#endif

std::istream &operator>>(std::istream &iss, Data &data) {
    return iss;
}

NumType Solve(const Data &) {
    return 0;
}

void PrintAnswer(const NumType) {

}

#ifndef IS_TEST

int main() {
    Data data;
    std::cin >> data;
    PrintAnswer(Solve(data));
    return 0;
}

#endif
