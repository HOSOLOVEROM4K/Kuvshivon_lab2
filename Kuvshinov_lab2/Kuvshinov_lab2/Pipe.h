#ifndef PIPE_H
#define PIPE_H

#include <iostream>
#include <fstream>

class Pipe {
private:
    int id;                     // Уникальный идентификатор
    std::string name;           // Название
    double length;              // Длина
    double diameter;            // Диаметр
    bool inRepair;              // Признак "в ремонте"

public:
    // Конструктор по умолчанию
    Pipe() : id(0), name(""), length(0), diameter(0), inRepair(false) {}

    // Конструктор с ID
    Pipe(int id) : id(id), name(""), length(0), diameter(0), inRepair(false) {}

    // Геттер для ID
    int getId() const { return id; }

    // Ввод данных
    void input();

    // Вывод данных
    void output() const;

    // Редактирование статуса ремонта
    void editRepairStatus();

    // Сохранение в файл
    void saveToFile(std::ofstream& out) const;

    // Загрузка из файла
    void loadFromFile(std::ifstream& in);
};

#endif
