/*
** EPITECH PROJECT, 2023
** Graphical in SFML
** File description:
** Rush 3.
*/

#include "SFMLDisplayer.hpp"
#include "MyGKrellm.hpp"

SFMLDisplayer::SFMLDisplayer(std::vector<IMonitorModule*> modules) {
    launcher(modules);
}

SFMLDisplayer::~SFMLDisplayer() {}

void SFMLDisplayer::updateModulesData(std::vector<IMonitorModule*> &modules) const {
    for (int i = 0; i < (int)modules.size(); i++)
        modules[i]->updateData();
}

void SFMLDisplayer::launcher(std::vector<IMonitorModule*> modules) {
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "MyGKrellm");
    sf::Font font;
    font.loadFromFile("font.ttf");
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::Black);
    window.setFramerateLimit(60);

    if (initCallback() == -1)
        return;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
                break;
            default:
                break;
            }
        }
        window.clear(sf::Color::White);
        updateModulesData(modules);
        displaySprites(window);
        int yPos = 150;
        int iPos = 70;

        for (size_t i = 0; i < modules.size(); i++) {
            std::vector<std::string> data = modules[i]->getDisplayData();
            if (i == 3) {
                iPos = 70;
                yPos = 620;
            }
            if (i == 4) {
                iPos = 800;
                yPos = 620;
            }
            if (i == 5) {
                iPos = 1550;
                yPos = 620;
            }
            for (auto &str : data) {
                text.setString(str);
                text.setPosition(iPos, yPos);
                window.draw(text);
                yPos += 30;
            }
            yPos = 150;
            iPos += 740;
        }
        window.display();
        sf::sleep(sf::milliseconds(500));
    }
}
