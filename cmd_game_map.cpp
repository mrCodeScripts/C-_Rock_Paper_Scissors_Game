#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <conio.h>

void controlDetection (int &xPos, int &yPos) {
    char key = _getch();
    switch (key) {
        case 119: yPos--; break; // w → UP
        case 115: yPos++; break; // s → DOWN
        case 100: xPos++; break; // d → RIGHT
        case 97:  xPos--; break; // a → LEFT
    }
}

int main () {

    std::string strMap;

    int height = 50;
    int width = 80;
    bool animate = true;
    int ms = 10;

    int heroPositionX = 10;
    int heroPositionY= 10;

    while (animate) {
        system("cls");

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (i == 0 || i == height - 1) {
                    std::cout << '-';
                } else if ((j == 0 || j == width - 1) && i > 0 && i < height - 1) {
                    std::cout << '|';
                } else if (i == heroPositionY && j == heroPositionX) {
                    std::cout << 'A';
                } else {
                    std::cout << ' ';
                }
            }
            std::cout << std::endl;
        }

        controlDetection(heroPositionX, heroPositionY);

        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }

    return 0;
}
