#ifdef PLAYER_H
#define PLAYER_H

#endif
#include "raylib.h"

typedef struct Circle {
    float innerRadius;
    float outerRadius;
    float startAngle;
    float endAngle;
    Vector2 origin;
} Circle;

typedef struct Player {
    float speed;
    Vector2 origin;
    Rectangle playerRect;
    Circle gunArc;

} Player;

void PosUpdate(Player *player, Rectangle RoomBoundaries, float frameTime);
