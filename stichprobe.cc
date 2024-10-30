#include <iostream>
#include <fstream>
#include <cmath>  // For sqrt() if you want to calculate standard deviation as well

int main() {
    std::ifstream infile("datensumme.txt");
    if (!infile) {
        std::cerr << "Error: Unable to open datensumme.txt\n";
        return 1;
    }

    int sum, count = 0;
    double total = 0.0;
    double mean = 0.0;
    double variance_total = 0.0;
    

    // First, read all sums to calculate total and count
    while (infile >> sum) {
        total += sum;
        ++count;
    }

    infile.close();

    // Check if count is zero to avoid division by zero
    if (count == 0) {
        std::cerr << "Error: No data to compute mean and variance.\n";
        return 1;
    }

    // Calculate the mean
    mean = total / count;

    // Reopen the file to calculate variance
    infile.open("datensumme.txt");
    while (infile >> sum) {
        variance_total += (sum - mean) * (sum - mean);
    }

    infile.close();

    // Calculate variance
    double variance = variance_total / count;
    double standard_deviation = sqrt(variance);

    // Output the results
    std::cout << "The mean of the sums in datensumme.txt is: " << mean << std::endl;
    std::cout << "The variance of the sums in datensumme.txt is: " << variance << std::endl;
    std::cout << "The standard variance of the sums in datensumme.txt is: " << standard_deviation  << std::endl;
    return 0;
}
