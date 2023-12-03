/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** OSKernel.hpp
*/

#include "IMonitorModule.hpp"

class OSKernel : public IMonitorModule {
    public:
        OSKernel ();
        ~OSKernel ();
        virtual std::vector<std::string> getDisplayData() const override;
        virtual void updateData() override;
        virtual std::string getModuleName() const override;

    private:
        std::vector<std::string> _nameVersion;
};
