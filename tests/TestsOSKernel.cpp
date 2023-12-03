/*
** EPITECH PROJECT, 2023
** TestsOpeNameKernelVe.cpp
** File description:
** OSKernel
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "OSKernel.hpp"

Test(OSKernel, GetModuleName) {
    OSKernel os;
    cr_assert_str_eq(os.getModuleName().c_str(), "OS & Kernel");
}

Test(OSKernel, GetDisplayData) {
    OSKernel os;
    std::vector<std::string> data = os.getDisplayData();
    cr_assert_gt(data.size(), 0, "Display data is empty");
}

Test(OSKernel, UpdateData) {
    OSKernel os;
    os.updateData();
    std::vector<std::string> data = os.getDisplayData();
    cr_assert_gt(data.size(), 0, "Display data is empty after update");
}
