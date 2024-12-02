#include "Station.h"

Station::Station() : name(""), total_workshops(0), working_workshops(0), efficiency(0) {}

void Station::input() {
    std::cout << "Введите название КС: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Введите общее количество цехов: ";
    while (!(std::cin >> total_workshops) || total_workshops <= 0) {
        std::cout << "Ошибка! Введите положительное целое число: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::cout << "Введите количество работающих цехов: ";
    while (!(std::cin >> working_workshops) || working_workshops < 0 || working_workshops > total_workshops) {
        std::cout << "Ошибка! Введите число от 0 до " << total_workshops << ": ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::cout << "Введите эффективность (0.0 - 100.0): ";
    while (!(std::cin >> efficiency) || efficiency < 0.0 || efficiency > 100.0) {
        std::cout << "Ошибка! Введите число от 0.0 до 100.0: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}

void Station::output() const {
    std::cout << "КС: " << name
        << "\nОбщее количество цехов: " << total_workshops
        << "\nРаботающие цехи: " << working_workshops
        << "\nЭффективность: " << efficiency << "%\n";
}

void Station::editWorkshops() {
    std::cout << "Введите новое количество работающих цехов (от 0 до " << total_workshops << "): ";
    while (!(std::cin >> working_workshops) || working_workshops < 0 || working_workshops > total_workshops) {
        std::cout << "Ошибка! Введите число от 0 до " << total_workshops << ": ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
}

void Station::saveToFile(std::ofstream& out) const {
    out << name << '\n'
        << total_workshops << '\n'
        << working_workshops << '\n'
        << efficiency << '\n';
}

void Station::loadFromFile(std::ifstream& in) {
    in.ignore();
    std::getline(in, name);
    in >> total_workshops >> working_workshops >> efficiency;
}
