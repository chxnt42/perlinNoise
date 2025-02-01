#include "FastNoise/FastNoise_Config.h"
#include "FastNoise/Generators/Fractal.h"
#include "FastNoise/Generators/Perlin.h"
#include "Globals.h"
#include "Tile.h"
#include "raylib.h"
#include "raymath.h"
#include <FastNoise/FastNoise.h>
#include <ctime>
#include <iostream>

#include "World.h"


int main()
{

    World world;


    auto fnPerlin = FastNoise::New<FastNoise::Perlin>();
    auto fnFractal = FastNoise::New<FastNoise::FractalFBm>();

    fnFractal->SetSource(fnPerlin);
    fnFractal->SetOctaveCount(8);
    fnFractal->SetGain(0.3f);




    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            world.addChunk(i,j);
            world.chunks[std::make_pair(i,j)]->generateChunkTiles(fnFractal, world.seed,0.08f);
            
        }
    }

    



    InitWindow(800, 800, "Cave Generation Demo");

    SetTargetFPS(60);

    world.chunks[{0,0}]->tiles[0][0] = Tile(world.chunks[{0,0}].get(), Vector2i(0,0), Tiles::Stone);
    world.chunks[{0,0}]->tiles[0][1] = Tile(world.chunks[{0,0}].get(), Vector2i(1,0), Tiles::Stone);






    auto res = world.chunks[{0,0}]->tiles[0][0].getNeighbor(Direction::Right);
    std::cout << res->localPosition.x << " " << res->localPosition.y << std::endl;

    while (!WindowShouldClose())
    {


        if(IsKeyDown(KEY_A))
        {
            world.camera.offset.x += 10.5;
        }
        if(IsKeyDown(KEY_D))
        {
            world.camera.offset.x -= 10.5;
        }
        if(IsKeyDown(KEY_W))
        {
            world.camera.offset.y += 10.5;
        }
        if(IsKeyDown(KEY_S))
        {
            world.camera.offset.y -= 10.5;
        }

        if(IsKeyDown(KEY_Q))
        {
            world.camera.zoom += 0.1 * world.camera.zoom;
        }
        if(IsKeyDown(KEY_E))
        {
            world.camera.zoom -= 0.1 * world.camera.zoom;
        }




        BeginDrawing();
        ClearBackground(RAYWHITE);


        world.draw();


        world.drawChunkBorders();

        EndDrawing();
    }
}