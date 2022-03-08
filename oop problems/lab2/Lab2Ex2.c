#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
// Write a program that takes a single command line argument:
// the path to a file.This file is actually a dictionary that contains, on each line, a word from the given language.
// You can consider that the maximum size of a word is 50 characters.
// Display the frequency table of the letters from this file, and then the word with the maximum number of letters, the word with the maximum number of vowels and the word with the maximum number of consonants

char* array;
size_t arraySize = 101;


void frequency_table() {
    int alphabet_array[26] = { 0 }; // ALPHABET_SIZE = 26

    int i = 0;
    // we will traverse the dynamic array
    // and increase the count of the current letter by 1 each time
    while (array[i] != '\0') {
        int letter_position = array[i] - 'a';
        alphabet_array[letter_position]++;
        i++;
    }
    // now i is the total number of letters in the file

    float number_of_letters_in_file = i;
    i = 0;

    // check if file is empty
    int empty = 1;
    for (i = 0; i < 26; i++) {
        if (alphabet_array[i] != 0) {
            empty = 0;
            break;
        }
    }
    if (empty == 1) {
        printf("Application will now stop");
        return;
    }

    // now we will display the letter frequency in a tabular form

    for (i = 0; i < 26; i++) {

        if (alphabet_array[i] != 0) {
            float result = (alphabet_array[i] / number_of_letters_in_file) * 100;
            printf("%c: %.2f%%\n", i + 'a', result);
        }
        else {
            printf("%c: 0.00%%\n", i + 'a');
        }
    }
}


int main() {

    // initialization and input
    FILE* dictionary_file;
    char line[256];
    char path[256];
    char word[101];

    array = calloc(arraySize, sizeof(char));

    strcpy(array, "");
    scanf("%s", path);
    dictionary_file = fopen(path, "r");

    // check if the file was found, if not stop the program
    if (dictionary_file == NULL){
       printf("Failed to open file %s. Application will now stop", path);
        return 1; 
    }


    // getting the words from the file and add them to the dynamic array in lower case
    fscanf(dictionary_file, "%s", word);
    strcat(array, word);
    //printf("%s", word);
    while (fgets(word, 101, dictionary_file) != NULL) {
        // doubleing the size of the array
        arraySize *= 2;
        array = realloc(array, arraySize * sizeof(char));
        if (array == NULL) {
            printf("Failed to open file %s. Application will now stop", path);
            return 1;
        }

        // reading the word from the dictionary file and concatinating it to the dynamic array
        fscanf(dictionary_file, "%s", word);
        strcat(array, word);
        //printf("%s", word);
    }

    frequency_table();

    // close and clear
    free(array);
    fclose(dictionary_file);
    return 0;
}