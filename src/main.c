#include "raylib.h"
#include "raymath.h"
#include "player.h"
#include <stddef.h>
#include <stdio.h>
#include "camera.h"


#define PHYSAC_IMPLEMENTATION

#include "physac.h"



int main(void)
{
    const float w = 1600.0f;
    const float h = 1000.0f;
    InitWindow(w, h, "Bubby Space Invaders");

    Rectangle playerRect = {400.0f, 600.0f, 80.0f, 80.0f};

    Rectangle RoomBoundaries = {0.0f, 0.0f, w, h};

    Circle gunArc = {60.0f, 70.0f, 90.0f, 0.0f, (Vector2){playerRect.x + 40.0f, playerRect.y + 40.0f}};

    


    PhysicsBody roomFloor = CreatePhysicsBodyRectangle((Vector2){0, h}, w, 70.0f, 1.0f);
    PhysicsBody playerPhysicsBody = CreatePhysicsBodyRectangle((Vector2){w/2, h/2}, playerRect.width, playerRect.height, 1.0f);
    roomFloor->enabled = false;
    playerPhysicsBody->useGravity = false;

    Player player = {playerPhysicsBody, playerRect, gunArc};

    SetPhysicsGravity(0.0f, 1.0f);

    SetTargetFPS(GetMonitorRefreshRate(1));

    SetMouseCursor(MOUSE_CURSOR_CROSSHAIR);
    SetMouseScale(1.0, 1.0);

    InitPhysics();

    while (!WindowShouldClose()){

        float frameTime = GetFrameTime();
        
        BeginDrawing();

        DrawRectangleV(playerPhysicsBody->position, (Vector2){playerRect.width, playerRect.height}, RED);


        // DrawRectanglePro(player.playerRect, player.origin, 0.0f, RED);
        // DrawRing(player.gunArc.origin, player.gunArc.innerRadius, player.gunArc.outerRadius, 
        //          player.gunArc.startAngle, player.gunArc.endAngle, 40, RED);


        PlayerControl(&player, frameTime);

       
        
        ClearBackground(RAYWHITE);
        UpdatePhysics();
        EndDrawing();

    }

    ClosePhysics();

    return 0;
}