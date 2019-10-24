#include <SFML/Graphics.hpp>
#include <cmath>

namespace pb
{
    class Particle;
};


class pb::Particle
{
    public:
        sf::RectangleShape shape{sf::Vector2f(4,4)};
        sf::Vector2f position;
        sf::Vector2f velocity;
    
        Particle() : velocity{0,0} , position{0,0} 
        {
            this->shape.setFillColor(sf::Color(143, 143, 143));
            this->shape.setPosition(position);
        }

        Particle(float x , float y) : velocity{0,0} , position{x,y} 
        {
            this->shape.setFillColor(sf::Color(143, 143, 143));
            this->shape.setPosition(position);
        }

        Particle(sf::Vector2f initial_pos) : velocity{0,0} , position{initial_pos} 
        {
            this->shape.setFillColor(sf::Color(143, 143, 143));
            this->shape.setPosition(position);
        }
        

        void update(sf::Vector2f force, float time_elapsed)
        {
            this->velocity = this->velocity + force * time_elapsed;
            this->position = this->position + this->velocity * time_elapsed + (force * std::pow(time_elapsed,2.f)) / 2.f;
            this->shape.setPosition(this->position);
        }

}; 