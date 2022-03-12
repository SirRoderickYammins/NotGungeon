#ifdef PLAYER_H
#define PLAYER_H

#endif
#include "raylib.h"
#include "physac.h"

typedef struct Circle {
    float innerRadius;
    float outerRadius;
    float startAngle;
    float endAngle;
    Vector2 origin;
} Circle;

typedef struct Player {
    PhysicsBody playerPhysicsBody;
    Rectangle playerRect;
    Circle gunArc;

} Player;

void PlayerControl(Vector2 *playerPosition, float frameTime);
