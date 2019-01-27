#include "map.h"
#include "texturemanager.h"
// TODO::Next is only tmp will replace it with external

    namespace SFGE {
        int lvl1[20][19] = {
        {1, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

        Map::Map()
        {
            waterTex = TextureManager::loadTexture("/home/samuil/projects/supreme-fiesta-game-engine/assets/water.png");
            dirtTex = TextureManager::loadTexture("/home/samuil/projects/supreme-fiesta-game-engine/assets/dirt.png");
            grassTex = TextureManager::loadTexture("/home/samuil/projects/supreme-fiesta-game-engine/assets/grass.png");

            src.w = 32;
            src.h = 32;
            src.x = 0;
            src.y = 0;
            dst.w = src.w;
            dst.h = src.h;
            dst.x = 0;
            dst.y = 0;

            Map::loadMap();
        }

        void Map::loadMap()
        {
            int row;
            int col;
            for (row = 0; row < 20; row++)
                for (col = 0; col < 19; col++)
                    map[row][col] = lvl1[row][col];
        }

        void Map::drawMap()
        {
            int row;
            int col;
            int type = 0;
        for (row = 0; row < 20; row++) {
                for (col = 0; col < 19; col++) {
                    type = map[row][col];

                    dst.x = col * src.w;
                    dst.y = row * src.h;

                    switch (type) {
                        case 0:
                            TextureManager::draw(waterTex, src, dst);
                            break;
                        case 1:
                            TextureManager::draw(grassTex, src, dst);
                            break;
                        case 2:
                            TextureManager::draw(dirtTex, src, dst);
                            break;
                    }
                }
            }
        }
}
