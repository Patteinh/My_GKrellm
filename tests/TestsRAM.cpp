/*
** EPITECH PROJECT, 2023
** TestsRAM.cpp
** File description:
** TestsRAM
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "RAM.hpp"

Test(RAM, getDisplayData)
{
    RAM ram;
    std::vector<std::string> expected = ram.getDisplayData();
    cr_assert_gt(expected.size(), 0, "RAM display data should have at least one element");
}

Test(RAM, getModuleName)
{
    RAM ram;
    std::string expected = ram.getModuleName();
    cr_assert_not_null(expected.c_str(), "RAM module name should not be null");
    cr_assert_gt(expected.length(), 0, "RAM module name should have at least one character");
}

Test(RAM, updateData)
{
    RAM ram;
    ram.updateData();
    std::vector<std::string> displayData = ram.getDisplayData();
    cr_assert_gt(displayData.size(), 0, "RAM display data should have at least one element after update");
}
