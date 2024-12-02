#include "Station.h"
#include <string>

using namespace std;

void Station::input() {
    cout << "������� �������� ��: ";
    cin.ignore(); // ������� ������ ����� ����������� �����
    getline(cin, name);

    cout << "������� ����� ���������� �����: ";
    cin >> totalWorkshops;

    do {
        cout << "������� ���������� ���������� �����: ";
        cin >> workingWorkshops;
        if (workingWorkshops > totalWorkshops) {
            cout << "������: ������� ����� �� ����� ���� ������ ������ ����������.\n";
        }
    } while (workingWorkshops > totalWorkshops);

    cout << "������� ������������� ��: ";
    cin >> efficiency;
}

void Station::output() const {
    cout << "�� ID: " << id << "\n"
        << "��������: " << name << "\n"
        << "����� ���������� �����: " << totalWorkshops << "\n"
        << "���������� �����: " << workingWorkshops << "\n"
        << "�������������: " << efficiency << "\n";
}

void Station::editWorkshops() {
    cout << "������� ���������� ���������� �����: " << workingWorkshops << "\n";
    cout << "������� ����� ���������� ���������� �����: ";

    int newWorkingWorkshops;
    do {
        cin >> newWorkingWorkshops;
        if (newWorkingWorkshops > totalWorkshops) {
            cout << "������: ������� ����� �� ����� ���� ������ ������ ����������.\n";
        }
    } while (newWorkingWorkshops > totalWorkshops);

    workingWorkshops = newWorkingWorkshops;
}

void Station::saveToFile(ofstream& out) const {
    out << id << "\n"
        << name << "\n"
        << totalWorkshops << "\n"
        << workingWorkshops << "\n"
        << efficiency << "\n";
}

void Station::loadFromFile(ifstream& in) {
    in >> id;
    in.ignore(); // ������� ������� ����� ������ ����� ������� ������
    getline(in, name);
    in >> totalWorkshops >> workingWorkshops >> efficiency;
}
