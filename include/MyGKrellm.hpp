/*
** EPITECH PROJECT, 2023
** Project.hpp
** File description:
** project
*/

#pragma once

#include "My.hpp"
#include "IMonitorModule.hpp"

class MyGKrellm {
    public:
        enum OPTMyGKrellm{ TEXT, GRAPH, HELP, NONE };
        MyGKrellm(const std::string& opt);
        ~MyGKrellm();
        int CheckMyGKrellm() const;
        int StartMyGKrellm() const;
        int StartNcurse() const;
        int StartSFML() const;
        void updateModulesData(std::vector<IMonitorModule*> &modules) const;
        std::vector<IMonitorModule*> getVisibleModules(const std::vector<IMonitorModule*> &modules, const std::vector<bool> &modVisibility) const;
        void toggleModuleVisibility(int ch, const std::vector<IMonitorModule*> &modules, std::vector<bool> &modVisibility) const;
    private:
        OPTMyGKrellm _opt;
};
