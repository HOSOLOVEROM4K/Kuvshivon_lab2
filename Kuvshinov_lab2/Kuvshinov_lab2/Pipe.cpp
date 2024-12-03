#include "Pipe.h"
#include <iostream>
#include <string>

using namespace std;

void Pipe::input() {
    cout << "������� �������� �����: ";
    cin.ignore();
    getline(cin, name);

    // ���� ����� ����� � ��������� �� ������������
    while (true) {
        cout << "������� ����� �����: ";
        cin >> length;

        if (cin.fail()) {  // �������� �� ������ �����
            cin.clear();  // ����� ����� ������
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������� ������ �����
            cout << "������: ������� ���������� ����� ��� ����� �����.\n";
        }
        else {
            break;  // ���������� �����, ���� ���� ���������
        }
    }

    // ���� �������� ����� � ��������� �� ������������
    while (true) {
        cout << "������� ������� �����: ";
        cin >> diameter;

        if (cin.fail()) {  // �������� �� ������ �����
            cin.clear();  // ����� ����� ������
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ������� ������ �����
            cout << "������: ������� ���������� ����� ��� �������� �����.\n";
        }
        else {
            break;  // ���������� �����, ���� ���� ���������
        }
    }

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
    in.ignore();
    getline(in, name);
    in >> length >> diameter >> inRepair;
}
