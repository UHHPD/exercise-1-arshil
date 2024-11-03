#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

// part a of exercise 2
// For sqrt() if you want to calculate standard deviation as well

int main()
{
    std::ifstream infile("datensumme.txt");
    if (!infile)
    {
        std::cerr << "Error: Unable to open datensumme.txt\n";
        return 1;
    }
    std::vector<int> sums;

    int sum;
    while (infile >> sum)
    {
        sums.push_back(sum);
    }
    infile.close();

    // checking for enough data

    if (sums.size() < 234)
    {
        std::cerr << "Error: Not enough data to compute mean and variance.\n";
        return 1;
    }
    std::ofstream meanFile("mittelwerte.txt");
    std::ofstream varianceFile("varianzen.txt");
    if (!meanFile || !varianceFile)
    {
        std::cerr << "Error: Unable to open files for writing.\n";
        return 1;
    }
    // mean and varience

    // calculate the groups
    for (size_t i = 0; i < 26; ++i)
    {
        double total = 0.0;
        double variancetotal = 0.0;

        // for total of current/each group

        for (size_t j = 0; j < 9; ++j)
        {
            total += sums[i * 9 + j];
        }
        // calculate mean for each group
        // checking
        double mean = total / 9;
        // varience for each group
        for (size_t j = 0; j < 9; ++j)
        {
            variancetotal += (sums[i * 9 + j] - mean) * (sums[i * 9 + j] - mean);
        }
        double variance = variancetotal / 9;

        // write the mean and varience to the files
        meanFile << mean << std::endl;
        varianceFile << variance << std::endl;
    }

    meanFile.close();
    varianceFile.close();
    std::cout << "Files 'mittelwerte.txt' and 'varianzen.txt' created successfully!" << std::endl;
    // return 0;

    std::ifstream infile2("mittelwerte.txt");
    if (!infile2)
    {
        std::cerr << "Error: Unable to open mittel3.txt\n";
        return 1;
    }

    double sum1, count1 = 0;
    double total1 = 0.0;
    double mean1 = 0.0;

    // First, read all sums to calculate total and count
    while (infile2 >> sum1)
    {
        total1 += sum1;
        ++count1;
    }

    infile2.close();

    // Check if count is zero to avoid division by zero
    if (count1 == 0)
    {
        std::cerr << "Error: No data to compute mean and variance.\n";
        return 1;
    }

    // Calculate the mean
    mean1 = total1 / count1;

    // variance

    std::ifstream infile1("varianzen.txt");
    if (!infile1)
    {
        std::cerr << "Error: Unable to open varianzen2.txt\n";
        return 1;
    }

    double summ, countt = 0;
    double totall = 0.0;
    double meann = 0.0;

    // First, read all sums to calculate total and count
    while (infile1 >> summ)
    {
        totall += summ;
        ++countt;
    }

    infile1.close();

    // Check if count is zero to avoid division by zero
    if (countt == 0)
    {
        std::cerr << "Error: No data to compute mean and variance.\n";
        return 1;
    }

    meann = totall / countt;

    // Output the results
    std::cout << "The mean of the mean in mittelwerte2.txt is: " << mean1 << std::endl;
    std::cout << "The mean of the variance in varianzen2.txt is: " << meann << std::endl;

    return 0;
}