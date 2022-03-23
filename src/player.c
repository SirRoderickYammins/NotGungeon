#include "player.h"
#include "raylib.h"
#include "raymath.h"
#include <stdio.h>

#define MOVEMENT_SPD 250.0f
#define RECOIL_SPD 1.f





/* Calculate the lengths of the sides of a right triangle between
the mouse cursor and the center of the player. */
Vector2 MouseDelta(Vector2 gunArcCenter){  

    Vector2 mousePosition = GetMousePosition();

    float dx = mousePosition.x - gunArcCenter.x;
    float dy = gunArcCenter.y - mousePosition.y;

    return (Vector2){dx, dy};

}


// Player recoil function for when fire button is pressed.

void PlayerRecoil(Player *player, float frameTime){

    Vector2 mouseDelta = MouseDelta(player->gunArc.origin);

    // Mouse Deltas
    float dx = mouseDelta.x;
    float dy = mouseDelta.y;



    // Apply recoil to position of player
    player->playerRect->x += Clamp(-dx * frameTime, -RECOIL_SPD, RECOIL_SPD);
    player->playerRect->y += Clamp(dy * frameTime, -RECOIL_SPD, RECOIL_SPD);
    player->gunArc.origin.x += Clamp(-dx * frameTime, -RECOIL_SPD, RECOIL_SPD);
    player->gunArc.origin.y += Clamp(dy * frameTime, -RECOIL_SPD, RECOIL_SPD);


}

Vector2 WeaponAngleDraw(Player *player, float rawMouseAngleRadians) {

    Vector2 mouseDelta = MouseDelta(player->gunArc.origin);

    float hypotenuse = player->gunArc.outerRadius;

    // Mouse Deltas
    float dx = mouseDelta.x;
    float dy = mouseDelta.y;

    // X and Y coordinates for triangle to calculate projectile vector
    float x;
    float y;

    if (dx > 0 && dy > 0) {
        x = hypotenuse * cosf(rawMouseAngleRadians) + player->gunArc.origin.x;
        y = player->gunArc.origin.y - hypotenuse * sinf(rawMouseAngleRadians);
        player->isFacingLeft = false;
    }

    if (dx < 0 && dy > 0) {
        x = player->gunArc.origin.x - hypotenuse * cosf(rawMouseAngleRadians);
        y = player->gunArc.origin.y + hypotenuse * sinf(rawMouseAngleRadians);
        player->isFacingLeft = true;
    }

    if (dx < 0 && dy < 0) {
        x = player->gunArc.origin.x - hypotenuse * cosf(rawMouseAngleRadians); 
        y = player->gunArc.origin.y + hypotenuse * sinf(rawMouseAngleRadians);
        player->isFacingLeft = true;
    }

    if (dx > 0 && dy < 0) {
        x = hypotenuse * cosf(rawMouseAngleRadians) + player->gunArc.origin.x;
        y = player->gunArc.origin.y - hypotenuse * sinf(rawMouseAngleRadians);
        player->isFacingLeft = false;
    }

    DrawRectangleV((Vector2){x, y}, (Vector2){20.f, 20.f}, WHITE);



    return (Vector2){x, y};

}


Vector2 RotationCalculator(Vector2 gunArcCenter){

    Vector2 mouseDelta = MouseDelta(gunArcCenter);

    float dx = mouseDelta.x;
    float dy = mouseDelta.y;

    /* Angle is a Vector2 because it returns an adjusted angle (for the weird Ring mechanic)
    and the raw angle from the arctan function. */

    Vector2 angle;



    // Quadrant 1 of unit cirlce
    if (dx > 0 && dy > 0) {
        angle = (Vector2){atanf(dy/dx) * (180/PI) + 90.0f, atanf(dy/dx)};
    }
    //Quadrant 2 of unit circle
    if (dx < 0 && dy > 0){
        angle = (Vector2){atanf(dy/dx) * (180/PI) - 90.0f, atanf(dy/dx)};
    }
    // Quadrant 3 of Unit Circle
    if (dx < 0 && dy < 0) {
        angle = (Vector2){atanf(dy/dx) * (180/PI) + 270.0f, atanf(dy/dx)};
    }
    // Quadrant 4 of Unit Circle
    if (dx > 0 && dy < 0) {
        angle = (Vector2){atanf(dy/dx) * (180/PI) + 90.0f, atanf(dy/dx)};
    }

    return angle;

}


void PlayerControl(Player *player, float frameTime) {

    player->playerRect->x = player->physicsBody->position.x;
    player->gunArc.origin.x = player->physicsBody->position.x;

    if (IsKeyDown(KEY_SPACE)) PlayerRecoil(player, frameTime);

    if(IsKeyDown(KEY_A)){
        PhysicsAddForce(player->physicsBody, (Vector2){-10.f, 0.f});
    }
    if(IsKeyDown(KEY_D)){
        player->playerRect->x += MOVEMENT_SPD * frameTime;
        player->gunArc.origin.x += MOVEMENT_SPD * frameTime;
    }
    if(IsKeyDown(KEY_W)){
        player->playerRect->y -= MOVEMENT_SPD * frameTime;
        player->gunArc.origin.y -= MOVEMENT_SPD * frameTime;
    }
    if(IsKeyDown(KEY_S)){
        player->playerRect->y += MOVEMENT_SPD * frameTime;
        player->gunArc.origin.y += MOVEMENT_SPD * frameTime;
    }


    WeaponAngleDraw(player, RotationCalculator(player->gunArc.origin).y);
    
    
}