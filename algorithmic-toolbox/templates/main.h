//
// Created by aleksei on 1/21/23.
//

#pragma once

#include <iostream>

using NumType = int;

struct Data {
};

std::istream &operator>>(std::istream &iss, Data &data);

Data ReadInput();

NumType Solve(const Data &);

void PrintAnswer(const NumType);