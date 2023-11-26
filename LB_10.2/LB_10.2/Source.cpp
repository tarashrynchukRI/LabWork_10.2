#include <iostream>
#include <fstream>
#include <string>
#include <stack>

void removeBracketsContent(std::string inputFileName, std::string outputFileName) {
    std::ifstream inputFile(inputFileName);
    std::ofstream outputFile(outputFileName);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cout << "Cannot open file.\n";
        return;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::stack<int> brackets;
        for (size_t i = 0; i < line.size(); ++i) {
            if (line[i] == '(') {
                brackets.push(i);
            }
            else if (line[i] == ')') {
                if (!brackets.empty()) {
                    int start = brackets.top();
                    brackets.pop();
                    line.erase(line.begin() + start, line.begin() + i + 1);
                    i = start - 1;
                }
            }
        }
        outputFile << line << '\n';
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    std::string inputFileName = "t1.txt";
    std::string outputFileName = "t2.txt";

    removeBracketsContent(inputFileName, outputFileName);

    return 0;
}
