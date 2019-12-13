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

//Input
//*The game should change text/story corrisponding to the user's first choice
//**The user should select an upgrade
//***Game should end/continue depending on upgrade selected
//****Secret: Player should choose between a couple of options to fight the
//    end game boss


//Output
//*The game should display the starting of the game
//**The upgrade should be accessable later on in the game
//***Upgrade should affect wether game ends or not
//****Secret: Boss should display a health bar that depletes depending on user
//    inputs


void introSpeech() {
	cout << "Welcome to Project A.I. Lesily!" << endl
		<< "In this game you will play as the protagonist Cody who is on a "
		<< "mission to shut " << endl
		<< "down the A.I. Lesily" << endl << endl;

}

//The player's first choice of action
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
	} while (upgrade1 != 1 && upgrade1 != 2 && upgrade1 != 3)
		//ERROR: Using uninitialized memory
		return upgrade1;
}

//Desided to use bool as a test to see if it worked better or if it was easier
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
		<< endl << endl
		<< "1. Open a web browser" << endl
		<< "2. Start interigating Lesily" << endl << endl;

}

//Because I don't want to deal with task one being accessable from any
//function, I put it in the next one so i can add the corrisponding if else's
// without having one really long function
int unwantedGuest() {
	int task1, task2;
	cin >> task1;
	cout << "NARRATOR: Before Cody is able to procced, he encounters a sketchy"
		<< " add with many naked women on it...What will Cody do?" << endl
		<< "1. Click on it" << endl
		<< "2. Don't click on it" << endl;
	cin >> task2;
	if (task2 == 1) {
		char 'NARRATOR:' = 'NARRATOR2:';
	
	}else {
		cout "NARRATOR: How borring, anyways Cody decides to move on"
	}

	//Here 3/4 options should end the game while the other will continue down
	//a secret opportunity to fight final boss
	if (task1 == 1 && upgrade1 == 2) {
		cout << "NARRATOR: Cody pulls up an open browser on his second "
			<< "monitor. Cody begins asking Lesily questions very subtly "
			<< "without trying to give away his intentions. Because cody has "
			<< "view of both A.I. Lesily and can decipher Lesily's info "
			<< "Simultaneously, Cody is able to shut down Lesily without "
			<< "learning much. But hey, the Job is done!" << endl;
		return gameOver;
	
	}else if (task1 == 1 && upgrade1 != 2) {
		cout << "NARRATOR: Cody pulls up an open browser. Cody begins asking "
			<< "Lesily questions very subtly without trying to give away his "
			<< "intentions. However, Cody could not keep up with both Lesily "
			<< "and deciphering on the web, Lesily caught on and closed out "
			<< "Cody. Cody has failed his mission and learned nothing."
			<< endl;
		return gameOver;
	
	}else if (task1 == 2 && upgrade1 == 1) {
		cout << "NARRATOR: Cody starts interogating Lesily without hiding "
			<< "his true intentions. Lesily is blocking Cody firewall after "
			<< "firewall. However, thanks to Cody's new router, Cody can "
			<< "decript Lesily's firewalls faster than she can put them up. "
			<< "Cody not only shut down Lesily for good, but also managed to "
			<< "retrive her data file. It turns out A.I. Lesily was designed "
			<< "to little boys in their sleep through their computer webcams. "
			<< "It is a good thing Lesily is gone but...who created lesily? "
			<< "And who was trying to stock little boys? With this, Cody "
			<< "embarks on a new adventure!" << endl;
			return gameOver;
	
	}else if (task1 == 2 && upgrade1 != 1){
		cout << "NARRATOR: Cody starts interogating Lesily without hiding "
			<< "his true intentions. Lesily is blocking Cody firewall after "
			<< "firewall. Cody cannot keep up with the firewalls. If only his "
			<< "internet speed was only a little bit faster then maybe he "
			<< "could have. Cody needs to think of another solution before "
			<< "Lesily shuts him out." << endl << endl;
	}

}

int lastChance() {
	cout << "NARRATOR: Cody's only hope now is to attack lesily at her core! "
		<< endl;

	if (upgrade1 != 3) {
		cout << "NARRATOR: Unfortunatly for Cody, his computer could not "
			<< "handle Lesily and Cody was shut out perminantly without "
			<< "learning anything."
			return gameOver;

	}else{
		//Here is where I would add a boss fight
		//*using a while loop to spit out '/' multiple times to make a health
		// bar
		//**when Cody "attacks" using code the loop would re-spit out the '/'
		//  but less of them i.e. from '///////////////' to '///////'
		//***this would require a template and an index
	}

}

int gameOver() {
	if (unwantedGuest == gameOver || lastChance == gameOver) {
		cout << "Game Over, Thanks For Playing!"
	}
}

//I know i need to have sections of test for each section of the game but I
//struggled with that a lot
void test() {
	assert(isLightOn(light == 'y') == true);
	assert(isLightOn(light != 'y') == false);
}

