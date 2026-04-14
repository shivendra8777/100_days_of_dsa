/*Problem Statement
Given a string s consisting of lowercase English letters, find and return the first character that does not repeat in the string. 
If all characters repeat, return '$'.
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int freq[26] = {0};

    printf("Enter string: ");
    scanf("%s", str);

    // Step 1: count frequency
    for(int i = 0; str[i] != '\0'; i++)
    {
        freq[str[i] - 'a']++;
    }

    printf("Character frequencies:\n");
    for(int i = 0; i < 26; i++)
    {
        if(freq[i] > 0)
            printf("%c → %d\n", i + 'a', freq[i]);
    }

    // Step 2: find first non-repeating
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(freq[str[i] - 'a'] == 1)
        {
            printf("\nFirst non-repeating character is: %c\n", str[i]);
            return 0;
        }
    }

    printf("\n$\n"); // if all repeat

    return 0;
}