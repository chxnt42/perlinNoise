#pragma once
#include "raylib.h"
#include <utility>



enum class Tiles 
{
    Empty,
    Dirt,
    Grass,
    Stone,
    Water
};


struct Vector2i
{
    int x,y;
    Vector2i(int x, int y) : x(x), y(y) {}
    Vector2i() : x(0), y(0) {}

    Vector2 toVector2()
    {
        return {static_cast<float>(x), static_cast<float>(y)};
    }
};



struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& pair) const {
        auto hash1 = std::hash<T1>{}(pair.first);
        auto hash2 = std::hash<T2>{}(pair.second);
        return hash1 ^ hash2; // Combine the two hash values
    }
};