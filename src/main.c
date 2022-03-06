#include "raylib.h"
#include "raymath.h"
#include "player.h"
#include <stddef.h>
#include <stdio.h>
#include "camera.h"





int main(void)
{
    const float w = 1600.0f;
    const float h = 1000.0f;
    InitWindow(w, h, "Bubby Space Invaders");

    Rectangle playerRect = {400.0f, 600.0f, 80.0f, 80.0f};

    Rectangle RoomBoundaries = {0.0f, 0.0f, w, h};

    Circle gunArc = {60.0f, 70.0f, 90.0f, 0.0f, (Vector2){playerRect.x + 40.0f, playerRect.y + 40.0f}};

    Player player = {0.0f, (Vector2){0.0f, 0.0f}, playerRect, gunArc};

    

    SetTargetFPS(60);

    SetMouseCursor(MOUSE_CURSOR_CROSSHAIR);
    SetMouseScale(1.0, 1.0);

    while (!WindowShouldClose()){

        float frameTime = GetFrameTime();
        
        BeginDrawing();


        DrawRectanglePro(player.playerRect, player.origin, 0.0f, RED);
        DrawRing(player.gunArc.origin, player.gunArc.innerRadius, player.gunArc.outerRadius, 
                player.gunArc.startAngle, player.gunArc.endAngle, 40, RED);
        PosUpdate(&player, RoomBoundaries, frameTime);

       
        
        ClearBackground(RAYWHITE);
        EndDrawing();

    }


    return 0;
}