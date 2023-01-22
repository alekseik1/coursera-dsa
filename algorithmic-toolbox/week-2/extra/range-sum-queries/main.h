//
// Created by aleksei on 1/21/23.
//

#pragma once

#include <iostream>
#include <vector>

using NumType = int;

struct Data {
    NumType total_numbers;
    std::vector<NumType> numbers;
    NumType total_queries;
    std::vector<std::pair<NumType, NumType>> queries;
};

std::istream &operator>>(std::istream &iss, Data &data);

std::vector<NumType> Solve(const Data &);

void PrintAnswer(const NumType);
