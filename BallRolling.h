#include "characterClass.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
//Mohamed Sharif
//Edited in a small way by Andy Lister

#pragma once
 
 bool BallRolling(Player1 & character)
 {
 
 	int answerNum = 0;
 	bool roomComplete = false;
 	string answer = "";
 
 	//Story
	cout << "As the last door shuts behind you, you hear a huge sound like something just collasped and got free. you look around and see a hallway with lights sparkling. Its not dark and not bright, Its pleasing for the eyes as you cantinued your walk to the hallway." << endl;
	cout << "You notice as you walk whats creating the sparkling is gold coins, As you look forward to the hallway you see more and more gold." << endl;
	cout << "you start grabed one gold as you walk through the hallway. You check it to see if it was a gold as you at it, your guts tell you this is the real thing GOLD.  " << endl;
	cout << "As you do so, you feel a floor tile sink into the floor and you hear a click." << endl;
	cout << "Fearing the worst, you still thinking about what was that loud sound." << endl;
	cin.ignore();
	cout << "You feel like you were walking for ever and you see a hole withing the wall where 3 people can fit in. When you saw this hole in the wall you got spoke and nevously step backwards and hit they oposite walk." << endl;
	cout << "You take you sword out and get ready for a fight. The wall you hit your back crumbles and you hear the same sound you heard when you step in this hallway." << endl;
	cout << "You looked around nevously and you Looked back and you see a one of the hallway walls is down, you started running forward and you see the roof falling down and a huge ball shaped rock rolling towards you." << endl;
	cout << "You freek out and run backwards and the walk that crumbled down prevous comes out a big rhino charging towards you. You are stuck in the middle of a charging rhino and a rock rolling towards you." << endl;
	cout << "-- You can enter the hole, fight the rhino, stop the rolling rock. --" << endl;
	
	
	cout << endl;	//Separates it from the story
	while (!roomComplete)
	{
		cout << "What will you do?" << endl;
		getline(cin, answer);

		if (answer == "enter hole")
		{
			answerNum = 1;
		}
		else if (answer == "fight rhino")
		{
			// fight with the rhino 
			answerNum = 2;
		}
		else
		{
			// rolling rock
			answerNum = 3;
		}
		
		switch (answerNum)
		{
			case 1:
				system("clear");
				system("cls");
				
				cout << "Both the rhino and the rock are moving fast, you think to your self can i make it to the hole in side the wall." << endl;
				cout << "You tried moving moving your legs out of fear and you barely move and you still tried running but you are slow." << endl;
				cout << "You stop and put your sword down and take off some of the gold you took, you are so focused to the rock rolling that you didn't look back to check how far the rhino was from you." << endl;
				cout << "The rhino was so close to you then you stood up and ran. you almost avoided a huge damage from the rhino and as you ran forward you noticed that the rock was getting closer too. " << endl;
				cout << "overwhelmed and stressed you almost made to the hole and left your sword behand." << endl;
				cout << "the rhino wasn trying to get in the hole and the rock and the rhino clashed together and the rhino was nocked out." << endl;
				cout << "You now walk to the next door and grabe as much treasure as you can. " <<endl;
				roomComplete = true;
				break;
				
			case 2:
				system("clear");
				system("cls");
				
				cout << "When you see the rhino charging at you and the rock rolling at you, you made a quick a decission on to take on the rhino to use it as a shield against the rock " <<endl;
				cout << " You grabed your sword and stand towards the the rhino's way and you charged to buy time before the rock comes. you grabed the gold rocks and started throwing to the rhino " <<endl;
				cout << "One of the rocks hits the eyes of the rhino and the rhino started to lose coordination and you dodged the rhino charged and you stapped its eye." <<endl;
				cout << "you looked back and the rock is so close and you look around and the rhino with a bleedy eye charging at you, and you are behind the wall and  the rhino charged and you dodged it again and the rhino smashed to the wall and it got stuck." <<endl;
				cout << "The Rock rolling smashed to the rhino and the rock splite to two pieces. The rhino got knock out and bleeding and its its face looks pretty bad and missing teeths and more. " << endl;
				cout << "You now walk to the next door and grabe as much treasure as you can. " <<endl;
				roomComplete = true;
				break;
			
			case 3:
				system("clear");
				system("cls");
				
				cout << "You got smashed to the rolling rock and got smahed to dead. " <<endl;
				
				break;
				
		}
		
		
	}
}
