#pragma once
#ifndef _FILE_HANDLER_HPP_
#define _FILE_HANDLER_HPP_

#include <fstream>
#include <iostream>
#include <vector>
#include "User.hpp"

void ReadIntoFile(std::vector<User>& users);
void ReadFromFile(std::vector<User>& users);
bool CheckLogin(std::vector<User>& users, char login[32]);
bool CheckPassword(std::vector<User>& users, char login[32], char password[40]);
void RegisterUser(std::vector<User>& users, char login[32]);
void ChangePassword(std::vector<User>& users, char login[32], char password[40]);
void ChangeLogin(std::vector<User>& users, char login[32]);

#endif