#include "Pipe.h"

Pipe::Pipe() : name(""), length(0), diameter(0), in_repair(false) {}

void Pipe::input() {
    cout << "������� �������� �����: ";
    cin.ignore();
    getline(cin, name);

    cout << "������� ����� ����� (��): ";
    while (!(cin >> length) || length <= 0) {
        cout << "������! ������� ������������� �����: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "������� ������� ����� (�): ";
    while (!(cin >> diameter) || diameter <= 0) {
        cout << "������! ������� ������������� �����: ";
        cin.clear();
        cin.ignore(10000, '\n');
    }

    cout << "����� � �������? (1 - ��, 0 - ���): ";
    int status;
    while (!(cin >> status) || (status != 0 && status != 1)) {
        cout << "������! ������� 1 (��) ��� 0 (���): ";
        cin.clear();
        cin.ignore(10000, '\n');
    }
    in_repair = (status == 1);
}

void Pipe::output() const {
    cout << "�����: " << name
        << "\n�����: " << length << " ��"
        << "\n�������: " << diameter << " �"
        << "\n������ �������: " << (in_repair ? "� �������" : "�� � �������") << "\n";
}

void Pipe::editRepairStatus() {
    in_repair = !in_repair;
    cout << "������ ������� ������. ������ �����: "
        << (in_repair ? "� �������" : "�� � �������") << "\n";
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
