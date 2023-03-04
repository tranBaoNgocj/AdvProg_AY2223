/*#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <stdexcept>
#include <algorithm>

#include "hangman.h"
#include "draw.h"

int main()
{
    srand((int)time(0));

    string vocabularyFile = "data/Ogden_Picturable_200.txt";
    //string vocabularyFile = "data/ErrorOpenFileTest.txt";
    //string vocabularyFile = "data/EmptyTest.txt";
    vector<string> wordList;
    try {
        wordList = readWordListFromFile(vocabularyFile);
    } catch (domain_error) {
        cout << endl << "Error: in reading vocabulary file: " << vocabularyFile << endl;
        return 1;
    }

    int index = generateRandomNumber(0, wordList.size()-1);
    string word = chooseWordFromList(wordList, index);

    if (word.empty()) {
        cout << "Error: Coud not choose a random word." << endl;
        return 1;
    }
    //cout << "Chosen word: " << word << endl;
    // string secretWord(word.length(), '-');
    string secretWord = generateHiddenCharacters(word);

    int incorrectGuess = 0;
    string correctChars = "";
    string incorrectChars = "";
    
    printScreen(word, secretWord, correctChars, incorrectGuess, incorrectChars); 
    
    do {
        char ch = getInputCharacter();

        processData(ch, word, secretWord, 
                    correctChars, incorrectGuess, incorrectChars);
        
        printScreen(word, secretWord, correctChars, incorrectGuess, incorrectChars); 

    } while (secretWord != word && incorrectGuess != MAX_MISTAKES-1);

    playAnimation(word, secretWord, correctChars, incorrectGuess, incorrectChars);

    return 0;
}*/#include <bits/stdc++.h>
#include <cstdlib>
#define endl '\n'

using namespace std;
static string words[] = {
	"meow", "go", "hihi", "fuku", "chottomattekudasai", "kimochi"
};
string chooseWord(){
	srand(time(0));
	int selectedIndex = rand() % 6;
	return words[selectedIndex];
}
const string FIGURE[] = {
	" ------------- \n"
	" | \n"
	" | \n"
	" | \n"
	" | \n"
	" | \n"
	" ----- \n",
	" ------------- \n"
	" | 	| \n"
	" | \n"
	" | \n"
	" | \n"
	" | \n"
	" ----- \n",
	" ------------- \n"
	" | 	| \n"
	" | 	O \n"
	" | \n"
	" | \n"
	" | \n"
	" ----- \n",
	" ------------- \n"
	" | 	| \n"
	" | 	O \n"
	" | 	| \n"
	" | \n"
	" | \n"
	" ----- \n",
	" ------------- \n"
	" | 	 	  | \n"
	" | 	 	  O \n"
	" | 	     /| \n"
	" | \n"
	" | \n"
	" ----- \n",
	" ------------- \n"
	" | 	 	  | \n"
	" | 	 	  O \n"
	" | 		 /|\\ \n"
	" | \n"
	" | \n"
	" ----- \n",
	" ------------- \n"
	" | 	 	  | \n"
	" | 	 	  O \n"
	" | 		 /|\\ \n"
	" | 		 / \n"
	" | \n"
	" ----- \n",
	" ------------- \n"
	" |    	      | \n"
	" | 	 	  O \n"
	" | 		 /|\\ \n"
	" | 		 / \\ \n"
	" | \n"
	" ----- \n"
};
void renderGame(string guessedWord, int badGuessCount){
	cout << FIGURE[badGuessCount] << endl;
	cout<< guessedWord<<endl;
	cout<< "Number of wrong guesses: "<< badGuessCount<< endl;
}

char readAGuess(){
	cout<<"Your Guess";
	char guessedChar;
	cin>> guessedChar;
	return tolower(guessedChar);
}

bool contains(string secretWord, char guess){
	//cout<< guess<<" - "<< secretWord<< endl;
	//cout<<" * "<< secretWord.find_first_of(guess)<< endl;
	return(secretWord.find_first_of(guess) < secretWord.length() ? true : false);  
}
string update(string guessedWord, string secretWord, char guess){
	for(int i = secretWord.length() - 1; i >= 0; i--){
		if(secretWord[i] == guess){
			guessedWord[i] = guess;
		}
	}
	return guessedWord;
}
int main(){
	string secretWord = chooseWord();
	string guessedWord = string(secretWord.length(), '-');
	//cout<< guessedWord;
	int badGuessCount = 0;
	do {
		renderGame(guessedWord, badGuessCount);
		char guess = readAGuess();
		if (contains(secretWord, guess))
			guessedWord = update(guessedWord, secretWord, guess);
		else badGuessCount++;
	} while (badGuessCount < 7 && secretWord != guessedWord);
		renderGame(guessedWord, badGuessCount);
	if (badGuessCount < 7) 
		cout << "Congratulations! You win!";
	else 
		cout << "You lost. The correct word is " << secretWord;
	   
    return 0;
    }


