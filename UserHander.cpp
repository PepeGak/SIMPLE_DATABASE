#include "UserHandler.hpp"

/*
Writes all user logins and passwords from the vector<User> to a binary file.
*/
void ReadIntoFile(std::vector<User>& users)
{
    std::ofstream fout("data.dat", std::ios::out | std::ios::binary);
    
    __int32_t t = users.size();
    fout.write((char*)&t, sizeof(__int32_t));
    
    for (auto user : users)
        fout.write((char*)&user, sizeof(User));
    fout.close();
}

/*
Reads all user logins and passwords and write them down to the vector<User>.
*/
void ReadFromFile(std::vector<User>& users)
{
    std::ifstream fin("data.dat", std::ios::in | std::ios::binary);
    __int32_t t;
    fin.read((char*)&t, sizeof(__int32_t));
    for (int i = 0; i < t; i++)
    {
        User temp("", "");
        fin.read((char*)&temp, sizeof(User));
        users.push_back(temp);
    }
    fin.close();
}

/*
This function allows to create a password and add the user to the vector<User>.
*/
void RegisterUser(std::vector<User>& users, char login[32])
{
    char password[40];
    std::cout << "Создайте пароль (до 40 символов): ";
    std::cin >> password;
    users.push_back(User(login, password));
}

/*
Changes the password for a chosen user in vector<User>.
*/
void ChangePassword(std::vector<User> &users, char login[32], char password[40])
{
    for (__int32_t i = 0; i < users.size(); i++)
        if (!strcmp(login, users[i].name))
        {
            strcpy(users[i].password, password);
            break;
        }
}

/*
Changes the login for a chosen user in vector<User>.
*/
void ChangeLogin(std::vector<User> &users, char login[32])
{
    for (__int32_t i = 0; i < users.size(); i++)
        if (!strcmp(login, users[i].name))
        {
            strcpy(users[i].name, login);
            break;
        }
}

/*
If the login is found, returns true. Otherwise, returns false.
*/
bool CheckLogin(std::vector<User>& users, char name[32])
{
    for (__int32_t i = 0; i < users.size(); i++)
        if (!strcmp(users[i].name, name))
            return true;
    return false;
}

/*
If the password is found, returns true. Otherwise, returns false.
*/
bool CheckPassword(std::vector<User>& users, char name[32], char password[40])
{
    for (__int32_t i = 0; i < users.size(); i++)
        if (!strcmp(users[i].name, name))
            if (!strcmp(users[i].password, password))
                return true;
            else
                return false;
    return false;
}