#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Store the winners
    typedef struct
    {
        string name;
        int votes;
    }
    win;

    // Array of winners
    win winner[candidate_count];

    // Winner name start with the first name of candidates
    winner[0].name = candidates[0].name;
    
    // Winner votes start with 0 to compare with other values
    winner[0].votes = 0;
    for (int i = 0; i < candidate_count; i++)
    {

        if (candidates[i].votes > winner[0].votes)
        {
            winner[0].name = candidates[i].name;
            winner[0].votes = candidates[i].votes;
        }
    }
    
    printf("%s\n", winner[0].name);
    
    for (int x = 0; x < candidate_count; x++)
    {
        // Compare the votes                            // See if is the same name
        if (candidates[x].votes == winner[0].votes && (strcmp(candidates[x].name, winner[0].name) != 0))
        {
            winner[x].name = candidates[x].name;
            winner[x].votes = candidates[x].votes;
            printf("%s\n", winner[x].name);
        }
    }
    return;
}