#include <iostream>
#include "locale.h"

using namespace std;

int prime(int n)
{
    if (n < 2 || n % 2 == 0)
    {
        return 0;
    } 
    for (int i = 3; i * i <= n; i = i+ 2) 
    {
        if (n % i == 0)
        {
            return 0;
        }
    } 
    return 1;
}
int main()
{
    int x;
    setlocale(LC_ALL, "Ru");
    int count = 0,flag = 0, namber = 0;
    for (x = 1; x <= 90000; x++)
    {
        if (prime(2 * x - 1) == 1)
        {
            count++;
            if (count==200)
            {
                namber = 2 * x - 1;
            }
            /*if (count <= 200)
            {
                cout << count << " = " << 2 * x - 1 << endl;
            }*/
        }
    }
    cout << "1#Кол= " << count << endl;
    cout << "2#200= " << namber << endl;
    //--------------------------------------------------------------------------------------------------------------
    
    count = 0;
    namber=0;
    int x2;
    _asm
    {
        mov EAX, 0; //Помещаем в регистр EAX 0
        mov dword ptr[x2], 1 // x2=1
        mov ECX, 90000 //Счётчик ECX =90000
        nextX: //цикл
        call Prime
            add dword ptr[x2], 2 //x2+2
            loop nextX //вызов цикла
            jmp quit

            Prime :
        cmp dword ptr[x2], 2 //сравниваем x2 и 2
            je prm //если х2=2 переходим prm
            ja jmp1 //если х2>2 переходим jmp1
            ret //Выход

            jmp1 : // исключаем все чётные числа
        or byte ptr[x2], 1 //Проверка на чётность
            jnz jmp2 //Если нечётное переходим jmp2
            ret //Выход

            jmp2 :
        mov EBX, 3 //EBX =3

            jmp4 :
            mov EAX, EBX //EAX=EBX
            mul EAX //EAX*EAX
            cmp EAX, x2//Сравниваем EAX и x2
            ja prm //если 9>x2 переходим prm
            mov EAX, x2 //EAX=x2
            div EBX// EAX/EBX
            cmp EDX, 0 //Сравниваем остаток EDX и 0
            jnz jmp3 //Если не равны переходим в jmp3
            ret //Выход

            jmp3 :
        add EBX, 2 //EBX+2
            jmp jmp4 //Без условный переход в jmp4

            prm :
        add dword ptr[count], 1 //n+1
            cmp count,200
            je save //
            ret //Выход

            save:
        mov EAX,x2 //EAX=x2
            add namber,EAX //namber=namber+EAX
            ret //Вывод

            quit ://выход
    }
    cout << "--------------------"<< endl;
    cout << "ASM Кол= " << count << endl;
    cout << "ASM 200= " << namber << endl;
    return 1;
}