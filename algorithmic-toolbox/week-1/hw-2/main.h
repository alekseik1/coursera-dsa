//
// Created by aleksei on 1/21/23.
//

#pragma once

#include <iostream>
#include <cstdint>
#include <vector>


using NumType = uint_fast64_t;

struct Data {
    std::vector<NumType> numbers;
    size_t total;
};

std::istream &operator>>(std::istream &iss, Data &data);

NumType Solve(const Data &data);

void PrintAnswer(const NumType result);