#pragma once
#include "Chunk.h"
#include <unordered_map>
#include "Globals.h"
#include "Tile.h"
#include "Util.h"
#include "raylib.h"
#include <memory>



class World
{
public:
    std::unordered_map<std::pair<int, int>, std::unique_ptr<Chunk>, pair_hash> chunks; // std::pair is stored in the order x,y not y,x



    Tile* getTile(int globalX, int globalY) {
        std::pair<int, int> chunkCoord = getChunkCoordFromGlobal(globalX, globalY);
        std::pair<int, int> localCoord = getLocalCoordFromGlobal(globalX, globalY);
        
        if (chunks.count(chunkCoord) == 0) {
            return nullptr;
        }
        
        return chunks[chunkCoord]->getTile(localCoord.first, localCoord.second);
    }


    std::pair<int, int> getChunkCoordFromGlobal(int globalX, int globalY) {
        return {
            std::floor(globalX / CHUNK_SIZE_TILES),
            std::floor(globalY / CHUNK_SIZE_TILES)
        };
    }
    
    std::pair<int, int> getLocalCoordFromGlobal(int globalX, int globalY) {
        return {
            ((globalX % CHUNK_SIZE_TILES) + CHUNK_SIZE_TILES) % CHUNK_SIZE_TILES,
            ((globalY % CHUNK_SIZE_TILES) + CHUNK_SIZE_TILES) % CHUNK_SIZE_TILES
        };
    }

    Tile* getNeighborTile(int globalX, int globalY, Direction dir) {
        switch (dir) {
            case Direction::Right:
                return getTile(globalX + 1, globalY);
            case Direction::Left:
                return getTile(globalX - 1, globalY);
            case Direction::Up:
                return getTile(globalX, globalY - 1);
            case Direction::Down:
                return getTile(globalX, globalY + 1);
        }
    }


    



    void draw();   
    void drawChunkBorders();
    void addChunk(int x,int y);
    int seed;

    Camera2D camera;


    World();
    ~World();


  

private:

};

