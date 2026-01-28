#include <functional>
#include <iostream>

bool bisection(std::function<double(double)> f,
               double a, double b,
               double *root)

               {
    // Initialize interval [a, b] and the calculated c value
    int counter{};
    double c{};
            
        // While the distance between b and a are not small enough, run this loop
        if (f(a)*f(b) < 0) {
                while (std::abs(b - a) >= 1e-6) {

                // Calculate the mid points 
                c = (a + b) / 2.00;

                // Keeps track of iteration count
                counter = counter + 1;

                // If f(c) is really close to 0, show that the root is at c
                if (std::abs(f(c)) < 1e-6) {
                    break;
                }

                // If f(c) is not really close to 0, we can iterate again by seeing if the root lies between a and c or c and b
                if (f(c) * f(a) < 0) {
                    b =  c; }
                    else {
                        a = c;
                }
            }
            *root = c; 
            return true;

                         }
            else {
                return false;
            }
    
}
    
bool regula_falsi(std::function<double(double)> f,
                  double a, double b,
                  double *root)

                  {
    // With a and b, we still need an initial c-value and to keep comparing it to itself for precision
    int counter{0};
    double c{};
    double cd{};
    
            
        // Keep running the loop until desired tolerance
        if (f(a) < 0 or f(b) > 0) { 
                while (std::abs(f(c)) >  1e-6) {

                // Calculate the x intersections (derived)
                c = a - ((f(a)*(b - a)) / (f(b)- f(a)));

                // Iteration count
                counter = counter + 1;

                // Stop whenever we get to a point where the difference between c and the previous iteration cd evaluates f(x) to nearly zero
                if (std::abs(f(c - cd)) < 1e-6) {
                    break;
                }

                // If f(c) is not really close to 0, we can iterate again by seeing if the root lies between a and c or c and b
                if (f(c) * f(a) < 0) {
                    b =  c; }
                    else {
                        a = c;
                }
        
        }
        }
        else {
            return false;
        }
    *root = c;
    
    return true;


}

bool newton_raphson(std::function<double(double)> f,
                    std::function<double(double)> g,
                    double a, double b, double c,
                    double *root)
                    {

    int counter{0};
        // While loop until desired tolerance
        if (c > a & c < b & g(c) != 0) {
                while (std::abs(f(c)) > 1e-6) {

                // Calculate the root using Newton's method
                c = c - (f(c)/g(c));

                // Iteration count
                counter = counter + 1;
                
            }
        *root = c;
            return true;
        }
            else {
                return false;
            }

}

bool secant(std::function<double(double)> f,
            double a, double b, double c,
            double *root)
            {
                
    int counter{0};

        // While loop until desired precision
        if (c > a & c < b) {
                while (std::abs(f(c)) > 1e-6) {

                // Use secant method to iterate c
                c = a - ((b - a) / (f(b) - f(a))) * f(a);
                
                // Iteration count for debugging
                counter = counter + 1;

                // The bounds are then swapped to keep stepping closer to c
                a = b;
                b = c;
        }
        *root = c;
        return true;
}
            else {
                return false;
            }
        }