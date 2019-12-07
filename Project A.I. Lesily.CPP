//Zachory Davis CSCI Project
// A.I. Lesily

////This program is a text adventure game where the protagonist Codie is trying
////to hack A.I Lesily, There should be items that effect the game story as
////well as vectors and sorts that will come into play with the story

#include<iostream>
#include<string>
#include<vector>
#include<cassert>

using namespace std;

void test();
void introSpeech();
void introGame();
int main()
{
	test();
	introSpeech();
	introGame();
}

//**Inputs**
//The game should change text/story corrisponding to the user's first choice


//**Outputs**
//The game should display the starting of the game


void introSpeech() {
	cout << "Welcome to Project A.I. Lesily!" << endl
		<< "In this game you will play as the protagonist Cody who is on a "
		<< "mission to shut " << endl
		<< "down the A.I. Lesily" << endl << endl;

}

//The game should show the player's first choice of action
void introGame() {
	cout << "CODY: I have some spare cash, I should buy an upgrade for my "
		<< "computer before" << endl
		<< "tonight." << endl
		<< "NARRATOR: You walk into best buy where you can buy only one of "
		<< "three upgrades."
		<< "  Choose an upgrade carfully, it will matter in the future!"
		<< endl << endl
		<< "1. Router Upgrade" << endl
		<< "2. Second Monitor" << endl
		<< "3. Ram Upgrade" << endl;

}

//User is choosing their first item
//NOTE: Consider using an enum insted??
int firstUpgrade() {
	int upgrade1;
	
	do {
		cin >> upgrade1;
		if (upgrade1 == 1) {
			cout << "Router Upgraded!" << endl;

		}
		else if (upgrade1 == 2) {
			cout << "Second Monitor Purchased!" << endl;

		}
		else if (upgrade1 == 3) {
			cout << "Ram Upgraded!" << endl;

		}
		else {
			cout << "NARRATOR: Hey? What part of choose a number from 1-3 did you "
				<< "not understand?" << endl;
		}
	}while ( upgrade1 != 1 && upgrade1 != 2 && upgrade1 != 3)
//ERROR: Using uninitialized memory
	return upgrade1;
}

bool isLightOn(char light) {
	bool bright = true;

	if (light != 'y') {
	bright = false;
    }
	return bright;
}

int lightIsOn() {
	cout << "NARRATOR: Cody walks into his room and notices it is dark"
		<< "Turn on light? (Y/N)" << endl;
	
	char light;
	cin >> light;

	if (isLightOn(light) == 1) {
		cout << "NARRATOR: Cody flips the light switch on and is imidiatly "
			<< "blinded by the bright light as he painfully awaits his for "
			<< "his eyes to adjust." << endl;
	
	}else{
		cout << "NARRATOR: Cody flips the light switch on and is imidiatly "
			<< "blinded by the bright light as he painfully awaits his for "
			<< "his eyes to adjust." << endl;
	}
	return light;
}

void computerStartUp() {
	cout << "NARRATOR: Cody starts up his computer after installing his new "
		<< "upgrade." << endl
		<< "Cody procceds to open file A.I. Lesily.txt" << endl
		<< "Lesily: Greetings breathing object, how may I help you today?"
		<< endl;
}


void test() {
	
}
