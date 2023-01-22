//
// Created by aleksei on 1/21/23.
//

#pragma once

#include <iostream>

using NumType = int;

struct Data {
    NumType n, k;
};

std::istream &operator>>(std::istream &iss, Data &data);

NumType Solve(const Data &);

void PrintAnswer(const NumType);
