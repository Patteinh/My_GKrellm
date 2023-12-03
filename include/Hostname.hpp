/*
** EPITECH PROJECT, 2023
** Hostname module
** File description:
** Rush 3.
*/

#ifndef HOSTNAME_HPP_
#define HOSTNAME_HPP_

#include "IMonitorModule.hpp"
#include <unistd.h>
#include <iostream>
#include <sys/types.h>
#include <pwd.h>

class Hostname : public IMonitorModule {
    public:
        Hostname();
        virtual void updateData() override;
        virtual std::string getModuleName() const override;
        virtual std::vector<std::string> getDisplayData() const override;
    private:
        std::string _hostname;
        std::string _username;
};


#endif /* !HOSTNAME_HPP_ */
