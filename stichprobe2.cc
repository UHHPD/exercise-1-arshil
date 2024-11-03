#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

// For sqrt() if you want to calculate standard deviation as well

int main() {
    std::ifstream infile("datensumme.txt");
    if (!infile) {
        std::cerr << "Error: Unable to open datensumme.txt\n";
        return 1;
    }
std::vector<int> sums;
    
    int sum;
    while(infile >> sum) {
        sums.push_back(sum);
    }
    infile.close();

    //checking for enough data

    if (sums.size() < 234){
        std::cerr << "Error: Not enough data to compute mean and variance.\n";
        return 1;
        
    }
    std::ofstream meanFile("mittelwerte.txt");
    std::ofstream varianceFile("varianzen.txt");
    if (!meanFile || !varianceFile){
        std::cerr << "Error: Unable to open files for writing.\n";
        return 1;
    
    }
// mean and varience

// calculate the groups
for(size_t i = 0; i < 26; ++i){
    double total=0.0;
    double variancetotal=0.0;

    //for total of current/each group

   for(size_t j = 0; j <9; ++j) {
       total += sums[i*9+j];
   }
    //calculate mean for each group
    double mean = total/9;
// varience for each group
    for(size_t j = 0; j < 9; ++j){
        variancetotal += (sums[i*9+j] - mean)*(sums[i*9+j] - mean);
    }
    double variance = variancetotal/9;

    //write the mean and varience to the files
    meanFile << mean << std::endl;
    varianceFile << variance << std::endl;
}

    meanFile.close();
    varianceFile.close();
    std::cout << "Files 'mittelwerte.txt' and 'varianzen.txt' created successfully!" << std::endl;
    return 0;

}