#include "Station.h"

Station::Station() : name(""), total_workshops(0), working_workshops(0), efficiency(0) {}

void Station::input() {
    cout << "Введите название КС: ";
    cin.ignore();
    getline(cin, name);

    cout << "Введите общее количество цехов: ";
    while (!(cin >> total_workshops) || total_workshops <= 0) {
        cout << "Ошибка! Введите положительное целое число: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Введите количество работающих цехов: ";
    while (!(cin >> working_workshops) || working_workshops < 0 || working_workshops > total_workshops) {
        cout << "Ошибка! Введите число от 0 до " << total_workshops << ": ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Введите эффективность (0.0 - 100.0): ";
    while (!(cin >> efficiency) || efficiency < 0.0 || efficiency > 100.0) {
        cout << "Ошибка! Введите число от 0.0 до 100.0: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void Station::output() const {
    cout << "КС: " << name
        << "\nОбщее количество цехов: " << total_workshops
        << "\nРаботающие цехи: " << working_workshops
        << "\nЭффективность: " << efficiency << "%\n";
}

void Station::editWorkshops() {
    cout << "Введите новое количество работающих цехов (от 0 до " << total_workshops << "): ";
    while (!(cin >> working_workshops) || working_workshops < 0 || working_workshops > total_workshops) {
        cout << "Ошибка! Введите число от 0 до " << total_workshops << ": ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
}

void Station::saveToFile(ofstream& out) const {
    out << name << '\n'
        << total_workshops << '\n'
        << working_workshops << '\n'
        << efficiency << '\n';
}

void Station::loadFromFile(ifstream& in) {
    in.ignore();
    getline(in, name);
    in >> total_workshops >> working_workshops >> efficiency;
}
