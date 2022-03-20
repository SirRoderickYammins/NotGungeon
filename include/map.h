#ifdef MAP_H
#define MAP_H

#endif


typedef struct Tile {
    int ID;
    int TileMapSequence_X;
    int TileMapSequence_Y;

} Tile;

typedef enum TileID
{
    GOLD_BAG_X = 1,
    GOLD_BAG_Y = 0,
    BARREL_X = 2,
    BARREL_Y = 0,
    BOOKCASE_X = 3,
    BOOKCASE_Y = 0,
    STAIRS_X = 1,
    STAIRS_Y = 3,
    FLOOR1_X = 2,
    FLOOR1_Y = 1,
    FLOOR2_X = 4,
    FLOOR2_Y = 2,
    DUNGEONWALL_X = 6,
    DUNGEONWALL_Y = 4,
    WALLTOP1_X = 4,
    WALLTOP1_Y = 5,
    WALLTOP2_X = 2,
    WALLTOP2_Y = 6,

}
TileID;

typedef struct MapPiece {
    int x;
    int y;
} MapPiece;

extern const float w;
extern const float h;


void Map_CreateRoom(Texture2D *tileMap, int RoomID);


