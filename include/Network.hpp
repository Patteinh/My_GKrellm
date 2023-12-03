/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** Network.hpp
*/

#include "IMonitorModule.hpp"

class Network : public IMonitorModule {
    public:
        Network ();
        ~Network ();
        virtual std::vector<std::string> getDisplayData() const override;
        virtual void updateData() override;
        virtual std::string getModuleName() const override;

    private:
        std::vector<std::string> _network;
};
