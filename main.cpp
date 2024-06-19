#include <iostream>
#include <vector>
#include <limits>

int main() {
    std::vector<double> L;
    double temp;

    std::cout << "Enter a list of items: " << std::endl;
    while (std::cin >> temp) {
        L.push_back(temp);
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::vector<double> nonNegative;
    std::vector<double> negative;

    for (double num : L) {
        if (num >= 0) {
            nonNegative.push_back(num);
        } else {
            negative.push_back(num);
        }
    }

    std::vector<double> modifiedList = nonNegative;

    for (auto it = negative.rbegin(); it != negative.rend(); ++it) {
        modifiedList.push_back(*it);
    }

    std::cout << "Modified list: " << std::endl;
    for (size_t i = 0; i < modifiedList.size(); ++i) {
        std::cout << modifiedList[i] << " ";
        if ((i + 1) % 5 == 0) {
            std::cout << std::endl;
        }
    }

    if (modifiedList.size() % 5 != 0) {
        std::cout << std::endl;
    }

    return 0;
}