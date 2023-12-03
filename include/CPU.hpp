/*
** EPITECH PROJECT, 2023
** CPU.hpp
** File description:
** CPU
*/

#pragma once

#include "IMonitorDisplay.hpp"

class CPU : public IMonitorModule {
    public:
        CPU();
        virtual void updateData() override;
        virtual std::string getModuleName() const override;
        virtual std::vector<std::string> getDisplayData() const override;
        std::string getModel() const;
        std::string getFrequency() const;
        std::string getNumCores() const;
    private:
        std::string _model;
        std::string _frequency;
        std::string _numCores;
};
