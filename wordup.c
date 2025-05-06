// Noah Arrowood
// Project 10

#include <stdbool.h>
#include <stdio.h>
#define INPUT "word.txt"
#define GUESSES 6
#define WORDLENGTH 5

void loadword(char word[]);
bool checkguess(const char guess[]);
void format(char guess[]);
void logic(const char guess[], const char word[], char result[], char arrows[]);
void display(char guesses[][WORDLENGTH + 1], char results[][WORDLENGTH + 1], char arrows[][WORDLENGTH + 1], int counter);
bool correct(const char guess[], const char word[]);
void displayline(int length, char symbol);

int main(){
	char word[WORDLENGTH + 1];
	char guesses[GUESSES][WORDLENGTH + 1];
	char results[GUESSES][WORDLENGTH + 1];
	char arrows[GUESSES][WORDLENGTH + 1];
	int numguess = 0;
	int length = 31;
    
	loadword(word);
    
while (numguess < GUESSES){
	char guess[100];

if (numguess == GUESSES - 1) {
	printf("Final guess: ");
} 
else {
	printf("Guess %d! Enter your guess: ", numguess + 1);
}

	scanf("%s", guess);
	displayline(length, '=');
        
while (!checkguess(guess)){
	printf("Your guess must be 5 letters long \n");
	printf("Please try again: ");
	scanf("%s", guess);
}
        
	format(guess);
        
for (int i = 0; i < WORDLENGTH; i++){
	guesses[numguess][i] = guess[i];
}
	guesses[numguess][WORDLENGTH] = '\0';
        
	logic(guess, word, results[numguess], arrows[numguess]);
	
	display(guesses, results, arrows, numguess + 1);
        
if (correct(guess, word)){
	displayline(length, '=');
	printf("%s\n", results[numguess]);
	printf("Amazing!\nYou won in %d guesses!\n", numguess + 1);
return 0;
}
	numguess++;
}
	printf("You lost, better luck next time!\n");
	return 0;
}

void loadword(char word[]){
	FILE* finput;
	finput = fopen(INPUT, "r");
if (finput == NULL) {
	printf("Could not open %s, try again\n", INPUT);
	return;
}
	fscanf(finput, "%5s", word);
	fclose(finput);
}

bool checkguess(const char guess[]){
	int i;

for (i = 0; guess[i] != '\0'; i++){
	if ((guess[i] < 'A' || (guess[i] > 'Z' && guess[i] < 'a') || guess[i] > 'z')){
	return false;
}
}

	return i == WORDLENGTH;
}

void format(char guess[]){

for (int i = 0; guess[i] != '\0'; i++){
	if (guess[i] >= 'A' && guess[i] <= 'Z'){
		guess[i] = guess[i] - 'A' + 'a';
}
}
}

void logic(const char guess[], const char word[], char result[], char arrows[]){
	bool used[WORDLENGTH] = {false};
    
for (int i = 0; i < WORDLENGTH; i++){
	result[i] = guess[i];
	arrows[i] = ' ';
}
    
for (int i = 0; i < WORDLENGTH; i++){
	if (guess[i] == word[i]){
		result[i] = guess[i] - 'a' + 'A';
		used[i] = true;
}
}
    
for (int i = 0; i < WORDLENGTH; i++){
	if (guess[i] != word[i]) {
		for (int j = 0; j < WORDLENGTH; j++){
			if (!used[j] && guess[i] == word[j]){
				arrows[i] = '^';
				used[j] = true;
				break;
}
}
}
}
    
	result[WORDLENGTH] = '\0';
	arrows[WORDLENGTH] = '\0';
}

void display(char guesses[][WORDLENGTH + 1], char results[][WORDLENGTH + 1], char arrows[][WORDLENGTH + 1], int counter){
	for (int i = 0; i < counter; i++){
		printf("%s\n", results[i]);
		printf("%s\n", arrows[i]);
 
}
}

bool correct(const char guess[], const char word[]){
	for (int i = 0; i < WORDLENGTH; i++){
		if (guess[i] != word[i]){
		return false;
}
}
return true;
}

void displayline(int length, char symbol) {
	for (int i = 0; i < length; i++) {
		printf("%c", symbol);
}
printf("\n");
}
