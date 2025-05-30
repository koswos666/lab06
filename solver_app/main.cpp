#include "solver.h"
#include <iostream>

int main() {
    double a = 1.0, b = 0.0, c = -4.0;
    Solution s = solve(a, b, c);
    
    std::cout << "Solving equation: " << a << "x^2 + " << b << "x + " << c << " = 0" << std::endl;
    std::cout << "Roots: " << s.x1 << ", " << s.x2 << std::endl;
    
    return 0;
}
