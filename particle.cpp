#include "particle.hpp"


pb::Particle::Particle() : velocity{0,0} , position{0,0} 
{
    this->shape.setFillColor(sf::Color(143, 143, 143));
    this->shape.setPosition(position);
}


pb::Particle::Particle(float x , float y) : velocity{0,0} , position{x,y} 
{
    this->shape.setFillColor(sf::Color(143, 143, 143));
    this->shape.setPosition(position);
}


pb::Particle::Particle(sf::Vector2f initial_pos) : velocity{0,0} , position{initial_pos} 
{
    this->shape.setFillColor(sf::Color(143, 143, 143));
    this->shape.setPosition(position);
}
        

void pb::Particle::update(sf::Vector2f force, float time_elapsed)
{
    this->velocity = this->velocity + force * time_elapsed;
    this->position = this->position + this->velocity * time_elapsed + (force * std::pow(time_elapsed,2.f)) / 2.f;
    this->shape.setPosition(this->position);
}


sf::Vector2f pb::atraction_force(sf::Vector2f vm , sf::Vector2f vp)
{
    sf::Vector2f tmp(vm - vp);
    tmp.x = std::log(tmp.x);
    tmp.y = std::log(tmp.y);
    return vm - vp;
}

float pb::vector_modulus(sf::Vector2f vec)
{
    return std::sqrt(std::pow(vec.x,2.f) + std::pow(vec.y,2.f));
}