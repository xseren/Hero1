#include "Item.h"

#include <string>
#include <iomanip>
#include <iostream>
using namespace std;
#include <ctime>
#include <cmath>

// *******************************************************************
// class Item
// *******************************************************************

Item::Item()
{ 
  hp = 0;
  mana = 0;
  str = 0;
  def = 0;
  magic = 0;
  arch = 0;
}

Item::Item(string t)
{
  hp = 5;
  mana = 5;
  str = 0;
  def = 5;
  magic = 0;
  arch = 0;

  int bonus = 10;
  int randBonus = 0;
  int perfectBonus = 100;
  int hpBonus = 0;

  hpBonus = (rand() % perfectBonus);
  randBonus = ((rand() % perfectBonus) + 1);

  if (randBonus == perfectBonus)
    tier = 'S';

  else if (randBonus >= (.8 * perfectBonus) && randBonus < perfectBonus)
	tier = 'A';

  else if (randBonus >= (.6 * perfectBonus) && randBonus < perfectBonus)
	tier = 'B';

  else if (randBonus >= (.4 * perfectBonus) && randBonus < perfectBonus)
	tier = 'C';

  else if (randBonus >= (.2 * perfectBonus) && randBonus < perfectBonus)
	tier = 'D';

  else
	tier = 'F';

  if (t == "Caster" || t == "Illusionist" || t == "Bloodmoon")
  {
    magic += bonus;
    magic += randBonus;
  }
  
  else if (t == "Sharpshooter" || t == "Tyrant" || t == "Monster")
  {
    arch += bonus;
    arch += randBonus;
  }
  
  else
  {
    str += bonus;
    str += randBonus;
  }
}
void Item::randStats(double &a, double &b, double &c, double &d, double &h, double &m)
{
  a += ((rand() % 50) + 75);
  b += ((rand() % 50) + 35);
  c += ((rand() % 50) + 35);

  d += (rand() % 50);
  h += (rand() % 50);
  m += (rand() % 50);

  itemTier(a, b, c, d, h, m);
}

void Item::itemTier(double &a, double &b, double &c, double &d, double &h, double &m)
{
  if ((a + d + h + m) >= 238 && (a + d + h + m) <= 285)
    tier = 'S';

  else if (((a + d + h + m) >= 250) && ((a + d + h + m) <= 300))
    tier = 'A';

  else if (((a + d + h + m) >= 175) && ((a + d + h + m) <= 250))
    tier = 'B';

  else if (((a + d + h + m) >= 150) && ((a + d + h + m) <= 175))
    tier = 'C';

  else if (((a + d + h + m) <= 50) && ((a + d + h + m) >= 75))
    tier = 'D';

  else
    tier = 'F';
}

void Item::randStats(double &a)
{
  a += ((rand() % 100) + 25);
}

int Item::randomize()
{
  return (rand() % 2);
}

void Item::boostItem()
{
  if (randomize() == 0)
    randStats(str, arch, magic, def, hp, mana);

  else if (randomize() == 1)
    randStats(arch, str, magic, def, hp, mana);

  else if (randomize() == 2)
    randStats(magic, str, arch, def, hp, mana);
}

void Item::showItem()
{
  cout << setw(8) << "Tier: " << tier << endl;
  cout << setw(8) << "HP: +" << hp << endl;
  cout << setw(8) << "Mana: +" << mana << endl;
  cout << setw(8) << "Def: +" << def << endl;

  cout << setw(8) << "Str: +" << str << endl;
  cout << setw(8) << "Magic: +" << magic << endl;
  cout << setw(8) << "Arch: +" << arch << endl;
}