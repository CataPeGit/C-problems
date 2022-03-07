// Substitution cipher or Caesar’s cipher.

// This program which reads a natural number n and a string s. The string s is encoded using Caesar’s cipher with a displacement of n (either positive or negative).
// The program decodes the message and display it on the screen. Punctuation marks and numbers are left as they are.

#include <stdio.h>
#include <ctype.h>
#include <string.h>


int main() {
    int n;
    char s[256];
    int shift = 0;
    char temp;
    int lower = 0;

    scanf("%d", &n);
    scanf("%c",&temp); // temp statement to clear buffer
    scanf("%[^\n]", s);

    for(int i = 0; i < strlen(s); i++) {
        
        if (s[i] == ' '){
            printf(" ");
            continue;
        }
        
        // set up the shift
        if(s[i] >= 'a' && s[i] <= 'z'){
                s[i] = s[i] - 32;  
                lower = 1;
        }
                
        if (s[i] >= 'A' && s[i] <= 'Z') {
            if(n < 0) {
                // 26 = number of letters in alphabet
                shift = (-1*n) % 26;
                shift = -1 * shift;
                
                // making the shift
                s[i] = shift + s[i];
                if (s[i] < 'A') {
                    s[i] = s[i] + 26;   
                }
            }
            else if (n > 0){
                // 26 = number of letters in alphabet
                shift = n % 26;

                // making the shift
                s[i] = shift + s[i];
                if (s[i] > 'Z') {
                    s[i] = s[i] - 26;   
                }
            }
        }
        
        if (lower == 1){
            lower = 0;
            s[i] = s[i] + 32;
        }
        
        //printf
        printf("%c", s[i]);
    }

    return 0;
}
