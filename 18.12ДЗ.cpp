#include <iostream>
#include <fstream>
#include <sys/stat.h>
#include <string>

using namespace std;

class User {
private:
    string _name;
    string _login;
    string _pass;

public:
    void readFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Ошибка: Невозможно открыть файл для чтения." << endl;
            return;
        }
        file >> _name >> _login >> _pass;
        file.close();
    }

    void writeToFile(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Ошибка: Невозможно открыть файл для записи." << endl;
            return;
        }
        file << _name << " " << _login << " " << _pass;
        file.close();
    }

    // Добавьте геттеры и сеттеры по необходимости
};

class Message {
private:
    string _text;
    string _sender;
    string _receiver;

public:
    void readFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Ошибка: Невозможно открыть файл для чтения." << endl;
            return;
        }
        file >> _text >> _sender >> _receiver;
        file.close();
    }

    void writeToFile(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Ошибка: Невозможно открыть файл для записи." << endl;
            return;
        }
        file << _text << " " << _sender << " " << _receiver;
        file.close();
    }

    // Добавьте геттеры и сеттеры по необходимости
};

bool hasPermission(const string& filename) {
    struct stat fileStat;
    if (stat(filename.c_str(), &fileStat) == -1) {
        cerr << "Ошибка: Невозможно получить статус файла." << endl;
        return false;
    }
    // Здесь можно добавить дополнительные проверки на права доступа
    return true;
}

int main() 
{
    setlocale(LC_ALL, "Rus");
    if (!hasPermission("user.txt")) 
    {
        cerr << "Ошибка: У вас нет разрешения на доступ к файлу user.txt" << endl;
        return 1;
    }

    if (!hasPermission("message.txt")) 
    {
        cerr << "Ошибка: У вас нет разрешения на доступ к файлу message.txt" << endl;
        return 1;
    }

    User user;
    Message message;

    // Чтение состояний из файлов
    user.readFromFile("user.txt");
    message.readFromFile("message.txt");

    // Ваш код здесь: обработка данных

    // Запись состояний в файлы
    user.writeToFile("user.txt");
    message.writeToFile("message.txt");

    return 0;
}