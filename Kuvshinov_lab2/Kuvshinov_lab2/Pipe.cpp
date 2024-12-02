#include "Pipe.h"

Pipe::Pipe() : name(""), length(0), diameter(0), in_repair(false) {}

void Pipe::input() {
    std::cout << "Введите название трубы: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Введите длину трубы (км): ";
    while (!(std::cin >> length) || length <= 0) {
        std::cout << "Ошибка! Введите положительное число: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::cout << "Введите диаметр трубы (м): ";
    while (!(std::cin >> diameter) || diameter <= 0) {
        std::cout << "Ошибка! Введите положительное число: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::cout << "Труба в ремонте? (1 - Да, 0 - Нет): ";
    int status;
    while (!(std::cin >> status) || (status != 0 && status != 1)) {
        std::cout << "Ошибка! Введите 1 (Да) или 0 (Нет): ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    in_repair = (status == 1);
}

void Pipe::output() const {
    std::cout << "Труба: " << name
        << "\nДлина: " << length << " км"
        << "\nДиаметр: " << diameter << " м"
        << "\nСтатус ремонта: " << (in_repair ? "В ремонте" : "Не в ремонте") << "\n";
}

void Pipe::editRepairStatus() {
    in_repair = !in_repair;
    std::cout << "Статус ремонта изменён. Теперь труба: "
        << (in_repair ? "В ремонте" : "Не в ремонте") << "\n";
}

void Pipe::saveToFile(std::ofstream& out) const {
    out << name << '\n'
        << length << '\n'
        << diameter << '\n'
        << in_repair << '\n';
}

void Pipe::loadFromFile(std::ifstream& in) {
    in.ignore();
    std::getline(in, name);
    in >> length >> diameter >> in_repair;
}
