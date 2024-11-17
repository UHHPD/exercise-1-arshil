#include <iostream>
#include <fstream>
#include <cmath>

// Function to compute Poisson probability
double poissonProbability(double lambda, int k) {
    if (k < 0) return 0.0; // No negative occurrences
    double factorial = tgamma(k + 1); // Using gamma function for factorial
    return (std::pow(lambda, k) * std::exp(-lambda)) / factorial;
}

int main() {
    const double lambda = 3.11538; // Mean value
    const int maxX = 10;            // X values from 0 to 8
    const int N = 234;             // Total number of events

    // Open file for writing
    std::ofstream outFile("histpoi.txt");
    if (!outFile) {
        std::cerr << "Error: Could not open file for writing!" << std::endl;
        return 1; // Exit with error code
    }

    // Write header to the file
    outFile << "X\tExpectationValue\n";

    // Calculate and write expectation values for X = 0 to 8
    for (int X = 0; X <= maxX; ++X) {
        double prob = poissonProbability(lambda, X); // Poisson probability
        double expectationValue = N * prob;          // N * P(X = k)
        outFile << X << "\t" << expectationValue << "\n";
    }

    // Close the file
    outFile.close();
    std::cout << "Data successfully written to histpoi.txt" << std::endl;

    return 0;
}
