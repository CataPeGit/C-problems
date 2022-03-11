#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


// !!! ADD DISTRIBUTION.TXT --- and --- use free() to prevent any memory leaks

// in the distribution.txt file we store the expected percentage of letter frequency 


float* read_distribution() {
    // opening the file and reading the distribution of letters
    FILE* file = fopen("input.txt", "r");
    float* alphabet_array = malloc(26 * sizeof(float));

    // the distribution of the letters is stored in an array
    // in which each position represents a letter
    
    for (int i = 0; i < 26; i++) {
        fscanf(file, "%f", &alphabet_array[i]);
    }

    fclose(file);
    return alphabet_array;
}


int* histogram_of_text() {
    // taking a string as an input and converting letters to lower case if needed
    char text[256];
    scanf("%s", text);
    for (int i = 0; text[i]; i++) {
        text[i] = tolower(text[i]);
    }

    
    // each letter a -> z will have 0 frequency to start with
    // initializing the frequency as 0
    int* text_array = malloc(26 * sizeof(int));
    for (int i = 0; i < 26; i++) {
        text_array[i] = 0;
    }

    // going trough all the letters and storing the frequency in an array
    int i = 0;
    while (text[i] != '\0') {
        if (text[i] >= 'a' && text[i] <= 'z') {
            int letter_position = text[i] - 'a';
            text_array[letter_position]++;
        }
        i++;
    }

    // now that we have the frequency we can return the array
    return text_array;
}


void chi_square() {
    // algorithm : https://www.youtube.com/watch?v=2QeDRsxSF9M
    /*
    This function computes the Chi - square distance between two histograms
    chi_square^2 = for each histogram we take the difference between the observed(using histogram_of_text function) and expected (the second histogram, maybe use read_distribution as percentage) where these 2 are not percentages
    we square it (^2)
    and devide this by the expected
    ! THIS PROCESS REPEATS FOR EACH LETTER (a->z)
    we add together all these results (a->z)

    the result will bet approximately a chi-squared distribution
    
    */
    
}


int main() {

    float* alphabet_array = read_distribution();

    int* histogram = histogram_of_text();

    for (int i = 0; i < 26; i++) {
        printf("%d", histogram[i]);
        printf("\n");
    }


    free(histogram);
    free(alphabet_array);
    return 0;
}
