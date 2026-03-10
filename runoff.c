#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Limits
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] stores the candidate index
// for voter i in rank j
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Each candidate has a name, votes, and elimination status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// List of candidates
candidate candidates[MAX_CANDIDATES];

// Total voters and candidates
int voter_count;
int candidate_count;

// Functions
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Need at least one candidate
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Save number of candidates
    candidate_count = argc - 1;

    // Check max number of candidates
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }

    // Save each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    // Ask for number of voters
    voter_count = get_int("Number of voters: ");

    // Check max number of voters
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Ask each voter for all rankings
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Save vote if the name is valid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep running rounds until someone wins
    while (true)
    {
        // Count votes for this round
        tabulate();

        // Stop if there is a winner
        if (print_winner())
        {
            break;
        }

        // Find the smallest vote count
        int min = find_min();

        // If everyone left has the same votes, it's a tie
        if (is_tie(min))
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Remove candidate(s) with the fewest votes
        eliminate(min);

        // Reset votes for the next round
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }

    return 0;
}

// Save candidate index in preferences
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }

    return false;
}

// Count one vote for the first non-eliminated choice
void tabulate(void)
{
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int index = preferences[i][j];

            if (!candidates[index].eliminated)
            {
                candidates[index].votes++;
                break;
            }
        }
    }
}

// Print winner if someone has more than 50%
bool print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > voter_count / 2)
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }

    return false;
}

// Find the smallest votes among candidates still in the race
int find_min(void)
{
    int min = voter_count;

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes < min)
        {
            min = candidates[i].votes;
        }
    }

    return min;
}

// Check if all remaining candidates have the same votes
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            return false;
        }
    }

    return true;
}

// Eliminate candidate(s) with the minimum votes
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
}
