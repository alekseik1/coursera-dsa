//
// Created by aleksei on 1/21/23.
//
#ifdef MY_COMPILATION

#include "main.h"

#endif

std::istream &operator>>(std::istream &iss, Data &data) {
    iss >> data.n;
    return iss;
}

NumType Fib(NumType n) {
    if (n == 0) {
        return 0;
    }
    if (n < 3) {
        return 1;
    }
    NumType prev = 1, current = 1;
    NumType tmp;
    for (NumType i = 2; i < n; ++i) {
        tmp = current;
        current = (current + prev) % 10;
        prev = tmp;
    }
    return current;
}

NumType Solve(const Data &data) {
    // one can see that S[n] = F[n+2] - 1
    // Same problem as Huge Fibonacci with m=10
    // pi(10) = 60 btw
    auto target = data.n + 2;
    target = target % 60;
    auto fib = Fib(target);
    return (fib - 1 + 10) % 10;
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
