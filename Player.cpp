#include <iostream>
#include "include/Player.h"

using namespace std;

Player::Player()
{
    x=1;
    y=1;
}

int Player::GetXAxis()
{
    return x;
}

int Player::GetYAxis()
{
    return y;
}

void Player::CallInput()
{
    char UserInput = ' ';
    cin >> UserInput;
    
    lastY=y;
    lastX=x;
    switch(UserInput)
    {
        case 'w':
         y=((y - 1)%15+15)%15;
         //cout << "Arriba"<<endl;
         break;
        case 's':
         y=(y + 1)%15;
         //cout << "Abajo"<<endl;
        break;
        case 'd':
         x=(x + 1)%10;
         //cout << "Derecha"<<endl;
         break;
        case 'a':
         x=((x - 1)%10+10)%10;
         //cout << "Izquierda"<<endl;
         break;
        default:
         //cout << "Tecla incorrecta"<< endl;
         break;
    }

    //cout << "Mi jugador esta en la coord. " << x << ","<< y << endl;
}

void Player::ResetToSafePosition()
{
    x=lastX;
    y=lastY;
}