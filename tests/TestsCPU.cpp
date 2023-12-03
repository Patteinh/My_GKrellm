/*
** EPITECH PROJECT, 2023
** TestsCPU.cpp
** File description:
** TestsCPU
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "CPU.hpp"

Test(CPU, Test_GetModuleName) {
    CPU cpu;
    std::string result = cpu.getModuleName();
    cr_assert_str_eq(result.c_str(), "CPU Information:", "Module name not as expected");
}

Test(CPU, Test_GetDisplayData) {
    CPU cpu;
    std::vector<std::string> result = cpu.getDisplayData();
    cr_assert_eq(result.size(), 3, "Incorrect number of data elements");
    cr_assert(result[0].find("Model:") == 0, "Model information missing");
    cr_assert(result[1].find("Frequency:") == 0, "Frequency information missing");
    cr_assert(result[2].find("NbCores:") == 0, "Number of cores information missing");
}

Test(CPU, Test_GetModel) {
    CPU cpu;
    std::string result = cpu.getModel();
    cr_assert(result.find("Model:") == 0, "Model information missing");
}

Test(CPU, Test_GetFrequency) {
    CPU cpu;
    std::string result = cpu.getFrequency();
    cr_assert(result.find("Frequency:") == 0, "Frequency information missing");
}

Test(CPU, Test_GetNumCores) {
    CPU cpu;
    std::string result = cpu.getNumCores();
    cr_assert(result.find("NbCores:") == 0, "Number of cores information missing");
}
