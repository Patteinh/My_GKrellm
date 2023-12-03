/*
** EPITECH PROJECT, 2023
** TestsNetwork.cpp
** File description:
** TestsNetwork
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "Network.hpp"

Test(Network, updateData) {
    Network network;
    network.updateData();
    std::vector<std::string> displayData = network.getDisplayData();
    cr_assert(displayData.size() > 0, "updateData() failed, displayData is empty");
}

Test(Network, getModuleName) {
    Network network;
    std::string moduleName = network.getModuleName();
    cr_assert_str_eq(moduleName.c_str(), "Network", "getModuleName() returned incorrect name");
}
