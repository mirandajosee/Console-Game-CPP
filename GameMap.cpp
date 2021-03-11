#include <iostream>
#include <fstream>
#include "include/GameMap.h"
#include <string>

using namespace std;

GameMap::GameMap()
{
  PlayerCell=NULL;
  LoadMapFromFile();
  isGameOver = false;
}

void GameMap::Draw()
{
  for (int i=0; i<15; i++)
  {
    for (int p=0; p<10; p++)
    {
      cout << cells[i][p].id;
    }
    cout << endl;
  }
}

bool GameMap::SetPlayerCell(int PlayerX, int PlayerY)
{
  if(!cells[PlayerY][PlayerX].IsBlocked())
  {
    if(cells[PlayerY][PlayerX].id=='X')
    {
      DrawVictory();
      isGameOver=true;
      return true;
    }else
    {
      if(PlayerCell!=NULL)
      {
        PlayerCell->id=' ';
      }
      PlayerCell = &cells[PlayerY][PlayerX];
      PlayerCell->id='H';
    }
    return true;
  //cout << "Las coordenas del jugador estan en "<< PlayerX<< "," <<PlayerY<< endl;
  }else
  {
    return false;
  }
}

void GameMap::DrawIntro()
{
  ifstream FileCreated("Intro.txt");
  if(!FileCreated.is_open())
  {
    ofstream FileCreated("Intro.txt");
    if(!FileCreated.is_open())
    {
    cout << "FATAL ERROR: Map Intro could not be created"<< endl;
    }
  }
  string line;
  ifstream MyFile("Intro.txt");

  if(MyFile.is_open())
  {
    while(getline(MyFile,line))
    {
      cout << line << endl;
    }
    cin >> line;
  }
  else
  {
    cout << "FATAL ERROR: Intro file is missing"<< endl;
  }
}

void GameMap::DrawVictory()
{
  ifstream FileCreated("Victory.txt");
  if(!FileCreated.is_open())
  {
    ofstream FileCreated("Victory.txt");
    if(!FileCreated.is_open())
    {
    cout << "FATAL ERROR: Victory text could not be created"<< endl;
    }
  }
  string line;
  ifstream MyFile("Victory.txt");

  if(MyFile.is_open())
  {
    while(getline(MyFile,line))
    {
      cout << line << endl;
    }
    cin >> line;
  }
  else
  {
    cout << "FATAL ERROR: Victory text is missing"<< endl;
  }
}

void GameMap::LoadMapFromFile()
{
  ifstream FileCreated("Map.txt");
  if(!FileCreated.is_open())
  {
    ofstream FileCreated("Map.txt");
    if(!FileCreated.is_open())
    {
    cout << "FATAL ERROR: Map file could not be created"<< endl;
    }
  }
  string line;
  int row=0;
  ifstream MyFile("Map.txt");

  if(MyFile.is_open())
  {
    while(getline(MyFile,line))
    {
      for(int p=0; p<line.length();p++)
      {
        if(line[p]=='0')
        {
        cells[row][p].id=' ';
        }else{
          cells[row][p].id=line[p];
        }
      }

      row++;
    }
  }
  else
  {
    cout << "FATAL ERROR: Map file is missing"<< endl;
  }
}