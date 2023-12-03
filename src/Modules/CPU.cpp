/*
** EPITECH PROJECT, 2023
** CPU.cpp
** File description:
** CPU
*/

#include "CPU.hpp"

CPU::CPU() {
    updateData();
}

void CPU::updateData() {
    this->_model = getModel();
    this->_frequency = getFrequency();
    this->_numCores = getNumCores();
}

std::string CPU::getModuleName() const {
    return ("CPU Information:");
}

std::vector<std::string> CPU::getDisplayData() const {
    return {this->_model, this->_frequency, this->_numCores};
}

std::string CPU::getModel() const {
    std::string model;
    std::ifstream cpuinfo("/proc/cpuinfo");
    if (cpuinfo.is_open()) {
        std::string line;
        while (std::getline(cpuinfo, line)) {
            if (line.find("model name") != std::string::npos) {
                model = line.substr(line.find(":") + 2);
                break;
            }
        }
        cpuinfo.close();
    }
    return ("Model: " + model);
}

std::string CPU::getFrequency() const {
    std::ifstream file("/proc/cpuinfo");
    std::string line;
    std::regex pattern("^cpu MHz\\s*: ([0-9]+\\.[0-9]+)");

    while (std::getline(file, line)) {
        std::smatch match;
        if (std::regex_search(line, match, pattern)) {
            return ("Frequency: " + match[1].str() + " MHz");
        }
    }

    return ("N/A");
}

std::string CPU::getNumCores() const {
    std::ifstream input("/proc/cpuinfo");
    std::string line;
    int cores = 0;

    while (std::getline(input, line)) {
        if (line.find("processor") != std::string::npos) {
            ++cores;
        }
    }

    return ("NbCores: " + std::to_string(cores));
}
