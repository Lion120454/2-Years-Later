#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Stack
{
    int info;//информация
    Stack* next;//ссылка на следующий эл-т
};

bool isEmpty(Stack* top)//проверка
{
    return top == NULL;
}

void push(Stack** top, int x) //Добавление элемента x
{
    Stack* q = new Stack(); //Создаем новый указатель q типа Stack.
    if (q)//Проверка выделения памяти
    {
        q->info = x; //Записываем необходимое число  в info элемента
        q->next = *top; //Проводим связь от нового элемента, к вершине.
        *top = q; //Обозначаем, что вершиной теперь является новый элемент
    }
    else
    {
        cout << "Память не выделилась" << endl;
    }
}

int pop(Stack** top)//удаление элемента
{
    if (isEmpty(*top) == 1)//Проверка на пустоту
    {
        cout << "Стек пустой!" << endl;
    }
    else 
    {
        Stack* q = *top; //создаем указатель типа Stack и приравниваем(ставим) его на вершину стека
        int Data = q->info;//записываем
        *top = q->next;//передвигаем вершину на следующий элемент
        delete(q);//очищаем ячейку
        return(Data);//возвращаем
    }
    
}
void Print(const Stack* stack)//Вывод стека на экран
{
    for (; stack; stack = stack->next)//перебираем все элементы стека
    {

        cout << stack->info << endl;//выводим на экран значение очередного элемента
    }
    cout << endl;
}

int top(Stack** top)//Вывод верхнего элемента
{
    if (isEmpty(*top) == 1)//Проверка на пустоту
    {
        cout << "Стек пустой!" << endl;
    }
    else
    {
        Stack* q = *top; //создаем указатель типа Stack и приравниваем(ставим) его на вершину стека
        int Data = q->info;//записываем
        return(Data);//возвращаем
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    Stack* stk1 = NULL;
    Stack* stk2 = NULL;
    int n = 0;
    string s;
    ifstream in("IN.txt");
    while (in>>n)
    {
        if (n % 2 == 0)
        {
            push(&stk1, n);
        }
        else
        {
            push(&stk2, n);
        }
    }
    cout << "Нечётный " << endl;
    while (isEmpty(stk2) != true)//Вывод стека на экран
    {
        int z;
        z = pop(&stk2);
        cout << z << endl;
    }
    cout << " " << endl;
    cout << "Чётный " << endl;
    while (isEmpty(stk1) != true)//Вывод стека на экран
    {
        int z;
        z = pop(&stk1);
        cout << z << endl;
    }
    return 0;
}