#include "solver.h"
#include <iostream>

int main() {
    // Пример использования
    std::cout << "Solving equation: x^2 - 4 = 0" << std::endl;
    double a = 1.0, b = 0.0, c = -4.0;
    Solution s = solve(a, b, c);
    std::cout << "Roots: " << s.x1 << ", " << s.x2 << std::endl;
    return 0;
}
