#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

void GenerateWord(char *Word){

    char WordData[][50] = {
    "APPLE",
    "HOUSE",
    "WATER",
    "GREEN",
    "MUSIC",
    "BANANA",
    "ORANGE",
    "GARDEN",
    "WINDOW",
    "COMPUTER",
    "KEYBOARD",
    "MOUSE",
    "SCREEN",
    "PRINTER",
    "LAPTOP",
    "TABLET",
    "PHONE",
    "INTERNET",
    "SERVER",
    "PROGRAM",
    "LANGUAGE",
    "VARIABLE",
    "FUNCTION",
    "COMPILER",
    "DEBUGGER",
    "SOFTWARE",
    "HARDWARE",
    "NETWORK",
    "DATABASE",
    "STORAGE",
    "BACKUP",
    "SECURITY",
    "PASSWORD",
    "WEBSITE",
    "BROWSER",
    "DOWNLOAD",
    "UPLOAD",
    "CLOUD",
    "ROUTER",
    "SWITCH",
    "FIREWALL",
    "ENCRYPTION",
    "ROBOT",
    "ANDROID",
    "SYSTEM",
    "PROCESS",
    "THREAD",
    "MEMORY",
    "BUFFER",
    "POINTER",
    "ARRAY",
    "STRUCTURE",
    "ALGORITHM"
};
    
    int Limit = sizeof(WordData)/sizeof(WordData[0]);
    int RandomNumber = rand() % Limit;

    strcpy(Word, WordData[RandomNumber]);
}

void Punishment(int Num) {
    switch (Num) {
        case 1:
            printf(" +---+\n"
                   " |   |\n"
                   " O   |\n"
                   "     |\n"
                   "     |\n"
                   "     |\n"
                   "=========\n");
            break;

        case 2:
            printf(" +---+\n"
                   " |   |\n"
                   " O   |\n"
                   " |   |\n"
                   "     |\n"
                   "     |\n"
                   "=========\n");
            break;

        case 3:
            printf(" +---+\n"
                   " |   |\n"
                   " O   |\n"
                   "/|   |\n"
                   "     |\n"
                   "     |\n"
                   "=========\n");
            break;

        case 4:
            printf(" +---+\n"
                   " |   |\n"
                   " O   |\n"
                   "/|\\  |\n"
                   "     |\n"
                   "     |\n"
                   "=========\n");
            break;

        case 5:
            printf(" +---+\n"
                   " |   |\n"
                   " O   |\n"
                   "/|\\  |\n"
                   "/    |\n"
                   "     |\n"
                   "=========\n");
            break;

        case 6:
            printf(" +---+\n"
                   " |   |\n"
                   " O   |\n"
                   "/|\\  |\n"
                   "/ \\  |\n"
                   "     |\n"
                   "=========\n");
            break;
    }
}

int GameAction(char *Word){

    char Answer = '\0';
    char Display[50] = {0};
    char FalseLetters[50] = {0};
    int X = 0;
    int Choice = 2;
    int WordLen = strlen(Word);
    bool Victory = false;
    
    
    for(int i = 0; i < WordLen; i++){
        Display[i] = '_';
    
    }

    while(!Victory){

        bool Penalty = true;
        bool F_Letters = true;

        printf("\n\nFalse Letters ---> ");
        for(int i = 0; i < 50 && FalseLetters[i] != 0; i++){
            printf("%c ", FalseLetters[i]);
        }

        printf("\n\nEnter a letter: ");
        scanf(" %c", &Answer);
        Answer = toupper(Answer);
 
        for(int i = 0; i < WordLen; i++){
            if(Answer == Word[i]){
                Display[i] = Answer;
            }
        }

        printf("\n( ");
        for(int i = 0; i < WordLen; i++){
            printf("%c ", Display[i]);
            if(Answer == Display[i]){
                Penalty = false;
                F_Letters= false;
            }

        }
        for(int i = 0; i < 50; i++){
            if(Answer == FalseLetters[i]){
                Penalty = false;
                break;
            }
            else if(FalseLetters[i] == 0 && F_Letters){
                FalseLetters[i] = Answer;
                break;
            }
        }
        
        printf(")");

        int CheckWin = 0;
        for(int i = 0; i < WordLen; i++){
            if (Display[i] == Word[i]){
                CheckWin+=1;
            }
            if (CheckWin == WordLen){
                printf("\n\nYou Win!");
                Victory = true;
            }
        }
            
        if(Penalty){
            X+=1;
            printf("\n\n");
            Punishment(X);
            if(X==6){
                printf("\n\nYou Lose!");
                printf("\nThe word was %s!", Word);
                break;
            }
        }

    
    }
    while(Choice != 0 && Choice != 1){
    printf("\n\nExit -> 0\nPlay Again -> 1\n");
    printf("Enter your choice: ");
    scanf("%d", &Choice);

    if(Choice != 0 && Choice != 1){
        printf("\nEnter a valid option!\n");
    }

    }

    return Choice;
}
    


int main(){

    int Result = 0;

    do{
    srand(time(NULL));

    printf("\n---- Hangman Game ----\n");
    sleep(1);

    printf("Choosing word.....");
    sleep(1);

    char Word[50];
    GenerateWord(Word);
    printf("\nThe word has %d letters!", strlen(Word));

    Result = GameAction(Word);

    } while(Result == 1);
    
    return 0;
}