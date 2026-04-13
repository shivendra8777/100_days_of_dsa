/*Problem Statement
Given a string s consisting of lowercase letters, find the first repeated character in the string. 
A character is considered repeated if it appears more than once, and among all such characters, 
the one whose second occurrence has the smallest index should be returned.
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int visited[26] = {0};

    printf("Enter string: ");
    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i++)
    {
        int index = str[i] - 'a';

        if(visited[index] == 1)
        {
            printf("First repeated character is: %c\n", str[i]);
            return 0;
        }
        else
        {
            visited[index] = 1;
            printf("Marking %c as visited\n", str[i]);
        }
    }

    printf("-1\n"); // no repeated character

    return 0;
}