#include "Hero.h"
// *******************************************************************
// class Hero
// *******************************************************************

void Hero::showHero()
{
  cout << "Class: " << type << endl;
  
  cout << "HP: " << cHp << "/" << mHp << endl;
  cout << "Mana: " << cMana << "/" << mMana << endl;
  cout << "Def: " << def << endl;

  cout << "Str: " << str << endl;
  cout << "Magic: " << magic << endl;
  cout << "Arch: " << arch << endl;
}

void Hero::showEnemy()
{
  cout << "                                                    Class: " << type << endl;
  
  cout << "                                                    HP: " << cHp << "/" << mHp << endl;
  cout << "                                                    Mana: " << cMana << "/" << mMana << endl;
  cout << "                                                    Def: " << def << endl;

  cout << "                                                    Str: " << str << endl;
  cout << "                                                    Magic: " << magic << endl;
  cout << "                                                    Arch: " << arch << endl;
}

Hero::Hero()
{
  type = "Bandits";
  rank = "Regular" ;
  level = 1;
  exp = 0;
  gold = 0;
  mHp = 100;
  cHp = 100;
  mMana = 100;
  cMana = 100;
  str = 10;
  def = 10;
  magic = 10;
  arch = 10;
}

Hero::Hero(string t)
{
  if (t == "Sharpshooter")
    sharpshooter();
		
  else if (t ==  "Caster")
    caster();
		
  else if (t ==  "Paladin")
    paladin();
		
  else if (t == "Berserker")
    berserker();
		
  else if (t == "Bloodmoon")
    bloodmoon();
		
  else if (t ==  "Illusionist")
    illusionist();
		
  else if (t ==  "Demon")
    demon();
		
  else if (t == "Tyrant")
    tyrant();
	
  else
  {
    type = "Bandits";
    rank = "Regular" ;
    level = 1;
    exp = 0;
    mHp = 100;
    cHp = 100;
    mMana = 100;
    cMana = 100;
    str = 10;
    def = 10;
    magic = 10;
    arch = 10;
  }
}

void Hero::caster()
{
  type = "Caster";
  rank = "Regular" ;
  level = 1;
  exp = 0;
  mHp = 100;
  cHp = 100;
  mMana = 100;
  cMana = 100;
  str = 5;
  def = 10;
  magic = 25;
  arch = 0;
}

void Hero::bloodmoon()
{
  type = "Bloodmoon";
  rank = "Regular" ;
  level = 1;
  exp = 0;
  mHp = 100;
  cHp = 100;
  mMana = 50;
  cMana = 50;
  str = 20;
  def = 10;
  magic = 20;
  arch = 0;
}

void Hero::illusionist()
{
  type = "Illusionist";
  rank = "Regular" ;
  level = 1;
  exp = 0;
  mHp = 100;
  cHp = 100;
  mMana = 75;
  cMana = 75;
  str = 0;
  def = 25;
  magic = 20;
  arch = 0;
}

void Hero::paladin()
{
  type = "Paladin";
  rank = "Regular" ;
  level = 1;
  exp = 0;
  mHp = 100;
  cHp = 100;
  mMana = 100;
  cMana = 100;
  str = 25;
  def = 10;
  magic = 5;
  arch = 0;
}

void Hero::berserker()
{
  type = "Berserker";
  rank = "Regular" ;
  level = 1;
  exp = 0;
  mHp = 150;
  cHp = 150;
  mMana = 75;
  cMana = 75;
  str = 30;
  def = 5;
  magic = 0;
  arch = 0;
}

void Hero::sharpshooter()
{
  type = "Sharpshooter";
  rank = "Regular" ;
  level = 1;
  exp = 0;
  mHp = 100;
  cHp = 100;
  mMana = 100;
  cMana = 100;
  str = 10;
  def = 10;
  magic = 0;
  arch = 25;
}

void Hero::demon()
{
  type = "Demon";
  rank = "Regular" ;
  level = 1;
  exp = 0;
  mHp = 150;
  cHp = 150;
  mMana = 75;
  cMana = 75;
  str = 5;
  def = 25;
  magic = 20;
  arch = 5;
}

void Hero::tyrant()
{
  type = "Tyrant";
  rank = "Regular" ;
  level = 1;
  exp = 0;
  mHp = 125;
  cHp = 125;
  mMana = 50;
  cMana = 50;
  str = 20;
  def = 10;
  magic = 0;
  arch = 15;
}

void Hero::rankUp()
{
  if (rank == "Regular")
    rank = "Novice";

  else if (rank == "Novice")
    rank = "Guided";

  else if (rank == "Guided")
    rank = "Disciplined";

  else if (rank == "Disciplined")
    rank = "Swift";

  else if (rank == "Swift")
    rank = "Heroic";

  else if (rank == "Heroic")
    rank = "Legendary";

  else
    rank = "Regular";
}

void Hero::gainExp(int x)
{
  exp += x;
  for (int i = 0; i < exp; i++)
  {
    if (exp == level * 10)
    {
      levelUp();
      exp = 0;
    }
  }
}

void Hero::levelUp()
{
  level += 1;
  cout << "Level Up!" << endl;

  if (type == "Caster" || type == "Illusionist" || type == "Bloodmoon")
  {
    mHp += 10;
    cHp += 10;
    mMana += 10;
    cMana += 10;
    magic += 10;
    def += 5;
  }
  
  else if (type == "Paladin" || type == "Berserker")
  {
    mHp += 15;
    cHp += 15;
    mMana += 5;
    cMana += 5;

    str += 10;
    magic += 5;
    arch += 0;
    def += 10;
  }

  else if (type == "Sharpshooter")
  {
    mHp += 15;
    cHp += 15;
    mMana += 5;
    cMana += 5;

    str += 5;
    arch += 15;
    def += 5;
  }
  
  else if (type == "Demon" || type == "Tyrant")
  {
    mHp += 15;
    cHp += 15;
    mMana += 5;
    cMana += 5;

    str += 10;
    def += 10;
    magic += 5;
  }
}

void Hero::setHp(double x)
{
  cHp -= x;
}

void Hero::setMana(double x)
{
  cMana -= x;
}

void Hero::heal()
{
  if (type == "Caster" || type == "Illusionist")
    cHp += mHp * .15;
    
  else if (rank == "Monster")
    cHp += mHp * .01;
    
  else
    cHp += mHp * .2;
    
	if (cHp > mHp)
	  cHp = mHp;
}

void Hero::manaRegen()
{
  if (type == "Caster" || type == "Illusionist")
    cMana += (mMana * .3);

  else
    cMana += (mMana * .15);
    
  if (cMana > mMana)
    cMana = mMana;
}

int Hero::basicDmg()
{
  int dmg;
  if (type == "Caster" || type == "Illusionist")
    dmg = magic;

  else if (type == "Monster")
    dmg = (magic + str + arch) * .75;
  
  else if (type == "Bloodmoon")
  {
    dmg = (magic + str) * .75;
    cHp += (dmg * .25);
    if (cHp > mHp)
      cHp = mHp;
  }
  
  else
    dmg = str + arch;
    
  return dmg;
}

int Hero::manaDmg()
{
  int dmg;
  if (cMana < 10)
    return 0;
    
  else
  {
    if (type == "Caster" || type == "Illusionist")
      dmg = (magic * 2);
      
    else if (type == "Monster")
      dmg = (magic + str + arch) * .55;
     
    else if (type == "Bloodmoon")
    {
      dmg = (magic + str) * .5;
      cHp += (dmg * .5);
      if (cHp > mHp)
        cHp = mHp;
    }
    
    else
      dmg = (str + arch) * 2;

    return dmg;
  }
}

int Hero::getHeal()
{
  if (type == "Caster" || type == "Illusionist")
    return mHp * .1;
    
  else if (rank == "Monster")
    return mHp * .01;
    
  else
    return mHp * .2;
}