#include "Tile.h"
#include "Globals.h"
#include "raylib.h"

#include "Chunk.h"

#include "World.h"


Tile::~Tile()
{

}


void Tile::draw(const Camera2D& cam)
{


     Vector2 chunkWorldPos = {
        parentChunk->position.x * CHUNK_SIZE_TILES * (float)TILE_SIZE,
        parentChunk->position.y * CHUNK_SIZE_TILES * (float)TILE_SIZE
    };



     Vector2 tileWorldPos = {
                    chunkWorldPos.x + (localPosition.x * TILE_SIZE),
                    chunkWorldPos.y + (localPosition.y * TILE_SIZE)
                };
                
                // Convert to screen coordinates
                Vector2 screenPos = GetWorldToScreen2D(tileWorldPos, cam);
                float scaledTileSize = TILE_SIZE * cam.zoom;
                

                int drawX = (int)screenPos.x;
                int drawY = (int)screenPos.y;


                if(type == Tiles::Stone)
                {
                    DrawRectangle(drawX ,drawY, 
                            scaledTileSize+1, scaledTileSize+1, BLACK);
                }
}



Tile* Tile::getNeighbor(Direction dir)
{
    return Tile::world->getNeighborTile(parentChunk->position.x * CHUNK_SIZE_TILES + localPosition.x, parentChunk->position.y * CHUNK_SIZE_TILES + localPosition.y, dir);
}

World* Tile::world = nullptr; 