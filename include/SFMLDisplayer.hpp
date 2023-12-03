/*
** EPITECH PROJECT, 2023
** Graphical part of Htop
** File description:
** Rush 3.
*/

#pragma once

#include "IMonitorModule.hpp"
#include "MyGKrellm.hpp"

class SFMLDisplayer {
    public:
        SFMLDisplayer(std::vector<IMonitorModule*> modules);
        ~SFMLDisplayer();
        void updateModulesData(std::vector<IMonitorModule*> &modules) const;
        void launcher(std::vector<IMonitorModule*> modules);
        int initTextures();
        int initCallback();
        void initSprites();
        void displaySprites(sf::RenderWindow &window);
        void setScales();
        void setPositions();

    private:
        sf::RenderWindow _window;
        sf::Texture _cpu;
        sf::Sprite _cpu_sprite;
        sf::Texture _ram;
        sf::Sprite _ram_sprite;
        sf::Texture _hostusers;
        sf::Sprite _hostusers_sprite;
        sf::Texture _datetime;
        sf::Sprite _datetime_sprite;
        sf::Texture _oskernel;
        sf::Sprite _oskernel_sprite;
        sf::Texture _network;
        sf::Sprite _network_sprite;
};
