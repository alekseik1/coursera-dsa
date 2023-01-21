//
// Created by aleksei on 1/21/23.
//
#include "main.h"

std::istream &operator>>(std::istream &iss, Data &data) {
    return iss;
}

Data ReadInput() {
    return {};
}

NumType Solve(const Data&) {
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
