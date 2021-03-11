#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "MapCell.h"

class GameMap
{
    public:
           GameMap();
           MapCell* PlayerCell;
           MapCell cells [15][10];

           void Draw();
           void DrawIntro();
           void DrawVictory();

           //Este función obtiene las coordenadas de Player y actualiza las coordenadas
           bool SetPlayerCell(int PlayerX, int PlayerY);
           bool isGameOver;

    protected:

    void LoadMapFromFile();


    private:
};

#endif //GAMEMAP_H