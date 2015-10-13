#ifndef Item_h
#define Item_h

#include <string>
#include <iostream>
using namespace std;

struct Item
{
  char tier;
  
  double hp;
  double mana;
  
  double str;
  double magic;
  double arch;
  double def;

  Item();
  Item(string t);
  void showItem();
  void randStats(double &a, double &b, double &c, double &d, double &h, double &m);
  void randStats(double &a);
  int randomize();
  void boostItem();

  void itemTier(double &a, double &b, double &c, double &d, double &h, double &m);
};
#endif