#include "solver.h"
#include <cmath>

Solution solve(double a, double b, double c) {
    double discriminant = b*b - 4*a*c;
    Solution s;
    
    if (discriminant > 0) {
        s.x1 = (-b + sqrt(discriminant)) / (2*a);
        s.x2 = (-b - sqrt(discriminant)) / (2*a);
    } else if (discriminant == 0) {
        s.x1 = s.x2 = -b / (2*a);
    } else {
       
        s.x1 = s.x2 = NAN;
    }
    
    return s;
}
