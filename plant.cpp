#include "Planet.hpp"
#include <cmath>

Planet::Planet(float radius, sf::Color color, float orbitRadius, float angularVelocity, sf::Vector2f center)
    : orbitRadius(orbitRadius), angularVelocity(angularVelocity), center(center), orbitPath(sf::LineStrip, 100)
{
    shape.setRadius(radius);
    shape.setFillColor(color);
    shape.setOrigin(radius, radius);

    for (int i = 0; i < 100; ++i)
    {
        float angle = i * 2 * 3.14159f / 100;
        float x = center.x + orbitRadius * std::cos(angle);
        float y = center.y + orbitRadius * std::sin(angle);
        orbitPath[i].position = sf::Vector2f(x, y);
        orbitPath[i].color = sf::Color(100, 100, 100);
    }
}

void Planet::update(float time)
{
    float angle = angularVelocity * time;
    float x = center.x + orbitRadius * std::cos(angle);
    float y = center.y + orbitRadius * std::sin(angle);
    shape.setPosition(x, y);
}

void Planet::draw(sf::RenderWindow& window)
{
    window.draw(orbitPath);
    window.draw(shape);
}
