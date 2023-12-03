/*
** EPITECH PROJECT, 2023
** IMonitorModule.hpp
** File description:
** IMonitorModule
*/

#pragma once

#include "My.hpp"

class IMonitorModule {
    public:
        virtual void updateData() = 0;
        virtual std::string getModuleName() const = 0;
        virtual std::vector<std::string> getDisplayData() const = 0;
};
