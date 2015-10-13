#include "Hero.h"
#include "Monster.h"
#include "Item.h"
#include "Map.h"

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

void fightScreen(Hero& attacker, Hero& target);
string compareItems(Item& a, Item& b);
void chooseClass(Hero& who, int type);
void chooseAction(Hero& who);

int main()
{ 
  srand((unsigned int)time(0));
  rand(); rand(); rand();
  cout << endl;
  
  //*****************************************************************
  Hero mainChar;
  Map maps;
  
  int whatClass;
  
  while (true)
  {
    cout << "---Select a class---" << endl;
    cout << "     (By Number)" << endl;
    cout << "1 - Sharpshooter" << setw(17) << "5 - Bloodmoon" << endl;
    cout << "2 - Caster"       << setw(25) << "6 - Illusionist" << endl;
    cout << "3 - Paladin"      << setw(18) << "7 - Demon" << endl;
    cout << "4 - Berserker"    << setw(17) << "8 - Tyrant"  << endl;
    cout << "What class would you like to start out as?";
    cin >> whatClass;
    cout << endl;
    if (whatClass > 0 && whatClass < 9)
      break;
  }
  
  chooseClass(mainChar, whatClass);
  mainChar.showHero();
  
  Monster monsters[10];
	
  cin.ignore(1000, 10);
    
  for (int i = 0; i < 10; i++)
    fightScreen(mainChar, monsters[i]);
}

void chooseClass(Hero& mainChar, int type)
{
  switch(type)
  {
    case 1:
      mainChar.sharpshooter();
      break;
    case 2:
      mainChar.caster();
      break;
    case 3:
      mainChar.paladin();
      break;
    case 4:
      mainChar.berserker();
      break;
    case 5:
      mainChar.bloodmoon();
      break;
    case 6:
      mainChar.illusionist();
      break;
    case 7:
      mainChar.demon();
      break;
    case 8:
      mainChar.tyrant();
      break;
  }
}

void fightScreen(Hero& attacker, Hero& target)
{    
  cout << "------------------------------Battle------------------------------" << endl;
  while (true)
  {
    if (attacker.cHp <= 0)
    {
      cout << "You were slain." << endl;
      cout << "------------------------------------------------------------------" << endl;
      break;
    }
    
    else if (target.cHp <= 0)
    {
      cout << "You have slain the target." << endl;
      cout << "------------------------------------------------------------------" << endl;
      break;
    }

    target.showEnemy();
    cout << endl;
    attacker.showHero();
    cout << endl;
    int choice = 4;
    
    cout << "                         What will you do?" << endl;
    cout << "                         (1) Attack: " << attacker.basicDmg() << endl;
    cout << "                         (2) Empowered: " << attacker.manaDmg() << endl;
    cout << "                         (3) Heal: " << attacker.getHeal() << endl;
		
    while (true)
    {
      cin >> choice;
      if (choice == 1)
      {
        target.setHp(attacker.basicDmg());
        cout << "You struck the target with a physical blow." << endl;
        cout << "------------------------------------------------------------------" << endl;
        break;
      }
			
      else if (choice == 2)
      {
        target.setHp(attacker.manaDmg());
        cout << "You struck the target with a magical attack." << endl;
        cout << "------------------------------------------------------------------" << endl;
        attacker.setMana(10);
        break;
      }
			
      else if (choice == 3)
      {
        attacker.heal();
        cout << "You regained a bit of health." << endl;
        cout << "------------------------------------------------------------------" << endl;
        break;
      }
			
      else
      {
          cout << "Invalid move" << endl;
      }
    }
	
    if (attacker.cHp <= 0)
    {
      cout << "You were slain." << endl;
      cout << "------------------------------------------------------------------" << endl;
      break;
    }
    
    else if (target.cHp <= 0)
    {
      cout << "You have slain the target." << endl;
      attacker.gainExp(target.exp);
      cout << "You gained " << target.exp << " exp." << endl;
      cout << "------------------------------------------------------------------" << endl;
      break;
    }  
	
    int choice2 = rand() % 2;
    if (choice2 == 1)
    {
        attacker.setHp(target.basicDmg());
      cout << "The target struck you with a physical attack." << endl;
      cout << "------------------------------------------------------------------" << endl;
    }
	
    else if (choice2 == 2)
    {
      attacker.setHp(target.manaDmg());
      target.setMana(10);
      cout << "The target struck you with a magical attack." << endl;
      cout << "------------------------------------------------------------------" << endl;
    }
	
    else if (choice2 == 0)
    {
      target.heal();
      cout << "The target regained a bit of health." << endl;
      cout << "------------------------------------------------------------------" << endl;
    }
  }
}

void chooseAction(Hero& who)
{
  cout << "What will you do?" << endl;
  cout << "(1) Head onward" << endl;
  cout << "(2) Head backwards" << endl;
  cout << "(3) Visit store" << endl;
  cout << "(4) Find monsters" << endl;
}