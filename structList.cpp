#include "structList.h"
#include<iostream>

listNode* listHeader;
int countItems;

void initList()
{
    listHeader = new listNode;
    listHeader->next = listHeader;
    listHeader->prev = listHeader;
    countItems = 0;
}
static bool isEmpty() {
    return (listHeader->next == listHeader->prev);
}

void printForward() {
    if (isEmpty()) {
        std::cout << "Список пуст. " << std::endl;
        return;
    }

    std::cout << "элементы списка в прямом направлении: ";
    listNode* current = listHeader->next;
    while (current != listHeader) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void printBackward() {
    if (isEmpty()) {
        std::cout << "Список пуст. " << std::endl;
        return;
    }
    std::cout << "элементы списка в обратном направлении: ";
    listNode* current = listHeader->prev;
    while (current != listHeader) {
        std::cout << current->data << " ";
        current = current->prev;
    }
    std::cout << std::endl;
}

int findIndex(int findData, Derection derection) {
    if (derection == FORWARD) {
        listNode* current = listHeader->next;
        int index = 0;
        while (current != listHeader) {
            if (current->data == findData) {
                return index;
            }
            current = current->next;
            index++;
        }
        return -1; 
    }
    else if (derection == BACKWARD) {
        listNode* current = listHeader->prev;
        int index = 0;
        while (current != listHeader) {
            if (current->data == findData) {
                return index;
            }
            current = current->prev;
            index++;
        }
        return -1;
    }
    else return -1;
}

int findData(int position, Derection direction) {
    if (direction == FORWARD) {
        listNode* current = listHeader->next;
        for (int i = 0; i < position; ++i) {
            if (current == listHeader) {
                return -1; 
            }
            current = current->next;
        }
        return current->data;
    }
    else if (direction == BACKWARD) {
        listNode* current = listHeader->prev;
        for (int i = 0; i < position; ++i) {
            if (current == listHeader) {
                return -1; 
            }
            current = current->prev;
        }
        return current->data;
    }
    return -1;
}

void insertByData(int findData, int newData, Position position) {

    listNode* searchNode = listHeader->next;
    while (searchNode != listHeader && searchNode->data != findData) {
        searchNode = searchNode->next;
    }

    countItems++;

    if (searchNode == listHeader) {
        listNode* newNode = new listNode;
        newNode->data = newData;
        newNode->next = listHeader;
        newNode->prev = listHeader->prev;
        listHeader->prev->next = newNode;
        listHeader->prev = newNode;
        std::cout << "Элемент " << newData << "вставлен в конец списка. Причина: отстствует искомый элемент. " << std::endl;
        return;
    }

    if (position == BEFORE) {
            listNode* newNode = new listNode;
            newNode->data = newData;
            newNode->next = searchNode;
            newNode->prev = searchNode->prev;
            searchNode->prev->next = newNode;
            searchNode->prev = newNode;
    }
    else if (position == AFTER) {
            listNode* newNode = new listNode;
            newNode->data = newData;
            newNode->next = searchNode->next;
            newNode->prev = searchNode;
            searchNode->next->prev = newNode;
            searchNode->next = newNode;
    }

    std::cout << "Элемент " << newData << " вставлен "
        << ((position == BEFORE) ? "перед" : "после") << " элемента " << findData
        << ". Количество элементов в списке: " << countItems << std::endl;

}

void deleteNode(int findData) {
    listNode* current = listHeader->next;

    while (current != listHeader && current->data != findData) {
        current = current->next;
    }

    if (current != listHeader) {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;
        countItems--;
        std::cout << "Элемент " << findData << " удален из списка. " << std::endl;
    }
    std::cout << "Элемент " << findData << " в списке не найден. " << std::endl;
    printForward();
}