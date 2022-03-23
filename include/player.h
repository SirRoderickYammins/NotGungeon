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
    Rectangle *playerRect;
    Circle gunArc;
    bool isFacingLeft;
    PhysicsBody physicsBody;

} Player;

void PlayerControl(Player *player, float frameTime);

extern Texture2D crossHair;