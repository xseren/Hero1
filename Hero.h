#ifndef Hero_h
#define Hero_h

#include "Item.h"

struct Hero : public Item
{
  string type;
  string rank;
  
  int level;
  int exp;
  int gold;
  
  int mHp;
  int cHp;
  
  int mMana;
  int cMana;
  
  int str;
  int magic;
  int arch;
  int def;

  Item weapon;
  void setWeapon();
  
  Item shield;
  void setShield();
  
  Item vest;
  void setVest();
  
  Item legs;
  void setLegs();
  
  Item cape;
  void setCape();

  Hero();
  Hero(string t);
  void showHero();
  void showEnemy();
  void ran();

  void caster();  
  void bloodmoon();
  void illusionist();

  void paladin();
  void berserker();

  void sharpshooter();

  void demon();
  void tyrant();

  void rankUp();
  void gainExp(int x);
  void levelUp();

  void setHp(double x);
  void setMana(double x);
  
  virtual int basicDmg();
  virtual int manaDmg();
  virtual int getHeal();
  void heal();
  void manaRegen();
  
  void addInvy(Item add);
  void dropItem(Item drop);
};
#endif