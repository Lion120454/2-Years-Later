#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <fstream>
using namespace std;

struct tnode 
{
    int field;//поле данных
    struct tnode* left;//левый потомок
    struct tnode* right;//правый потомок
};


struct tnode* Add(int x, tnode* tree)//Добавление узла
{
    if (tree == NULL)  // Если дерева нет, то формируем корень
    {
        tree = new tnode;// память под узел
        if (tree != NULL)//Проверка
        {
            tree->field = x;    // поле данных
            tree->left = NULL;  // ветвь инициализируем пустотой
            tree->right = NULL; // ветвь инициализируем пустотой
        }
    }
    else  if (x < tree->field)// условие добавление левого потомка
    {
        tree->left = Add(x, tree->left);
    }
    else// условие добавление правого потомка
    {
        tree->right = Add(x, tree->right);
    }
    return(tree);
}

void Delete(tnode* tree)//Удаление
{
    if (tree != NULL)//Проверка
    {
        Delete(tree->left);
        Delete(tree->right);
        delete tree;
    }
}

void Print(tnode* tree,int lvl)//Вывод дерева на экран
{
    if (tree != NULL) //Пока не встретится пустой узел
    {
        Print(tree->left,lvl+1);
        for (int i = 0;i<lvl; i++) cout << "   ";
        { 
            cout << tree->field << endl;
        }
        Print(tree->right,lvl+1);
    }
}

int countVer(tnode* tree,int n)//Подсчёт количества вершин на n-ом уровне
{
    if (tree == 0)//Проверка на пустоту
    {
        return 0;
    }
    if (n == 0)//Проверка на нулевой уровень
    {
        return 1;
    }
    return countVer(tree->left, n - 1) + countVer(tree->right, n - 1);
}

void DeleteElem(tnode** tree, int n)//Удаление элемента
{
    if (tree == 0)//Проверка на пустоту
    {
        return;
    }
    if (n < (*tree)->field) 
    {
        DeleteElem(&(*tree)->left, n);
    }
    else 
    {
        if (n > (*tree)->field) 
        {
            DeleteElem(&(*tree)->right, n);
        }
        else
        {
            tnode* buf = (*tree)->left;
            tnode* t = (*tree)->right;
            free(*tree);
            *tree = t;

            while (*tree)
            {
                tree = &(*tree)->left;
            }
            *tree = buf;
        }
    }
}

tnode* DeleteVal(tnode* tree, int val) 
{
    if (tree == NULL)//Проверка на пустоту
    {
        return 0;
    }

    if (val == tree->field)//Проверка на искомый узел
    {
        tnode* tmp;
        if (tree->right == NULL)//Если правые потомки отсутствуют
        {
            tmp = tree->left;//Запоминаем левых потомков
        }
        else//Если левые потомки отсутствуют
        {
            tnode* ptr = tree->right;// Запоминаем правых потомков
            if (ptr->left == NULL) 
            {
                ptr->left = tree->left;
                tmp = ptr;
            }
            else 
            {
                tnode* pmin = ptr->left;
                while (pmin->left != NULL) 
                {
                    ptr = pmin;
                    pmin = ptr->left;
                }
                ptr->left = pmin->right;
                pmin->left = tree->left;
                pmin->right = tree->right;
                tmp = pmin;
            }
        }
        delete tree;
        return tmp;
    }
    else if (val < tree->field)//Поиск по левым потомкам
    {
        tree->left = DeleteVal(tree->left, val);
    }
    else//Поиск по правым потомкам
    {
        tree->right = DeleteVal(tree->right, val);
    }
    return tree;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    tnode* tree=NULL;
    int option;
    cout << "Введите вариант заполнения дерева:" << endl;
    cout << "1)Ввод с клавиатуры" << endl;
    cout << "2)Ввод из файла" << endl;
    cout << "3)Рандомный ввод" << endl;
    cin >> option;
    if (option == 1)//Заполнение дерева с клавиатуры
    {
        int namber=1;
        while (namber!=0)
        {
            cin >> namber;
            tree=Add(namber, tree);
        }
    }
    if (option == 2)//Заполнение дерева из файла
    {
        ifstream in("IN.txt");
        int n;
        while (in >> n)
        {
            tree=Add(n, tree);
        }
    }
    if (option == 3)//Заполнение дерева рандомно
    {
        tree=Add(1 + rand() % 9, tree);
        tree=Add(1 + rand() % 9, tree);
        tree=Add(1 + rand() % 9, tree);
        tree=Add(1 + rand() % 9, tree);
        tree=Add(1 + rand() % 9, tree);
    }
    Print(tree,5);
    int n;
    cout << "Введите уровень сформированного дерева: ";
    cin >> n;
    DeleteVal(tree, n);
    //Print(tree, 5);
    cout << " Количество вершин на " << n << " уровне = " << countVer(tree, n) << endl;
    Delete(tree);
}