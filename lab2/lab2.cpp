#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
    Queue<int> q;
    int elem{}, command{ -1 };
    setlocale(LC_ALL, "Russian");
    while (command != 0) 
    {
        cout << "Меню:" << endl;
        cout << "1 - добавить элемент в очередь;" << endl;
        cout << "2 - извлечь элемент из очереди;" << endl;
        cout << "3 - вернуть количество элементов очереди;" << endl;
        cout << "4 - удалить все элементы очереди;" << endl;
        cout << "5 - вставить перед каждым отрицательным числом очереди элемента со значением 1;" << endl;
        cout << "6 - удалить из очереди все элементы с отрицательной информационной частью;" << endl;
        cout << "7 - подсчет количества вхождений в очередь значения введенного пользователем;" << endl;
        cout << "0 - завершение программы;" << endl;
        cout << "Введите команду: ";
        cin >> command;
        switch (command) 
        {
        case 1: 
        {
            cout << "Введите значение: ";
            cin >> elem;
            q.queue(elem);
            break;
        }
        case 2: 
        {
            int v = q.unqueue();
            cout << "Извлеченный элемент: " << v << endl;
            break;
        }
        case 3: 
        {
            cout << "Количество элементов очереди: " << q.count() << endl;
            break;
        }
        case 4: 
        {
            q.clear();
            break;
        }
        case 5: 
        {
            q.add1();
            break;
        }
        case 6: 
        {
            q.remove_negative();
            break;
        }
        case 7: 
        {
            cout << "Введите значение: ";
            cin >> elem;
            int v = q.countof(elem);
            cout << "Извлеченный элемент: " << v << endl;
            break;
        }
        }
    }
}