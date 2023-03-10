#pragma once
#include <iostream>
#include <fstream>
#include "VideoCards.hpp"
#include "Prototypes.h"

void line_search(Video_Cards* obj, int size)
{
    int k;
    std::cout << "\nМетод последовательного поиска: "<<std::endl;
    std::cout << "Введите код товара -> ";
    std::cin >> k;
    std::cout << " " << std::endl;
    for (int i = 0; i < size; i++)
    {
        if (obj[i].Product_code == k) {
            obj[i].output();
        }
    }
}

int Search_Binary(Video_Cards* obj, int left, int right, int key)
{
while (left <= right)
{
    int i = (left + right) / 2;
            if (key < obj[i].Product_code)
                right = i - 1;
            else if (key > obj[i].Product_code)
                left = i + 1;
            else
                return i;
    }

    return -1;
}


//интерполяционный поиск
int InterpolSearch(Video_Cards* obj, int key)
{
int left = 0;
int right = 49;
while (left <= right && key >= obj[left].Price && key <= obj[right].Price)
{
int pos = left + ((key - obj[left].Price) * (right - left)) / (obj[right].Price - obj[left].Price);
if (obj[pos].Price == key)
return pos;
if (obj[pos].Price < key)
left = pos + 1;
else
right = pos - 1;
}
return -1;
}

int min(int x, int y) { return (x <= y) ? x : y; }

//поиск методом Фибоначчи
int fibMonaccianSearch(Video_Cards* obj, int n)
{
    int x;
    std::cout << "\nВведите цену товара:  ";
    std::cin >>  x;
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;

    while (fibM < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    int offset = -1;

    while (fibM > 1)
    {
        
        int i = min(offset + fibMMm2, n - 1);

        if (obj[i].Price < x)
        {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }

        else if (obj[i].Price > x)
        {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }

        else return i;
    }

    if (fibMMm1 && obj[offset + 1].Price == x)return offset + 1;
    return -1;
}

//
//struct BinTree {
//    int value; //содержит значение
//    BinTree* left;//адрес левого поддерева
//    BinTree* right;//адрес правого поддерева
//};

void newBinTree(int val, BinTree** Tree) {
    if ((*Tree) == NULL)
    {
        (*Tree) = new BinTree; //Выделить память
        (*Tree)->value = val;  //Поместить в выделенное место аргумент
        (*Tree)->left = (*Tree)->right = NULL;
    }
    if (val > (*Tree)->value) newBinTree(val, &(*Tree)->right);//Если аргумент больше чем текущий элемент, поместить его вправо
    else if (val < (*Tree)->value) newBinTree(val, &(*Tree)->left);//Иначе поместить его влево
}

int Search(BinTree* Tree, int key) {
    if (Tree == NULL) return NULL;
    if (Tree->value == key) return Tree->value;
    if (key < Tree->value) return Search(Tree->left, key);
    else
        return Search(Tree->right, key);
}

