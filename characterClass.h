//Coded by Andy Lister, aglister@dmacc.edu, 09/18/19


#ifndef characterClass
#define characterClass

#include <iostream>
#include <string>
using namespace std;
//Character class suggestion
//Everything is a suggestion and is open to change. Just brainstorming as I type.

class Player1
{
	private:
		int hp;
		//These are for inventory management
		bool sword; //changes to true if you find it
		bool shield; //changes to true if you find it
		int potion; //keeps a running total
	
	public:
		Player1(){hp = 20; sword = false; shield = false; potion = 0; } //default constructor
		
		//setters
		void setHp(int s) {hp = hp + s; if (hp > 20){hp = 20;}};//running total. Allows us to put in negative or positive numbers and have it work just fine
		void setSword(bool s) {sword = s;};
		void setShield(bool s){shield = s;};
		void setPotion(int s){potion = potion + s;}; //running total. Is 5 enough or too many? 
		
		//getters
		int getHp(){return hp;};
		bool getSword(){return sword;};
		bool getShield(){return shield;};
		int getPotion(){return potion;};
		
		//shows inventory when you call this in a cout statement.
		//only shows potions until there is a sword/shield there as well.
		string showInventory(){
			string inventory = "";
			if (sword){inventory = inventory + "- 1 sword \n";}
			if (shield){inventory = inventory + "- 1 shield \n";}
			inventory = inventory + "- " + to_string(potion) + " potion(s) \n";
			return inventory;
			}
		
		//checks for hp each time you call it and ends the game if their hp is 0 or below	
		void gameOver(){
			if(hp <= 0){
				system("clear");
				system("cls");
				cout << "Your HP is " << hp << endl;
				cout << "As you draw your last breath, you reflect on your life." << endl;
				cout << "It was good, but it would have been so much better if you had" << endl;
				cout << "found the treasure. Better luck to the next person to try." << endl;
				cout << endl;
				cout << "---- GAME OVER ----" << endl;
				exit(-1);
				system("pause");
			}
		}
		
};

#endif
