#pragma once
#include "VectorUtils.h"

namespace FlatEngine::Core::Tools::Vector
{
    sf::Vector2f Normalize(const sf::Vector2f& source)
    {
        float length = Length(source);
        if (length != 0)
            return sf::Vector2f(source.x / length, source.y / length);
        else
            return source;
    }

    float Length(const sf::Vector2f& source)
    {
        return sqrt(SqrLength(source));
    }

    float SqrLength(const sf::Vector2f& source)
    {
        return source.x * source.x + source.y * source.y;
    }

    bool IsZero(const sf::Vector2f source)
    {
        return source.x == 0 && source.y == 0;
    }
}