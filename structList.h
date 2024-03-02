#pragma once

enum Position {
    BEFORE,
    AFTER
};

enum Derection {
    FORWARD,
    BACKWARD
};

struct listNode {
    int data;
    int count;
    listNode* next, * prev;
};

extern listNode* listHeader;
extern int countMain;

void initList();

void printForward();

void printBackward();

int findIndex(int findData, Derection derection);
int findData(int position, Derection direction);

void insertByData(int findData, int newData, Position position);

void deleteNode(int findData);
static bool isEmpty();



