/*
** EPITECH PROJECT, 2022
** Rush3
** File description:
** Network.cpp
*/

#include "Network.hpp"

Network::Network()
{
    updateData();
}

Network::~Network() {}

void Network::updateData()
{
    this->_network.clear();
    struct ifaddrs *ifap, *ifa;
    struct sockaddr_in *sa;
    char *addr;

    getifaddrs(&ifap);
    for (ifa = ifap; ifa; ifa = ifa->ifa_next)
    {
        if (ifa->ifa_addr->sa_family == AF_INET)
        {
            sa = (struct sockaddr_in *)ifa->ifa_addr;
            addr = inet_ntoa(sa->sin_addr);
            this->_network.push_back("Name of network interface: " + std::string(ifa->ifa_name));
            this->_network.push_back("Network address: " + std::string(addr));
        }
    }
    freeifaddrs(ifap);
}

std::vector<std::string> Network::getDisplayData() const
{
    return (this->_network);
}

std::string Network::getModuleName() const
{
    return ("Network");
}