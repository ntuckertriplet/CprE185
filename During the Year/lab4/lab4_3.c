/*-----------------------------------------------------------------------------
-                             SE 185 Lab 05
-             Developed for 185-Rursch by T.Tran and K.Wang
-----------------------------------------------------------------------------*/
#include <stdio.h>

//needed standard library
#include <stdio.h>
#include <time.h>

//Didn't have the comment typed correctly
/* Prototypes */
char AskToPlay(int timesPlayed);

//need the SelectRandNum() prototype
int SelectRandNum();

void RunGame (int computerNum);

int main()
{
    char prompt = '-';
    int played = 0, computerGuess = 0;

    prompt = AskToPlay(played);
    played = 1;

    while(prompt == 'y')     /* This line does not contain an error */
    {

        //used == instead of = to assign
        computerGuess = SelectRandNum();
        RunGame(computerGuess);
        prompt = AskToPlay(played);
    }
    //no semicolon
    printf("\n\nThank you for playing.\n");
    return 0;
}


char AskToPlay(int playedBefore)
{
    char yesNo;
    if (playedBefore == 0)
    {
        printf("Do you want to play a game?\n  ->");

        //needs a pointer for scanf
        scanf(" %c", &yesNo);
    }
    else
    {
        printf("Do you want to play again?\n  ->");
        scanf(" %c", &yesNo);
    }
    return yesNo;
}

int SelectRandNum()
{
    //misspelled
    int compGuess = 0;
    srand((int)time(0));
    compGuess = ((rand() % 100) + 1);
    return compGuess;
}


void RunGame (int computerNum)
{
    int number = 0, correct = 0;


    printf("\nYou are guessing a number.  The options are 1 through 100.\n\n");
    printf("What is your guess on what number I will select?\n  ->");
    scanf("%d", &number);

    while ((number <1) || (number >100))    /* This line does not contain an error */
    {
        printf("\nYour number is not within the correct range of numbers.  Guess again\n  ->");
        scanf("%d", &number);
    }


    while (correct == 0)    /* This line does not contain an error */
    {

        if (number = computerNum)
        {
            printf("\nYou guessed the number correctly!\n");

            //was printing the ASCII place of the number, the argument needed to be %d
            printf("The number was %d\n\n", computerNum);
            correct = 1;
        }
        else if (number < computerNum);
        {
            printf("\nYou guessed too low.  Enter another guess.\n  ->");
            scanf("%d", &number);
        }
        else
        {
            printf("\nYou guessed too high.  Enter another guess.\n  ->");
            scanf("%d", &number);
        }
    }
}
