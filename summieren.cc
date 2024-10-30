#include <iostream>
#include <fstream>

int main() {
    std::ifstream infile("daten.txt");
    std::ofstream outfile("datensumme.txt");
    if (!infile) {
        std::cerr << "Error: Unable to open daten.txt\n";
        return 1;
    }
    if (!outfile) {
        std::cerr << "Error: Unable to open datensumme.txt\n";
        return 1;
    }

    int num1, num2;
    for (int i = 0; i < 234; ++i) {
        infile >> num1 >> num2;
        if (infile.fail()) {
            std::cerr << "Error reading pair at line " << i + 1 << "\n";
            break;
        }
        int sum = num1 + num2;
        outfile << sum << std::endl;
    }

    infile.close();
    outfile.close();
    return 0;
}
