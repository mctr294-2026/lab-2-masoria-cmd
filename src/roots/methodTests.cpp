#include <iostream>
#include <iomanip>

#include "roots.hpp"

double poly1(double x)
{
    // initial bracket [-200, 300]
    return x * x * x - x * x + 2;
}

double poly1_deriv(double x)
{
    return 3 * x * x - 2 * x;
}

double poly1_deriv_deriv(double x) {
    return 6 * x - 2;
}

double poly2(double x)
{
    // initial bracket [-1,1]
    return 2 * x * x * x - 4 * x * x + 3 * x;
}

double poly2_deriv(double x)
{
    return 6 * x * x - 8 * x + 3;
}


double bisectMethod(double a, double b) {
    // Initialize interval [a, b] and the calculated c value
    int counter{};
    double c{0};
            
        // While the distance between b and a are not small enough, run this loop
                while (std::abs(b - a) >= 1e-6) {

                // Calculate the mid points 
                c = (a + b) / 2.00;
                std::cout << c << std::endl;
                counter = counter + 1;
                // If f(c) is really close to 0, show that the root is at c
                if (std::abs(poly2(c)) < 1e-12) {
                    break;
                }

                // If f(c) is not really close to 0, we can iterate again by seeing if the root lies between a and c or c and b
                if (poly2_deriv(c) * poly2(a) < 0) {
                    b =  c; }
                    else {
                        a = c;
                }
        
        }
    double root = c;
    std::cout << "Bisection: root = " << root << ", poly2(root) = " << poly2(root) << ", iterations = " << counter << std::endl;   
    
    return root;

}

double regulaFalsi(double a, double b) {
    // Initialize interval [a, b] and the calculated c value

    double c{a};
    double cd{};
    int iterations{};
            
        // Keep running the loop until a set
                while (poly1(a) * poly1(b) < 0) {
                // Calculate the x intersections 
                c = a - ((poly1(a)*(b - a)) / (poly1(b)- poly1(a)));
                std::cout << c << std::endl;

                // If f(c) is really close to 0, show that the root is about at c
                if (std::abs(poly1(c)) < 1e-12) {
                    break;
                }

                if (std::abs(poly1(c - cd)) < 1e-15) {
                    break;
                }

                // If f(c) is not really close to 0, we can iterate again by seeing if the root lies between a and c or c and b
                if (poly1(c) * poly1(a) < 0) {
                    b =  c; }
                    else {
                        a = c;
                }
        
        }
    double root = c;
    std::cout << "Regula Falsi : root = " << root << ", poly1(root) = " << poly1(root) << std::endl;   
    
    return root;


}

double newtonMethod(double a, double b) {
    // Initialize interval [a, b] and the starting guess c value
    double c{(a - b)/2};
    int counter{0};
        // Infinite while loop for now
                while (std::abs(poly2(c)) > 1e-14) {

                // Calculate the root 
                c = c - (poly2(c)/poly2_deriv(c));
                std::cout << c << std::endl;
                counter = counter + 1;
                
        }
    double root = c;
    std::cout << "Newton : root = " << root << ", poly2(root) = " << poly2(root) << ", iterations = " << counter << std::endl;   
    
    return root;

}

double secantMethod(double a, double b) {
    // Initialize interval [a, b] and the calculated c value
     // Initialize interval [a, b] and the starting guess c value
    double c{};

    int counter{0};
        // Infinite while loop for now
                while (std::abs(poly2(c)) > 1e-14) {

                // Calculate the root 
                c = a - ((b - a) / (poly2(b) - poly2(a))) * poly2(a);
                std::cout << c << std::endl;
                counter = counter + 1;
                a = b;
                b = c;
        }
    double root = c;
    std::cout << "Secant : root = " << root << ", poly2(root) = " << poly2(root) << ", iterations = " << counter << std::endl;   
    
    return root;

}

int main(int argc, char **argv) {       
    const char *method_names[] = {"Bisection", "Regula Falsi", "Newton-Raphson", "Secant"};

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Testing all root-finding methods\n"
              << std::endl;

    // Test poly1 with all methods
    std::cout << "=== poly1(x) = x^3 - x^2 + 2, bracket [-200, 300] ===" << std::endl;
    double a{-200.0};
    double b{300.0};

    bisectMethod(a, b);
    // regulaFalsi(a, b);
    newtonMethod(a, b);
    secantMethod(a, b);


    return 0;
}

    



