/*
** EPITECH PROJECT, 2023
** NcurseDisplayer.cpp
** File description:
** NcurseDisplayer
*/

#include "NcurseDisplayer.hpp"

NcursesDisplayer::NcursesDisplayer() {
    initscr();
    noecho();
    cbreak();
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_CYAN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
}

void NcursesDisplayer::RefreshSetNcurse(std::vector<IMonitorModule*> &modules) {
    clear();
    this->_row = 0;
    this->_maxLen = 0;
    this->_screenWidth = getmaxx(stdscr);
    for (const auto &module : modules) {
        std::string name = module->getModuleName();
        if ((int)name.length() > this->_maxLen)
            this->_maxLen = name.length();
        for (const auto &line : module->getDisplayData())
            if ((int)line.length() > this->_maxLen)
                this->_maxLen = line.length();
    }
    this->_maxLen += 4;
    this->_centerCols = (this->_screenWidth - this->_maxLen) / 2;
}

void NcursesDisplayer::dataInfo(IMonitorModule *const &module, int center) {
    for (const auto &line : module->getDisplayData()) {
        center = (this->_maxLen - line.length()) / 2;
        mvprintw(this->_row, this->_centerCols - 1, "|");
        mvprintw(this->_row, this->_centerCols + this->_maxLen + 2, "|");
        mvprintw(this->_row, this->_centerCols + 1, " ");
        attron(COLOR_PAIR(2));
        mvprintw(this->_row, this->_centerCols + center + 1, line.c_str());
        attroff(COLOR_PAIR(2));
        mvprintw(this->_row, this->_centerCols, " ");
        this->_row++;
    }
}

void NcursesDisplayer::tabsModulesName(std::string name, int center) {
    attron(COLOR_PAIR(1));
    mvprintw(this->_row, this->_centerCols, "+");
    for (int i = 0; i < this->_maxLen; i++)
        mvprintw(this->_row, this->_centerCols + i + 1, "-");
    mvprintw(this->_row, this->_centerCols + this->_maxLen + 1, "+");
    attroff(COLOR_PAIR(1));
    this->_row++;
    mvprintw(this->_row, this->_centerCols, "|");
    mvprintw(this->_row, this->_centerCols + this->_maxLen + 1, "|");
    attron(COLOR_PAIR(1));
    mvprintw(this->_row, this->_centerCols + 1, " ");
    attron(COLOR_PAIR(3));
    mvprintw(this->_row, this->_centerCols + center + 1, name.c_str());
    attroff(COLOR_PAIR(3));
    mvprintw(this->_row, this->_centerCols + this->_maxLen, " ");
    attroff(COLOR_PAIR(1));
    this->_row++;
    attron(COLOR_PAIR(1));
    mvprintw(this->_row, this->_centerCols, "+");
    for (int i = 0; i < this->_maxLen; i++)
        mvprintw(this->_row, this->_centerCols + i + 1, "-");
    mvprintw(this->_row, this->_centerCols + this->_maxLen + 1, "+");
    attroff(COLOR_PAIR(1));
    this->_row++;
}

void NcursesDisplayer::displayNcurse(std::vector<IMonitorModule*> &modules) {
    RefreshSetNcurse(modules);
    for (const auto &module : modules) {
        std::string name = module->getModuleName();
        int center = (this->_maxLen - name.length()) / 2;
        tabsModulesName(name, center);
        dataInfo(module, center);
    }
    attron(COLOR_PAIR(1));
    mvprintw(this->_row, this->_centerCols, "+");
    for (int i = 0; i < this->_maxLen; i++)
        mvprintw(this->_row, this->_centerCols + i + 1, "-");
    mvprintw(this->_row, this->_centerCols + this->_maxLen + 1, "+");
    refresh();
}

void NcursesDisplayer::displaySFML(std::vector<IMonitorModule*> &modules) {
    (void)modules;
}

NcursesDisplayer::~NcursesDisplayer() {
    endwin();
}