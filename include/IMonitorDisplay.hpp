/*
** EPITECH PROJECT, 2023
** IMonitorDisplay.hpp
** File description:
** IMonitorDisplay
*/

#pragma once

#include "My.hpp"
#include "IMonitorModule.hpp"

class IMonitorDisplay {
    public:
        virtual void displayNcurse(std::vector<IMonitorModule*> &modules) = 0;
        virtual void displaySFML(std::vector<IMonitorModule*> &modules) = 0;
};
