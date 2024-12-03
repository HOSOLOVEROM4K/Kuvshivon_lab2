#include "Station.h"
#include <iostream>
#include <string>

using namespace std;

void Station::input() {
    cout << "Введите название КС: ";
    cin.ignore();
    getline(cin, name);

    // Ввод общего количества цехов с проверкой на корректность
    while (true) {
        cout << "Введите общее количество цехов: ";
        cin >> totalWorkshops;

        if (cin.fail()) {  // Проверка на ошибку ввода
            cin.clear();  // Сброс флага ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Очистка буфера ввода
            cout << "Ошибка: Введите корректное число для общего количества цехов.\n";
        }
        else {
            break;  // Прерывание цикла, если ввод корректен
        }
    }

    // Ввод количества работающих цехов с проверкой на корректность
    while (true) {
        cout << "Введите количество работающих цехов: ";
        cin >> workingWorkshops;

        if (cin.fail()) {  // Проверка на ошибку ввода
            cin.clear();  // Сброс флага ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Очистка буфера ввода
            cout << "Ошибка: Введите корректное число для количества работающих цехов.\n";
        }
        else if (workingWorkshops > totalWorkshops) {
            cout << "Ошибка: Рабочих цехов не может быть больше общего количества.\n";
        }
        else {
            break;  // Прерывание цикла, если ввод корректен
        }
    }

    cout << "Введите эффективность КС: ";
    cin >> efficiency;
}


void Station::output() const {
    cout << "КС ID: " << id << "\n"
        << "Название: " << name << "\n"
        << "Общее количество цехов: " << totalWorkshops << "\n"
        << "Работающих цехов: " << workingWorkshops << "\n"
        << "Эффективность: " << efficiency << "\n";
}

void Station::editWorkshops() {
    cout << "Текущее количество работающих цехов: " << workingWorkshops << "\n";
    cout << "Введите новое количество работающих цехов: ";

    int newWorkingWorkshops;
    do {
        cin >> newWorkingWorkshops;
        if (newWorkingWorkshops > totalWorkshops) {
            cout << "Ошибка: Рабочих цехов не может быть больше общего количества.\n";
        }
    } while (newWorkingWorkshops > totalWorkshops);

    workingWorkshops = newWorkingWorkshops;
}

void Station::saveToFile(ofstream& out) const {
    out << id << "\n"
        << name << "\n"
        << totalWorkshops << "\n"
        << workingWorkshops << "\n"
        << efficiency << "\n";
}

void Station::loadFromFile(ifstream& in) {
    in >> id;
    in.ignore(); // Очистка символа новой строки перед чтением строки
    getline(in, name);
    in >> totalWorkshops >> workingWorkshops >> efficiency;
}
