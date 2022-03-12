#ifdef MAP_H
#define MAP_H

#endif


typedef struct Tile {
    int ID;
    int TileMapSequence_X;
    int TileMapSequence_Y;

} Tile;

typedef enum TileID {
    GOLD_BAG_X = 1,
    GOLD_BAG_Y = 0,
    BARREL_X = 2,
    BARREL_Y = 0,
    BOOKCASE_X = 3,
    BOOKCASE_Y = 0,

} TileID;

