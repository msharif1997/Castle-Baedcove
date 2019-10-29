//Coded by Andy Lister, aglister@dmacc.edu, 09/18/19

//Team, if this doesn't compile for you, be sure your complier is using C++11
//To do this in Dev C++, go to Tools -> Compiler Options, check the box labeled "Add the following commands when calling the compiler"
//and add in the text entry box, "-std=c++11"

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>	//used for random_shuffle
#include <ctime>	//used for random_shuffle

#include "characterClass.h" //needed to make a new Player1
#include "playerHelp.h" //needed to call playerHelp function
#include "room1.h" //needed to call the room1Function
#include "swordRoom.h" //needed to call swordRoomFunction
#include "openingChamber.h" //needed to call openingChamber function
#include "BlackRoom.h" //needed to call DarkRoomFunction
#include "room3.h" //needed to call room3Function
#include "room7.h" //needed to call room7Function
#include "BallRolling.h"
#include "fateRoom.h" //needed to call fateRoomFunction
#include "finalBossRoom.h" //needed to call bossRoomFunction

using namespace std;


int main()
{
	//Declares 2 arrays of ints and then shuffles them.
	//Used to randomize the rooms in a for loop and if statement combo
	unsigned seed = time(0);
	unsigned seed2 = 1;
	
	int firstHalf [] = {1, 2, 3};
	int secondHalf [] = {1, 2, 3};
	shuffle(firstHalf, firstHalf + 3, default_random_engine(seed));
	shuffle(secondHalf, secondHalf + 3, default_random_engine(seed2));

	
	//Object creation
	Player1 character;
	
	//This section explains the game to the player if they want it
	//and then starts the plot off
	playerHelp();
	openingChamber();
	
	//for loop that randomizes rooms in the first half
	for(int i = 0; i < 3; i++)
	{
		if(firstHalf[i] == 1)
		{
			room1Function(character); //Shield is in this room
		} 
		else if (firstHalf[i] == 2)
		{
			room3Function(character);
		} 
		else
		{
			BallRolling(character);
		}
	}
	
	
	//These are always in the middle
	
	DarkRoomFunction(character);	//mini boss
	swordRoomFunction(character);	//Sword is obviously in this room
	
	
	//for loop that randomizes rooms in the second half
	for(int i = 0; i < 3; i++)
	{
		if(secondHalf[i] == 1)
		{
			room7Function(character);
		} 
		else if (secondHalf[i] == 2)
		{
			//Unable to test this room before prototype release, good luck!
			fateRoomFunction(character);
		}
		else
		{
			//Brinsly was supposed to do one more room, but failed to do his part.
			cout << "You come to an empty room. Literally, it's empty." << endl;
			cout << "There's nothing on the walls, no cabinet to search, no secret door." << endl;
			cout << "You feel as if there was something that was supposed to go there, but much like the person" << endl;
			cout << "who was supposed to design this room, you cant be bothered to put much more thought into it." << endl;
			cout << endl;
			cout << "You leave to room and go on to the next one." << endl;
			cin.ignore();
		}
	}
	
	//Final boss room is always at the end
	bossRoomFunction(character);
	
	system("clear");
	system("cls");
	cout << "Congratulations!! You beat the game!!"<< endl;
	cout << endl;
	cout << "Thank you so much for playing!" << endl;
	cin.ignore();
return 0;
}

