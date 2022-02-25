// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine( TEXT("Hi There! Welcome to Bull Cows."));
    PrintLine(TEXT("Guess the 4 letter word!")); //change hard coded length
    HiddenWord = TEXT("cake");
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
 
    PrintLine(Input);

    if (Input == HiddenWord) {
        PrintLine(TEXT("You have won!"));
    }

    else {
        PrintLine(TEXT("You've lost!"));
    }

}