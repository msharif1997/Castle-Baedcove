//Coded by Andy Lister, aglister@dmacc.edu, 09/18/19
#include "characterClass.h"	//needed to pass the class as a reference
#include <cstdlib>	//used for random number
#include <ctime>	//used for random number

#pragma once

bool room1Function(Player1& character)
{
	//Pass by reference so it changes the actual class instead of the copy

	//Stuff I need
	unsigned seed = time(0);
	srand(seed);
	int randomNum = (rand() % (3 - 1 + 1)) + 1;	//Generates a number 1-3
	//int test = 1;	//Used to test new additions so you dont have to rely on a 1/3 chance to try your code
	string answer = "";
	bool roomComplete = false;
	//cout << randomNum; used to test that a number is actually generated

	bool knightDead = false;
	int knightHealth = 10;
	int combatNum = 0;

	system("clear");
	system("cls");
	//Story
	cout << "You come to a room with three different doors. They're all on the same wall." << endl;
	cout << "One is on the left, one on the right, and one is in the center. " << endl;
	cout << "You turn around quickly to try to leave the room and the door disappears behind you." << endl;
	cout << "Better luck next time." << endl;
	cout << "You see a torch on either side of all three doors." << endl;
	cout << "The torches are all lit, except for one to the left of the center door. " << endl;

	//This section randomizes the room and looks for the character to find the correct path to change roomComplete to true
	if (randomNum == 1)
	{
		cout << endl;	//Separates it from the story
		int answerNum = 0;	//Used to change string to num

		int noteNum = 0;	//Used for trap room
		bool finishTrapRoom = false;	//Used for trap room

		while (!roomComplete)
		{
			cout << "What will you do?" << endl;
			getline(cin, answer);
			cout << endl;

			//Changes answer to number for use in switch statement
			if (answer == "light torch")
			{
				answerNum = 1;
			}
			else if (answer == "open left")
			{
				answerNum = 2;
			}
			else if (answer == "open center")
			{
				answerNum = 3;
			}
			else if (answer == "open right")
			{
				answerNum = 4;
			}
			else if (answer == "show inventory")
			{
				answerNum = 5;
			} 
			else
			{
				answerNum = 6;
			}
			

			switch (answerNum)
			{
				case 1:
					cout << "You take the right torch off the wall and use it to light the left torch." << endl;
					cout << "You hear a click behind you that sounds very sinister..." << endl;
					cin.ignore();	//Pauses for dramatic effect
					cout << "Its a treasure chest! Yay! +1 potion has been added to your inventory." << endl;
					if (character.getPotion() < 5)
					{
						character.setPotion(1);
					}
					else
					{
						cout << "It looks like your bag is too full. You put the potion back and walk away." << endl;
					}

					cout << endl;
					break;

				case 2:
					system("clear");
					system("cls");
					cout << "You walk over to the door on the left and slowly try and turn the doorknob." << endl;
					cout << "The doorknob feels rusty, but after a little bit of effort you're able to turn it and open the door." << endl;
					cin.ignore();	//Even more dramatic effect
					cout << "You found the way to the next room! You let go of the breath you didn't know you were holding and venture to the next room." << endl;
					roomComplete = true;
					cout << endl;
					break;

				case 3:
					system("clear");
					system("cls");
					cout << "Something is drawing you to the center door. Was it the unlit torch? Or divine intervention?" << endl;
					cout << "This door feels light and is easy to open. As you open it a huge gust of wind, as if a big pressure was released, hits you in the face." << endl;
					cin.ignore();	//Damn I'm dramatic
					cout << "The room inside is dark. Even though the previous room was lit, no light passes the threshold of the door." << endl;
					cout << "Something is moving in the corner? As you approach to see what it is, a ragged knight jumps at you!" << endl;
					cin.ignore();

					//Knight fight!!!
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
					}

					cout << "You killed the knight! Congratulations!" << endl;
					cin.ignore();
					cout << "As you deal the finishing blow, you hear the knight whisper with is dying breath 'I just wanted a hug...'" << endl;
					cout << "The guilt weighs on you, but then you remember there are other doors to open and you forget all about the knight!" << endl;
					cout << "You leave the room." << endl;
					cout << endl;
					break;

				case 4:
					system("clear");
					system("cls");
					
					cout << "The ease and lack of fanfare as this door opens should unsettle you, but you're not self-aware enough to realize that." << endl;
					cout << "You walk right into the room without a care in the world." << endl;
					cin.ignore();
					cout << "Nothing happens. There seems to not be a point to this room at all. As you turn to leave, you see a note laying on the" << endl;
					cout << "floor in the middle of the room." << endl;

					finishTrapRoom = false;	//resets bool for multiple visits to the room
					while (!finishTrapRoom)
					{
						noteNum = 0;
						cout << endl;
						cout << "What will you do?" << endl;
						getline(cin, answer);
						if (answer == "grab note")
						{
							noteNum = 1;
						}
						else if (answer == "read note")
						{
							noteNum = 2;
						}
						else if (answer == "search room")
						{
							noteNum = 3;
						}
						else if (answer == "show inventory")
						{
							noteNum = 4;
						} else if (answer == "leave room")
						{
							noteNum = 5;	
						}

						switch (noteNum)
						{
							case 1:
								cout << "You bend down, and as you pick up the note you pull a string that was attached to the back of it." << endl;
								cout << "You hang in the air for an almost cartoonish amount of time before plummeting to your death." << endl;
								cin.ignore();	//Someone call kenny loggins, this is the danger zone of drama
								cout << "Or it would have been your death if you didn't grab the ledge at the last second." << endl;
								cout << "You take -2 damage just from the sheer stress of it all." << endl;
								character.setHp(-2);
								character.gameOver();
								cout << "Your current HP is: " << character.getHp() << endl;
								finishTrapRoom = true;
								break;
							case 2:
								cout << "You bend down to read the note without touching it." << endl;
								cin.ignore();
								cout << "The note says: 'Ha! Almost got ya!" << endl;
								cout << "Further inspection of the note shows a string tied to the back. It looks like it was a trap of some kind." << endl;
								finishTrapRoom = true;
								break;
							case 3:
								cout << "You search the room." << endl;
								cin.ignore();
								cout << "Hidden right behind the now open door is a potion! Yay!" << endl;
								if (character.getPotion() < 5)
								{
									character.setPotion(1);
									cout << "You added that potion to your bag." << endl;
								}
								else
								{
									cout << "It looks like your bag is too full. You put the potion back and walk away." << endl;
								}
								cin.ignore();
								cout << "You also see a shield hanging on the wall. What will you do?" << endl;
								getline(cin, answer);
								if(answer == "grab shield"){
									character.setShield(true);
									cout << "You grab the shield and add it to your inventory!" << endl;
								} else {
									cout << "Welp, thats a shield alright, but apparently you don't want to grab it." << endl;
								}

								finishTrapRoom = true;
								break;

							case 4:
								cout << endl;
								cout << character.showInventory();
								break;
							
							case 5:
								finishTrapRoom = true;

							default:
								cout << "You stand in the room looking blankly at the wall in front of you." << endl;
								cout << "(Try again)" << endl;
								cout << endl;
							break;
						}
					}	// end of trap room
					cout << "You leave the room." << endl;
					cout << endl;
					break;

				case 5:
					cout << endl;
					cout << character.showInventory();
					break;

				default:
					cout << "You feel as if there was almost something you should be doing, but instead you just stand in the center of the room." << endl;
					cout << "(Try again)" << endl;
					cout << endl;

			}
		}	// end of while loop

	}
	else if (randomNum == 2)
	{
		cout << endl;	//Separates it from the story
		int answerNum = 0;

		int noteNum = 0;	//Used for trap room
		bool finishTrapRoom = false;	//Used for trap room

		while (!roomComplete)
		{
			cout << "What will you do?" << endl;
			getline(cin, answer);
			cout << endl;

			//Changes answer to number for use in switch statement
			if (answer == "light torch")
			{
				answerNum = 1;
			}
			else if (answer == "open left")
			{
				answerNum = 2;
			}
			else if (answer == "open center")
			{
				answerNum = 3;
			}
			else if (answer == "open right")
			{
				answerNum = 4;
			}
			else if (answer == "show inventory")
			{
				answerNum = 5;
			} 
			else
			{
				answerNum = 6;
			}
			

			switch (answerNum)
			{
				case 1:
					cout << "You take the right torch off the wall and use it to light the left torch." << endl;
					cout << "You hear a click behind you that sounds very sinister..." << endl;
					cin.ignore();
					cout << "Its a treasure chest! Yay! +1 potion has been added to your inventory." << endl;
					if (character.getPotion() < 5)
					{
						character.setPotion(1);
					}
					else
					{
						cout << "It looks like your bag is too full. You put the potion back and walk away." << endl;
					}

					cout << endl;
					break;

				case 2:
					system("clear");
					system("cls");
					cout << "Something is drawing you to the left door. Was it divine intervention?" << endl;
					cout << "This door feels light and is easy to open. As you open it a huge gust of wind, as if a big pressure was released, hits you in the face." << endl;
					cin.ignore();
					cout << "The room inside is dark. Even though the previous room was lit, no light passes the threshold of the door." << endl;
					cout << "Something is moving in the corner? As you approach to see what it is, a ragged knight jumps at you!" << endl;
					cin.ignore();

					//Knight fight!!!
					while (!knightDead)
					{
						//Clears console so it doesn't get cluttered
						system("clear");
						system("cls");

						//This section deals with the knight attacking

						randomNum = (rand() % (4 - 1 + 1)) + 1;	//Generates a number 1-4
						if (randomNum == 1 || randomNum == 2 || randomNum == 3) //Allows for a 1 in 4 shot of the attack missing
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
								if (randomNum != 6) //theres a 1 in 6 chance that your attack misses
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

						cin.get();	//Pauses the console a bit so the player can read whats on it before it clears
						cin.ignore();	//Helps pause it

						//Checks if knight's health is 0 or less and exits the while loop if it is
						if (knightHealth <= 0)
						{
							knightDead = true;
						}
					}

					cout << "You killed the knight! Congratulations!" << endl;
					cin.ignore();
					cout << "As you deal the finishing blow, you hear the knight whisper with is dying breath 'I just wanted a hug...'" << endl;
					cout << "The guilt weighs on you, but then you remember there are other doors to open and you forget all about the knight!" << endl;
					cout << "You leave the room." << endl;
					cout << endl;
					break;

				case 3:
					system("clear");
					system("cls");
					
					cout << "The ease and lack of fanfare as this door opens should unsettle you, but you're not self-aware enough to realize that." << endl;
					cout << "You walk right into the room without a care in the world." << endl;
					cin.ignore();
					cout << "Nothing happens. There seems to not be a point to this room at all. As you turn to leave, you see a note laying on the" << endl;
					cout << "floor in the middle of the room." << endl;

					finishTrapRoom = false;	//resets bool for multiple visits to the room
					while (!finishTrapRoom)
					{
						noteNum = 0;
						cout << endl;
						cout << "What will you do?" << endl;
						getline(cin, answer);
						if (answer == "grab note")
						{
							noteNum = 1;
						}
						else if (answer == "read note")
						{
							noteNum = 2;
						}
						else if (answer == "search room")
						{
							noteNum = 3;
						}
						else if (answer == "show inventory")
						{
							noteNum = 4;
						} else if (answer == "leave room")
						{
							noteNum = 5;	
						}

						switch (noteNum)
						{
							case 1:
								cout << "You bend down, and as you pick up the note you pull a string that was attached to the back of it." << endl;
								cout << "You hang in the air for an almost cartoonish amount of time before plummeting to your death." << endl;
								cin.ignore();	//Someone call kenny loggins, this is the danger zone of drama
								cout << "Or it would have been your death if you didn't grab the ledge at the last second." << endl;
								cout << "You take -2 damage just from the sheer stress of it all." << endl;
								character.setHp(-2);
								character.gameOver();
								cout << "Your current HP is: " << character.getHp() << endl;
								finishTrapRoom = true;
								break;
							case 2:
								cout << "You bend down to read the note without touching it." << endl;
								cin.ignore();
								cout << "The note says: 'Ha! Almost got ya!" << endl;
								cout << "Further inspection of the note shows a string tied to the back. It looks like it was a trap of some kind." << endl;
								finishTrapRoom = true;
								break;
							case 3:
								cout << "You search the room." << endl;
								cin.ignore();
								cout << "Hidden right behind the now open door is a potion! Yay!" << endl;
								if (character.getPotion() < 5)
								{
									character.setPotion(1);
									cout << "You added that potion to your bag." << endl;
								}
								else
								{
									cout << "It looks like your bag is too full. You put the potion back and walk away." << endl;
								}
								cin.ignore();
								cout << "You also see a shield hanging on the wall. What will you do?" << endl;
								getline(cin, answer);
								if(answer == "grab shield"){
									character.setShield(true);
									cout << "You grab the shield and add it to your inventory!" << endl;
								} else {
									cout << "Welp, thats a shield alright, but apparently you don't want to grab it." << endl;
								}

								finishTrapRoom = true;
								break;

							case 4:
								cout << endl;
								cout << character.showInventory();
								break;
							
							case 5:
								finishTrapRoom = true;

							default:
								cout << "You stand in the room looking blankly at the wall in front of you." << endl;
								cout << "(Try again)" << endl;
								cout << endl;
							break;
						}
					}	// end of trap room
					cout << "You leave the room." << endl;
					cout << endl;
					break;

				case 4:
					system("clear");
					system("cls");
					cout << "You walk over to the door on the right and slowly try and turn the doorknob." << endl;
					cout << "The doorknob feels rusty, but after a little bit of effort you're able to turn it and open the door." << endl;
					cin.ignore();
					cout << "You found the way to the next room! You let go of the breath you didn't know you were holding and venture to the next room." << endl;
					roomComplete = true;
					cout << endl;
					break;

				case 5:
					cout << endl;
					cout << character.showInventory();
					break;

				default:
					cout << "You feel as if there was almost something you should be doing, but instead you just stand in the center of the room." << endl;
					cout << "(Try again)" << endl;
					cout << endl;

			}
		}	// end of while loop

	}
	else
	{
		cout << endl;	//Separates it from the story
		int answerNum = 0;

		int noteNum = 0;	//Used for trap room
		bool finishTrapRoom = false;	//Used for trap room

		while (!roomComplete)
		{
			cout << "What will you do?" << endl;
			getline(cin, answer);
			cout << endl;

			//Changes answer to number for use in switch statement

			if (answer == "light torch")
			{
				answerNum = 1;
			}
			else if (answer == "open left")
			{
				answerNum = 2;
			}
			else if (answer == "open center")
			{
				answerNum = 3;
			}
			else if (answer == "open right")
			{
				answerNum = 4;
			}
			else if (answer == "show inventory")
			{
				answerNum = 5;
			} 
			else
			{
				answerNum = 6;
			}
			
			

			switch (answerNum)
			{
				case 1:
					cout << "You take the right torch off the wall and use it to light the left torch." << endl;
					cout << "You hear a click behind you that sounds very sinister..." << endl;
					cin.ignore();
					cout << "Its a treasure chest! Yay! +1 potion has been added to your inventory." << endl;
					if (character.getPotion() < 5)
					{
						character.setPotion(1);
					}
					else
					{
						cout << "It looks like your bag is too full. You put the potion back and walk away." << endl;
					}

					cout << endl;
					break;

				case 2:
					system("clear");
					system("cls");
					
					cout << "The ease and lack of fanfare as this door opens should unsettle you, but you're not self-aware enough to realize that." << endl;
					cout << "You walk right into the room without a care in the world." << endl;
					cin.ignore();
					cout << "Nothing happens. There seems to not be a point to this room at all. As you turn to leave, you see a note laying on the" << endl;
					cout << "floor in the middle of the room." << endl;

					finishTrapRoom = false;	//resets bool for multiple visits to the room
					while (!finishTrapRoom)
					{
						noteNum = 0;
						cout << endl;
						cout << "What will you do?" << endl;
						getline(cin, answer);
						if (answer == "grab note")
						{
							noteNum = 1;
						}
						else if (answer == "read note")
						{
							noteNum = 2;
						}
						else if (answer == "search room")
						{
							noteNum = 3;
						}
						else if (answer == "show inventory")
						{
							noteNum = 4;
						} else if (answer == "leave room")
						{
							noteNum = 5;	
						}

						switch (noteNum)
						{
							case 1:
								cout << "You bend down, and as you pick up the note you pull a string that was attached to the back of it." << endl;
								cout << "You hang in the air for an almost cartoonish amount of time before plummeting to your death." << endl;
								cin.ignore();	//Someone call kenny loggins, this is the danger zone of drama
								cout << "Or it would have been your death if you didn't grab the ledge at the last second." << endl;
								cout << "You take -2 damage just from the sheer stress of it all." << endl;
								character.setHp(-2);
								character.gameOver();
								cout << "Your current HP is: " << character.getHp() << endl;
								finishTrapRoom = true;
								break;
							case 2:
								cout << "You bend down to read the note without touching it." << endl;
								cin.ignore();
								cout << "The note says: 'Ha! Almost got ya!" << endl;
								cout << "Further inspection of the note shows a string tied to the back. It looks like it was a trap of some kind." << endl;
								finishTrapRoom = true;
								break;
							case 3:
								cout << "You search the room." << endl;
								cin.ignore();
								cout << "Hidden right behind the now open door is a potion! Yay!" << endl;
								if (character.getPotion() < 5)
								{
									character.setPotion(1);
									cout << "You added that potion to your bag." << endl;
								}
								else
								{
									cout << "It looks like your bag is too full. You put the potion back and walk away." << endl;
								}
								cin.ignore();
								cout << "You also see a shield hanging on the wall. What will you do?" << endl;
								getline(cin, answer);
								if(answer == "grab shield"){
									character.setShield(true);
									cout << "You grab the shield and add it to your inventory!" << endl;
								} else {
									cout << "Welp, thats a shield alright, but apparently you don't want to grab it." << endl;
								}

								finishTrapRoom = true;
								break;

							case 4:
								cout << endl;
								cout << character.showInventory();
								break;
							
							case 5:
								finishTrapRoom = true;

							default:
								cout << "You stand in the room looking blankly at the wall in front of you." << endl;
								cout << "(Try again)" << endl;
								cout << endl;
							break;
						}
					}	// end of trap room
					cout << "You leave the room." << endl;
					cout << endl;
					break;

				case 3:
					system("clear");
					system("cls");
					cout << "You walk over to the center door and slowly try and turn the doorknob." << endl;
					cout << "The doorknob feels rusty, but after a little bit of effort you're able to turn it and open the door." << endl;
					cin.ignore();
					cout << "You found the way to the next room! You let go of the breath you didn't know you were holding and venture to the next room." << endl;
					roomComplete = true;
					cout << endl;
					break;

				case 4:
					system("clear");
					system("cls");
					cout << "Something is drawing you to the right door. Was it divine intervention?" << endl;
					cout << "This door feels light and is easy to open. As you open it a huge gust of wind, as if a big pressure was released, hits you in the face." << endl;
					cin.ignore();
					cout << "The room inside is dark. Even though the previous room was lit, no light passes the threshold of the door." << endl;
					cout << "Something is moving in the corner? As you approach to see what it is, a ragged knight jumps at you!" << endl;
					cin.ignore();

					//Knight fight!!!
					while (!knightDead)
					{
						//Clears console so it doesn't get cluttered
						system("clear");
						system("cls");

						//This section deals with the knight attacking

						randomNum = (rand() % (4 - 1 + 1)) + 1;	//Generates a number 1-4
						if (randomNum == 1 || randomNum == 2 || randomNum == 3) //Allows for a 1 in 4 shot of the attack missing
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
								if (randomNum != 6) //theres a 1 in 6 chance that your attack misses
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

						cin.get();	//Pauses the console a bit so the player can read whats on it before it clears
						cin.ignore();	//Helps pause it

						//Checks if knight's health is 0 or less and exits the while loop if it is
						if (knightHealth <= 0)
						{
							knightDead = true;
						}
					}

					cout << "You killed the knight! Congratulations!" << endl;
					cin.ignore();
					cout << "As you deal the finishing blow, you hear the knight whisper with is dying breath 'I just wanted a hug...'" << endl;
					cout << "The guilt weighs on you, but then you remember there are other doors to open and you forget all about the knight!" << endl;
					cout << "You leave the room." << endl;
					cout << endl;
					break;

				case 5:
					cout << endl;
					cout << character.showInventory();
					break;

				default:
					cout << "You feel as if there was almost something you should be doing, but instead you just stand in the center of the room." << endl;
					cout << "(Try again)" << endl;
					cout << endl;
			}
		}	// end of while loop

	}	//End of if statements

	return roomComplete;
}
