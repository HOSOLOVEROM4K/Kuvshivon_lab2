#include "Pipe.h"
#include <iostream>
#include <string>

using namespace std;

void Pipe::input() {
    cout << "Введите название трубы: ";
    cin.ignore();
    getline(cin, name);

    // Ввод длины трубы с проверкой на корректность
    while (true) {
        cout << "Введите длину трубы: ";
        cin >> length;

        if (cin.fail()) {  // Проверка на ошибку ввода
            cin.clear();  // Сброс флага ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Очистка буфера ввода
            cout << "Ошибка: Введите корректное число для длины трубы.\n";
        }
        else {
            break;  // Прерывание цикла, если ввод корректен
        }
    }

    // Ввод диаметра трубы с проверкой на корректность
    while (true) {
        cout << "Введите диаметр трубы: ";
        cin >> diameter;

        if (cin.fail()) {  // Проверка на ошибку ввода
            cin.clear();  // Сброс флага ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Очистка буфера ввода
            cout << "Ошибка: Введите корректное число для диаметра трубы.\n";
        }
        else {
            break;  // Прерывание цикла, если ввод корректен
        }
    }

    cout << "Труба в ремонте? (1 - да, 0 - нет): ";
    cin >> inRepair;
}

void Pipe::output() const {
    cout << "Труба ID: " << id << "\n"
        << "Название: " << name << "\n"
        << "Длина: " << length << "\n"
        << "Диаметр: " << diameter << "\n"
        << "Статус ремонта: " << (inRepair ? "В ремонте" : "Не в ремонте") << "\n";
}

void Pipe::editRepairStatus() {
    cout << "Текущий статус ремонта: " << (inRepair ? "В ремонте" : "Не в ремонте") << "\n";
    cout << "Изменить статус ремонта? (1 - да, 0 - нет): ";
    cin >> inRepair;
}

void Pipe::saveToFile(ofstream& out) const {
    out << id << "\n"
        << name << "\n"
        << length << "\n"
        << diameter << "\n"
        << inRepair << "\n";
}

void Pipe::loadFromFile(ifstream& in) {
    in >> id;
    in.ignore();
    getline(in, name);
    in >> length >> diameter >> inRepair;
}
