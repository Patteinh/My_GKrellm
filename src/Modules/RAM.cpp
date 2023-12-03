/*
** EPITECH PROJECT, 2023
** RAM Module
** File description:
** Rush3.
*/

#include "RAM.hpp"

RAM::RAM() {
    updateData();
}

std::string RAM::getModuleName() const {
    return ("RAM: ");
}

std::vector<std::string> RAM::getDisplayData() const {
    return {this->_totalRAM, this->_freeRAM, this->_usedRAM};
}

void RAM::updateData() {
    struct sysinfo info;
    sysinfo(&info);
    double usedRAM = (double)(info.totalram - info.freeram);
    double totalRAM = (double)info.totalram;
    double percentage = (usedRAM / totalRAM) * 100;

    this->_totalRAM = "TOTAL RAM: " + std::to_string(info.totalram / 1000000) + " Mb";
    this->_freeRAM = "FREE RAM: " + std::to_string(info.freeram / 1000000) + " Mb";
    std::string tmp = "USED RAM: " + std::to_string(percentage);
    this->_usedRAM = tmp.substr(0, 15) + " %%%";
}
