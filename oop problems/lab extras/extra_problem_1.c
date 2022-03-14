#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void read_distribution(float* alphabet_array) {
    // opening the file and reading the distribution of letters
    FILE* file = fopen("distribution.txt", "r");

    // the distribution of the letters is stored in an array
    // in which each position represents a letter

    for (int i = 0; i < 26; i++) {
        fscanf(file, "%f", &alphabet_array[i]);
    }

    fclose(file);
}

void histogram_of_text(char histogram[], int alphabet_array_histogram[]) {
    int i;
    for (i = 0; i < 26; i++) {
        alphabet_array_histogram[i] = 0;
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
            alphabet_array_histogram[letter_position]++;
        }
        else if (histogram[i] >= 'a' && histogram[i] <= 'z') {
            int letter_position = histogram[i] - 'a';
            alphabet_array_histogram[letter_position]++;
        }
    }

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



char* permute(char str[], int shift) {
    // we will move all letters with +shift places

    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            char c = str[i] - 'A';
            c += shift;
            c = c % 26;
            str[i] = c + 'A';
        }
        else if (str[i] >= 'a' && str[i] <= 'z') {
            char c = str[i] - 'a';
            c += shift;
            c = c % 26;
            str[i] = c + 'a';
        }
        i++;
    }
    return str;

}

double chi_square(char text[], float alphabet_array[], int alphabet_array_histogram[]) {
    // algorithm : https://www.youtube.com/watch?v=2QeDRsxSF9M
    double result = 0;

    read_distribution(alphabet_array);

    histogram_of_text(text, alphabet_array_histogram);

    int total_letters_count = count_letters(text);

    for (int i = 0; i < 26; i++) {
        if (alphabet_array_histogram[i] != 0) {
            double expected = total_letters_count * (alphabet_array[i] / 100);
            double fraction = pow((expected - alphabet_array_histogram[i]), 2) / alphabet_array_histogram[i];
            result = result + fraction;
            //printf("%c: %.2f%%\n", i + 'a', result);
        }
    }
    //printf("%f", result);
    return result;
}

void decrypt(char text[], float alphabet_array[], int alphabet_array_histogram[], char result[]) {
    // using chi_square on all permutation in order to find out the proper outcome
    // when permute_counter reaches 26(alphabet size) all the permutations are done
    double min = 9999999;

    int permute_counter = 0;
    while (permute_counter < 26) {
        permute(text, 1);
        if (min > chi_square(text, alphabet_array, alphabet_array_histogram)) {
            min = chi_square(text, alphabet_array, alphabet_array_histogram);
            strcpy(result, text);
            //printf("%s", text);
        }
        permute_counter++;
    }

    // print the final result and go back to UI
    printf("%s", result);
    printf("\n");
}

void user_interface() {
    printf("Pick your command: \n");
    printf("0 -> Stop the program \n");
    
    printf("2 -> Decrypt Caesar's cipher example\n");
    printf("Your command:");
}

int main() {

    float* alphabet_array = malloc(26 * sizeof(float));
    int* alphabet_array_histogram = malloc(26 * sizeof(int));

    /*
    Text examples:
    Uf ime ftq nqef ar fuyqe, uf ime ftq iadef ar fuyqe, uf ime ftq msq ar iuepay, uf ime ftq msq ar raaxuetzqee, uf ime ftq qbaot ar nqxuqr, uf ime ftq qbaot ar uzodqpgxufk, uf ime ftq eqmeaz ar xustf, uf ime ftq eqmeaz ar pmdwzqee, uf ime ftq ebduzs ar tabq, uf ime ftq iuzfqd ar pqebmud.
    AOLJHLZHYJPWOLYPZVULVMAOLLHYSPLZARUVDUHUKZPTWSLZAJPWOLYZPAPZHAFWLVMZBIZAPABAPVUJPWOLYPUDOPJOLHJOSLAALYPUAOLWSHPUALEAPZZOPMALKHJLYAHPUUBTILYVMWSHJLZKVDUAOLHSWOHILA
    */
    
    char text[1000];
    printf("Break Caesar's cipher! \n");
    printf("Please enter the text you want to decipher:\n");
    scanf("%[^\n]s", text);

    printf("\n");
    printf("\n");
    printf("\n");
    printf("Result: \n");
    char* result = malloc(strlen(text) * sizeof(char));
    decrypt(text, alphabet_array, alphabet_array_histogram, result);



    free(alphabet_array);
    free(alphabet_array_histogram);
    return 0;
}

