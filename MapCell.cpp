#include <iostream>
#include "include/MapCell.h"

using namespace std;

MapCell::MapCell()
{
  id=0;
}

bool MapCell::IsBlocked()
{
  if(id=='1')
  {
    return true;
  }else
  {
    return false;
  }
}