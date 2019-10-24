#include <iostream>
#include <SFML/Graphics.hpp>
#include "particle.hpp"
#include <cmath>

const float FORCE_INTENSITY = 5000.f;

sf::Vector2f atraction_force(sf::Vector2f vm , sf::Vector2f vp)
{
    sf::Vector2f tmp(vm - vp);
    tmp.x = std::log(tmp.x);
    tmp.y = std::log(tmp.y);
    return vm - vp;
}

float vector_modulus(sf::Vector2f vec)
{
    return std::sqrt(std::pow(vec.x,2.f) + std::pow(vec.y,2.f));
}


int main(int argc, char** argv)
{
    sf::RenderWindow window(sf::VideoMode::getDesktopMode() , "Particle Boi" , sf::Style::Fullscreen);

    sf::Clock clock;

    pb::Particle particle1(20,20);
    //pb::Particle particle2(200,350);

    window.setFramerateLimit(120);

    while(window.isOpen())
    {
        sf::Vector2f a_force1 = sf::Vector2f(0,0);
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();

            //if(event.type == sf::Event::MouseButtonPressed)
                
                


        }

        //sf::Vector2f a_force1 = atraction_force(sf::Vector2f(sf::Mouse::getPosition(window)) , particle1.position);
        //sf::Vector2f a_force2 = atraction_force(sf::Vector2f(sf::Mouse::getPosition(window)) , particle2.position);
        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                    a_force1 = atraction_force(sf::Vector2f(sf::Mouse::getPosition(window)) , particle1.position);
                    
        //std::cout << a_force1.x << ',' << a_force1.x << '\n'; 

        particle1.update(a_force1 * FORCE_INTENSITY, clock.getElapsedTime().asSeconds());
        //particle2.update(a_force2 * FORCE_INTENSITY, clock.getElapsedTime().asSeconds());

        window.draw(particle1.shape);
        //window.draw(particle2.shape);
        window.display();
        window.clear();
        clock.restart();
        
    }

    return 0;
}