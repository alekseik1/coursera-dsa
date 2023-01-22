//
// Created by aleksei on 1/21/23.
//

#pragma once

#include <iostream>

using NumType = int;

struct Data {
    NumType first_number, second_number;
};

std::istream &operator>>(std::istream &iss, Data &data);

NumType Solve(Data);

void PrintAnswer(const NumType);
