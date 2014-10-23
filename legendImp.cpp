//File Name:legendImp.cpp
//Programmer:Jon Holmberg
//Date:4/1/2013
//Purpose: Implementing the header prototypes for storing values for the Player
//class objects and using those object values
// to determine decision outcomes in story.

#include "legendHeader.h"
#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <cstdlib>


Player::Player(){
	// end while
	initialize();
	std::cout << "Would you like to use these stats or redistribute? [enter n to continue or y to redo stats]: ";
		char check;
	std::cin >> check;
	redoInput(check);
}

void Player::initialize(){
	std::cout << "What is your name?" << std::endl;
	std::cin >> name;
	if (std::string::npos != name.find_first_of("0123456789!@#$%^&*()_-+={}[]\|;:/*"))
		initialize();
	std::cout << std::endl;
	int inputTotal = 0;
	std::cout << "Welcome to LEGEND!\n\nThis is a game where your decisions affect";
	std::cout << " the outcome of your story.\nChoose wisely, as poor decisions will yield you misfortune!" << std::endl;
	std::cout << "You have 18 points to spend on your character's stats. These stats will help you develop a strategy ";
	std::cout << "for making your decisions. Each choice requires a dice-roll.\n" << std::endl;
	std::cout << "Your trait bonus adds to that dice-roll to help you succeed! ";
	std::cout << "(e.g. A high strength score helps you accomplish more aggressive decisions!)." << std::endl;
	do
	{

		inputTotal = 18;
		std::cout << std::endl;
		std::cout << "Please enter the number of points you want for strength: ";
		std::cin >> strength;
		inputTotal -= strength;
		std::cout << std::endl;
		checkTotal(inputTotal);
		std::cout << std::endl;
		std::cout << "Please enter the number of points you want for luck: ";
		std::cin >> luck;
		inputTotal -= luck;
		std::cout << std::endl;
		checkTotal(inputTotal);
		std::cout << std::endl;
		std::cout << "Please enter the number of points you want for persuasion: ";
		std::cin >> persuasion;
		inputTotal -= persuasion;
		std::cout << std::endl;
		checkTotal(inputTotal);
		std::cout << std::endl;
		std::cout << "Please enter the number of points you want for speed: ";
		std::cin >> speed;
		inputTotal -= speed;
		std::cout << std::endl;
		checkTotal(inputTotal);
		std::cout << std::endl;
		std::cout << "Please enter the number of points you want for prestige: ";
		std::cin >> prestige;
		inputTotal -= prestige;
		std::cout << std::endl;
		checkTotal(inputTotal);
		std::cout << std::endl;

		if (!(inputTotal == 0))
		{
			std::cout << "Invalid point distribution! Please try again!" << std::endl;
			std::cout << std::endl;
		} // end if

	} while (!(inputTotal == 0));

	
}

void Player::displaySta(){

	std::cout << "Character traits complete!" << std::endl;
	std::cout << std::endl;

	std::cout << "YOUR CHARACTER'S TRAITS: " << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << std::endl;
	std::cout << "Strength: " << strength << std::endl;
	std::cout << "Luck: " << luck << std::endl;
	std::cout << "Persuasion: " << persuasion << std::endl;
	std::cout << "Speed: " << speed << std::endl;
	std::cout << "Prestige: " << prestige << std::endl;
	std::cout << std::endl;

}

void Player::checkTotal(int inputTotal)
{
	if (inputTotal > 0)
	{
		std::cout << "trait stored!" << std::endl;
		std::cout << std::endl;
		std::cout << "You have " << inputTotal << " points left to spend on your character's stats!" << std::endl;
		std::cout << std::endl;
	} // end if

}

void Player::redoInput(char c) {
	c = tolower(c);
	if (c == 'y') {
		initialize();
	}
	std::cout << std::endl;
}

int Player::diceRoll()
{
	srand(static_cast <int> (time(0)));
	int randomInteger = 0;
	randomInteger = 1 + rand() % (8 - 1 + 1);

	return randomInteger;
} // end dice roll



void Player::choice(int skillRequireStrength, int skillRequireLuck, int skillRequirePersuasion, int skillRequireSpeed, int skillRequirePrestige){

	int decision = 0;

	std::cout << std::endl;
	std::cout << "What would you like to do? [enter an option between 1-5]: ";
	std::cin >> decision;
	std::cout << std::endl;

	switch (decision){
	case 1:
		outcome(skillRequireStrength, strength);
		break;
	case 2:
		outcome(skillRequireLuck, luck);
		break;
	case 3:
		outcome(skillRequirePersuasion, persuasion);
		break;
	case 4:
		outcome(skillRequireSpeed, speed);
		break;
	case 5:
		outcome(skillRequirePrestige, prestige);
		break;
	default:
		std::cout << "invalid selection" << std::endl;
		act1();


	}//end switch
}// end choice

void Player::outcome(int skillrequirement, int skill)
{
	int score = 0;
	score = skill + diceRoll();
	if (score > skillrequirement)
	{
		std::cout << "You succeeded!" << std::endl;
		skill++; //level up
	}
	else
	{
		lose();
	}
}



////////If your choice fails///////////////////
void Player::lose()
{
	std::cout << "Sorry, game over, your choice has failed. Please try again!" << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	act1();
}


void Player::readFromFile(){
	std::ifstream iFile;
	std::cout << "THE LEGEND BEGINS....\n\n";
	iFile.open("C:\\Users\\Jon\\My Documents\\Act1.txt");
	//^input file location for text file for ACT 1!
	//iFile.open("C:\\Users\\Jon\\My Documents\\Act1.txt");
	int i = 0;
	if (iFile.is_open()){
		while (!iFile.eof()){
			getline(iFile, para[i], '#');
			i++;
		}
	}
}

void Player::act1(){

	/*int ending = 0;*/
	std::cout << std::endl;
	std::cout << para[0] << std::endl;
	choice(6, 5, 6, 5, 8); //6
	std::cout << para[1] << std::endl;
	choice(7, 8, 6, 6, 10);//7
	std::cout << para[2] << std::endl;
	choice(9, 7, 8, 9, 10);//7
	std::cout << para[3] << std::endl;
	choice(10, 9, 9, 9, 12);//8
	std::cout << para[4] << std::endl;
	choice(12, 10, 10, 10, 14);//9
	std::cout << para[5] << std::endl;



}

void Player::display(){
	for (int i = 0; i < 8; i++){
		std::cout << para[i] << std::endl;
	}
}

void Player::ending()
{
	int ending = 0;
	do
	{
		std::cout << "What do you want to do?" << std::endl;
		std::cin >> ending;
		if (ending == 2)
			std::cout << para[6] << std::endl;
		else if (ending == 1)
		{
			std::cout << para[7] << std::endl;
		}

	} while (ending != 2 && ending != 1);
}