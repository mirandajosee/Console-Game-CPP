#include <iostream>
#include "include/Player.h"
#include "Player.cpp"
#include "include/MapCell.h"
#include "MapCell.cpp"
#include "include/GameMap.h"
#include "GameMap.cpp"

using namespace std;

int main()
{
    GameMap Map;
    Player Hero;

    Map.DrawIntro();
    Map.Draw();

        while (Map.isGameOver == false)
    {
      //Aquí es el loop de nuestro juego
      //Se recibe un input del jugador
      cout << "Introduce el comando de movimiento ('w','a','s' o 'd')"<<endl;
      Hero.CallInput();

      //Actualizamos de información Heroe a mapa
      if(Map.SetPlayerCell(Hero.GetXAxis(), Hero.GetYAxis()))
      {
        Map.Draw();
      }else
      {
        Hero.ResetToSafePosition();
        Map.Draw();
      }

      //Aquí se dibuja el mapa
      
    }

    return 0;
}