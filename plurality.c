#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Maximum number of candidates allowed in the election
#define MAX 9

// Structure to store information about each candidate
typedef struct
{
    string name;   // Candidate's name
    int votes;     // Number of votes received
} candidate;

// Array that stores all candidates
candidate candidates[MAX];

// Variable that keeps track of how many candidates there are
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check if the program was run with candidate names
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Number of candidates is the number of arguments minus the program name
    candidate_count = argc - 1;

    // Check if we exceeded the maximum number of candidates
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    // Save each candidate name and start their votes at 0
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // Ask how many voters will vote
    int voter_count = get_int("Number of voters: ");

    // Loop once for each voter
    for (int i = 0; i < voter_count; i++)
    {
        // Ask the voter to type a candidate name
        string name = get_string("Vote: ");

        // If the vote is not valid, print a message
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // After all votes are counted, print the winner
    print_winner();
}

// Function that adds a vote to the correct candidate
bool vote(string name)
{
    // Go through each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        // Compare the typed name with the candidate's name
        if (strcmp(candidates[i].name, name) == 0)
        {
            // If the names match, increase vote count
            candidates[i].votes++;
            return true;
        }
    }

    // If no candidate matched the name, the vote is invalid
    return false;
}

// Function that prints the candidate(s) with the most votes
void print_winner(void)
{
    int max_votes = 0;

    // First loop: find the highest number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    // Second loop: print all candidates who have the highest votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
