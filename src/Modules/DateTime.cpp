/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** DateTimeModule.cpp
*/

#include "DateTime.hpp"

DateTime::DateTime()
{
    updateData();
}

DateTime::~DateTime() {}

void DateTime::updateData() {
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 80, "DATE: %Y-%m-%d", timeinfo);
    this->_date = buffer;
    strftime(buffer, 80, "TIME: %H:%M:%S", timeinfo);
    this->_time = buffer;
}

std::vector<std::string> DateTime::getDisplayData() const
{
    return {this->_date, this->_time};
}

std::string DateTime::getModuleName() const
{
    return ("Date & Time");
}