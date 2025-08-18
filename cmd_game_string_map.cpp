#include <iostream>
#include <conio.h>
#include <thread>
#include <chrono>
#include <fstream>

int main () {
    std::string fileName = "myfile.txt";
    std::string paper;
    char c;

    std::ofstream file(fileName);
    std::fstream fs(fileName, std::ios::out | std::ios::app);

    if (!fs) {
        std::cerr << "File error!" << std::endl;
    }

    while ((c = _getch()) != 13) {
        system("cls");
        std::cout << "======================" << std::endl;
        std::cout << "Write here: " << std::endl;
        std::cout << "======================" << std::endl;

        if (c == 8) {
            if (!paper.empty()) {
                paper.pop_back();
            } 
        } else {
            paper.push_back(c);
        }
        std::cout << paper;
    }

    fs << paper;
    fs.close();
}

