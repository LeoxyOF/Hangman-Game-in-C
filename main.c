#include "Hangman.h"

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
