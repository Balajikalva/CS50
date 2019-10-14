#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 9

typedef struct
{
    char *name;
    int votes;
}
candidate;

//Array of candidates
candidate candidates[10];
int candidate_count;

// functions
bool vote(char *name);
void print_winner(void);

int main( int argc , char *argv[])
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

    int t;
    printf("Number of voters: ");
    scanf("%d",&t);

    // intializing the data
    for(int i = 0 ; i < argc -1 ; i++)
    {
        candidates[i].name = argv[i+1];
        candidates[i].votes = 0;
    }

    // getting votes from user
    char *v;
    v = (char*) malloc(1);

    for (int i = 0 ; i < t ; i++)
    {
        printf("Vote : ");
        scanf("%s",v);
        //printf("vote is : %s\n",vote);

        if (!vote(v))
        {
            printf("Invalid vote.\n");
        }
    }

    print_winner();
    free(v);
}


// Update vote totals given a new vote
bool vote(char *name)
{
    for (int i = 0 ; i < candidate_count ; i++)
    {
      if (strcmp(candidates[i].name,name) == 0)
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
  int M = -10;

  for (int i = 0 ; i < candidate_count ; i++)
  {
    if (candidates[i].votes > M)
    {
      M = candidates[i].votes;
    }
  }

  for (int j = 0 ; j < candidate_count ; j++)
  {
    if (candidates[j].votes == M)
    {
      printf("%s\n",candidates[j].name);
    }
  }
    return;
}
