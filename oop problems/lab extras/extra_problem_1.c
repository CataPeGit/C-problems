#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


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

int* histogram_of_text(char histogram[]) {
    int* alphabet_array = malloc(26 * sizeof(int));
    int i;
    for (i = 0; i < 26; i++) {
        alphabet_array[i] = 0;
    }

    // we will traverse the dynamic array
    // and increase the count of the current letter by 1 each time

    int nonAlpha = 0;
    for (i = 0; i < strlen(histogram); i++) {

        // check in we have a letter
        if (!isalpha(histogram[i])) {
            nonAlpha++;
            continue;
        }

        if (histogram[i] >= 'A' && histogram[i] <= 'Z') {
            int letter_position = histogram[i] - 'A';
            alphabet_array[letter_position]++;
        }
        else if (histogram[i] >= 'a' && histogram[i] <= 'z') {
            int letter_position = histogram[i] - 'a';
            alphabet_array[letter_position]++;
        }
    }

    return alphabet_array;
}

int count_letters(char text[]) {
    // return the number of letters in a string
    int nonAlpha = 0;
    int i = 0;
    for (i = 0; i < strlen(text); i++) {
        if (!isalpha(text[i])) {
            nonAlpha++;
        }
    }
    return i - nonAlpha;
}

float chi_square(char text[]) {
    // algorithm : https://www.youtube.com/watch?v=2QeDRsxSF9M
    float result = 0;

    float* alphabet_array = read_distribution();

    int* histogram = histogram_of_text(text);

    int total_letters_count = count_letters(text);

    for (int i = 0; i < 26; i++) {
        if (histogram[i] != 0) {
            float expected = total_letters_count * (alphabet_array[i] / 100);
            float fraction = pow((expected - histogram[i]), 2) / histogram[i];
            result = result + fraction;
            //printf("%c: %.2f%%\n", i + 'a', result);
            
        }
    }
    printf("%f", result);
    return result;
}



int main() {
    char* text1 = "AOLJHLZHYJPWOLYPZVULVMAOLLHYSPLZARUVDUHUKZPTWS  LZAJPWOLYZPAPZHAFWL  VMZBIZAPABAPVUJPWOLYPUDOPJOLHJOSLAALYPUAOLWSHPUALEAPZZOPMALKHJLYAHPUUBTILYVMWSHJLZKVDUAOLHSWOHILA";
    chi_square(text1);
    printf("\n");
    printf("\n");
    printf("\n");

    /*
    for (int i = 0; i < 26; i++) {
        printf("%c: %.2f%%\n", i + 'a', histogram1[i]);
    }
    */
    return 0;
}
