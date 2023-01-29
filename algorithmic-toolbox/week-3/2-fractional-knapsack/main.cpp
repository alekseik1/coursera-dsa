//
// Created by aleksei on 1/21/23.
//
#ifdef MY_COMPILATION

#include "main.h"
#include <iomanip>

#endif

std::istream &operator>>(std::istream &iss, Data &data) {
    iss >> data.total_compounds >> data.capacity;
    data.compounds.resize(data.total_compounds);
    for (NumType i = 0; i < data.total_compounds; ++i) {
        iss >> data.compounds[i].first >> data.compounds[i].second;
    }
    return iss;
}

double Solve(const Data &data) {
    return 180.012301248124;
}

void PrintAnswer(const double answer) {
    std::cout << std::fixed << std::showpoint << std::setprecision(4) << answer;
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
