/*Problem Statement
Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. 
In case of a tie, return the lexicographically smallest candidate name.
*/
#include <stdio.h>
#include <string.h>

#define MAX 100

int main()
{
    int n;
    char names[MAX][50];
    int count[MAX] = {0};

    printf("Enter number of votes: ");
    scanf("%d", &n);

    printf("Enter names:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%s", names[i]);
    }

    // count votes
    for(int i = 0; i < n; i++)
    {
        if(count[i] == -1) continue;

        count[i] = 1;

        for(int j = i + 1; j < n; j++)
        {
            if(strcmp(names[i], names[j]) == 0)
            {
                count[i]++;
                count[j] = -1; // mark as counted
            }
        }

        printf("Candidate %s has %d votes\n", names[i], count[i]);
    }

    // find winner
    int maxVotes = 0;
    char winner[50];

    for(int i = 0; i < n; i++)
    {
        if(count[i] == -1) continue;

        if(count[i] > maxVotes)
        {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        }
        else if(count[i] == maxVotes)
        {
            // lexicographically smaller
            if(strcmp(names[i], winner) < 0)
            {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("\nWinner is: %s with %d votes\n", winner, maxVotes);

    return 0;
}