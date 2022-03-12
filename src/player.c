#include "player.h"
#include "raylib.h"
#include "raymath.h"
#include <stdio.h>

#define MOVEMENT_SPD 350.0f


/* Calculate the lengths of the sides of a right triangle between
the mouse cursor and the center of the player. */
Vector2 MouseDelta(Vector2 gunArcCenter){  

    Vector2 mousePosition = GetMousePosition();

    float dx = mousePosition.x - gunArcCenter.x;
    float dy = gunArcCenter.y - mousePosition.y;

    return (Vector2){dx, dy};

}

Vector2 WeaponAngle(Circle gunArc, float rawMouseAngleRadians) {

    Vector2 mouseDelta = MouseDelta(gunArc.origin);

    float hypotenuse = gunArc.outerRadius;

    // Mouse Deltas
    float dx = mouseDelta.x;
    float dy = mouseDelta.y;

    // X and Y coordinates for triangle to calculate projectile vector
    float x;
    float y;

    if (dx > 0 && dy > 0) {
        x = hypotenuse * cosf(rawMouseAngleRadians) + gunArc.origin.x;
        y = gunArc.origin.y - hypotenuse * sinf(rawMouseAngleRadians);
    }

    if (dx < 0 && dy > 0) {
        x = gunArc.origin.x - hypotenuse * cosf(rawMouseAngleRadians);
        y = gunArc.origin.y + hypotenuse * sinf(rawMouseAngleRadians);
    }

    if (dx < 0 && dy < 0) {
        x = gunArc.origin.x - hypotenuse * cosf(rawMouseAngleRadians); 
        y = gunArc.origin.y + hypotenuse * sinf(rawMouseAngleRadians);
    }

    if (dx > 0 && dy < 0) {
        x = hypotenuse * cosf(rawMouseAngleRadians) + gunArc.origin.x;
        y = gunArc.origin.y - hypotenuse * sinf(rawMouseAngleRadians);
    }

    DrawRectangle(x, y, 20, 20, BLACK);



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





void PlayerControl(Vector2 *playerPosition, float frameTime) {

    if(IsKeyDown(KEY_A)){
        playerPosition->x -= MOVEMENT_SPD * frameTime;
        
    }
    if(IsKeyDown(KEY_D)){
        playerPosition->x += MOVEMENT_SPD * frameTime;
    }
    if(IsKeyDown(KEY_W)){
        playerPosition->y -= MOVEMENT_SPD * frameTime;
    }
    if(IsKeyDown(KEY_S)){
        playerPosition->y += MOVEMENT_SPD * frameTime;
    }



    
    
}