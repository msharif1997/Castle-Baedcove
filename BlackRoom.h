#include "characterClass.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

#pragma once

/*
 *	Mohamed Sharif
 */
//edited by Andy Lister
bool DarkRoomFunction(Player1& character){
	
	int randomNum = 0;
	int combatNum = 0;
	int knightHealth = 10;
	bool knightDead = false;
	bool DarkRoomComplete = false;
	
	// gets the user input for the lever
		string lever = "";
		
		// tells the general story for the room
			system("clear");
			system("cls");
			cout << "You find yourself in a room with no light. The last sound you hear is the door shutting behind you. The following silence is deafening. " << endl;
			cout << "You decide you need to get your bearings and start to feel your way around the room." << endl;
			cout << "Everything feels metallic and cool to the touch. Is this room made out of metal? Not even your footsteps are making a noise as you try to find the next door." << endl;
			cout << " you walked around and around the wall you feel like you are in a rectangle shaped dark room." << endl;
			cout << " As you feel your way around the the steel wall to find the exist you come across a lever that's attached to the wall." << endl;
			cout << endl;
			cout << "What will you do?" << endl;
			getline(cin, lever);
			
			while(!DarkRoomComplete)
			{
			
			// gets the input for the lever and campares it to the static string i inputted to meet these two string rules for the if statement.
			if(lever == "pushdown" || lever == "down" || lever == "pull lever"){
				
				//tells a story of how the fight starts with the knight
				cout << " One of the wall sides crumbles and a bright light hits your eyes and you walk to your right to avoid the bright light, As your eyes are getting use to the light " << endl;
				cout << " you hear a foot steps coming on your way and you see a suite of armor walking towards you... Its a KNIGHT. The Knight charges towards you. Its now Survive or be killed. You Charged as the Knight Charged as you two CLASHED! " << endl;
				cout<<endl;
				
				//The loop begins with the knight fight if the if statement is satisfied
					//Knight fight!!! Made by Andy Lister
					while (!knightDead)
					{
						//Clears console so it doesn't get cluttered
						system("clear");
						system("cls");
						

						//This section deals with the knight attacking

						randomNum = (rand() % (4 - 1 + 1)) + 1;	//Generates a number 1-4
						if (randomNum == 1 || randomNum == 2 || randomNum == 3)//Allows for a 1 in 4 shot of the attack missing
						{
							cout << endl;	//Little bit of space

							//Determines if you have a shield or not and then subtracts damage
							cout << "The knight hit you for 2 damage!" << endl;
							if (character.getShield())
							{
								cout << "Your shield took a point of damage for you!" << endl;
								character.setHp(-1);
								character.gameOver();
							}
							else
							{
								character.setHp(-2);
								character.gameOver();
							}

							cout << "Your current HP is: " << character.getHp() << endl;
						}
						else
						{
							cout << endl;
							cout << "The knight's attack misses!" << endl;
						}

						cout << endl;
						//End of knight
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
										cout << "Your attack does 3 damage!" << endl;
										knightHealth = knightHealth - 3;
										cout << "The knight's current health is: " << knightHealth;
										cout << endl;
									}
									else
									{
										cout << "Your attack does 2 damage!" << endl;
										knightHealth = knightHealth - 2;
										cout << "The knight's current health is: " << knightHealth;
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

						cin.ignore();	//Helps pause it

						//Checks if knight's health is 0 or less and exits the while loop if it is
						if (knightHealth <= 0)
						{
							knightDead = true;
						}
						//end of knight fight
					}
						system("clear");
						system("cls");
						cout << "As you had a death battle with Room Knight and won the battle." << endl;
						cout << "You take the cristal eye ball of the knight and put them two holes on the wall and a door opens up with a bright light. you move towards it. " << endl;
						DarkRoomComplete = true;
					
				
			} else {
				
				cout << "The fear of being trapped in this room damages you." << endl;
				cout << endl;
				character.setHp(-1);
				character.gameOver();
				cout << "Your current HP is " << character.getHp() << endl; 
			}
			
			}
			
}
