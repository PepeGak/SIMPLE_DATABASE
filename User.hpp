#pragma once
#ifndef _USER_HPP_
#define _USER_HPP_

#include <string>
#include <cstring>

struct User
{
public:
    User(std::string name, std::string password)
    {
        strcpy(this->name, name.c_str());
        strcpy(this->password, password.c_str());
    }
    char name[32];
    char password[40];
};

#endif