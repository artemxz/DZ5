#include <iostream>
#include "ArrayContainer.h"
#include "OneWayList.h"

int main() {
    setlocale(LC_ALL, "RU");

    std::cout << "=== ТЕСТ 1: Последовательный контейнер (Массив) ===\n";
    ArrayContainer<int> arr;

    for (int i = 0; i < 10; i++) {
        arr.push_back(i);
    }


    std::cout << "Содержимое: ";
    arr.print();


    std::cout << "Размер: " << arr.size() << "\n";


    arr.erase(6);
    arr.erase(4);
    arr.erase(2);

    std::cout << "После удаления: ";
    arr.print();


    arr.insert(0, 10);
    std::cout << "После вставки в начало (10): ";
    arr.print();


    arr.insert(4, 20);
    std::cout << "После вставки в середину (20): ";
    arr.print();

    arr.push_back(30);
    std::cout << "После вставки в конец (30): ";
    arr.print();

    std::cout << "\n=== ТЕСТ 2: Контейнер спискового типа (Однонаправленный список) ===\n";
    OneWayList<int> list;

    for (int i = 0; i < 10; i++) {
        list.push_back(i);
    }

    std::cout << "Содержимое: ";
    list.print();
    std::cout << "Размер: " << list.size() << "\n";

    list.erase(1);
    list.erase(3);

    std::cout << "После удаления элементов: ";
    list.print();

    list.insert(0, 99);
    list.insert(5, 42);

    std::cout << "После вставки элементов: ";
    list.print();
    std::cout << "Финальный размер списка: " << list.size() << "\n";

    return 0;
}