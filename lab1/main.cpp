
#include "VideoCards.hpp"
#include "Prototypes.h"
#include <locale.h>


using std::string;
using std::cout;
using std::cin;
using std::endl;
/*В методе последовательного поиска пользователю предлагается ввести код товара и затем поиск осуществляется по всему массиву объектов Video_Cards до тех пор, пока не будет найден объект с заданным кодом товара.
 Метод бинарного поиска ищет элементы в отсортированном массиве объектов Video_Cards.
 Интерполяционный поиск ищет элементы, основываясь на предположении, что элементы равномерно распределены в массиве объектов Video_Cards.
 Метод поиска Фибоначчи также используется для поиска элементов в отсортированном массиве объектов Video_Cards.
 В конце определена функция newBinTree, которая создает бинарное дерево поиска.*/
int i = 0;

int main()
{
    
    int key = 0;
    int index = 0;
    int key2, m, m1;
    setlocale(LC_ALL, "rus");
    
    Video_Cards obj[50];
    std::ifstream file("/Users/ericadiaciuc/Desktop/алгоритмы и стр/lab1/Table.txt");
    
    
    
    cin.clear();
    while (i != 50) {
        file >> obj[i].Product_code >>  obj[i].Name >> obj[i].Producer >> obj[i].TechnicalProcess >> obj[i].EnergyConsum >> obj[i].Price;
        i++;
    }
    
    
    for (i = 0; i < 50; i++) {
        obj[i].output();
        cout << endl;
    }
    /////////
    line_search(&obj[0], 50);
    
    ////////////
    cout << "\n-------------------------------------------------";
    
    cout << "\nМетод бинарного поиска" << endl;
    cout << "\n\nВведите код товара:";
    cin >> key;
    cout << endl;
    index = Search_Binary(&obj[0], 0, 50, key);
    if (index >= 0)
    {
        cout << "\nТовар находится в ячейке с индексом: " << index << "\n\n";
        obj[index-1].output();
    }
    else
        cout << "\n\nВ массиве нет такого товара!\n\n";
    cout << "\n-------------------------------------------------";
    
    /////////
    cout << "\nМетод поиска интерполированием" << endl;
    cout << "\nВведите цену товара:  "; cin >> key2; //ввод ключа
    m = InterpolSearch(&obj[0], key2);
    if (m == -1) cout << "\nТовар не найден";
    else { cout << "\nТовар находится в ячейке с индексом: " << m + 1; cout << endl; obj[m].output(); }
    cout << "\n-------------------------------------------------";
    
    /////////
    cout << "\nМетод Фибоначчи" << endl;
    m1= fibMonaccianSearch(&obj[0], 50);
    if (m1 == -1) cout << "\nТовар не найден";
    else { cout << "\nТовар находится в ячейке с индексом: " << m1 + 1; cout << endl; obj[m1].output(); }
    
    cout << "\n-------------------------------------------------";
    
    /////////
    
    cout << "\n\nМетод поиска в неотсортированных массивах древовидно структурированных" << endl;
    BinTree* Tree = NULL;
    
    for (i = 0; i < 50; i++) {
        newBinTree(obj[i].Product_code, &Tree);
    }
    
    
    cout << "\nВведите значение элемента для поиска-> ";
    cin >> key;
    int result_4 = Search(Tree, key);
    if (result_4 == 0)
        cout << "Элемент не найден";
    else
        cout << "Ваш элемент->" << endl;
    for (i = 0; i < 50; i++) {
        if (result_4 == obj[i].Product_code) {
            obj[i].output();
        }
    }
    
    
    
    
    return 0;
}










