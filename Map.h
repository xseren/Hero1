#ifndef Map_h
#define Map_h

#include "Monster.h"

#include <iostream>
using namespace std;
#include <ctime>
#include <cmath>

class Map : public Monster
{
  Monster *top;
public:
  Map();
  ~Map();
  void spawn();
  bool isEmpty() const;
  void pop();
};

Map::Map()
{
  top = 0;
}

Map::~Map()
{
  Monster *temp = top;
  while (top != 0)
  {
    temp = top;
    top = top->next;
    delete temp;
  }
}

void Map::spawn()
{
  Monster *newMonster = new Monster;
  newMonster->next = top;
  top = newMonster;
}

bool Map::isEmpty() const
{
  return top == 0;
}

void Map::pop()
{
  if (top != 0)
  {
    Monster *temp = top;
    top = top->next;
    delete temp;
  }
}
#endif