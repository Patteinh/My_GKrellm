/*
** EPITECH PROJECT, 2023
** TestsDateTime.cpp
** File description:
** TestsDateTime
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "DateTime.hpp"

Test(DateTime, updateData) {
    DateTime dt;
    dt.updateData();
    std::vector<std::string> displayData = dt.getDisplayData();
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 80, "DATE: %Y-%m-%d", timeinfo);
    cr_assert_str_eq(displayData[0].c_str(), buffer);
    strftime(buffer, 80, "TIME: %H:%M:%S", timeinfo);
    cr_assert_str_eq(displayData[1].c_str(), buffer);
}

Test(DateTime, getModuleName) {
    DateTime dt;
    std::string moduleName = dt.getModuleName();
    cr_assert_str_eq(moduleName.c_str(), "Date & Time");
}

Test(DateTime, getDisplayData) {
    DateTime dt;
    std::vector<std::string> displayData = dt.getDisplayData();
    cr_assert_eq(displayData.size(), 2, "Expected 2 strings in vector, but got %d", displayData.size());
}
