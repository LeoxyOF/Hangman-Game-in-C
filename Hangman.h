#ifndef HANGMAN_H
#define HANGMAN_H

#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

void GenerateWord(char *Word);
void Punishment(int Num);
int GameAction(char *Word);

#endif