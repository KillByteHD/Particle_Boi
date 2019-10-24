#include <iostream>
#include <SFML/Graphics.hpp>
#include "particle.hpp"
#include <cmath>


const float FORCE_INTENSITY = 5000.f;


int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode() , "Particle Boi" , sf::Style::Fullscreen);

    sf::Clock clock;

    pb::Particle particle1(20,20);

    window.setFramerateLimit(120);

    while(window.isOpen())
    {
        sf::Vector2f a_force1 = sf::Vector2f(0,0);
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
            a_force1 = pb::atraction_force(sf::Vector2f(sf::Mouse::getPosition(window)) , particle1.position);
                    

        particle1.update(a_force1 * FORCE_INTENSITY, clock.getElapsedTime().asSeconds());

        window.draw(particle1.shape);
        window.display();
        window.clear();
        clock.restart();
        
    }

    return 0;
}