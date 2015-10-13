#ifndef Monster_h
#define Monster_h

#include "Hero.h"

#include <iostream>
using namespace std;
#include <ctime>
#include <cmath>

struct Monster : public Hero
{
  Monster* next;
  Monster();
  
  void slime(); // 1
  void goblin(); // 3
  
  void harpy(); // 13
  void banshee(); // 15
  
  void orc(); // 20
  void cerberus(); // 24
  
  void chimera(); // 27
  void dragon(); // 30
};

Monster::Monster()
{
  rank = "Monster";
  int whatType = rand() % 11;
  switch (whatType)
  {
    case 0:
    case 1:
    case 2:
      slime();
      break;
    case 3:
    case 4:
      goblin();
      break;
    case 5:
      harpy();
      break;
    case 6:
      banshee();
      break;
    case 7:
    case 8:
      orc();
      break;
    case 9:
      cerberus();
      break;
    case 10:
      chimera();
      break;
    case 11:
      dragon();
      break;
  }
}

void Monster::slime()
{
  type = "Slime" ;
  level = 1;
  exp = 20;
  mHp = 150;
  cHp = 150;
  mMana = 50;
  cMana = 50;
  str = 20;
  def = 15;
  magic = 0;
  arch = 0;
}

void Monster::dragon()
{
  type = "Dragon" ;
  level = 30;
  exp = 1500;
  mHp = 800;
  cHp = 800;
  mMana = 200;
  cMana = 200;
  str = 70;
  def = 70;
  magic = 100;
  arch = 0;
}

void Monster::orc()
{
  type = "Orc" ;
  level = 20;
  exp = 1200;
  mHp = 500;
  cHp = 500;
  mMana = 50;
  cMana = 50;
  str = 100;
  def = 100;
  magic = 0;
  arch = 0;
}

void Monster::harpy()
{
  type = "Harpy" ;
  level = 13;
  exp = 230;
  mHp = 375;
  cHp = 375;
  mMana = 200;
  cMana = 200;
  str = 40;
  def = 25;
  magic = 0;
  arch = 0;
}

void Monster::banshee()
{
  type = "Banshee" ;
  level = 15;
  exp = 250;
  mHp = 450;
  cHp = 450;
  mMana = 200;
  cMana = 200;
  str = 0;
  def = 60;
  magic = 0;
  arch = 80;
}

void Monster::goblin()
{
  type = "Goblin" ;
  level = 3;
  exp = 25;
  mHp = 80;
  cHp = 80;
  mMana = 20;
  cMana = 20;
  str = 20;
  def = 5;
  magic = 0;
  arch = 0;
}

void Monster::chimera()
{
  type = "Chimera" ;
  level = 27;
  exp = 1000;
  mHp = 700;
  cHp = 700;
  mMana = 200;
  cMana = 200;
  str = 0;
  def = 70;
  magic = 70;
  arch = 70;
}

void Monster::cerberus()
{
  type = "Cerberus" ;
  level = 24;
  exp = 1250;
  mHp = 750;
  cHp = 750;
  mMana = 200;
  cMana = 200;
  str = 65;
  def = 50;
  magic = 100;
  arch = 0;
}
#endif