#pragma once

#include "Util.h"

#include "raylib.h"

#include "Globals.h"

#include <algorithm>
#include <iostream>
#include <mutex>

class World;

class Chunk;


class Tile
{
public:
    Tiles type;

    Tile() = default;
    Tile(Chunk* parent, Vector2i localPos, Tiles type) : parentChunk(parent), localPosition(localPos), type(type) {
        valid = true;
    }

    ~Tile();
    Vector2i localPosition;


    void draw(const Camera2D& cam);
    bool valid = false;
    Tile* getNeighbor(Direction dir);


    Tile(const Tile& other)
    {
        std::cout << "COPIED" << std::endl;
        *this = other;
        
    }



    static World* world;
    static void SetWorld(World* w) { world = w; }

    Chunk* parentChunk;
private:



    Texture2D texture;
};
