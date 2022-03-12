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

    Texture2D playerTexture = LoadTexture("../resources/spritesheet.png");
    float Player_TileSpaceY = playerTexture.height/9;
    float Player_TileSpaceX = playerTexture.width/28;

    Rectangle playerPiece = {0, Player_TileSpaceY*5, 72.f, 72.f};

    int tileSpace = tileMap.width/9;

    SetTargetFPS(60);

    Rectangle tilePiece = {tileSpace, 0, tileMap.height/8, tileMap.width/9}; 
    Rectangle tileFloor = {tileSpace*2, tileSpace, tileMap.height/8, tileMap.width/9}; 

    int currentFrame = 0;
    int framesCounter = 0;
    int framesSpeed = 9;

    Vector2 playerPosition = {500.f, 500.f};


    InitPhysics();

    while (!WindowShouldClose()){

        float frameTime = GetFrameTime();

        framesCounter++;

        if (framesCounter >= (60/framesSpeed)){
            framesCounter = 0;
            currentFrame++;

            if (currentFrame > 5) currentFrame = 0;

            playerPiece.x = (float)currentFrame*Player_TileSpaceX;

            if (IsKeyDown(KEY_W) || IsKeyDown(KEY_A) || IsKeyDown(KEY_D) || IsKeyDown(KEY_S)) {
                playerPiece.y = Player_TileSpaceY*6;
            } else{
                playerPiece.y = Player_TileSpaceY*5;
            }
        }

        PlayerControl(&playerPosition, frameTime);

        BeginDrawing();
        

        
        DrawTextureRec(tileMap, tileFloor, (Vector2){400.f, 400.f}, WHITE);
        DrawTextureRec(tileMap, tilePiece, (Vector2){400.f, 400.f}, WHITE);
        DrawTextureRec(playerTexture, playerPiece, playerPosition, WHITE);
       
        
        ClearBackground(BLACK);
        UpdatePhysics();
        EndDrawing();

    }

    ClosePhysics();

    return 0;
}