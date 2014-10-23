//File Name: legendHeader.h
//Programmer: Jon Holmberg
//Date: 4/1/2013
//Purpose: Declaration of Function prototypes--LEGEND game, a game where the user enters 
//stats for skill traits which are then used to determine if the character succeeds with //his or her decisions.
//

//Pre-conditions:: 


/*


void readFromFile();-------requires “Act1.txt” to be created.

void choice(int skill...)—requires skillRequire to be manually inserted
as part of the parameters in order to be called.

*void outcomeStrength along with the other "outcome" functions requires
The manually inserted skillRequire value in order to be called.



*/


//Post-conditions::   
/*

void redoInput(char c); ----Will have given user to redo his or her character stats.

void checkTotal(int inputTotal); --Checked to see how many skill points are left for the 
user to use then displays amount.

void displaySta();--Will have display showing the amount of stat points are allocated to 
each skill trait along with the user's name.

void initialize(); --Will have stored character trait values that the user entered.

void readFromFile();-- Will have fed para array with the contents of "Act1.txt" text file.

void display(); --During bug testing, this will have shown whether para array has been fed 
correctly from the iFile.

/////Story Chapters///////////

void act1(); --Will have displayed story paragraphs from para array and prompted user to 
enter decision choices for each paragraph.

void choice(int skillRequireStrength, ...)-- Will have given success or fail outcome
based on the user's character traits.

int diceRoll(); Will have returned a random integer to be added to the user's character 
trait score.

void outcomeStrength(int skillRequireStrength); --Will have compared user's strength 
score to the skill requirement and yield a success or failure result. If successful, the
player’s skill score will have been leveled up!

void outcomeLuck(int skillRequireLuck);----Will have compared user's luck score to the 
skill requirement and yield a success or failure result. If successful, the
player’s skill score will have been leveled up!


void outcomePersuasion(int skillRequirePersuasion);----Will have compared user's persuasion
score to the skill requirement and yield a success or failure result. If successful, the 
player’s skill score will have been leveled up!


void outcomeSpeed(int skillRequireSpeed);----Will have compared user's speed score to the 
skill requirement and yield a success or failure result. If successful, the
player’s skill score will have been leveled up!


void outcomePrestige(int skillRequirePrestige);----Will have compared user's prestige score
to the skill requirement and yield a success or failure result. If successful, the
player’s skill score will have been leveled up!


void lose();--Will have given user a message saying they have lost the game and will start
from the beginning of the story(Act1()), so they don't have to input stats again.*/

#ifndef LEGEND_H
#define LEGEND_H
#include <iostream>
#include <string>
#include <fstream>
class Player
{

public:

	/////Beginning of game////////
	Player();


	void redoInput(char c);
	void checkTotal(int inputTotal);
	void displaySta();
	void initialize();
	void readFromFile();
	void display();
	/////Story Chapters///////////
	void act1();
	void choice(int skillRequireStrength, int skillRequireLuck, int
		skillRequirePersuasion, int skillRequireSpeed, int skillRequirePrestige);
	int diceRoll();
	void outcome(int skillrequirement, int skill);
	void ending();
	void lose();

private:
	std::string name;
	int strength;
	int luck;
	int persuasion;
	int speed;
	int prestige;
	std::string para[10];
	// end struct
}; // end class


#endif // legend_h