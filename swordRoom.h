//Coded by Andy Lister, aglister@dmacc.edu, 09/30/19
#include "characterClass.h"	//needed to pass the class as a reference


#pragma once

bool swordRoomFunction(Player1& character)
{

	string answer = "";
	string swordAnswer1 = "";
	bool answer1 = false;
	string swordAnswer2 = "";
	bool answer2 = false;
	string swordAnswer3 = "";
	bool answer3 = false;
	bool roomComplete = false;
	bool swordRetrieved = false;
	bool riddlesAnswered = false;
	bool doneWithRiddles = false;


	system("clear");
	system("cls");
	//Story
	cout << "As the previous door shuts behind you with a click, you wonder what you've gotten yourself into." << endl;
	cout << "The room is dark (and probably full of terrors), but even though you can't see," << endl;
	cout << "you decide to take a step forward into the room." << endl;
	cout << "As you do so, you feel a floor tile sink into the floor and you hear a click." << endl;
	cout << "Fearing the worst, you stay still as you wait for something to happen." << endl;
	cin.ignore();
	cout << "You hear gears start to spin. As they spin faster and faster you notice the room is lighting up." << endl;
	cout << "Looking up, you notice that a section of the roof is retracting to give you light." << endl;
	cout << "Looking back down, you can now see that there is a sword stuck upright in stone in the center of the room." << endl;
	cout << "-- You can leave the room, as you suspect this might be a trap, or inspect the sword. --" << endl;

	cout << endl;	//Separates it from the story
	int answerNum = 0;	//Used to change string to num
	while (!roomComplete)
	{
		cout << "What will you do?" << endl;
		getline(cin, answer);

		if (answer == "inspect sword")
		{
			answerNum = 1;
		}
		else if (answer == "leave room")
		{
			answerNum = 2;
		}
		else
		{
			answerNum = 3;
		}

		switch (answerNum)
		{
			case 1:
				system("clear");
				system("cls");

				cout << "As you approach the sword, you can't help but marvel at its beauty." << endl;
				cout << "It has a bright silver blade and a deep purple hilt. You can see a glowing, yellow triangular jewel" << endl;
				cout << "rests at the midpoint on the cross-guard pointing down towards the point of the sword." << endl;
				cout << "You see some words in the stone at the base of the sword covered in dust, but the desire to pull" << endl;
				cout << "out the sword is pretty overwhelming." << endl;

				while (!swordRetrieved)
				{
					cout << endl;
					cout << "What will you do?" << endl;
					getline(cin, answer);
					if (answer == "pull sword")
					{
						answerNum = 1;
					}
					else if (answer == "read words" || answer == "read stone")
					{
						answerNum = 2;
					}
					else
					{
						answerNum = 3;
					}

					switch (answerNum)
					{
						case 1:
							system("clear");
							system("cls");
							cout << "Ignoring all common sense you go straight to trying to pull out the sword." << endl;
							cout << "You take 5 points of health damage." << endl;
							character.setHp(-5);
							character.gameOver();
							cout << "Your current HP is " << character.getHp() << endl;
							cout << "You see some words in the stone at the base of the sword." << endl;
							break;

						case 2:
							while (!doneWithRiddles)
							{
								system("clear");
								system("cls");
								cout << "You dust off the words at the bottom of the stone." << endl;
								cout << "They read:" << endl;
								cout << endl;
								cout << "Here is my gift to aid in your quest." << endl;
								cout << "But to get it, you must be the best." << endl;
								cout << endl;
								cout << "Answer me these riddles three," << endl;
								cout << "And your best this sword will surely see." << endl;
								cout << endl;
								cout << "If you try to grab it and run," << endl;
								cout << "With you, this sword shall be so done." << endl;
								cin.ignore();
								cout << "You wonder what that could possibly mean, when an overpowering voice sounds in your head." << endl;
								cout << endl;
								cout << "A NEW CHAMPION! VERY WELL." << endl;
								cin.ignore();
								cout << "IF THE SUM OF A NUMBER'S DIGITS ADD UP TO ME" << endl;
								cout << "THEN I SHALL CERTAINLY DIVIDE EVENLY" << endl;
								cout << "WHAT AM I?" << endl;
								getline(cin, swordAnswer1);
								if (swordAnswer1 == "three" || swordAnswer1 == "3" || swordAnswer1 == "THREE")
								{
									answer1 = true;
								}

								cout << endl;
								cout << "GETTING THE < SYMBOL IS A SIGN OF THE LESSER" << endl;
								cout << "BUT ADD ME TO IT AND YOU'LL SURELY BE BETTER" << endl;
								cout << "WHAT AM I?" << endl;
								getline(cin, swordAnswer2);
								if (swordAnswer2 == "three" || swordAnswer2 == "3" || swordAnswer2 == "THREE")
								{
									answer2 = true;
								}

								cout << endl;
								cout << "THE ANSWER TO THIS RIDDLE IS FOUND BELOW" << endl;
								cout << "USE YOUR EYES AND YOU SHALL SURELY KNOW" << endl;
								cout << "WHAT IS THE ANSWER?" << endl;
								getline(cin, swordAnswer3);
								if (swordAnswer3 == "three" || swordAnswer3 == "3" || swordAnswer3 == "THREE")
								{
									answer3 = true;
								}

								if (answer1, answer2, answer3)
								{
									riddlesAnswered = true;
									doneWithRiddles = true;
									cout << endl;
									cout << "CONGRATULATIONS YOU'VE PASSED THE TEST." << endl;
									cout << "I CERTAINLY KNOW NOW THAT YOU'RE THE BEST." << endl;
									cin.ignore();
								}
								else
								{
									cout << endl;
									cout << "IT TURNS OUT I'M STILL SMARTER THAN THOU" << endl;
									cout << "TELL ME, WILL YOU GIVE UP NOW?" << endl;
									cout << "(You may -give up- or -try again-, What will you do?)" << endl;
									getline(cin, answer);
									if (answer == "give up")
									{
										doneWithRiddles = true;
									}
								}
							}

							if (riddlesAnswered)
							{
								system("clear");
								system("cls");
								cout << "With that last statement you feel the sword's presence fade from your mind." << endl;
								cout << "You're very thankful that the sword has stopped yelling at you." << endl;
								cout << "Upon closer inspection, you see that the yellow triangular jewel" << endl;
								cout << "is glowing brighter than ever before. You go to take the sword out..." << endl;
								cin.ignore();
								cout << "And you find that the sword slides out easily!" << endl;
								cout << "You hold it triumphantly above your head before adding it to your inventory." << endl;
								swordRetrieved = true;
								character.setSword(true);
								cout << "You hear a click and notice that a door just appeared in the wall in front of you." << endl;
								cout << "You leave through that door." << endl;
								roomComplete = true;
							}
							else
							{
								system("clear");
								system("cls");
								cout << "You no longer hear the sword's voice in your head." << endl;
								cout << "You see a door open in the wall at the far side of the room." << endl;
								cout << "You feel as if you are no longer welcome in the chamber" << endl;
								cout << "and hurry into the next room." << endl;
								swordRetrieved = true;	//Still has to be true to exit while loop. We dont give them a sword.
								roomComplete = true;
							}

							break;

						case 3:
							cout << "The sword is still overwhelming you with its beauty, but you're starting to think" << endl;
							cout << "its weird to just keep staring at the sword." << endl;
							cout << "(Try again)" << endl;
							break;
					}
				}

				break;

			case 2:
				system("clear");
				system("cls");
				cout << "Not wanting to take any chances, you leave the room without approaching the sword." << endl;
				cout << "Was that wise? Probably not. But are you safe? ....for now, yes." << endl;
				roomComplete = true;
				break;

			case 3:
				cout << "You know there are only two options, and yet you stand still." << endl;
				cout << "(Try again)" << endl;
				break;
		}
	}

	return roomComplete;

}
