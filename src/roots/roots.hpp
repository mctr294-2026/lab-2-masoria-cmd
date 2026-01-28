#include <functional>

/* Tries to find a zero crossing in f() in the interval [a,b] with the bisection method
 * Returns true if a root is found. The crossing is stored in root.
 * Returns false if a crossing could not be found. Finding a root
 * is only guarenteed if f is continous within the interval and
 * a & b have opposite signs
 */
bool bisection(std::function<double(double)> f,
               double a, double b,
               double *root)

               {
    // Initialize interval [a, b] and the calculated c value
    int counter{};
    double c{0};
            
        // While the distance between b and a are not small enough, run this loop
                while (std::abs(b - a) >= 1e-6) {

                // Calculate the mid points 
                c = (a + b) / 2.00;
                // std::cout << c << std::endl;
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
    std::cout << "iterations = " << counter << ", ";
    *root = c;  
    
    return true, counter;
}
    

/* Tries to find a zero crossing in f() in the interval [a,b] with the
 * false positive / regula falsi method
 * Returns true if a root is found. The crossing is stored in root.
 * Returns false if a crossing could not be found. Finding a root
 * is only guarenteed if f is continous within the interval and
 * a & b have opposite signs
 */
bool regula_falsi(std::function<double(double)> f,
                  double a, double b,
                  double *root)

                  {
    // Initialize interval [a, b] and the calculated c value

    double c{a};
    double cd{};
    int counter{0};
            
        // Keep running the loop until a set
                while (std::abs(f(c)) >  1e-6) {
                // Calculate the x intersections 
                counter = counter + 1;
                c = a - ((f(a)*(b - a)) / (f(b)- f(a)));
                // std::cout << c << std::endl;

                if (std::abs(f(c - cd)) < 1e-15) {
                    break;
                }

                // If f(c) is not really close to 0, we can iterate again by seeing if the root lies between a and c or c and b
                if (f(c) * f(a) < 0) {
                    b =  c; }
                    else {
                        a = c;
                }
        
        }
    std::cout << "iterations = " << counter << ", ";
    *root = c;
    
    return true, counter;


}


/* Tries to find a zero crossing in f() in the interval [a,b] with
 * the netwon-raphson method, given a function that computes the
 * derivative g() and a starting guess c.
 * Returns true if a root is found. The crossing is stored in root.
 * Returns false if a crossing could not be found, which can happen
 * if iteration leaves the interval, or the derivative is zero.
 */
bool newton_raphson(std::function<double(double)> f,
                    std::function<double(double)> g,
                    double a, double b, double c,
                    double *root)
                    {
    // Initialize interval [a, b] and the starting guess c value
    int counter{0};
        // Infinite while loop for now
                while (std::abs(f(c)) > 1e-6) {

                // Calculate the root 
                c = c - (f(c)/g(c));
                // std::cout << c << std::endl;
                counter = counter + 1;
                
        }
    std::cout << "iterations = " << counter << ", ";
    *root = c;
    
    return true, counter;

}

/* Tries to find a zero crossing in f() in the interval [a,b] with
 * the secant method, given a starting guess c.
 * Returns true if a root is found. The crossing is stored in root.
 * Returns false if a crossing could not be found, which can happen
 * if iteration leaves the interval, or derivative is zero.
 */
bool secant(std::function<double(double)> f,
            double a, double b, double c,
            double *root)
            {
    // Initialize interval [a, b] and the calculated c value
     // Initialize interval [a, b] and the starting guess c value

    int counter{0};
        // Infinite while loop for now
                while (std::abs(f(c)) > 1e-6) {

                // Calculate the root 
                c = a - ((b - a) / (f(b) - f(a))) * f(a);
                // std::cout << c << std::endl;
                counter = counter + 1;
                a = b;
                b = c;
        }
    *root = c;
    std::cout << "iterations = " << counter << ", ";
    return true, counter;

}