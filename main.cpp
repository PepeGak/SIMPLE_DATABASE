#include <iostream>
#include "UserHandler.hpp"
#include "User.hpp"
using namespace std;

int main(int argc, char *args[])
{
    vector<User> users;
    ReadFromFile(users);
    for (auto i : users)
        cout << i.name << " " << i.password << "\n";

    char login[32], password[40];
    bool isRunning = true;
    while (isRunning)
    {
        cout << "Выберите действие:\n"
                "1: Войти\n"
                "2: Регистрация\n"
                "3: Выход\n";
        char choice;
        cin >> choice;
        switch (choice)
        {
        case '1':
        {
            cout << "Введите логин (до 32 символов): ";
            cin >> login;
            if (CheckLogin(users, login)) // login does exist
            {
                cout << "Введите пароль (до 40 символов): ";
                cin >> password;
                if (CheckPassword(users, login, password))
                {
                    cout << "Доступ разрешён\n";
                    cout << "Выберите вариант: "
                    "1: Сменить пароль"
                    "2: Сменить логин"
                    "3: Удалить аккаунт"
                    "4: Выход";
                    cin >> choice;
                    switch (choice)
                    {
                        case '1':
                            {
                                cout << "Введите новый пароль (до 40 символов): ";
                                cin >> password;
                                ChangePassword(users, login, password);
                                cout << "Пароль изменён!\n";
                            }
                        case '2':
                            {
                                cout << "Ввудите новый логин (до 32 символов): ";
                                cin >> login;
                                if (!CheckLogin(users, login))
                                {
                                    ChangeLogin(users, login);
                                    cout << "Логин изменён!\n";
                                }
                                else
                                    cout << "Данный логин уже занят!\n";
                            }
                        case '3':
                            {

                            }
                            break;
                        case '4':
                        break;
                    
                    default:
                        break;
                    }
                }
                else
                    cout << "Доступ запрещён\n";
            }
            else // login does not exist
            {
                cout << "Такого логина нет! Создать его? Д/Н ";
                char yn;
                cin >> yn;
                if (yn == 'Д' || yn == 'д')
                {
                    RegisterUser(users, login);
                    cout << "Аккаунт создан!\n";
                }
            }
        }
        break;

        case '2':
        {
            cout << "Придумайте логин (до 32 символов): ";
            cin >> login;
            if (CheckLogin(users, login))
                cout << "Данный логин уже занят!\n";
            else
                RegisterUser(users, login);
        }
        break;

        case '3':
        {
            isRunning = false;
        }
        break;

        default:
            break;
        }
    }

    ReadIntoFile(users);
    return 0;
}