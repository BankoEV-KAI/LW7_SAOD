#include "menu.h"
#include"structList.h"
#include <iostream>

//линейный динамический двунаправленный список

int main()
{

    setlocale(LC_ALL, "ru");
    int newData{ 0 }, operation{ 0 }, findData{ 0 }, index{ 0 };
    initList();

    
    printForward();

    insertByData(78, 17, BEFORE); insertByData(2, 21, AFTER);
    printForward();
    printBackward();

    while (true)
    {
        printMenu(1);
        enteringNumber(0, 8, operation);
        switch (operation) {
        case 0:
            break;
        case 1:
            printForward();
            break;
        case 2:
            printBackward();
            break;
        case 3:
            std::cout << "Какой элемент добавим >> ";
            enteringNumber(1, 100, newData);
            std::cout << "До какого добавим >> ";
            enteringNumber(1, 100, findData);
            insertByData(findData, newData, BEFORE);
            printForward();
            break;
        case 4:
            std::cout << "Какой элемент добавим >> ";
            enteringNumber(1, 100, newData);
            std::cout << "После какого добавим >> ";
            enteringNumber(1, 100, findData);
            insertByData(findData, newData, AFTER);
            printForward();
            break;
        case 5:
            std::cout << "Какой элемент удалить >> ";
            enteringNumber(1, 100, findData);
            deleteNode(findData);
            break;
        case 6:
            std::cout << "Индекс какого элемента ищем >> ";
            enteringNumber(0, 100, findData);
            index = findIndex(findData, FORWARD);
            index == -1 ?
                std::cout << "Элемент " << findData << " найден на позиции (в ПРЯМОМ направлении) " << index :
                std::cout << "Элемент " << findData << " не найден.";
            break;
        case 7:
            std::cout << "Индекс какого элемента ищем >> ";
            enteringNumber(0, 100, findData);
            index = findIndex(findData, FORWARD);
            index == -1 ?
                std::cout << "Элемент " << findData << " найден на позиции (в ОБРАТНОМ направлении) " << index :
                std::cout << "Элемент " << findData << " не найден.";
            break;
        case 8:
            printForward(); 
            break;
        default:
            break;
        }
    }
}

