/////////////////////////////////////////////////////
// Seth Huffman
/////////////////////////////////////////////////////
//edited in a very small way by Andy Lister

#include "characterClass.h"
#include <cstdlib>
#include <ctime>

#pragma once

bool room7Function(Player1& character)
{

    unsigned seed = time(0);
    srand(seed);
    int randomNum = (rand() % (3 - 1 + 1)) + 1;
    string answer = "";
    bool roomComplete = false;


    system("clear");
    system("cls");

    cout << "Holy goats, they are everywhere!" << endl; 
    cout << "Right in front of you is a sign that says please keep room closed and locked at all times." << endl; 
    cout << "After that it read, key for locking and unlocking the room is on a hook on the other side of the room" << endl; 
    cout << "You look up, see the hook but no key..." << endl;
    cout << "It appears the goats might have thought it was food." << endl; 
    cout << "Might have to search their poop to get out of this one..." << endl; 
    cout << "You survey the room and see three piles of poop." << endl; 


    if (randomNum == 1) {

        cout << endl;
        int answerNum = 0;


        while (!roomComplete) {
            cout << "Do you search left, right or center poop?" << endl;
            getline(cin, answer);
            cout << endl;

            if (answer == "search left") {
                answerNum = 1;
            }
            else if (answer == "search center") {
                answerNum = 2;
            }
            else if (answer == "search right") {
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
                cout << "God, this is gross..." << endl;
                cout << "but good thing you chose the right pile of poop" << endl;
                cin.ignore();
                roomComplete = true;
                cout << "Its a key and a potion! +1 potion has been added to your inventory." << endl;
                if (character.getPotion() < 5) {
                    character.setPotion(1);
                }
                else {
                    cout << "It looks like your bag is too full. You put the potion back and walk away." << endl;
                }
                cout << endl;
                break;

            case 2:
                system("clear");
                system("cls");
                cout << "God, this is gross... " << endl;
                cout << "and one goat is pooping next to you." << endl;
                cout << "He doesn't like that and kicks you in the head." << endl;
                character.setHp(-2);
                character.gameOver();
                cout << endl;
                cout << "Your current HP is " << character.getHp() << endl;
                cout << endl;
                break;
            case 3:
                system("clear");
                system("cls");
                cout << "God, this is gross... " << endl;
                cout << "The smell of this pile is getting way to much to handle and you take damage from the smell." << endl;
                character.setHp(-1);
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

        while (!roomComplete) {
            cout << "Do you search left, right or center poop?" << endl;
            getline(cin, answer);
            cout << endl;

            if (answer == "search right") {
                answerNum = 1;
            }
            else if (answer == "search left") {
                answerNum = 2;
            }
            else if (answer == "search center") {
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
                cout << "God, this is gross... " << endl;
                cout << "The smell of this pile is getting way to much to handle and you take damage from the smell." << endl;
                character.setHp(-1);
                character.gameOver();
                cout << endl;
                cout << "Your current HP is " << character.getHp() << endl;
                cin.ignore();
                break;

            case 2:
                system("clear");
            	system("cls");
                cout << "God, this is gross..." << endl;
                cout << "but good thing you chose the right pile of poop" << endl;
                cin.ignore();
                roomComplete = true;
                cout << "Its a key and a potion! +1 potion has been added to your inventory." << endl;
                if (character.getPotion() < 5) {
                    character.setPotion(1);
                }
                else {
                    cout << "It looks like your bag is too full. You put the potion back and walk away." << endl;
                }
                cout << endl;
                break;
            case 3:
                system("clear");
                system("cls");
                cout << "God, this is gross... " << endl;
                cout << "and one goat is pooping next to you." << endl;
                cout << "He doesn't like that and kicks you in the head." << endl;
                character.setHp(-2);
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

        while (!roomComplete) {
            cout << "Do you search left, right or center poop?" << endl;
            getline(cin, answer);
            cout << endl;

            if (answer == "search center") {
                answerNum = 1;
            }
            else if (answer == "search right") {
                answerNum = 2;
            }
            else if (answer == "search left") {
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
                cout << "God, this is gross... " << endl;
                cout << "and one goat is pooping next to you." << endl;
                cout << "He doesn't like that and kicks you in the head." << endl;
                character.setHp(-2);
                character.gameOver();
                cout << endl;
                cout << "Your current HP is " << character.getHp() << endl;
                cout << endl;
                break;

            case 2:
                system("clear");
                system("cls");
                cout << "God, this is gross... " << endl;
                cout << "The smell of this pile is getting way to much to handle and you take damage from the smell." << endl;
                character.setHp(-1);
                character.gameOver();
                cout << endl;
                cout << "Your current HP is " << character.getHp() << endl;
                cin.ignore();
                break;

            case 3:
                system("clear");
            	system("cls");
                cout << "God, this is gross..." << endl;
                cout << "but good thing you chose the right pile of poop" << endl;
                cin.ignore();
                roomComplete = true;
                cout << "Its a key and a potion! +1 potion has been added to your inventory." << endl;
                if (character.getPotion() < 5) {
                    character.setPotion(1);
                }
                else {
                    cout << "It looks like your bag is too full. You put the potion back and walk away." << endl;
                }
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
