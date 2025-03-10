#include <iostream>
#include <fstream>
#include "caesar_cipher.h"

// Function to process a file (encrypt or decrypt)
void processFile(const std::string& inputFile, const std::string& outputFile, int key, bool encryptFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    if (!inFile) {
        std::cerr << "Error: Could not open input file.\n";
        return;
    }
    if (!outFile) {
        std::cerr << "Error: Could not open output file.\n";
        return;
    }

    std::string line;
    while (getline(inFile, line)) {
        std::string processedLine = encryptFile ? encrypt(line, key) : decrypt(line, key);
        outFile << processedLine << "\n";
    }

    std::cout << "File processing completed. Output saved to " << outputFile << "\n";
}

int main() {
    std::string inputFile, outputFile;
    int key;
    char choice;

    std::cout << "Enter input file name: ";
    std::cin >> inputFile;
    std::cout << "Enter output file name: ";
    std::cin >> outputFile;
    std::cout << "Enter key (integer): ";
    std::cin >> key;
    std::cout << "Encrypt (E) or Decrypt (D)? ";
    std::cin >> choice;

    if (tolower(choice) == 'e') {
        processFile(inputFile, outputFile, key, true);
    } else if (tolower(choice) == 'd') {
        processFile(inputFile, outputFile, key, false);
    } else {
        std::cerr << "Invalid choice. Please choose 'E' or 'D'.\n";
    }

    return 0;
}
