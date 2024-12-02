#include "Pipe.h"
#include <string>

using namespace std;

void Pipe::input() {
    cout << "Введите название трубы: ";
    cin.ignore(); // Очистка буфера после предыдущего ввода
    getline(cin, name);

    cout << "Введите длину трубы: ";
    cin >> length;

    cout << "Введите диаметр трубы: ";
    cin >> diameter;

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
    in.ignore(); // Очистка символа новой строки перед чтением строки
    getline(in, name);
    in >> length >> diameter >> inRepair;
}
