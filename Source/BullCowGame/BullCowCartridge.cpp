// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();

    SetupGame();

    PrintLine(FString::Printf(TEXT("The HiddenWord is: %s. \n It is %i characters long"), *HiddenWord, HiddenWord.Len()));
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver) {
        ClearScreen();
        SetupGame();
    }
    else {
        ProcessGuess(Input);
    }
}
  

void UBullCowCartridge::EndGame() {
    bGameOver = true;
    PrintLine(TEXT("\nGame is over. Press enter to play again"));

}
void UBullCowCartridge::SetupGame() 
{
    PrintLine(TEXT("Hi There! Welcome to Bull Cows."));
    HiddenWord = TEXT("cake");
    Lives = HiddenWord.Len();
    bGameOver = false;
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len()); 
    PrintLine(TEXT("You have %i number of lives!"), Lives);
    PrintLine(TEXT("Type in your guess. \nPress Enter to continue..."), HiddenWord.Len()); //Prompt player to enter their guess

    const TCHAR HW[] = TEXT("cakes");
}

void UBullCowCartridge::ProcessGuess(FString Guess)
{

    //If guess is correct
    if (Guess == HiddenWord)
    {
        PrintLine(TEXT("You have won!"));
        EndGame();
        return;
    }

    //check if right number of characters
    if (HiddenWord.Len() != Guess.Len())
    {
        PrintLine(TEXT(" Sorry, try guessing again. \n Lives remaining: %i"), Lives);
        PrintLine(TEXT("The hidden word is %i letters long"), HiddenWord.Len());
        return;
    }
    //Check if isogram'

    if (!IsIsogram(Guess))
    {
        --Lives;
        PrintLine(TEXT("No repeating letters, guess again!"));
        PrintLine(TEXT(" \n Lives remaining: %i"), Lives);
        return;
    }


    //Removing a life
    PrintLine(TEXT("Incorrect! You lost a life!"));
    --Lives;
 

     //if lives are 0, then end game
      if (Lives <= 0)
        {
          ClearScreen();
          PrintLine(TEXT("You have no lives left!"));
          PrintLine(TEXT("The hidden word was %s!"), *HiddenWord);
            EndGame();
            return;
        }


      PrintLine(TEXT("Guess again, you have %i lives left"), Lives);
    }

bool  UBullCowCartridge::IsIsogram(FString Guess) const {

    //break into char array

    //check for repeating characters
    for (int32 i = 0; i < Guess.Len() -1; i++) {
        for (int32 j = i+1; j < Guess.Len(); j++) {
            if (Guess[i] == Guess[j]){
                return false;
            }
        }
    }
    return true;

    //if repeating characters, return false otherwise true
}

    




