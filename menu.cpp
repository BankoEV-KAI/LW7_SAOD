#include "menu.h"
#include <iostream>


void printMenu(int operation) {

    std::cout << std::endl << "  > - - - - - - - - <     " << std::endl;
    switch (operation)
    {
    case 1:
        std::cout << std::endl
            << "1. Просмотр в ПРЯМОМ напрвлении; " << std::endl
            << "2. Просмотр в ОБРАТНОМ напрвлении; " << std::endl
            << "3. Добавление элемента ДО;" << std::endl
            << "4. Добавление элемента ПОСЛЕ;" << std::endl
            << "5. Удаление элемента из списка; " << std::endl
            << "6. Поиск элемента в списке в ПРЯМОМ направлении; " << std::endl
            << "7. Поиск элемента в списке в ОБРАТНОМ направлении; " << std::endl
            << "8. Вывод текущего состояния списка; " << std::endl
            << "0. Вернуться в начало." << std::endl
            << std::endl;
        break;
    default:
        break;
    }
}

void enteringNumber(int rangeStart, int rangeStop, int& value) {
    while (true) {
        std::cout << "Введите число от " << rangeStart << " до " << rangeStop << " >> ";
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. ";
        }
        else if (value >= rangeStart && value <= rangeStop) {
            return;
        }
        else {
            std::cout << "Некорректное число. ";
        }
    }
}