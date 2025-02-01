#pragma once

#include "FastNoise/Generators/Fractal.h"
#include "Tile.h"
#include "raylib.h"
#include "Util.h"
#include <vector>
#include <FastNoise/FastNoise.h>
#include <iostream>
#include <iomanip>
#include "globals.h"


class Chunk
{
public:


    Vector2i position;
    static int size;

    std::vector<std::vector<Tile>> tiles;






    Chunk(Vector2i pos);
    ~Chunk();


    void draw(const Camera2D& cam);
    void drawChunkBorder(const Camera2D& cam);
    void generateChunkTiles(FastNoise::SmartNode<FastNoise::FractalFBm>& noise,int seed,float frequency);


    Tile* getTile(int x, int y)
    {
        return &tiles[y][x];
    }


    

private:

};
