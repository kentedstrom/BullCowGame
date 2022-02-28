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
    else{
        PrintLine(Input);

        if (Input == HiddenWord) 
        {
            PrintLine(TEXT("You have won!"));
            EndGame();
        }

        else 
        {
            --Lives;
            if (Lives > 0)
            { 
                if (HiddenWord.Len() != Input.Len())
                {
                    PrintLine(TEXT("The Hidden Word is %i characters long. \nYou have lost a life! Lives remaining: %i"), HiddenWord.Len(), Lives);

                }

            }
            else {
                PrintLine(TEXT("You have no lives left!"));
                EndGame();
            }
        }
       }
}
  

void UBullCowCartridge::EndGame() {
    bGameOver = true;
    PrintLine(TEXT("Game is over. Press enter to play again"));

}
void UBullCowCartridge::SetupGame() 
{
    PrintLine(TEXT("Hi There! Welcome to Bull Cows."));
    HiddenWord = TEXT("cake");
    Lives = HiddenWord.Len();
    bGameOver = false;
    PrintLine(TEXT("Guess the %i letter word!"), HiddenWord.Len()); //change hard coded length
    PrintLine(TEXT("You have %i number of lives!"), Lives);
    PrintLine(TEXT("Type in your guess. \nPress Enter to continue..."), HiddenWord.Len()); //change hard coded length
}


