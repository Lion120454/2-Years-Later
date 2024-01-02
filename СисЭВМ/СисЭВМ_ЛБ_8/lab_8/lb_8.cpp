﻿#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>

using namespace std;

void printArray(double* arr) 
{
    for (int i = 0; i< _msize(arr) / sizeof(double); i++)
    {
        cout<<arr[i]<<endl;
    }
    cout << endl;
}

// Функция блочной сортировки
void blockSort(double* arr, int blockSize)
{
    // Вычисляем количество блоков
    int numBlocks = (_msize(arr) / sizeof(double)) / blockSize;
    if (_msize(arr) / sizeof(double) % blockSize != 0) 
    {
        numBlocks++;
    }

    // Создаем вектор блоков
    double block[10][10];

    // Разбиваем массив на блоки
    for (int i = 0; i < _msize(arr) / sizeof(double); i++)
    {
        int blockIndex = i / blockSize;
        block[blockIndex][0] = arr[i];
    }
    double buf[10];
    for (int i = 0; i < numBlocks; i++)
    {
        buf[i] = block[i][0];
    }
    //Сортируем каждый блок
    for (int i = 1; i < numBlocks; i++)
    {
        for (int j = i; j > 0 && buf[j - 1] > buf[j]; j--) // пока j>0 и элемент j-1 > j, x-массив int
        {
            swap(buf[j - 1], buf[j]);        // меняем местами элементы j и j-1
        }
    }

    // Объединяем отсортированные блоки обратно в массив
    int arrIndex = 0;
    for (int i = 0; i < numBlocks; i++)
    {
        for (int j = 0; j < _msize(block) / sizeof(double); j++)
        {
            arr[arrIndex] = block[i][j];
            arrIndex++;
        }
    }
    printArray(arr);
}


int main() 
{
    setlocale(LC_ALL, "RU");
    // Открываем файлы
    ifstream file1("input100.txt");
    ifstream file2("input1000.txt");
    ifstream file3("input10000.txt");

    // Считываем данные из файлов
    double* arr1=new double[100];
    double* arr2= new double[1000];
    double* arr3= new double[10000];
    double val;

    for (int i=0; file1 >> val;i++)
    {
        arr1[i]=val;
    }
    for (int i=0;file2 >> val;i++) 
    {
        arr2[i]=val;
    }
    for (int i=0;file3 >> val;i++) 
    {
        arr3[i]=val;
    }
    

    // Запускаем таймер для первого файла
    auto start = chrono::high_resolution_clock::now();

    // Сортируем первый файл
    blockSort(arr1, 10);
    //printArray(arr1);
    // Останавливаем таймер
    auto finish = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = finish - start;
    time[0] = elapsed.count();

    // Запускаем таймер для второго файла
    start = chrono::high_resolution_clock::now();

    // Сортируем второй файл
    blockSort(arr2, 100);

    // Останавливаем таймер
    finish = chrono::high_resolution_clock::now();
    elapsed = finish - start;
    time[1] = elapsed.count();

    // Запускаем таймер для третьего файла
    start = chrono::high_resolution_clock::now();

    // Сортируем третий файл
    blockSort(arr3, 1000);

    // Останавливаем таймер
    finish = chrono::high_resolution_clock::now();
    elapsed = finish - start;
    time[2] = elapsed.count();
    cout << "Файл input100 отсортирован за " << time[0] << " секунды\n";
    cout << "Файл input1000 отсортирован за " << time[1] << " секунды\n";
    cout << "Файл input10000 отсортирован за " << time[2] << " секунды\n";

    // Закрываем файлы
    file1.close();
    file2.close();
    file3.close();

    return 0;
}