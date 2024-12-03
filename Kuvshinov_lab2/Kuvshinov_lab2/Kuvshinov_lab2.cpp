#include "Pipe.h"
#include "Station.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <exception>
#include <ctime>

using namespace std;

// Функция для логирования действий
void logAction(const string& action) {
    ofstream logFile("log.txt", ios::app);
    if (logFile.is_open()) {
        time_t now = time(0);
        char dt[26]; // Массив для хранения строки времени
        ctime_s(dt, sizeof(dt), &now); // Безопасная версия функции
        dt[strlen(dt) - 1] = '\0'; // Убираем символ новой строки
        logFile << "[" << dt << "] " << action << endl;
        logFile.close();
    }
    else {
        cout << "Не удалось открыть файл для записи лога.\n";
    }
}

// Функция для получения уникального ID
int getUniqueId(const vector<Pipe>& pipes, const vector<Station>& stations) {
    int id = 1;
    while (find_if(pipes.begin(), pipes.end(), [id](const Pipe& p) { return p.getId() == id; }) != pipes.end() ||
        find_if(stations.begin(), stations.end(), [id](const Station& s) { return s.getId() == id; }) != stations.end()) {
        id++;
    }
    return id;
}

// Функция для редактирования всех труб по фильтру
void editAllPipes(vector<Pipe>& pipes) {
    if (pipes.empty()) {
        cout << "Нет труб для редактирования.\n";
        logAction("Попытка редактировать трубы, но объекты отсутствуют.");
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
        logAction("Отредактированы все трубы.");
    }
}

// Функция для редактирования выбранных труб по ID
void editSelectedPipes(vector<Pipe>& pipes) {
    if (pipes.empty()) {
        cout << "Нет труб для редактирования.\n";
        logAction("Попытка редактировать трубы, но объекты отсутствуют.");
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
            logAction("Труба с ID " + to_string(id) + " отредактирована.");
        }
        else {
            cout << "Труба с ID " << id << " не найдена.\n";
            logAction("Труба с ID " + to_string(id) + " не найдена для редактирования.");
        }
    }
}

// Функция для редактирования всех станций по фильтру
void editAllStations(vector<Station>& stations) {
    if (stations.empty()) {
        cout << "Нет станций для редактирования.\n";
        logAction("Попытка редактировать станции, но объекты отсутствуют.");
        return;
    }

    cout << "Вы хотите отредактировать все станции (1 - да, 0 - нет): ";
    int choice;
    cin >> choice;

    if (choice == 1) {
        for (auto& station : stations) {
            station.editWorkshops(); // Редактируем количество рабочих цехов для каждой станции
        }
        cout << "Все найденные станции отредактированы.\n";
        logAction("Отредактированы все станции.");
    }
}

// Функция для редактирования выбранных станций по ID
void editSelectedStations(vector<Station>& stations) {
    if (stations.empty()) {
        cout << "Нет станций для редактирования.\n";
        logAction("Попытка редактировать станции, но объекты отсутствуют.");
        return;
    }

    cout << "Введите количество станций, которые вы хотите отредактировать: ";
    int num;
    cin >> num;

    vector<int> selectedIds(num);
    cout << "Введите ID станций для редактирования:\n";
    for (int i = 0; i < num; ++i) {
        cin >> selectedIds[i];
    }

    for (int id : selectedIds) {
        auto it = find_if(stations.begin(), stations.end(), [id](const Station& s) { return s.getId() == id; });
        if (it != stations.end()) {
            it->editWorkshops(); // Редактируем количество рабочих цехов
            cout << "Станция с ID " << id << " отредактирована.\n";
            logAction("Станция с ID " + to_string(id) + " отредактирована.");
        }
        else {
            cout << "Станция с ID " << id << " не найдена.\n";
            logAction("Станция с ID " + to_string(id) + " не найдена для редактирования.");
        }
    }
}

// Функция для удаления трубы по ID
void deletePipe(vector<Pipe>& pipes) {
    if (pipes.empty()) {
        cout << "Нет труб для удаления.\n";
        logAction("Попытка удалить трубы, но объекты отсутствуют.");
        return;
    }

    cout << "Введите ID трубы для удаления: ";
    int id;
    cin >> id;

    auto it = find_if(pipes.begin(), pipes.end(), [id](const Pipe& p) { return p.getId() == id; });
    if (it != pipes.end()) {
        pipes.erase(it);
        cout << "Труба с ID " << id << " удалена.\n";
        logAction("Труба с ID " + to_string(id) + " удалена.");
    }
    else {
        cout << "Труба с ID " << id << " не найдена.\n";
        logAction("Труба с ID " + to_string(id) + " не найдена для удаления.");
    }
}

// Функция для удаления станции по ID
void deleteStation(vector<Station>& stations) {
    if (stations.empty()) {
        cout << "Нет станций для удаления.\n";
        logAction("Попытка удалить станции, но объекты отсутствуют.");
        return;
    }

    cout << "Введите ID станции для удаления: ";
    int id;
    cin >> id;

    auto it = find_if(stations.begin(), stations.end(), [id](const Station& s) { return s.getId() == id; });
    if (it != stations.end()) {
        stations.erase(it);
        cout << "Станция с ID " << id << " удалена.\n";
        logAction("Станция с ID " + to_string(id) + " удалена.");
    }
    else {
        cout << "Станция с ID " << id << " не найдена.\n";
        logAction("Станция с ID " + to_string(id) + " не найдена для удаления.");
    }
}

// Функция для вывода всех объектов
void showAllObjects(const vector<Pipe>& pipes, const vector<Station>& stations) {
    if (pipes.empty() && stations.empty()) {
        cout << "Нет объектов для отображения.\n";
        logAction("Попытка отображения объектов, но их нет.");
        return;
    }

    cout << "Трубы:\n";
    for (const auto& pipe : pipes) {
        pipe.output();
    }

    cout << "КС:\n";
    for (const auto& station : stations) {
        station.output();
    }

    logAction("Просмотрены все объекты.");
}

// Функция для отображения меню
void showMenu() {
    cout
        << "1. Добавить трубу\n"
        << "2. Добавить КС\n"
        << "3. Просмотреть все объекты\n"
        << "4. Редактировать статус ремонта труб\n"
        << "5. Редактировать цехи КС\n"
        << "6. Удалить трубу\n"
        << "7. Удалить КС\n"
        << "8. Сохранить данные в файл\n"
        << "9. Загрузить данные из файла\n"
        << "10. Поиск труб\n"
        << "11. Поиск КС\n"
        << "12. Пакетное редактирование труб (по фильтру или ID)\n"
        << "0. Выход\n";
}

int main() {
    setlocale(LC_ALL, "RU");
    vector<Pipe> pipes;
    vector<Station> stations;

    logAction("Программа запущена.");

    while (true) {
        showMenu();

        int choice;
        cout << "Введите номер действия: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int id = getUniqueId(pipes, stations);
            Pipe p(id);
            p.input();
            pipes.push_back(p);
            logAction("Добавлена труба с ID " + to_string(id));
            break;
        }
        case 2: {
            int id = getUniqueId(pipes, stations);
            Station s(id);
            s.input();
            stations.push_back(s);
            logAction("Добавлена КС с ID " + to_string(id));
            break;
        }
        case 3:
            showAllObjects(pipes, stations);
            break;
        case 4:
            editSelectedPipes(pipes);
            break;
        case 5:
            editSelectedStations(stations);
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
                logAction("Данные сохранены в файл.");
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
                logAction("Данные загружены из файла.");
            }
            else {
                cout << "Ошибка: Не удалось открыть файл.\n";
            }
            break;
        }
        case 10:
            // Поиск труб
            logAction("Выполнен поиск труб.");
            break;
        case 11:
            // Поиск КС
            logAction("Выполнен поиск КС.");
            break;
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
            logAction("Программа завершена.");
            return 0;
        default:
            cout << "Неверный выбор.\n";
            logAction("Неверный выбор в меню.");
        }
    }
}
