/*
** EPITECH PROJECT, 2023
** MyGKrellm.cpp
** File description:
** MyGKrellm
*/

#include "OSKernel.hpp"
#include "DateTime.hpp"
#include "NcurseDisplayer.hpp"
#include "SFMLDisplayer.hpp"
#include "CPU.hpp"
#include "Hostname.hpp"
#include "RAM.hpp"
#include "Network.hpp"
#include "MyGKrellm.hpp"

MyGKrellm::MyGKrellm(const std::string& opt) {
    if (!opt.compare("text"))
        this->_opt = TEXT;
    else if (!opt.compare("graphical"))
        this->_opt = GRAPH;
    else if (!opt.compare("-h"))
        this->_opt = HELP;
    else
        this->_opt = NONE;
    CheckMyGKrellm();
}

MyGKrellm::~MyGKrellm() {}

int MyGKrellm::CheckMyGKrellm(void) const {
    if (this->_opt == NONE) {
        std::cout << "Usage: ./MyGKrellm [text / graphical]" << std::endl;
        exit(ERROR);
    } else if (this->_opt == HELP) {
        std::cout << "Usage: ./MyGKrellm [text / graphical]" << std::endl;
        std::cout << "[text]:" << std::endl;
        std::cout << "\tPress [MAJ + 1] to hide/unhide CPU module" << std::endl;
        std::cout << "\tPress [MAJ + 2] to hide/unhide RAM module" << std::endl;
        std::cout << "\tPress [MAJ + 3] to hide/unhide USR module" << std::endl;
        std::cout << "\tPress [MAJ + 4] to hide/unhide TIME module" << std::endl;
        std::cout << "\tPress [MAJ + 5] to hide/unhide OS module" << std::endl;
        std::cout << "\tPress [MAJ + 6] to hide/unhide NETWORK module" << std::endl;
        std::cout << "[graphical]:" << std::endl;
        std::cout << "\tNo input." << std::endl;
        exit(SUCCESS);
    }
    return (SUCCESS);
}

int MyGKrellm::StartMyGKrellm(void) const {
    if (this->_opt == TEXT)
        return(this->StartNcurse());
    else
        return(this->StartSFML());
}

int MyGKrellm::StartNcurse() const {
    Hostname modUsers;
    Network modNetwork;
    CPU modCpu;
    RAM modRAM;
    OSKernel modOS;
    NcursesDisplayer display;
    DateTime modTime;
    std::vector<IMonitorModule*> modules = {&modCpu, &modRAM, &modUsers, &modTime, &modOS, &modNetwork};
    std::vector<bool> modVisibility(modules.size(), true);
    int ch;
    while (1) {
        updateModulesData(modules);
        std::vector<IMonitorModule*> modsToDisplay = getVisibleModules(modules, modVisibility);
        display.displayNcurse(modsToDisplay);
        napms(500);
        ch = getch();
        if (ch == 'q')
            break;
        toggleModuleVisibility(ch, modules, modVisibility);
    }
    return (SUCCESS);
}

void MyGKrellm::updateModulesData(std::vector<IMonitorModule*> &modules) const {
    for (int i = 0; i < (int)modules.size(); i++)
        modules[i]->updateData();
}

std::vector<IMonitorModule*> MyGKrellm::getVisibleModules(const std::vector<IMonitorModule*> &modules, const std::vector<bool> &modVisibility) const {
    std::vector<IMonitorModule*> modsToDisplay;
    for (int i = 0; i < (int)modules.size(); i++)
        if (modVisibility[i]) modsToDisplay.push_back(modules[i]);
    return modsToDisplay;
}

void MyGKrellm::toggleModuleVisibility(int ch, const std::vector<IMonitorModule*> &modules, std::vector<bool> &modVisibility) const {
    if (ch >= '1' && ch <= '6') {
        int index = ch - '1';
        if (index >= 0 && index < (int)modules.size()) modVisibility[index] = !modVisibility[index];
    }
}

int MyGKrellm::StartSFML() const {
    Hostname modUsers;
    Network modNetwork;
    CPU modCpu;
    RAM modRAM;
    OSKernel modOS;
    DateTime modTime;
    std::vector<IMonitorModule*> modules = {&modCpu, &modRAM, &modUsers, &modTime, &modOS, &modNetwork};
    SFMLDisplayer display(modules);

    return (SUCCESS);
}
