/////////////////////////////////////////////////////
// Seth Huffman
/////////////////////////////////////////////////////
//edited in a very small way by Andy Lister
#include "characterClass.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream> 

#pragma once

bool room3Function(Player1& character)
{

    unsigned seed = time(0);
    srand(seed);
    int randomNum = (rand() % (3 - 1 + 1)) + 1;
    string answer = "";
    bool roomComplete = false;

    bool knightDead = false;
    int knightHealth = 10;
    int combatNum = 0;


    system("clear");
    system("cls");

    cout << "After turning a corner you see a hall way, empty and lined with bricks." << endl; 
    cout << "You could swear it goes on for miles. BOOM!" << endl; 
    cout << "You start to hear a clicking noise that repeats over and over again." << endl; 
    cout << "As if a gear was connected to a chain." << endl;
    cout << "Next you notice that one wall is slowly coming down in front of you and one behind you." << endl; 
    cout << "Making it so that you will be trapped." << endl; 
    cout << "You know if you if sprint now you might make it but you will be trapped inside." << endl; 
    cout << "All of the sudden you see a shovel next to some grease." << endl;


    if (randomNum == 1) {

        cout << endl;
        int answerNum = 0;


        while (!roomComplete) {
            cout << "What will you do?" << endl;
            getline(cin, answer);
            cout << endl;

            if (answer == "grab shovel") {
                answerNum = 1;
            }
            else if (answer == "grab grease") {
                answerNum = 2;
            }
            else if (answer == "sprint") {
                answerNum = 3;
            }
            else if (answer == "show inventory") {
                answerNum = 4;
            }
            else {
                answerNum = 5;
            }
            switch (answerNum) {
            case 1:
                cout << "Perfect! You jammed the shovel under the door to give yourself more time to get out." << endl;
                cout << "Great quick thinking." << endl;
                cin.ignore();
                cout << "Its a treasure chest! Yay! +1 potion has been added to your inventory." << endl;
                if (character.getPotion() < 5) {
                    character.setPotion(1);
                }
                else {
                    cout << "It looks like your bag is too full. You put the potion back and walk away." << endl;
                }
                roomComplete = true;
                cout << endl;
                break;

            case 2:
                system("clear");
                system("cls");
                cout << "The grease didn't work out as planned." << endl;
                cout << "You greased up and as the door closed on you it shot you out backwards from under it like the" << endl;
				cout << "grease bullet you are and hit the wall." << endl;
				character.setHp(-1);
				character.gameOver();
				cout << endl;
				cout << "Your current HP is " << character.getHp() << endl;
                cout << endl;
                break;
            case 3:
                system("clear");
                system("cls");
                cout << "WHAT ARE YOU DOING!?!" << endl;
                cout << "After taking off and trying to make it in time before the wall closes you damage your ankle..." << endl;
                character.setHp(-2);
                character.gameOver();
                cout << endl;
                cout << "Your current HP is " << character.getHp() << endl;
                cin.ignore();
                break;
            case 4:
                cout << endl;
                cout << character.showInventory();	
		        break;
            default:
                cout << "You feel as if there was almost something you should be doing, but instead you just stand in the center of the room." << endl;
                cout << "(Try again)" << endl;
                cout << endl;
            }
        }
    }
    else if (randomNum == 2) {
     
        cout << endl;
        int answerNum = 0;

        int noteNum = 0;
        bool finishTrapRoom = false;

        while (!roomComplete) {
            cout << "What will you do?" << endl;
            getline(cin, answer);
            cout << endl;

            if (answer == "sprint") {
                answerNum = 1;
            }
            else if (answer == "grab shovel") {
                answerNum = 2;
            }
            else if (answer == "grab grease") {
                answerNum = 3;
            }
            else if (answer == "show inventory") {
                answerNum = 4;
            }
            else {
                answerNum = 5;
            }
            switch (answerNum) {
            case 1:
                system("clear");
                system("cls");
                cout << "WHAT ARE YOU DOING!?!" << endl;
                cout << "After taking off and trying to make it in time before the wall closes you damage your ankle..." << endl;
                character.setHp(-2);
                character.gameOver();
                cout << endl;
                cout << "Your current HP is " << character.getHp() << endl;
                cin.ignore();
                break;

            case 2:
                cout << "Perfect! You jammed the shovel under the door to give yourself more time to get out." << endl;
                cout << "Great quick thinking." << endl;
                cin.ignore();
                cout << "Its a treasure chest! Yay! +1 potion has been added to your inventory." << endl;
                if (character.getPotion() < 5) {
                    character.setPotion(1);
                }
                else {
                    cout << "It looks like your bag is too full. You put the potion back and walk away." << endl;
                }
                roomComplete = true;
                cout << endl;
                break;
            case 3:
                system("clear");
                system("cls");
                cout << "The grease didn't work out as planned." << endl;
                cout << "You greased up and as the door closed on you it shot you out backwards from under it like the" << endl;
				cout << "grease bullet you are and hit the wall." << endl;
				character.setHp(-1);
				character.gameOver();
				cout << endl;
				cout << "Your current HP is " << character.getHp() << endl;
                cout << endl;
                break;

            case 4:
                cout << endl;
                cout << character.showInventory();	
		        break;
            default:
                cout << "You feel as if there was almost something you should be doing, but instead you just stand in the center of the room." << endl;
                cout << "(Try again)" << endl;
                cout << endl;
            }
        }
    } 
    else {
     
        cout << endl;
        int answerNum = 0;

        int noteNum = 0;
        bool finishTrapRoom = false;

        while (!roomComplete) {
            cout << "What will you do?" << endl;
            getline(cin, answer);
            cout << endl;

            if (answer == "grab grease ") {
                answerNum = 1;
            }
            else if (answer == "sprint") {
                answerNum = 2;
            }
            else if (answer == "grab shovel") {
                answerNum = 3;
            }
            else if (answer == "show inventory") {
                answerNum = 4;
            }
            else {
                answerNum = 5;
            }
            switch (answerNum) {
            case 1:
                system("clear");
                system("cls");
                cout << "The grease didn't work out as planned." << endl;
                cout << "You greased up and as the door closed on you it shot you out backwards from under it like the" << endl;
				cout << "grease bullet you are and hit the wall." << endl;
				character.setHp(-1);
				character.gameOver();
				cout << endl;
				cout << "Your current HP is " << character.getHp() << endl;
                cout << endl;
                break;

            case 2:
                system("clear");
                system("cls");
                cout << "WHAT ARE YOU DOING!?!" << endl;
                cout << "After taking off and trying to make it in time before the wall closes you damage your ankle..." << endl;
                character.setHp(-2);
                character.gameOver();
                cout << endl;
                cout << "Your current HP is " << character.getHp() << endl;
                cin.ignore();
                break;
                
            case 3:
                cout << "Perfect! You jammed the shovel under the door to give yourself more time to get out." << endl;
                cout << "Great quick thinking." << endl;
                cin.ignore();
                cout << "Its a treasure chest! Yay! +1 potion has been added to your inventory." << endl;
                if (character.getPotion() < 5) {
                    character.setPotion(1);
                }
                else {
                    cout << "It looks like your bag is too full. You put the potion back and walk away." << endl;
                }
                roomComplete = true;
                cout << endl;
                break;
            case 4:
                cout << endl;
                cout << character.showInventory();	
		        break;
            default:
                cout << "You feel as if there was almost something you should be doing, but instead you just stand in the center of the room." << endl;
                cout << "(Try again)" << endl;
                cout << endl;
            }
        }
    }

    return roomComplete;
}
