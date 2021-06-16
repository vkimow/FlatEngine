#pragma once
#include "SFML/System.hpp"

namespace FlatEngine::Core::Tools::Vector
{
    sf::Vector2f Normalize(const sf::Vector2f& source);
    float Length(const sf::Vector2f& source);
    float SqrLength(const sf::Vector2f& source);

    bool IsZero(const sf::Vector2f source);
}