/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** OSKernel.cpp
*/

#include "OSKernel.hpp"

OSKernel::OSKernel()
{
    updateData();
}

OSKernel::~OSKernel() {}

void OSKernel::updateData()
{
    this->_nameVersion.clear();
    struct utsname unameData;
    uname(&unameData);
    std::stringstream ss;

    ss << unameData.sysname;
    this->_nameVersion.push_back("OS: " + ss.str());
    ss.str("");
    ss << unameData.release;
    this->_nameVersion.push_back("Kernel-Version: " + ss.str());
}

std::vector<std::string> OSKernel::getDisplayData() const
{
    return (this->_nameVersion);
}

std::string OSKernel::getModuleName() const
{
    return ("OS & Kernel");
}