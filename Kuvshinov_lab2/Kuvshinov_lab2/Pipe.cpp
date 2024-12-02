#include "Pipe.h"

Pipe::Pipe() : name(""), length(0), diameter(0), in_repair(false) {}

void Pipe::input() {
    std::cout << "������� �������� �����: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "������� ����� ����� (��): ";
    while (!(std::cin >> length) || length <= 0) {
        std::cout << "������! ������� ������������� �����: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::cout << "������� ������� ����� (�): ";
    while (!(std::cin >> diameter) || diameter <= 0) {
        std::cout << "������! ������� ������������� �����: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::cout << "����� � �������? (1 - ��, 0 - ���): ";
    int status;
    while (!(std::cin >> status) || (status != 0 && status != 1)) {
        std::cout << "������! ������� 1 (��) ��� 0 (���): ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }
    in_repair = (status == 1);
}

void Pipe::output() const {
    std::cout << "�����: " << name
        << "\n�����: " << length << " ��"
        << "\n�������: " << diameter << " �"
        << "\n������ �������: " << (in_repair ? "� �������" : "�� � �������") << "\n";
}

void Pipe::editRepairStatus() {
    in_repair = !in_repair;
    std::cout << "������ ������� ������. ������ �����: "
        << (in_repair ? "� �������" : "�� � �������") << "\n";
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
