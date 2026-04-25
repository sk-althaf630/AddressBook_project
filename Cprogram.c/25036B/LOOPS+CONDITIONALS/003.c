/* WAP to check if a character is a vowel or not.
sample input :- E
sample output :- E is a vowel.

sample input :- z
sample output :- z is a consonant. */

#include <stdio.h>
#include <ctype.h>

int main() 
{
    char ch;
    int isLowercaseVowel, isUppercaseVowel;
    
    printf("Enter an alphabet: ");
    scanf(" %c", &ch);
    
    // Evaluate if it's a lowercase or uppercase vowel
    isLowercaseVowel = (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    isUppercaseVowel = (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
    
    if (!isalpha(ch)) 
    {
        printf("Error! Non-alphabetic character.\n");
    } 
    else if (isLowercaseVowel || isUppercaseVowel) 
    {
        printf("%c is a vowel.\n", ch);
    } 
    else 
    {
        printf("%c is a consonant.\n", ch);
    }
    
    return 0;
}