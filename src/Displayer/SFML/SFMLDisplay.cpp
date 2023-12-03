/*
** EPITECH PROJECT, 2023
** Display Sprites
** File description:
** Rush 3.
*/

#include "SFMLDisplayer.hpp"

void SFMLDisplayer::displaySprites(sf::RenderWindow &window) {
    window.draw(this->_cpu_sprite);
    window.draw(this->_ram_sprite);
    window.draw(this->_hostusers_sprite);
    window.draw(this->_datetime_sprite);
    window.draw(this->_oskernel_sprite);
    window.draw(this->_network_sprite);
}
