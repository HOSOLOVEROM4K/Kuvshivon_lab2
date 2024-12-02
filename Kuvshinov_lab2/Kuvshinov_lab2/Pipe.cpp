#include "Pipe.h"

Pipe::Pipe() : name(""), length(0), diameter(0), in_repair(false) {}

void Pipe::input() {
    cout << "Введите название трубы: ";
    cin.ignore();
    getline(cin, name);

    cout << "Введите длину трубы (км): ";
    while (!(cin >> length) || length <= 0) {
        cout << "Ошибка! Введите положительное число: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Введите диаметр трубы (м): ";
    while (!(cin >> diameter) || diameter <= 0) {
        cout << "Ошибка! Введите положительное число: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "Труба в ремонте? (1 - Да, 0 - Нет): ";
    int status;
    while (!(cin >> status) || (status != 0 && status != 1)) {
        cout << "Ошибка! Введите 1 (Да) или 0 (Нет): ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    in_repair = (status == 1);
}

void Pipe::output() const {
    cout << "Труба: " << name
        << "\nДлина: " << length << " км"
        << "\nДиаметр: " << diameter << " м"
        << "\nСтатус ремонта: " << (in_repair ? "В ремонте" : "Не в ремонте") << "\n";
}

void Pipe::editRepairStatus() {
    in_repair = !in_repair;
    cout << "Статус ремонта изменён. Теперь труба: "
        << (in_repair ? "В ремонте" : "Не в ремонте") << "\n";
}

void Pipe::saveToFile(ofstream& out) const {
    out << name << '\n'
        << length << '\n'
        << diameter << '\n'
        << in_repair << '\n';
}

void Pipe::loadFromFile(ifstream& in) {
    in.ignore();
    getline(in, name);
    in >> length >> diameter >> in_repair;
}
