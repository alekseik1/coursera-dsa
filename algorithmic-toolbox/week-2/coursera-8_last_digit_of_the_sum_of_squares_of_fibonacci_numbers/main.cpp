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

NumType LastForNum(const NumType n) {
    auto target = n % 60;
    auto fib = Fib(target);
    return fib;
}

NumType Solve(const Data &data) {
    // One can see that answer is F[n] * F[n+1]
    // Let F[n] = r1 + 10 d1
    // F[n+1] = r2 + 10 d2
    // then F[n] * F[n+1] = r1 r2 + 10r1 d2 + 10 r2 d1 + 100d1 d2
    // F[n] * F[n+1] % 10 = (r1 r2) % 10
    // Nice, we can reuse solution from the previous task
    auto r1 = LastForNum(data.n);
    auto r2 = LastForNum(data.n + 1);
    return (r1 * r2) % 10;
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
