//
// Created by aleksei on 1/21/23.
//

#pragma once

#include <iostream>
#include <vector>

using NumType = int;

struct Data {
    NumType total_compounds;
    NumType capacity;
    std::vector<std::pair<NumType, NumType>> compounds;
};

std::istream &operator>>(std::istream &iss, Data &data);

double Solve(const Data &);

void PrintAnswer(const double);
