#include "raylib.h"
#include "raymath.h"
#include "player.h"
#include <stddef.h>
#include <stdio.h>
#include "camera.h"
#include "map.h"


#define PHYSAC_IMPLEMENTATION

#include "physac.h"

Texture2D crossHair;

int main(void)
{
    const float w = 1600.0f;
    const float h = 1000.0f;
    InitWindow(w, h, "Bubby Dungeons");

    Texture2D crossHair = LoadTexture("../resources/ui/crosshair_1.png");

    Texture2D tileMap = LoadTexture("../resources/tilemap.png");
    Texture2D playerTexture = LoadTexture("../resources/spritesheet.png");

    float Player_TileSpaceY = playerTexture.height/9;
    float Player_TileSpaceX = playerTexture.width/28;

    Rectangle playerPiece = {0, Player_TileSpaceY*5, 72.f, 72.f};
    Rectangle playerRect = {400.0f, 400.0f, Player_TileSpaceX, Player_TileSpaceY};

    Circle gunArc = {70.0f, 80.0f, 90.0f, 0.0f, (Vector2){playerRect.x + Player_TileSpaceX/2, playerRect.y + Player_TileSpaceY/2}};
    Player Bubby = {&playerRect, gunArc};

    int tileSpace = tileMap.width/9;

    SetTargetFPS(144);

    Rectangle tilePiece = {tileSpace, 0, tileMap.height/8, tileMap.width/9}; 
    Rectangle tileFloor = {tileSpace*2, tileSpace, tileMap.height/8, tileMap.width/9}; 

    int currentFrame = 0;
    int framesCounter = 0;
    int framesSpeed = 9;


    InitPhysics();

    while (!WindowShouldClose()){

        float frameTime = GetFrameTime();

        framesCounter++;

        if (IsKeyPressed(KEY_A) && playerPiece.width > 0) playerPiece.width = -playerPiece.width;

        if (IsKeyPressed(KEY_D) && playerPiece.width < 0) playerPiece.width = -playerPiece.width;

        if (framesCounter >= (144/framesSpeed)){
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

        PlayerControl(&Bubby, frameTime);

        BeginDrawing();
        

            DrawTextureRec(tileMap, tileFloor, (Vector2){400.f, 400.f}, WHITE);
            DrawTextureRec(tileMap, tilePiece, (Vector2){400.f, 400.f}, WHITE);
            DrawTextureRec(playerTexture, playerPiece, (Vector2){playerRect.x, playerRect.y}, WHITE);
       
        
            ClearBackground(BLACK);
            UpdatePhysics();
        EndDrawing();

    }

    ClosePhysics();

    return 0;
}