#include "raylib.h"
#include "map.h"
#include <stdio.h>

#define MAPSTART_X 3
#define MAPSTART_Y 3

const float w = 1600.0f;
const float h = 1000.0f;

// Static Room Generation (This is a very disgusting function. Need to clean this up)
void Map_CreateRoom(Texture2D *tileMap, int RoomID){

    int CellWidth = tileMap->width / 9;
    int CellHeight = tileMap->height / 8;

    // Setting Dungeon Wall Rect

    Rectangle DungeonWall = {DUNGEONWALL_X * CellWidth, DUNGEONWALL_Y * CellHeight, CellWidth, CellHeight};
    Rectangle Stairs = {STAIRS_X * CellWidth, STAIRS_Y * CellHeight, CellWidth, CellHeight};
    Rectangle Floor1 = {FLOOR1_X * CellWidth, FLOOR1_Y * CellHeight, CellWidth, CellHeight};
    Rectangle Floor2 = {FLOOR2_X * CellWidth, FLOOR2_Y * CellHeight, CellWidth, CellHeight};
    Rectangle Walltop1 = {WALLTOP1_X * CellWidth, WALLTOP1_Y * CellHeight, CellWidth, CellHeight};
    Rectangle Walltop2 = {WALLTOP2_X * CellWidth, WALLTOP2_Y * CellHeight, CellWidth, CellHeight};

    for (int i = MAPSTART_X; i < 19; i++)
    {
        Vector2 walltop2 = {CellWidth * i, CellHeight * (MAPSTART_Y - 2)};
        Vector2 DungeonWallVec = {CellWidth * i, CellHeight * (MAPSTART_Y - 1)};

        for (int j = MAPSTART_Y - 1; j < 11; j++){

            Vector2 floorPos = {CellWidth * i, CellHeight * j};
            Vector2 walltop = {CellWidth * (MAPSTART_X - 1), CellHeight * j};

            DrawTextureRec(*tileMap, Floor1, floorPos, WHITE);

            if (j == 5 && i == 5){

                DrawTextureRec(*tileMap, Stairs, floorPos, WHITE);

            }

            if (j == 8 && i == 8){
                DrawTextureRec(*tileMap, Floor2, floorPos, WHITE);
            }

            DrawTextureRec(*tileMap, Walltop1, walltop, WHITE);
        }

        DrawTextureRec(*tileMap, Walltop2, walltop2, WHITE);
        DrawTextureRec(*tileMap, DungeonWall, DungeonWallVec, WHITE);
    }
}