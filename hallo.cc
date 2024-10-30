#include <iostream>
#include <cmath> // for sqrt function
#include <complex> // for complex numbers

void findRoots(double a, double b, double c) {
    if (a == 0) {
        std::cout << "Not a quadratic equation (a should not be 0)." << std::endl;
        return;
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        // Two distinct real roots
        double root1 = (-b + std::sqrt(discriminant)) / (2 * a);
        double root2 = (-b - std::sqrt(discriminant)) / (2 * a);
        std::cout << "Roots are real and distinct:\n";
        std::cout << "Root 1 = " << root1 << "\n";
        std::cout << "Root 2 = " << root2 << "\n";
    } 
    else if (discriminant == 0) {
        // One real root
        double root = -b / (2 * a);
        std::cout << "Roots are real and equal:\n";
        std::cout << "Root = " << root << "\n";
    } 
    else {
        // Complex roots
        std::complex<double> root1((-b / (2 * a)), std::sqrt(-discriminant) / (2 * a));
        std::complex<double> root2((-b / (2 * a)), -std::sqrt(-discriminant) / (2 * a));
        std::cout << "Roots are complex:\n";
        std::cout << "Root 1 = " << root1 << "\n";
        std::cout << "Root 2 = " << root2 << "\n";
    }
}

int main() {
    double a, b, c;

    std::cout << "Enter coefficients a, b, and c: ";
    std::cin >> a >> b >> c;

    findRoots(a, b, c);

    return 0;
}


