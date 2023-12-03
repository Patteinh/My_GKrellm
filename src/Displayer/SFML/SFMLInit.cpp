/*
** EPITECH PROJECT, 2023
** Init sprites
** File description:
** Graphical for MyGKrellm.
*/

#include "SFMLDisplayer.hpp"

int SFMLDisplayer::initCallback() {
    if (initTextures() == -1) return -1;
    initSprites();
    setScales();
    setPositions();
    return 0;
}

int SFMLDisplayer::initTextures() {
    if (!this->_cpu.loadFromFile("./assets/cpu.png"))
        return (-1);
    if (!this->_ram.loadFromFile("./assets/ram.png"))
        return (-1);
    if (!this->_hostusers.loadFromFile("./assets/hostname.png"))
        return (-1);
    if (!this->_datetime.loadFromFile("./assets/datetime.png"))
        return (-1);
    if (!this->_oskernel.loadFromFile("./assets/oskernel.png"))
        return (-1);
    if (!this->_network.loadFromFile("./assets/network.png"))
        return (-1);
    return 0;
}

void SFMLDisplayer::initSprites() {
    this->_cpu_sprite = (sf::Sprite (this->_cpu));
    this->_ram_sprite = (sf::Sprite (this->_ram));
    this->_hostusers_sprite = (sf::Sprite (this->_hostusers));
    this->_datetime_sprite = (sf::Sprite (this->_datetime));
    this->_oskernel_sprite = (sf::Sprite (this->_oskernel));
    this->_network_sprite = (sf::Sprite (this->_network));
}

void SFMLDisplayer::setScales() {
    this->_cpu_sprite.setScale(0.35, 0.35);
    this->_ram_sprite.setScale(0.35, 0.35);
    this->_hostusers_sprite.setScale(0.35, 0.35);
    this->_datetime_sprite.setScale(0.35, 0.35);
    this->_oskernel_sprite.setScale(0.35, 0.35);
    this->_network_sprite.setScale(0.35, 0.35);
}

void SFMLDisplayer::setPositions() {
    this->_cpu_sprite.setPosition(50, 20);
    this->_ram_sprite.setPosition(775, 20);
    this->_hostusers_sprite.setPosition(1500, 20);
    this->_datetime_sprite.setPosition(50, 500);
    this->_oskernel_sprite.setPosition(775, 500);
    this->_network_sprite.setPosition(1500, 500);
}