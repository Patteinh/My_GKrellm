/*
** EPITECH PROJECT, 2023
** Rush3
** File description:
** DateTimeModule.hpp
*/

#include "IMonitorModule.hpp"

class DateTime : public IMonitorModule {
    public:
        DateTime();
        ~DateTime();
        virtual std::vector<std::string> getDisplayData() const override;
        virtual void updateData() override;
        virtual std::string getModuleName() const override;

    private:
        std::string _date;
        std::string _time;
};
