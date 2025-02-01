#include "Chunk.h"
#include "Globals.h"
#include "Tile.h"
#include "Util.h"
#include "raylib.h"


Chunk::Chunk(Vector2i pos)
{
    position = pos;

    tiles.resize(size, std::vector<Tile>(size));
}


Chunk::~Chunk()
{

}


void Chunk::draw(const Camera2D& cam)
{
    // Calculate chunk's world position once
    Vector2 chunkWorldPos = {
        position.x * CHUNK_SIZE_TILES * (float)TILE_SIZE,
        position.y * CHUNK_SIZE_TILES * (float)TILE_SIZE
    };
    
    for(int y = 0; y < size; y++)
    {
        for(int x = 0; x < size; x++)
        {
            if(tiles[x][y].valid)
            {
                tiles[x][y].draw(cam);
            }
        }
    }
}

void Chunk::drawChunkBorder(const Camera2D& cam)
{
    Vector2 worldPos = {
        position.x * (float)CHUNK_SIZE_TILES * CHUNK_SIZE_TILES,
        position.y * (float) CHUNK_SIZE_TILES * CHUNK_SIZE_TILES
    };
    


    // Convert to screen space
    Vector2 screenPos = GetWorldToScreen2D(worldPos, cam);
    
    // Calculate chunk size in screen space
    float chunkScreenSize = (CHUNK_SIZE_TILES * TILE_SIZE) * cam.zoom;
    
    DrawRectangleLines(
        (int)screenPos.x,
        (int)screenPos.y, 
        chunkScreenSize + 1,
        chunkScreenSize + 1,
        RED
    );
}


void Chunk::generateChunkTiles(FastNoise::SmartNode<FastNoise::FractalFBm>& noise,int seed,float frequency)
{
    for(int y = 0; y < size; y++)
    {
        for(int x = 0; x < size; x++)
        {
            float value = noise->GenSingle2D(((position.x * size) + x) * frequency , ((position.y * size) + y) * frequency, seed); //this function needs MANUAL frequency or else will return 0 every time
            if(value > 0.1)
            {
    
                tiles[y][x] = Tile(this, Vector2i(x, y), Tiles::Stone);

            }
        }
    }


}


int Chunk::size = 16;