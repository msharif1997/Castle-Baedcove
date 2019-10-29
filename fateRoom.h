//Coded by Brinsly Mbindong Yendeh @bmyendeh@dmacc.edu. 02/08/2019
//This room plays a minigame called the dice of fate. You begin with 15 points and It consists of the user guessing a number between 1 and 6. and 4 dice are being rolled
//If the number you guessed matches any of the rolled dice values, you gain a point but lose a point for every other value which doesn't match
//If your points drop to 0 you lose if not you win.

#include "characterClass.h"	//needed to pass the class as a reference
#include <cstdlib>	//used for random number
#include <ctime>	//used for random number
#include <string>
#include <windows.h> //header file which permits text color change
#include <sstream>	//to use stringstream variables
#include <iostream>

#ifndef fateRoom
#define fateRoom

bool fateRoomFunction(Player1& character) {

	//Pass by reference so it changes the actual class instead of the copy

	HANDLE  hConsole; //for text color manipulation

	//to generate seed which is determined at run time
	unsigned seed = time(0);
	srand(seed);

	string 	staircase_choice,
	        answer_to_guardian,
	        stringFateValue; //string to recieve value of dice.

	stringstream fateConverter; //used to convert stringFateValue to an int

	bool 	giantDead = false, //check if you battled giant
	        roomComplete = false;	//check if you have completed the room

	int diceNum = 4,	//number of dice to be used in dice of fate
	    dices[diceNum],	//array holding the values of all dice of fate.
	    matchingNumber,	//stores the number of times matching values were found during the dice of fate minigame
	    nonMatchingNumber,	//stores the number of times non-matching values were found during the dice of fate minigame
	    points = 15,	//Number of points used to play dice of fate minigame. If points dropto zero you lose
	    randomNum = 0,	//random number generator
	    combatNum = 0,	//Used to attack or use potions during a battle
	    turnCount = 5,	//Number of turns the dice of fate game plays
	    stair_choice,	//stores int of choice on the staircase which is used in switch statement
	    guardian_choice1,	//stores int of choice on the staircase which is used in switch statement
	    giantHealth = 12,	//health of the giant
	    fateValue;	//value the user will guess and will be used in the dice of fate mini-game

	//set the color manipulation template
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

staircase:	//point to return to.

	cout << "Room of fate\n";
	cout << "As you climb this staircase which seems like it's on a mission to kill you, you notice a faint light \n";
	cout << "as you keep the staircase excited, you notice a set of wierd looking stairs which lead to the entrance from where the light come from\n";


	cout << "You are evaluating whether you try jumping over the stairs, throw a rock at it or just running over them. Unable to choose you refer to the voice in your head\n";

	int text_color = 3;
	SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

staircase_decision:	//return point of the satircase_decision goto statement

	cout << "\n\"Hey you voice in my head which keeps telling me what to do. What is the best decision?\" \n";
	getline(cin, staircase_choice);

	if (staircase_choice == "jump" || staircase_choice == "jump stair" || staircase_choice == "jump over" || staircase_choice == "jump stairs")
		stair_choice = 1;
	else if (staircase_choice == "throw rock" || staircase_choice == "throw" || staircase_choice == "test with rock" || staircase_choice == "try rock")
		stair_choice = 2;
	else if (staircase_choice == "run over them" || staircase_choice == "run" || staircase_choice == "run over" || staircase_choice == "running over them")
		stair_choice = 3;
	else {
		cout << "Hey stupid voice in my head I need help choosing which one of my brilliant ideas is the best. I didn't ask for your own thoughts. Let's restart'\n";
		goto staircase_decision;	//go back to the staircase_decision checkpoint
	}

	cout <<"\n\n";

	text_color = 15;
	SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

	switch (stair_choice) {
		case 1:
			cout << "You take a few steps back, take enough momentum and jump over the stair set\n";
			cout << "But you overestimated your phisical abilities and you landed on one of the wierd looking stairs\n";
			cout << "You ignite a trap and you are hit by arrows\n";

			character.setHp(-2);	//lose 2 hp
			if (character.getHp() <= 0) {	//if hp drop to or below 0 end program
				character.gameOver();
			}

			cout << "You lose 2 Hp\n";
			cout << "Your current HP is: " << character.getHp() << endl;
			cout << "You finish climbing the staircase bruised but still alive\n\n";
			break;
		case 2:
			cout << "You pick a rock and throw it on the remaining stairs and you it triggers a trap\n";
			cout << "The stone is bombarded by arows from all directions\n";
			cout << "\"Wow that was close\"\n";
			cout << "You notice something in a crack on the wall\n";

			character.setPotion(1);	//gain a potion

			cout << "You found a potion\n";
			cout << "(Sigh of relief). That was lucky you finish climbing the staircase tired but still alive\n\n";
			break;
		case 3:
			cout << "You take a few steps back and run straight through the remaining stairs\n";
			cout << "But you overestimated your phisical abilities and you slow down on one of the wierd looking stairs\n";
			cout << "You ignite a trap and you are hit by arrows\n";

			character.setHp(-3);	//lose 3 hp
			if (character.getHp() <= 0) {	//if hp drop to or below 0 end program
				character.gameOver();
			}

			cout << "You lose 3 Hp\n";
			cout << "Your current HP is: " << character.getHp() << endl;
			cout << "You finish climbing the staircase bruised but still alive\n\n";
			break;
	}

	cin.get();

	//Clears console so it doesn't get cluttered
	system("clear");
	system("cls");

	cout << "As go through the entrance, you find yourself in a white hall room.\n";
	cout << "Then seemingly out of nowhere a you see a an ghost like figure appear in the hall and introduces himself\n\n";

	text_color = 5;
	SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

	cout << "*Guardian of Fate*\n";
	cout << "\"I am the guardian of fate and this is the hall of fate. No ordinary mortal who enters this hall shall leave.\"\n";
	cout << "\"What are you here for mortal?...\"\n";

	cin.get(); //Pauses the console a bit so the player can read whats on it before it clears

	text_color = 3;
	SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

	cout << "\nYou think to yourself \"this guys is here for my life. I have to think of something if not i'm toast\" \n";

guardian_decision1:	//check point

	cout << "\"I can either lie to him, tell him the truth or stay silent. Hey you voice in my head what do I do?...\"\n";
	getline(cin, answer_to_guardian);

	if(answer_to_guardian == "lie to him" || answer_to_guardian == "lie" || answer_to_guardian == "lie to guardian")
		guardian_choice1 = 1;
	else if(answer_to_guardian == "tell him the truth" || answer_to_guardian == "tell the truth" || answer_to_guardian == "truth")
		guardian_choice1 = 2;
	else if(answer_to_guardian == "stay silent" || answer_to_guardian == "silence" || answer_to_guardian == "silent")
		guardian_choice1 = 3;
	else {
		cout << "\"Hey stupid voice in my head I need help choosing which one of my brilliant ideas is the best. I didn't ask for your own thoughts. let's redo this\"\n";
		goto guardian_decision1;	//return to guardian_decision checkpoint
	}

	text_color = 15;
	SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

	randomNum = rand() % 2;	//generates a random number betweeen 0 and 1

	//Depending on the guardian_decision1 value we can have different outcomes
	switch (guardian_choice1) {

		case 1:
			cout << "\nAfter a little while of silence. you answer\n\n";

			text_color = 3;
			SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

			cout << "\"I am here for... you know... Oh yes I came here to look how the good looking the guardian of fate looked like and I am for sure impressed\" \n";
			if(randomNum == 1) {

				cin.get(); //Pauses the console a bit so the player can read whats on it before it clears

				text_color = 4;
				SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

				cout << "\n*Guardian of Fate*\n";
				cout << "\"Do you take me for a fool?\"\n";
				cout << "\"I will make you pay for lying to guardian of fate himself\"\n";
				cout << "\"come unto me GIANT OF TRUTH\"\n";

				cin.get(); //Pauses the console a bit so the player can read whats on it before it clears

				text_color = 15;
				SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

				cout << "An angry looking Giant falls from sky and assaults you\n";
				cout << "A battle starts \n";
				//Giant fight!!!

				cin.get(); //Pauses the console a bit so the player can read whats on it before it clears

				//Clears console so it doesn't get cluttered
				system("clear");
				system("cls");

				while(!giantDead) {
					//This section deals with the giant attacking
					cout << "The Giant hurls a giant stone at you! \n";

					randomNum = (rand() % (3 - 1 + 1)) + 1; //Generates a number 1-2

					cin.get(); //Pauses the console a bit so the player can read whats on it before it clears

					if(randomNum == 1 || randomNum == 2) {	//Allows for a 1 in 3 shot of the attack missing
						cout << endl; //Little bit of space

						//Determines if you have a shield or not and then subtracts damage
						cout << "The stone hits you head on. You for 2 damage!" << endl;
						if(character.getShield()) {
							cout << "Your shield took a point of damage for you!" << endl;
							character.setHp(-1);
						} else {
							character.setHp(-2);
						}
						cout << "Your current HP is: " << character.getHp() << endl;
					} else {
						cout << endl;
						cout << "You manage to dodge with an acrobatic back flip\n";
					}
					if (character.getHp() <= 0) {	//if hp drop to or below 0 end program
						character.gameOver();
					}

					text_color = 3;
					SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

					cout << "\n\"You will pay for this stupid giant\"\n";
					cout << endl;
					//End of giant's turn

					text_color = 15;
					SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

					//Character choice
					cout << "What will you do?" << endl;
					cout << "1 - Sword attack \t 2 - Drink potion" << endl;
					cin >> combatNum;
					cout << endl; //Little bit of space

					//Player's move is in this area
					switch(combatNum) {
						case 1:
							randomNum = rand() % 2;
							if (randomNum == 1)
								cout << "You use a samurai spinning slash!\n";
							else
								cout << "You use the ninja shadow walk\n";

							randomNum = (rand() % (6 - 1 + 1)) + 1; //Generates a number 1-2

							if (randomNum != 6) { //theres a 1 in 6 chance that your attack misses
								if(character.getSword()) {
									cout << "Critical hit! Your attack does 3 damage!" << endl;
									giantHealth = giantHealth - 3;
								} else {
									cout << "Your attack does 2 damage!" << endl;
									giantHealth = giantHealth - 2;
									cout << "The giant's current health is: " << giantHealth;
									cout << endl;
								}
							} else {
								cout << "Your attack misses my an inch!" << endl;

								text_color = 1;
								SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

								cout << "\n\"I will get you lucky piece of $#!t\"\n";
								cout << endl;
							}
							break;

							text_color = 15;
							SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

						case 2:
							if(character.getPotion() != 0) {
								cout << "You used a potion!" << endl;
								character.setHp(20);
								cout << "Your current HP is: " << character.getHp() << endl;
							} else {
								cout << "You don't have any potions left! what are you doing?" << endl;
								cout << "Your current HP is: " << character.getHp() << endl;
							}
							break;

						default:
							cout << "You do nothing while the giant gets ready for another strike" << endl;
							cout << "too bad the giant is ready to strike" << endl;
					}
					cin.get(); //Pauses the console a bit so the player can read whats on it before it clears

					//Checks if knight's health is 0 or less and exits the while loop if it is
					if(giantHealth <= 0) {
						giantDead = true;
					}
				}
			} else {

				text_color = 4;
				SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

				cout << "\n*Guardian of Fate*\n";
				cout << "\"I see you have good taste. I will give you a chance to save yourself\"\n";
				cout << "\"You will participate in dice of fate.\"\n";
				cout << "\"If you win you will make it out of here else you will perish for trespassing sacred grounds\"\n";
				cout << "\"Let the dice of FATE decide your future\"\n";

				cin.get(); //Pauses the console a bit so the player can read whats on it before it clears

				text_color = 15;
				SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

				cout <<"\n\n\t\t Suddenly out of nowhere three giant dice appear\n\n";

				cin.get(); //Pauses the console a bit so the player can read whats on it before it clears

				text_color = 4;
				SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

				cout << "*Guardian of Fate*\n";
				cout << "\"The concept is simple. You start with 15 points. You can call a value and roll these dice up to 5 times.\"\n";
				cout << "\"If the number you called is equal to the amount rolled by at least 1 dice, you recieve points equal to the number of dice which equal said number\"\n";
				cout << "\"ut if not you lose points up to the number of dice not equal to the number you called. If your points drop below 0 you die.\"\n";
				cout << "\"Let's start\"\n";

				cin.get(); //Pauses the console a bit so the player can read whats on it before it clears

				text_color = 15;
				SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

				//Clears console so it doesn't get cluttered
				system("clear");
				system("cls");

				for (int i = 0; i < turnCount; i++) {
					matchingNumber = 0;
					nonMatchingNumber = 0;
					cout << "Turn " << i + 1 << " : number of points: " << points << "\n";	//displays number of points and current turn

					do {
						cout << "\t\tChoose the number which will decide your fate \n";
						getline(cin, stringFateValue);
						fateConverter << stringFateValue;	//use the sstream to convert string input to an int and clear the sstream for reuse
						fateConverter >> fateValue;
						fateConverter.str("");
						fateConverter.clear();

						if(fateValue < 1 || fateValue > 6) {
							cout << "\t\tDont be stupid. The dice can only output values from 1 to 6.\n\n";
						}
					} while (fateValue < 1 || fateValue > 6);

					cout << "\t\tNow let the dice of fate decide your fate\n\n";
					for(int dice = 0; dice < diceNum; dice++) {
						dices[dice] = rand() % 6 + 1;
						cout << "\t\tDice " << dice + 1 << " : " << dices[dice];
					}
					for(int dice = 0; dice < diceNum; dice++) {
						if (fateValue == dices[dice]) {
							matchingNumber++;
						} else {
							nonMatchingNumber++;
						}
					}
					points = points + matchingNumber - nonMatchingNumber;

					cout << "\n\t\tYou have got " << matchingNumber << " values right\n";
					cout << "\t\tYou have got " << nonMatchingNumber << " values wrong\n";
					cout << "\t\tYou have " << points << " points remaining.\n";
					if(points <= 0) {
						cout << "\t\tYou try to run for your life....\n";

						cin.get();

						cout << "\t\tbut its too late!\n";
						cout << "\t\tThe sky above you opens like wide and a beam of light falls down unto you engulfing\n";
						cout << "\t\tGAME OVER!";

						cin.get(); //Pauses the console a bit so the player can read whats on it before it clears
						exit(-1);
					}
				}
			}

			break;
		case 2:
			cout << "\nAfter a little while of silence. you answer\n";

			text_color = 3;
			SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

			cout << "\"I came here to find the great treasure of the Alps so I can become rich and and live a lavish lifestyle surounded by cars and hot chicks\"\n";
			if(randomNum == 1) {

				text_color = 4;
				SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

				cout << "\n*Guardian of Fate*\n";
				cout << "\"I can't let someone with such selfish plans leave this room.\"\n";
				cout << "\"This room shall your grave\"\n";
				cout << "\"Come unto me GIANT OF TRUTH\"\n";

				cin.get(); //Pauses the console a bit so the player can read whats on it before it clears

				text_color = 15;
				SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

				cout << "An angry looking Giant falls from sky and assaults you\n";
				cout << "A battle starts \n";
				//Giant fight!!!

				cin.get(); //Pauses the console a bit so the player can read whats on it before it clears

				//Clears console so it doesn't get cluttered
				system("clear");
				system("cls");

				while(!giantDead) {
					//This section deals with the giant attacking
					cout << "The Giant hurls a giant stone at you! \n";

					randomNum = (rand() % (3 - 1 + 1)) + 1; //Generates a number 1-2

					cin.get(); //Pauses the console a bit so the player can read whats on it before it clears

					if(randomNum == 1 || randomNum == 2) {	//Allows for a 1 in 3 shot of the attack missing
						cout << endl; //Little bit of space

						//Determines if you have a shield or not and then subtracts damage
						cout << "The stone hits you head on. You for 2 damage!" << endl;
						if(character.getShield()) {
							cout << "Your shield took a point of damage for you!" << endl;
							character.setHp(-1);
						} else {
							character.setHp(-2);
						}
						cout << "Your current HP is: " << character.getHp() << endl;
					} else {
						cout << endl;
						cout << "You manage to dodge with an acrobatic back flip\n";
					}
					if (character.getHp() <= 0) {	//if hp drop to or below 0 end program
						character.gameOver();
					}

					text_color = 3;
					SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

					cout << "\n\"You will pay for this stupid giant\"\n";
					cout << endl;
					//End of giant's turn

					text_color = 15;
					SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

					//Character choice
					cout << "What will you do?" << endl;
					cout << "1 - Sword attack \t 2 - Drink potion" << endl;
					cin >> combatNum;
					cout << endl; //Little bit of space

					//Player's move is in this area
					switch(combatNum) {
						case 1:
							randomNum = rand() % 2;
							if (randomNum == 1)
								cout << "You use a samurai spinning slash!\n";
							else
								cout << "You use the ninja shadow walk\n";
							randomNum = (rand() % (6 - 1 + 1)) + 1; //Generates a number 1-2
							if (randomNum != 6) { //theres a 1 in 6 chance that your attack misses
								if(character.getSword()) {
									cout << "Critical hit! Your attack does 3 damage!" << endl;
									giantHealth = giantHealth - 3;
								} else {
									cout << "Your attack does 2 damage!" << endl;
									giantHealth = giantHealth - 2;
									cout << "The giant's current health is: " << giantHealth;
									cout << endl;
								}
							} else {
								cout << "Your attack misses my an inch!" << endl;

								text_color = 1;
								SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

								cout << "\n\"I will get you lucky piece of $#!t\"\n";
								cout << endl;
							}
							break;

							text_color = 15;
							SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

						case 2:
							if(character.getPotion() != 0) {
								cout << "You used a potion!" << endl;
								character.setHp(20);
								cout << "Your current HP is: " << character.getHp() << endl;
							} else {
								cout << "You don't have any potions left! what are you doing?" << endl;
								cout << "Your current HP is: " << character.getHp() << endl;
							}
							break;

						default:
							cout << "You do nothing while the giant gets ready for another strike" << endl;
							cout << "too bad the giant is ready to strike" << endl;
					}
					cin.get(); //Pauses the console a bit so the player can read whats on it before it clears

					//Checks if knight's health is 0 or less and exits the while loop if it is
					if(giantHealth <= 0) {
						giantDead = true;
					}
				}
			} else {

				text_color = 4;
				SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

				cout << "\n*Guardian of Fate*\n";
				cout << "\"I see you are a big dreamer. I will give you a chance to realize those dreams of yours\"\n";
				cout << "\"You will participate in dice of fate.\"\n";
				cout << "\"If you win you will make it out of here else you will perish for trespassing sacred grounds\"\n";
				cout << "\"Let the dice of FATE decide your future\"\n";

				cin.get(); //Pauses the console a bit so the player can read whats on it before it clears

				text_color = 15;
				SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

				cout <<"\n\n\t\t Suddenly out of nowhere three giant dice appear\n\n";

				text_color = 4;
				SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

				cin.get(); //Pauses the console a bit so the player can read whats on it before it clears

				cout << "*Guardian of Fate*\n";
				cout << "\"The concept is simple. You start with 15 points. You can call a value and roll these dice up to 5 times.\"\n";
				cout << "\"If the number you called is equal to the amount rolled by at least 1 dice, you recieve points equal to the number of dice which equal said number\"\n";
				cout << "\"but if not you lose points up to the number of dice not equal to the number you called. If your points drop below 0 you die.\"\n";
				cout << "\"Let's start\"\n";

				cin.get(); //Pauses the console a bit so the player can read whats on it before it clears

				//Clears console so it doesn't get cluttered
				system("clear");
				system("cls");

				text_color = 15;
				SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

				for (int i = 0; i < turnCount; i++) {
					matchingNumber = 0;
					nonMatchingNumber = 0;
					cout << "Turn " << i + 1 << " : number of points: " << points << "\n";	//displays number of points and current turn

					do {
						cout << "\t\tChoose the number which will decide your fate \n";
						getline(cin, stringFateValue);
						fateConverter << stringFateValue;	//use the sstream to convert string input to an int and clear the sstream for reuse
						fateConverter >> fateValue;
						fateConverter.str("");
						fateConverter.clear();

						if(fateValue < 1 || fateValue > 6) {
							cout << "\t\tDont be stupid. The dice can only output values from 1 to 6.\n\n";
						}
					} while (fateValue < 1 || fateValue > 6);

					cout << "\t\tNow let the dice of fate decide your fate\n\n";
					for(int dice = 0; dice < diceNum; dice++) {
						dices[dice] = rand() % 6 + 1;
						cout << "\t\tDice " << dice + 1 << " : " << dices[dice];
					}
					for(int dice = 0; dice < diceNum; dice++) {
						if (fateValue == dices[dice]) {
							matchingNumber++;
						} else {
							nonMatchingNumber++;
						}
					}
					points = points + matchingNumber - nonMatchingNumber;

					cout << "\n\t\tYou have got " << matchingNumber << " values right\n";
					cout << "\t\tYou have got " << nonMatchingNumber << " values wrong\n";
					cout << "\t\tYou have " << points << " points remaining.\n";
					if(points <= 0) {
						cout << "\t\tYou try to run for your life....\n";

						cin.get();

						cout << "\t\tbut its too late!\n";
						cout << "\t\tThe sky above you opens like wide and a beam of light falls down unto you engulfing\n";
						cout << "\t\tGAME OVER!";

						cin.get(); //Pauses the console a bit so the player can read whats on it before it clears
						exit(-1);
					}
				}
			}

			break;
		case 3:

			text_color = 4;
			SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

			cout << "\n*Guardian of Fate*\n";
			cout << "\"I see you have are a wise person. But I need to test your honesty\"\n";

restart:

			cout << "\"You will participate in dice of fate to.\"\n";
			cout << "\"If you win you will make it out of here else you will perish for trespassing sacred grounds\"\n";
			cout << "\"Let the dice of FATE decide your future\"\n";


			cin.get(); //Pauses the console a bit so the player can read whats on it before it clears

			text_color = 15;
			SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

			cout <<"\n\n\t\t Suddenly out of nowhere three giant dice appear\n\n";

			cin.get(); //Pauses the console a bit so the player can read whats on it before it clears

			text_color = 4;
			SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

			cout << "*Guardian of Fate*\n";
			cout << "\"The concept is simple. You start with 15 points. You can call a value and roll these dice up to 5 times.\"\n";
			cout << "\"If the number you called is equal to the amount rolled by at least 1 dice, you recieve points equal to the number of dice which equal said number\"\n";
			cout << "\"ut if not you lose points up to the number of dice not equal to the number you called. If your points drop below 0 you die.\"\n";
			cout << "\"Let's start\"\n";

			cin.get(); //Pauses the console a bit so the player can read whats on it before it clears

			//Clears console so it doesn't get cluttered
			system("clear");
			system("cls");

			text_color = 15;
			SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

			for (int i = 0; i < turnCount; i++) {
				matchingNumber = 0;
				nonMatchingNumber = 0;
				cout << "Turn " << i + 1 << " : number of points: " << points << "\n";	//displays number of points and current turn

				do {
					cout << "\t\tChoose the number which will decide your fate \n";
					getline(cin, stringFateValue);
					fateConverter << stringFateValue;	//use the sstream to convert string input to an int and clear the sstream for reuse
					fateConverter >> fateValue;
					fateConverter.str("");
					fateConverter.clear();

					if(fateValue < 1 || fateValue > 6) {
						cout << "\t\tDont be stupid. The dice can only output values from 1 to 6.\n\n";
					}
				} while (fateValue < 1 || fateValue > 6);

				cout << "\t\tNow let the dice of fate decide your fate\n\n";
				for(int dice = 0; dice < diceNum; dice++) {
					dices[dice] = rand() % 6 + 1;
					cout << "\t\tDice " << dice + 1 << " : " << dices[dice];
				}
				for(int dice = 0; dice < diceNum; dice++) {
					if (fateValue == dices[dice]) {
						matchingNumber++;
					} else {
						nonMatchingNumber++;
					}
				}
				points = points + matchingNumber - nonMatchingNumber;

				cout << "\n\t\tYou have got " << matchingNumber << " values right\n";
				cout << "\t\tYou have got " << nonMatchingNumber << " values wrong\n";
				cout << "\t\tYou have " << points << " points remaining.\n";
				if(points <= 0) {
					cout << "\t\tYou try to run for your life....\n";

					cin.get();

					cout << "\t\tbut its too late!\n";
					cout << "\t\tThe sky above you opens like wide and a beam of light falls down unto you engulfing\n";
					cout << "\t\tGAME OVER!";

					cin.get(); //Pauses the console a bit so the player can read whats on it before it clears
					exit(-1);
				}
			}
			break;
	}
	if (points < 8) {
		text_color = 4;
		SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

		cout << "\n*Guardian of fate*\n";
		cout << "\"You barely made it. But I will respect my word and let you go\"\n";

		text_color = 15;
		SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

		cout << "\nA beam of light falls upon you and teleports you out of the room\n";

		cin.get(); //Pauses the console a bit so the player can read whats on it before it clears

		return !roomComplete;	//return to main program
	} else if (points == 15 && giantDead == true) {	//If you defeated the giant and havent's participated yet in the dice of fate minigame.

		text_color = 4;
		SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

		cout << "\n*Guardian of fate*\n";
		cout << "\"I see you were able to defeat the giant\"\n";
		cout << "\"could it be that fate is on your side\"\n";
		cout << "\"Human your act of courage has impressed me. Now you have a chance to save your life\"\n\n";

		goto restart;	//return to restart checkpoint

	} else {
		text_color = 4;
		SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

		cout << "\n*Guardian of fate*\n";
		cout << "\"Looks like fate is on your side mortal\"\n";
		cout << "\"You have triumphed of this challenge\"\n";
		cout << "\"You have won my respects and the right to leave alive with this reward\"\n";

		text_color = 15;
		SetConsoleTextAttribute(hConsole,text_color);	//Change text color to show characters thoughts

		cout << "A sword slowly falls from the sky glowing in light\n";
		cout << "You grab the sword and stored it\n";
		     character.setSword(true);


		cout << "You recieved a sword\n";
		cout << "A beam of light falls upon you and teleports you out of the room\n";

		cin.get(); //Pauses the console a bit so the player can read whats on it before it clears

		return !roomComplete;
	}
}

#endif
