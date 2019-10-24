#ifndef PARTICLE_HPP
#define PARTICLE_HPP

#include <SFML/Graphics.hpp>
#include <cmath>


namespace pb
{
    class Particle;

    sf::Vector2f atraction_force(sf::Vector2f vm , sf::Vector2f vp);

    float vector_modulus(sf::Vector2f vec);
}


class pb::Particle
{
    public:
        sf::RectangleShape shape{sf::Vector2f(4,4)};
        sf::Vector2f position;
        sf::Vector2f velocity;
        
        Particle();

        Particle(float x , float y);

        Particle(sf::Vector2f initial_pos);

        void update(sf::Vector2f force, float time_elapsed);
};


#endif
