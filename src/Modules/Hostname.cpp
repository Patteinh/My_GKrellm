/*
** EPITECH PROJECT, 2023
** Hostname module
** File description:
** Rush 3.
*/

#include "Hostname.hpp"
#include <string>
#include <string.h>

Hostname::Hostname() {
    updateData();
}

std::string Hostname::getModuleName() const {
    return ("Host / Users");
}

std::vector<std::string> Hostname::getDisplayData() const {
    return { this->_hostname, this->_username };
}

void Hostname::updateData() {
    uid_t uid = geteuid();
    struct passwd *pw = getpwuid(uid);
    char tmp[256];
    gethostname(tmp, 256);
    std::string host = tmp;
    std::string user = pw->pw_name;
    this->_hostname = "Hostname: " + host;
    if (pw)
        this->_username = "UserName: " + user;
    else
        this->_username = "getpwuid() failed";
}
