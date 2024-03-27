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
            cerr << "������: ���������� ������� ���� ��� ������." << endl;
            return;
        }
        file >> _name >> _login >> _pass;
        file.close();
    }

    void writeToFile(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "������: ���������� ������� ���� ��� ������." << endl;
            return;
        }
        file << _name << " " << _login << " " << _pass;
        file.close();
    }

    // �������� ������� � ������� �� �������������
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
            cerr << "������: ���������� ������� ���� ��� ������." << endl;
            return;
        }
        file >> _text >> _sender >> _receiver;
        file.close();
    }

    void writeToFile(const string& filename) {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "������: ���������� ������� ���� ��� ������." << endl;
            return;
        }
        file << _text << " " << _sender << " " << _receiver;
        file.close();
    }

    // �������� ������� � ������� �� �������������
};

bool hasPermission(const string& filename) {
    struct stat fileStat;
    if (stat(filename.c_str(), &fileStat) == -1) {
        cerr << "������: ���������� �������� ������ �����." << endl;
        return false;
    }
    // ����� ����� �������� �������������� �������� �� ����� �������
    return true;
}

int main() 
{
    setlocale(LC_ALL, "Rus");
    if (!hasPermission("user.txt")) 
    {
        cerr << "������: � ��� ��� ���������� �� ������ � ����� user.txt" << endl;
        return 1;
    }

    if (!hasPermission("message.txt")) 
    {
        cerr << "������: � ��� ��� ���������� �� ������ � ����� message.txt" << endl;
        return 1;
    }

    User user;
    Message message;

    // ������ ��������� �� ������
    user.readFromFile("user.txt");
    message.readFromFile("message.txt");

    // ��� ��� �����: ��������� ������

    // ������ ��������� � �����
    user.writeToFile("user.txt");
    message.writeToFile("message.txt");

    return 0;
}