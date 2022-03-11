#include "raylib.h"
#include "raymath.h"
#include "player.h"
#include <stddef.h>
#include <stdio.h>
#include "camera.h"
#include "map.h"


#define PHYSAC_IMPLEMENTATION

#include "physac.h"



int main(void)
{
    const float w = 1600.0f;
    const float h = 1000.0f;
    InitWindow(w, h, "Bubby Dungeons");

    Texture2D tileMap = LoadTexture("../resources/tilemap.png");

    int tileSpace = tileMap.width/9;

    Rectangle tilePiece = {tileSpace, 0, tileMap.height/8, tileMap.width/9}; 
    Rectangle tileFloor = {tileSpace*2, tileSpace, tileMap.height/8, tileMap.width/9}; 

    InitPhysics();

    while (!WindowShouldClose()){

        float frameTime = GetFrameTime();

        BeginDrawing();
        DrawTextureRec(tileMap, tileFloor, (Vector2){400.f, 400.f}, WHITE);
        DrawTextureRec(tileMap, tilePiece, (Vector2){400.f, 400.f}, WHITE);
        
       
        
        ClearBackground(BLACK);
        UpdatePhysics();
        EndDrawing();

    }

    ClosePhysics();

    return 0;
}