/*
** EPITECH PROJECT, 2023
** NcurseDisplayer.hpp
** File description:
** NcurseDisplayer
*/

#pragma once

#include "My.hpp"
#include "IMonitorDisplay.hpp"

class NcursesDisplayer : public IMonitorDisplay {
    public:
        NcursesDisplayer();
        void RefreshSetNcurse(std::vector<IMonitorModule*> &modules);
        void dataInfo(IMonitorModule *const &module, int center);
        void tabsModulesName(std::string name, int center);
        void displayNcurse(std::vector<IMonitorModule*> &modules) override;
        void displaySFML(std::vector<IMonitorModule*> &modules) override;
        ~NcursesDisplayer();
    private:
        int _row;
        int _maxLen;
        int _screenWidth;
        int _centerCols;
};
