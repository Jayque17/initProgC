#ifndef POLY_H
#define POLY_H
#define TAILLE_X   512
#define TAILLE_Y   512
typedef  struct {
  int x;
  int y;
} Point ;

typedef struct cellulePoint {
  Point p;
  struct cellulePoint *suivant;
}CellulePoint,*ListePoint;
#endif
