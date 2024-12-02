#include "Station.h"
#include <string>

using namespace std;

void Station::input() {
    cout << "Введите название КС: ";
    cin.ignore(); // Очистка буфера после предыдущего ввода
    getline(cin, name);

    cout << "Введите общее количество цехов: ";
    cin >> totalWorkshops;

    do {
        cout << "Введите количество работающих цехов: ";
        cin >> workingWorkshops;
        if (workingWorkshops > totalWorkshops) {
            cout << "Ошибка: Рабочих цехов не может быть больше общего количества.\n";
        }
    } while (workingWorkshops > totalWorkshops);

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
