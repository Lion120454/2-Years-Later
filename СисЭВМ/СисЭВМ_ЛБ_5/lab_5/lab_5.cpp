#include <iostream>
#include <fstream>
using namespace std;

const int hash_size = 20;

struct Hash 
{
    int data; //ключ
    int index; //индекс
    int tries; //попытки
};
Hash hash_array[hash_size];

void init()//Инициализация
{
    for (int i = 0; i < hash_size; i++) 
    {
        hash_array[i].tries = 0;
        hash_array[i].index = i;
    }
}

int getHash(int number) 
{
    return (number % hash_size);
}

void Add(int Index, int number)//Добавление
{
    bool found = false;
    int i = 0;
    while (i != hash_size) 
    {
        Index = (number + i) % hash_size;

        if (hash_array[Index].data == 0 || hash_array[Index].data == -1)
        {
            hash_array[Index].data = number;
            hash_array[Index].tries = i;
            found = true;
            break;
        }
        else
        {
            i++;
        }
    }
    if (found != true) 
    {
        cout << "Хеш-таблица заполнена" << endl;
    }
}

void Print()//Вывод
{
    cout << "Хэш-Таблица:" << endl;
    cout << "Индекс " <<  " Ключ  " << "Попытки:" << endl;
    for (int i = 0; i < hash_size; i++) 
    {
        cout << "---------------------" << endl;
        cout << "   " << hash_array[i].index << "    " << hash_array[i].data << "      " << hash_array[i].tries << endl;
    }
}

void Search(int number)//Поиск
{
    int i = 0;
    bool found = false;
    while (i != hash_size)
    {
        int index = (number + i) % hash_size;
        if (hash_array[index].data == number)
        {
            cout << "Число " << number << " найдено" << endl;
            cout << "Кол-во попыток при поиске "<<i << endl;
            found = true;
            break;
        }
        else if (hash_array[index].data == 0)
        {
            break;
        }
        i++;
    }
    if (found != true) 
    {
        cout << "Число " << number << " не найдено" << endl;
    }
}

void Delete(int number)//Удаление
{
    int i = 0;
    bool found = false;
    while (i != hash_size)
    {
        int index = (number + i) % hash_size;
        if (hash_array[index].data == number)
        {
            hash_array[index].data = -1;
            hash_array[index].tries = -1;
            cout << "Число "<< number << " удалено" << endl;
            found = true;
            break;
        }
        i++;
    }
    if (found != true) 
    {
        cout << "Число " << number << " не найдено" << endl;
    }
}

int main() 
{
    setlocale(LC_ALL, "RUS");
    int number, Index;
    init();
    ifstream File("IN.txt");
    if (File.is_open()) 
    {
        while (File.eof() == 0) 
        {
            File >> number;
            Index = getHash(number);
            Add(Index, number);
        }
        File.close();
        Print();
    }
    else 
    {
        cout << "Файл не открыт";
    }
    cout << endl;
    Search(1+rand()%100);
    cout << endl;
    Delete(42);
    Print();
}