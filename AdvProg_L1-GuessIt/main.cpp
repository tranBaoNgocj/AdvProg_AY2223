#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <cmath>
#include "guessit.h"

using namespace std;
//Creation a random number
int generateRandomNumber(){
    srand(time(0));
    return rand() % 100 + 1;
    }

//number getPlayerGuess
int getPlayerGuess(){
    int guess;
     cout<< endl <<"Enter your guess"<<endl;
     cin>>guess;
     return guess;
}

//continue to Play
bool checkContinuePlaying(){
    cout<<"You want to continue? Press y or n"<<endl;
    char getPlayerOpinion;
    cin>>getPlayerOpinion;
    if (getPlayerOpinion=='y') {
        return true;
        }
    else return false; 
}

 //print answer base on numberPlayerGuess
    void printAnswer(int guess, int secretNumber){
        if(guess>secretNumber) 
        {
            cout<<"Your number is too big."<<endl;
            }
        else if(guess<secretNumber) 
        {
            cout<<"Your number is too small."<<endl;
            }
        else cout<<"Congratulation! You win."<<endl;
        }

int main()
{
     do{
        //Creation a random number
    int secretNumber = generateRandomNumber();
        //number getPlayerGuess
    int guess;
    do {
        guess = getPlayerGuess();
        printAnswer(guess, secretNumber);
        }
     while (guess != secretNumber);
     }
     while(checkContinuePlaying());
     return 0;
}