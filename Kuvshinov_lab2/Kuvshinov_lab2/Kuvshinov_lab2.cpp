#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include "Pipe.h"
#include "Station.h"

using namespace std;

bool isUniqueId(int id, const vector<Pipe>& pipes, const vector<Station>& stations) {
    for (const auto& pipe : pipes) {
        if (pipe.getId() == id) {
            return false;
        }
    }

    for (const auto& station : stations) {
        if (station.getId() == id) {
            return false;
        }
    }

    return true;
}

int getUniqueId(const vector<Pipe>& pipes, const vector<Station>& stations) {
    int maxId = 0;

    // Ищем максимальный ID среди всех объектов
    for (const auto& pipe : pipes) {
        if (pipe.getId() > maxId) {
            maxId = pipe.getId();
        }
    }

    for (const auto& station : stations) {
        if (station.getId() > maxId) {
            maxId = station.getId();
        }
    }

    // Новый уникальный ID будет на 1 больше максимального
    return maxId + 1;
}


int getValidMenuChoice() {
    string input;
    int choice;

    while (true) {
        cout << "Введите номер действия: ";
        cin >> input;

        try {
            choice = stoi(input);
            if (choice >= 0 && choice <= 12) {
                return choice;
            }
            else {
                cout << "Ошибка: Введите число от 0 до 9.\n";
            }
        }
        catch (exception& e) {
            cout << "Ошибка: Введите корректное целое число.\n";
        }
    }
}

void showAllObjects(const vector<Pipe>& pipes, const vector<Station>& stations) {
    cout << "\nСписок труб:\n";
    for (const auto& pipe : pipes) {
        pipe.output();
    }
    cout << "\nСписок КС:\n";
    for (const auto& station : stations) {
        station.output();
    }
}

void deletePipe(vector<Pipe>& pipes) {
    if (pipes.empty()) {
        cout << "Нет труб для удаления.\n";
        return;
    }

    cout << "Введите ID трубы для удаления: ";
    int id;
    cin >> id;

    auto it = find_if(pipes.begin(), pipes.end(), [id](const Pipe& p) { return p.getId() == id; });
    if (it != pipes.end()) {
        pipes.erase(it);
        cout << "Труба удалена.\n";
    }
    else {
        cout << "Ошибка: Труба с таким ID не найдена.\n";
    }
}

void deleteStation(vector<Station>& stations) {
    if (stations.empty()) {
        cout << "Нет КС для удаления.\n";
        return;
    }

    cout << "Введите ID КС для удаления: ";
    int id;
    cin >> id;

    auto it = find_if(stations.begin(), stations.end(), [id](const Station& s) { return s.getId() == id; });
    if (it != stations.end()) {
        stations.erase(it);
        cout << "КС удалена.\n";
    }
    else {
        cout << "Ошибка: КС с таким ID не найдена.\n";
    }
}

void editPipe(vector<Pipe>& pipes) {
    if (pipes.empty()) {
        cout << "Нет труб для редактирования.\n";
        return;
    }
    cout << "Введите ID трубы для редактирования: ";
    int id;
    cin >> id;

    auto it = find_if(pipes.begin(), pipes.end(), [id](const Pipe& p) { return p.getId() == id; });
    if (it != pipes.end()) {
        it->editRepairStatus();
    }
    else {
        cout << "Ошибка: Труба с таким ID не найдена.\n";
    }
}

void editStation(vector<Station>& stations) {
    if (stations.empty()) {
        cout << "Нет КС для редактирования.\n";
        return;
    }
    cout << "Введите ID КС для редактирования: ";
    int id;
    cin >> id;

    auto it = find_if(stations.begin(), stations.end(), [id](const Station& s) { return s.getId() == id; });
    if (it != stations.end()) {
        it->editWorkshops();
    }
    else {
        cout << "Ошибка: КС с таким ID не найдена.\n";
    }
}

void editAllPipes(vector<Pipe>& pipes) {
    if (pipes.empty()) {
        cout << "Нет труб для редактирования.\n";
        return;
    }

    cout << "Вы хотите отредактировать все трубы (1 - да, 0 - нет): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        for (auto& pipe : pipes) {
            pipe.editRepairStatus(); // Редактируем статус ремонта для каждой трубы
        }
        cout << "Все найденные трубы отредактированы.\n";
    }
}

// Функция для редактирования выбранных труб по ID
void editSelectedPipes(vector<Pipe>& pipes) {
    if (pipes.empty()) {
        cout << "Нет труб для редактирования.\n";
        return;
    }

    cout << "Введите количество труб, которые вы хотите отредактировать: ";
    int num;
    cin >> num;

    vector<int> selectedIds(num);
    cout << "Введите ID труб для редактирования:\n";
    for (int i = 0; i < num; ++i) {
        cin >> selectedIds[i];
    }

    for (int id : selectedIds) {
        auto it = find_if(pipes.begin(), pipes.end(), [id](const Pipe& p) { return p.getId() == id; });
        if (it != pipes.end()) {
            it->editRepairStatus(); // Редактируем статус ремонта
            cout << "Труба с ID " << id << " отредактирована.\n";
        }
        else {
            cout << "Труба с ID " << id << " не найдена.\n";
        }
    }
}

void searchPipes(const vector<Pipe>& pipes) {
    if (pipes.empty()) {
        cout << "Нет труб для поиска.\n";
        return;
    }

    int choice;
    cout << "Поиск труб по:\n"
        << "1. Названию\n"
        << "2. Признаку «в ремонте»\n";
    cin >> choice;

    switch (choice) {
    case 1: {  // Поиск по названию
        cout << "Введите название трубы: ";
        string name;
        cin.ignore();
        getline(cin, name);

        bool found = false;
        for (const auto& pipe : pipes) {
            if (pipe.getName() == name) {
                pipe.output();
                found = true;
            }
        }

        if (!found) {
            cout << "Труба с таким названием не найдена.\n";
        }
        break;
    }
    case 2: {  // Поиск по признаку «в ремонте»
        cout << "Введите статус ремонта (1 - в ремонте, 0 - не в ремонте): ";
        bool inRepair;
        cin >> inRepair;

        bool found = false;
        for (const auto& pipe : pipes) {
            if (pipe.getRepairStatus() == inRepair) {
                pipe.output();
                found = true;
            }
        }

        if (!found) {
            cout << "Трубы с таким статусом ремонта не найдены.\n";
        }
        break;
    }
    default:
        cout << "Неверный выбор.\n";
        break;
    }
}

void searchStations(const vector<Station>& stations) {
    if (stations.empty()) {
        cout << "Нет КС для поиска.\n";
        return;
    }

    int choice;
    cout << "Поиск КС по:\n"
        << "1. Названию\n"
        << "2. Проценту незадействованных цехов\n";
    cin >> choice;

    switch (choice) {
    case 1: {  // Поиск по названию
        cout << "Введите название КС: ";
        string name;
        cin.ignore();
        getline(cin, name);

        bool found = false;
        for (const auto& station : stations) {
            if (station.getName() == name) {
                station.output();
                found = true;
            }
        }

        if (!found) {
            cout << "КС с таким названием не найдена.\n";
        }
        break;
    }
    case 2: {  // Поиск по проценту незадействованных цехов
        cout << "Введите процент незадействованных цехов (от 0 до 100): ";
        double percentage;
        cin >> percentage;

        bool found = false;
        for (const auto& station : stations) {
            double unusedPercentage = 100.0 * (station.getTotalWorkshops() - station.getWorkingWorkshops()) / station.getTotalWorkshops();
            if (unusedPercentage >= percentage) {
                station.output();
                found = true;
            }
        }

        if (!found) {
            cout << "КС с таким процентом незадействованных цехов не найдена.\n";
        }
        break;
    }
    default:
        cout << "Неверный выбор.\n";
        break;
    }
}

void showMenu() {
    cout
        << "\n_________________________________________\n"
        << "1. Добавить трубу\n"
        << "2. Добавить КС\n"
        << "3. Просмотреть все объекты\n"
        << "4. Редактировать статус ремонта трубы\n"
        << "5. Редактировать цехи КС\n"
        << "6. Удалить трубу\n"
        << "7. Удалить КС\n"
        << "8. Сохранить данные в файл\n"
        << "9. Загрузить данные из файла\n"
        << "10. Поиск труб\n"
        << "11. Поиск КС\n"
        << "12. Пакетное редактирование труб (по фильтру или ID)\n"
        << "0. Выход\n"
        << "_________________________________________\n";
}

int main() {
    setlocale(LC_ALL, "RU");
    vector<Pipe> pipes;
    vector<Station> stations;

    while (true) {
        showMenu();

        int choice = getValidMenuChoice();

        switch (choice) {
        case 1: {
            int id = getUniqueId(pipes, stations);
            Pipe p(id);
            p.input();
            pipes.push_back(p);
            break;
        }
        case 2: {
            int id = getUniqueId(pipes, stations);
            Station s(id);
            s.input();
            stations.push_back(s);
            break;
        }
        case 3:
            showAllObjects(pipes, stations);
            break;
        case 4:
            editPipe(pipes);
            break;
        case 5:
            editStation(stations);
            break;
        case 6:
            deletePipe(pipes);
            break;
        case 7:
            deleteStation(stations);
            break;
        case 8: {
            ofstream file("data.txt");
            if (file.is_open()) {
                file << pipes.size() << '\n';
                for (const auto& pipe : pipes) {
                    pipe.saveToFile(file);
                }
                file << stations.size() << '\n';
                for (const auto& station : stations) {
                    station.saveToFile(file);
                }
                file.close();
                cout << "Данные сохранены.\n";
            }
            else {
                cout << "Ошибка: Не удалось открыть файл.\n";
            }
            break;
        }
        case 9: {
            ifstream file("data.txt");
            if (file.is_open()) {
                size_t count;
                file >> count;
                pipes.clear();
                for (size_t i = 0; i < count; ++i) {
                    Pipe p;
                    p.loadFromFile(file);
                    pipes.push_back(p);
                }
                file >> count;
                stations.clear();
                for (size_t i = 0; i < count; ++i) {
                    Station s;
                    s.loadFromFile(file);
                    stations.push_back(s);
                }
                file.close();
                cout << "Данные загружены.\n";
            }
            else {
                cout << "Ошибка: Не удалось открыть файл.\n";
            }
            break;
        }
        case 10: {
            searchPipes(pipes);
            break;
        }
        case 11: {
            searchStations(stations);
            break;
        }
        case 12:
            cout << "Выберите метод редактирования:\n"
                << "1. Редактировать все трубы (по фильтру)\n"
                << "2. Редактировать выбранные трубы по ID\n";
            int subChoice;
            cin >> subChoice;
            if (subChoice == 1) {
                editAllPipes(pipes);
            }
            else if (subChoice == 2) {
                editSelectedPipes(pipes);
            }
            break;
        case 0:
            return 0;
        default:
            break;
        }
    }
}
