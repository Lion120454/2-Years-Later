#include <iostream> 
#include <fstream> 
#include <iomanip> 

using namespace std;

struct Node
{
    int ver1, ver2;
    int weight;//вес
    Node* next;
    Node(int _ver1, int _ver2,int _weight)
    {
        ver1 = _ver1;
        ver2 = _ver2;
        weight = _weight;
        next = nullptr;
    }
};
struct List
{
    Node* first;
    Node* last;
    List()//Инициализация 
    {
        first = nullptr;
        last = nullptr;
    }
    bool isEmpty()//Проверка на пустоту 
    {
        if (first == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void PushBack(int _ver1, int _ver2, int _weight)//Добавление 
    {
        Node* p = new Node(_ver1, _ver2,_weight);

        if (isEmpty() == true)
        {
            first = p;
            last = p;
            return;
        }

        last->next = p;
        last = p;
    }
    void DeleteFirst()//Удаление 
    {
        if (isEmpty() == true)
        {
            return;
        }

        Node* p = first;
        first = p->next;
        delete p;
    }
};

struct NodeQ
{
    int data;
    NodeQ* next;
};
struct Queue
{
    NodeQ* firstQ;
    NodeQ* lastQ;

    bool isEmpty(Queue* q)//Проверка очереди на пустоту 
    {
        if (q->firstQ == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void init(Queue* q)//Инициализация очереди 
    {
        q->firstQ = nullptr;
        q->lastQ = nullptr;
    }
    List push(Queue* q, List l, int data, bool* visited)//Вставка нового элемента в очередь 
    {
        if (l.first->ver1 == data)
        {
            NodeQ* k = new NodeQ;

            if (k == nullptr)
            {
                cout << "k = nullptr" << endl;
                exit(-1);
            }
            if (q->firstQ == nullptr)
            {
                k->data = 1;
                visited[0] = true;
            }
            else if (visited[l.first->ver2 ] == false)
            {
                if (l.first->weight > l.last->weight) 
                {
                    visited[l.last->ver2] = true;
                    k->data = l.last->weight;
                    l.DeleteFirst();
                }
                else 
                {
                    visited[l.first->ver2] = true;
                    k->data = l.first->weight;
                    l.DeleteFirst();
                }
                cout << l.first->ver1 << " " << l.first->ver2 << "   вес " << l.first->weight << endl;
            }
            else
            {
                l.DeleteFirst();
                return l;
            }
            k->next = nullptr;
            if (q->firstQ == nullptr)
            {
                q->firstQ = k;
            }
            else
            {
                q->lastQ->next = k;
            }
            q->lastQ = k;

            return l;
        }
        else
        {
            l.DeleteFirst();
            return l;
        }
    }
    int top(Queue* q)//Вернуть первый элемент очереди 
    {
        if (isEmpty(q) == true)
        {
            cout << "Очередь пуста" << endl;
            exit(0);
        }
        else
        {
            return q->firstQ->data - 1;
        }
    }
    void pop(Queue* q)
    {
        if (isEmpty(q) == 1)
        {
            cout << "Очередь пуста" << endl;
        }
        else
        {
            NodeQ* p = new NodeQ;
            p = q->firstQ;
            q->firstQ = p->next;

            if (q->firstQ == nullptr)
            {
                q->lastQ = nullptr;
            }

            delete p;
        }
    }
};
List File() 
{
    ifstream File("input.txt");
    if (File.is_open())
    {
        List l;
        int ver1, ver2,weight;
        while (!File.eof())
        {
            File >> ver1 >> ver2 >> weight;
            l.PushBack(ver1, ver2, weight);

        }
        return l;
    }
    else
    {
        cout << "Файл не открыт";
        exit(-1);
    }
}

void MST(List graph) 
{
    Queue q;
    q.init(&q);
    bool* visited = new bool[5];
    for (int i = 0; i < 5; i++)
    {
        visited[i] = false;
    }
    visited[0] = true;
    int z = 0;
    graph = q.push(&q, graph, z + 1, visited);

    while (!q.isEmpty(&q))
    {
        z = q.top(&q);
        q.pop(&q);
        while (graph.first->next != nullptr) 
        {
            if (!visited[graph.first->ver2]) 
            {
                graph = q.push(&q, graph, z + 1, visited);
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "RU");
    List graph=File();
    cout << "Ребра графа, вошедшие в минимальное стягивающее дерево:" << endl;
    MST(graph);
    return 0;
}