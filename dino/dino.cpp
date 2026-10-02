#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

size_t score = 0;

const size_t screenWidth = 60;
const size_t pos = screenWidth / 3;
size_t chance = 20;
size_t speed = 100;

bool jumping = false;
size_t airTime = 0;

char dino = '&';
char air = ' ';
char flr = '-';
char dbg = 'X';

char getObs() {
    size_t options = rand() % (3 + 1);
    switch (options) {
    case 1:
        return 'T';
        break;
    case 2:
        return 'Y';
        break;

    default:
        return 'I';
        break;
    }
}

size_t printHighscore() {
    std::ifstream file("highscore.txt");

    size_t hsc = 0;

    if (file) {
        file >> hsc;
    }

    file.close();

    return hsc;
}

void writeHighscore() {
    size_t hsc = printHighscore();

    if (score > hsc) {
        std::ofstream hs("highscore.txt");

        hs << score;

        hs.close();
     }
}

void hud() {
    std::cout << std::setw(20) << "\tSCORE: " << score << std::endl;
    if (score > printHighscore()) {
        std::cout << std::setw(20) << "\tHighscore: " << score << std::endl;
    }
    else {
        std::cout << std::setw(20) << "\tHighscore: " << printHighscore() << std::endl;
    }
}

void fillLayer1(char* arr2) {
    for (size_t i = 0; i < screenWidth; i++) {
        arr2[i] = air;
    }
}

void fillLayer2(char *arr2) {
    for (size_t i = 0; i < screenWidth; i++) {
        arr2[i] = air;
    }
}

void fillLayer3(char* arr3) {
    for (size_t i = 0; i < screenWidth; i++) {
        arr3[i] = flr;
    }
}

void scrollLayer2(char* arr2, size_t rare) {
    for (size_t i = 1; i < screenWidth; i++) {
        arr2[i - 1] = arr2[i];
    }

    if (rand() % rare == rare - 1) {
        arr2[screenWidth - 1] = getObs();
    }
    else {
        arr2[screenWidth - 1] = air;
    }
}

void printBoard(char* arr1, char* arr2, char* arr3) {
    for (size_t i = 0; i < screenWidth; i++) {
        std::cout << arr1[i];
    }
    std::cout << std::endl;
    for (size_t i = 0; i < screenWidth; i++) {
        std::cout << arr2[i];
    }
    std::cout << std::endl;
    for (size_t i = 0; i < screenWidth; i++) {
        std::cout << arr3[i];
    }
}

void player(char* arr1, char* arr2) {
    if (_kbhit()) {
        char key = _getch();
        if (key == ' ' && jumping) {
            airTime = 0;
            jumping = false;
        }
        if (key == ' ' && !jumping) {
            airTime = 5;
            jumping = true;
        }
    }

    arr1[pos] = air;
    if (arr2[pos - 1] == dino) {
        arr2[pos-1] = air;
    }

    if (jumping) {
        arr1[pos] = dino;

        airTime--;

        if (airTime <= 0) {
            jumping = false;
        }
    }
    else {
        arr2[pos] = dino;
    }
}

bool isValid(char* arr2, bool inAir) {
    if (arr2[pos + 1] != air && inAir == false) {
        return false;
    }
    else{
        return true;
    }
}

void game(size_t tick=speed, size_t obst=chance) {
    char arr1[screenWidth];
    char arr2[screenWidth];
    char arr3[screenWidth];

    fillLayer1(arr1);
    fillLayer2(arr2);
    fillLayer3(arr3);

    do {
        scrollLayer2(arr2, obst);

        hud();
        player(arr1, arr2);

        printBoard(arr1, arr2, arr3);

        if (isValid(arr2,jumping)) {
            score++;
            Sleep(tick);
            system("cls");
        }
        else {
            break;
        }
    } while (true);
    writeHighscore();
    std::cout << std::endl << std::setw(20) << "End" << std::endl
        << std::setw(20) << "Your score: " << score << std::endl
        << std::setw(20) << "Your highscore: " << printHighscore();
    Sleep(1000);
}

int main()
{
    srand(time(NULL));

    std::cout << std::setw(55) << "V(Recommended ~100)" << std::endl;
    std::cout << "Enter time (ms) between game ticks: ";
    size_t speedIn;
    std::cin >> speedIn;
    std::cout << std::endl << std::setw(66) << "V(Recommended ~20)" << std::endl;
    std::cout << "Enter chance (smaller=more) to spawn obstacles: ";
    size_t chanceIn;
    std::cin >> chanceIn;

    game(speedIn, chanceIn);
    
    return 0;
}