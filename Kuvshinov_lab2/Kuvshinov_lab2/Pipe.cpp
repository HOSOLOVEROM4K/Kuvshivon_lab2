#include "Pipe.h"
#include <string>

using namespace std;

void Pipe::input() {
    cout << "������� �������� �����: ";
    cin.ignore(); // ������� ������ ����� ����������� �����
    getline(cin, name);

    cout << "������� ����� �����: ";
    cin >> length;

    cout << "������� ������� �����: ";
    cin >> diameter;

    cout << "����� � �������? (1 - ��, 0 - ���): ";
    cin >> inRepair;
}

void Pipe::output() const {
    cout << "����� ID: " << id << "\n"
        << "��������: " << name << "\n"
        << "�����: " << length << "\n"
        << "�������: " << diameter << "\n"
        << "������ �������: " << (inRepair ? "� �������" : "�� � �������") << "\n";
}

void Pipe::editRepairStatus() {
    cout << "������� ������ �������: " << (inRepair ? "� �������" : "�� � �������") << "\n";
    cout << "�������� ������ �������? (1 - ��, 0 - ���): ";
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
    in.ignore(); // ������� ������� ����� ������ ����� ������� ������
    getline(in, name);
    in >> length >> diameter >> inRepair;
}
