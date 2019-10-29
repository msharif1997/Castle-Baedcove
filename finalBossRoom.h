//Andy Lister, aglister@dmacc.edu, 10/8/2019
//This function is the boss room

#include "characterClass.h"	//needed to pass the class as a reference
#include <cstdlib>	//used for random number
#include <ctime>	//used for random number

#pragma once

bool bossRoomFunction(Player1& character){
	
	//Pass by reference so it changes the actual class instead of the copy

	//Stuff I need
	unsigned seed = time(0);
	srand(seed);
	int randomNum;	//Holds a variable place to generate a randomNum later
	string answer = "";
	bool roomComplete = false;
	
	bool fightDragon = false;
	bool dragonDead = false;
	bool takeDeal = false;
	
	int dragonHealth = 30;
	int combatNum = 0;
	
	cout << "You made it! After what feels like a gauntlet of puzzles, traps, and knights you've" << endl;
	cout << "finally made it to the treasure room." << endl;
	cout << endl;
	cout << "The overwhelming brightness of the treasure room nearly blinds you, but as your eyes" << endl;
	cout << "adjust you start to really get the scope of this challenge that the Dead King set before you." << endl;
	cin.ignore();
	system("clear");
	system("cls");
	cout << "This room, quite frankly, is HUGE. A mountain of treasure reaching all the way up to the ceiling" << endl;
	cout << "is stacked up against the far wall, but even though its across the room the base of that mountain" << endl;
	cout << "is within a few feet of you." << endl;
	cout << endl;
	cout << "As your eyes trace the treasure to its very top, you notice that the room has a glass ceiling." << endl;
	cout << "'A glass ceiling...' you think to yourself, right before it hits you that you can see the other" << endl;
	cout << "rooms of the castle that you beat. They're all connected in a giant globe of gears that look like" << endl;
	cout << "they can shift and change in endless combinations." << endl;
	cin.ignore();
	cout << "'THE CASTLE CAN SHIFT ROOMS?!' you exclaim before you can stop yourself. As these words echo through" << endl;
	cout << "the chamber, the mountain of gold starts to shift. You wonder if those words will be your last." << endl;
	cin.ignore();
	
	//This room has two different endings depending on if the player grabbed the sword or not
	
	if(character.getSword()){
		system("clear");
		system("cls");
		cout << "Gold starts cascading down the mountain as a massive weight shifts within it. More gently than you" << endl;
		cout << "thought was possible the head of a beautifuly red dragon shows itself from within the mountain." << endl;
		cin.ignore();
		cout << "'I thought I sensed my old foe stumbling into this room. Come to vanquish me?'" << endl;
		cout << endl;
		cout << "Your confusion must have been plainly visible on your face because the dragon speaks again." << endl;
		cout << endl;
		cout << "'Not you, you insignificant human. I'm talking to that sword on your back.'" << endl;
		cout << "'We've fought time and time again since the beginning. I'm not surprised to find it here again.'" << endl;
		cin.ignore();
		system("clear");
		system("cls");
		cout << "'Frankly, I'm tired of fighting, so I'll offer you a deal. If you leave me alone, you get half.'" << endl;
		cout << "'There is more wealth in here than you can spend in 50 lifetimes, so 25 lifetimes'" << endl;
		cout << "'of treasure should be more than enough. What say you? Will you take my deal?'" << endl;
		
		bool madeChoice = false;
		while(!madeChoice){
		cout << endl;
		cout << "--- You can take deal or fight dragon. The choice is yours, wise adventurer. ---" << endl;
		cin >> answer;
		
		int switchNum = 0;
		if(answer == "take deal"){ switchNum = 1;} else if (answer == "fight dragon"){ switchNum = 2;}
		
		switch(switchNum){
			case 1:
				takeDeal = true;
			break;
			
			case 2:
				fightDragon = true;
			break;
			
			default:
				cout << "The dragon stairs at you with an expression of hope...or is that boredom??" << endl;
				cout << "(Try again)" << endl;
			break;
		}
		
	} //end of while loop checking for the player's choice
		
} //end of sword-check if
else
{
	fightDragon = true;
}

//This if only activates if the player has the sword and chose to take the deal
if(takeDeal)
{
	system("clear");
	system("cls");
	cout << "'A wise decision, friend. The self-preservation of humans never ceases to amuse me.'" << endl;
	cout << "'Take your bag's worth in gold and leave me. I never want to see you again.'" << endl;
	cin.ignore();
	cout << "A bags worth?? This dragon said HALF. How dare he! Still, the temptation to leave this" << endl;
	cout << "room alive is pretty overwhelming. You have a choice to make, adventurer. Do you leave" << endl;
	cout << "the room with your bag of gold? Or do you challenge the dragon?" << endl;
	
	bool madeChoice = false;
		while(!madeChoice){
		cout << endl;
		cout << "--- You can leave room or fight dragon. The choice is yours, wise adventurer. ---" << endl;
		cin >> answer;
		
		int switchNum = 0;
		if(answer == "leave room"){ switchNum = 1;} else if (answer == "fight dragon"){ switchNum = 2;}
		
		switch(switchNum){
			case 1:
				roomComplete = true;
				system("clear");
				system("cls");
				cout << "You fill your bag with as much gold as you can and leave." << endl;
				cout << "The bag of gold lasts you and your family for a little bit, but you" << endl;
				cout << "die the same poor person that you were when you started this adventure." << endl;
				cin.ignore();
			break;
			
			case 2:
				fightDragon = true;
				system("clear");
				system("cls");
				cout << "You silently draw your sword in response to what the dragon said." << endl;
				cout << endl;
				cout << "'HA! I must have been mistaken about you. Very well, then.'" << endl;
				cin.ignore();
			break;
			
			default:
				cout << "The dragon stairs at you with an expression of hope...or is that boredom??" << endl;
				cout << "(Try again)" << endl;
			break;
		}
		
	} //end of while loop checking for the player's choice
}


//This activates if the player chooses to fight the dragon or if the player enters the room without the sword
if(fightDragon)
{
	system("clear");
	system("cls");
	cout << "In a violent shower of coins and jewels the dragon bursts from underneath the mountain of gold." << endl;
	cout << "Wings open wide, it lunges at you and attacks." << endl;
	cin.ignore();
	
		//Dragon fight!!!
		while (!dragonDead)
		{
			//Clears console so it doesn't get cluttered
			system("clear");
			system("cls");
			

			//This section deals with the dragon attacking

			randomNum = (rand() % (4 - 1 + 1)) + 1;	//Generates a number 1-4
			if (randomNum == 1 || randomNum == 2 || randomNum == 3)//Allows for a 1 in 4 shot of the attack missing
			{
				cout << endl;	//Little bit of space
				//Determines if you have a shield or not and then subtracts damage
				cout << "The dragon fireballed you for 3 damage!" << endl;
				if (character.getShield())
				{
					cout << "Your shield took two points of damage for you!" << endl;
					character.setHp(-1);
					character.gameOver();
				}
				else
				{
					character.setHp(-3);
					character.gameOver();
				}
					cout << "Your current HP is: " << character.getHp() << endl;
			}
			else
			{
				cout << endl;
				cout << "You barely avoid the dragon's fireball." << endl;
			}
			cout << endl;
			//End of dragon
			//Character choice
			cout << "What will you do?" << endl;
			cout << "1 - Attack \t 2 - Drink potion" << endl;
			cin >> combatNum;
			cout << endl;	//Little bit of space
			//Player's move is in this area
			switch (combatNum)
			{
				case 1:
					randomNum = (rand() % (6 - 1 + 1)) + 1;	//Generates a number 1-6
					if (randomNum != 6)//theres a 1 in 6 chance that your attack misses
					{
						if (character.getSword())
						{
							cout << "Your attack does 4 damage!" << endl;
							dragonHealth = dragonHealth - 4;
							cout << "The dragon's current health is: " << dragonHealth;
							cout << endl;
						}
						else
						{
							cout << "Your attack does 2 damage!" << endl;
							dragonHealth = dragonHealth - 2;
							cout << "The dragon's current health is: " << dragonHealth;
							cout << endl;
						}
					}
					else
					{
						cout << "Your attack misses!" << endl;
						cout << endl;
					}
				break;

				case 2:
					if (character.getPotion() != 0)
					{
						cout << "You used a potion!" << endl;
						character.setHp(20);
						cout << "Your current HP is: " << character.getHp() << endl;
					}
					else
					{
						cout << "You don't have any potions left!" << endl;
						cout << "Your current HP is: " << character.getHp() << endl;
					}
				break;

				default:
					cout << "You think standing there like an idiot is a bad choice." << endl;
					cout << "(Try Again)" << endl;
			}

			cin.get();	//Pauses the console a bit so the player can read whats on it before it clears
			cin.ignore();	//Helps pause it

			//Checks if dragon's health is 0 or less and exits the while loop if it is
			if (dragonHealth <= 0)
			{
				dragonDead = true;
			}
		}
		
		cout << "With a final roar, the dragon collapses to the ground." << endl;
		cout << "Just as you wonder how you're going to get the body out of the room," << endl;
		cout << "it starts to turn to ash and vanish right before your eyes." << endl;
		cout << endl;
		cout << "As the last speck of ash floats away, a small bright orb descends from the ceiling." << endl;
		cout << "It gets closer, and you realize that its not an orb so much as a swirling ball" << endl;
		cout << "of energy." << endl;
		cin.ignore();
		cout << "Suddenly, the Dead King appears before you." << endl;
		cout << "'Good job finishing this challenge! You are more than worthy to inherit my kingdom.'" << endl;
		cout << endl;
		cout << "A crown appears on your head and you're teleported back to the beginning chamber." << endl;
		cin.ignore();
		cout << "The years of your rule are kind and prosperous. Your wealth lasts generations on generations" << endl;
		cout << "until it fades back into legend, and then into myth..." << endl;
		cin.ignore();
		roomComplete = true;

		
}	
	
	
return roomComplete;
	
}
