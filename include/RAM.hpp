/*
** EPITECH PROJECT, 2023
** RAM Module
** File description:
** Rush3 Htop.
*/

#ifndef RAM_HPP_
#define RAM_HPP_

#include "IMonitorModule.hpp"
#include <iostream>
#include <sys/sysinfo.h>

class RAM : public IMonitorModule {
    public:
        RAM();
        virtual void updateData() override;
        virtual std::string getModuleName() const override;
        virtual std::vector<std::string> getDisplayData() const override;

    private:
        std::string _usedRAM;
        std::string _totalRAM;
        std::string _freeRAM;
};

#endif /* !RAM_HPP_ */
