//Coded by Andy and Seth
#include "characterClass.h"	//needed to pass the class as a reference
#include <string>

#pragma once

void playerHelp(){
	
	string answer = "";
	int switchNum = 0;
	bool readyToGo = false;
	
	cout << "___|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__" << endl;
	cout << "_|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|_" << endl;
	cout << "___|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__" << endl;
	cout << "_|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|_" << endl;
	cout << "___|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__" << endl;
	cout << "_|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|_" << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "                      Welcome to Castle Baedcove!!                         " << endl;
	cout << "---------------------------------------------------------------------------" << endl;
	cout << "___|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__" << endl;
	cout << "_|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|_" << endl;
	cout << "___|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__" << endl;
	cout << "_|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|_" << endl;
	cout << "___|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__" << endl;
	cout << "_|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|__|_" << endl;
	cout << endl;
	cout << endl;
	
	while (!readyToGo){
	
	cout << "New to text based games? Want to know how this one works?" << endl;
	cout << "Type 'help' to get a basic breakdown of how this game works." << endl;
	cout << "Type 'start game' to just get on with it." << endl;
	getline(cin, answer);
	
	if (answer == "help") 
	{
		switchNum = 1;
	} else if (answer == "start game")
	{
		switchNum = 2;
	} else 
	{
		switchNum = 3;
	}
	
	switch(switchNum){
		
		case 1:
			system("clear");
			system("cls");
			cout << "This game is so easy don't even sweat it! All things that this game asks" << endl;
			cout << "you to type will be either one or two words. All words need to be in lowercase!" << endl;
			cout << endl;
			cout << "For an example, if the game asks you to type which door(left or right) you want"<< endl;
			cout << "to open, instead of typing 'open the left door' you would just type 'open left'." << endl;
			cout << "Easy, right??" << endl;
			cout << endl;
			cout << "The console will pause to allow you to read, when you're done reading, just hit" << endl;
			cout << "the Enter key once to move on to the next section!" << endl;
			cout << endl;
			cout << "There's a whole world of possibility when it comes to rooms, so don't be afraid" << endl;
			cout << "to type something that we don't tell you is an option! Happy questing!" << endl;
			readyToGo = true;
		break;
		
		case 2:
			cout << endl;
			cout << "Ok! Let's adventure!" << endl;
			readyToGo = true;
		break;
		
		default:
			cout << "If you're struggling now then maybe you should ask for help?" << endl;
			cout << endl;
		break;
	}
	}
	cin.ignore(); //Hits enter one more time to start adventure
}
