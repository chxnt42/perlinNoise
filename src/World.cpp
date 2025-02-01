#include "World.h"
#include "Tile.h"
#include <cstddef>

World::World()
{
    seed = time(nullptr);

    camera.zoom = 1.0f;
    camera.offset = {0,0};
    camera.rotation = 0.0f;
    camera.target = {0,0};


    Tile::SetWorld(this);
}

World::~World()
{

}


void World::addChunk(int x, int y)
{
    chunks[std::make_pair(x, y)] = std::make_unique<Chunk>(Vector2i(x, y));
}

void World::draw()
{
    for(auto& chunk : chunks)
    {
        chunk.second->draw(camera);
    }
}

void World::drawChunkBorders()
{
    for(auto& chunk : chunks)
    {
        chunk.second->drawChunkBorder(camera);
    }
}

