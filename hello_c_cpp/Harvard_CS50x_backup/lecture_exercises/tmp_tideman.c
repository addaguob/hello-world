#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    const bool isvalid_candidate = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        preferences[rank][i] = 0; // initate for later use in record_preferences

        // look if name is a candidate
        if (strcmp(name, candidates[i]) == isvalid_candidate)
        { // then store candidate index
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    /*
    manual model based on walkthrough:

    candidates: 3 {0:Alice, 1:Bob, 2:Charlie}

    voters: 5
    {
           r 0--1--2 ---> ranks
        v 0 |0, 2, 1], --> it means Charlie is preferred or ranked 0, Bob 1, Alice 2 by voter 0
        v 1 |0, 2, 1],
        v 2 |1, 2, 0],
        v 3 |1, 2, 0],
        v 4 |2, 0, 1],
    }

    preferences: 3x3
    { --> increment each[i][j] based above preferences
          j__0__1__2
        i 0| 0  3  2
        i 1| 2  0  2
        i 2| 3  3  0
    }

    */
    for (int i = 0; i < candidate_count; i++) // rank counter
    {
        // candidate in rank[i] preferred over candidate in rank[j]
        for (int j = i + 1; j < candidate_count; j++)
        { // (j + 1) skips same candidate index
            // ranks[i, j ... ]
            // ranks[2, 0, 3, 1]
            preferences[ranks[i]][ranks[j]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++) // compare this candidate
    {
        for (int j = i + 1; j < candidate_count; j++) // with each of these
        {                                             // j = i + 1 = so that after i/j don't have to check the inverse j/i
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            { // we can't just use "else" in case i and j are the same candidate index (initiated to 0)
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
            // if tie, just move on, no pair_count++
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    /*

    pairs
    { --> add pair's indices of winner and loser:
        0:[0][1], --> sample current_win_strength is [preferences[0][1] vs [1][0] or 3 vs 2 = 1
        1:[2][0], --> 3 - 2 = 1
        2:[2][1], --> 3 - 2 = 1
    } --> pair_count = 3

    and now, let's sort win strength!

    loop i through pairs
        swapped of bubble sort = false
        loop j = i + 1 through next pairs
            pair current_wins_by; // will store total victories instead of preferences indices
            current_wins_by.winner = preferences[pairs[j].winner][pair[j].loser];
            current_wins_by.loser = preferences[pairs[j].loser][pair[j].winner];
            current_win_strength = current_wins_by.winner - current_wins_by.loser;
            pair next_wins_by;
            next_wins_by.winner = preferences[pairs[j + 1].winner][pair[j + 1].loser];
            next_wins_by.loser = preferences[pairs[j + 1].loser][pair[j + 1].winner];
            next_win_strength = next_wins_by.winner - next_wins_by.loser;
            if current_win_strength < next_win_strength
                then swap pairs[i] and pairs[j], i = 0 is the strongest first come first serve

    Let's try below!
    */

    // Sort by descending order through strongest_pair ranking
    for (int i = 0; i < pair_count; i++) // will use bubble sort
    {
        bool swapped = false; // bubble sort's swap detector

        for (int j = 0; j < pair_count; j++) // loop through pairs and desc_sort them
        {
            pair current_wins_by; // will store total victories instead of preferences indices
            current_wins_by.winner = preferences[pairs[j].winner][pairs[j].loser];
            current_wins_by.loser = preferences[pairs[j].loser][pairs[j].winner];
            int current_win_strength = current_wins_by.winner - current_wins_by.loser;

            pair next_wins_by;
            next_wins_by.winner = preferences[pairs[j + 1].winner][pairs[j + 1].loser];
            next_wins_by.loser = preferences[pairs[j + 1].loser][pairs[j + 1].winner];
            int next_win_strength = next_wins_by.winner - next_wins_by.loser;

            pair tmp;

            if (current_win_strength < next_win_strength)
            {
                tmp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = tmp;

                swapped = true;
            }
            // but if they're equal, I want the winner's loser who wins over the other loser
            else if (current_win_strength == next_win_strength)
            { // let's have them battle by preferences
                if (preferences[pairs[j].loser][pairs[j + 1].loser] > preferences[pairs[j + 1].loser][pairs[j].loser])
                {
                    tmp = pairs[j];
                    pairs[j] = pairs[j + 1];
                    pairs[j + 1] = tmp;

                    swapped = true;
                }
                else if (preferences[pairs[j].loser][pairs[j + 1].loser] < preferences[pairs[j + 1].loser][pairs[j].loser])
                {
                    tmp = pairs[j];
                    pairs[j] = pairs[j + 1];
                    pairs[j + 1] = tmp;

                    swapped = true;
                }
            }
        }

        if (swapped)
            swapped = false; // reset before repeating loop
        else
            return;
    }
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    /*
    pairs
    { --> add pair's indices of winner and loser:
        0:[0][1], --> sample current_win_strength is [preferences[0][1] vs [1][0] or 3 vs 2 = 1
        1:[2][0], --> 3 - 2 = 1
        2:[2][1], --> 3 - 2 = 1
    } --> pair_count = 3
                                                            0|1 -> 1|2
    loop through i:   {0-------1-------2}                    |      |
                    {[0][1], [2][0], [2][1]}                 |      v
          strength:    1   vs   1   vs  1                   3|0 <- 2|3
            locked:    T        T       F
    */

    bool there_is_cycle = false;
    int graph_limit = pair_count - 1;
    int lock_count = 0;
    int partial_cycle_count = 0;

    for (int i = 0; i < pair_count; i++) // loop from strongest pairs[i].winner
    {
        // 1st: Lock current pair since there's no locked pairs yet
        if (lock_count == 0)
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
            lock_count++;
        }

        // 2nd: If there is/are locked pairs, check if the current winner
        //      and loser's edge is connecting to each locked pairs
        else if (lock_count > 0 && lock_count < graph_limit)
        {
            int current_winner = pairs[i].winner;

            // traverse back to each locked pair starting from the recent one
            for (int j = lock_count - 1; j > 0; j--)
            {
                // recent locked[winner][loser] = true = is a locked pair
                if (locked[pairs[j].winner][pairs[j].loser] == true)
                {
                    int recent_winner = pairs[j].winner;
                    // cycle visual sample of 3 beaten by 2 beaten by 1<--0<--3
                    // let's say current W|L is here---------------- ↓
                    // loop of i-----------------------------------(3↓0)
                    // locked pairs of j---------[0|1] [1|2] [2|3] (3|0)
                    // j = 3 = (lock_count - 1)    j0    j1    j2
                    if (current_winner == pairs[j].loser)
                    {
                        current_winner = recent_winner;
                        // if loop of j completes and lock_count equals to:
                        partial_cycle_count++;
                        // then we have a complete cycle
                    }
                }
            }

            if (partial_cycle_count == lock_count)
                there_is_cycle = true;
            else if (partial_cycle_count < lock_count)
            else
            {
                // reset for next [i] in case there was a cycle
                there_is_cycle = false;

                // lock pair if there is no cycle
                locked[pairs[i].winner][pairs[i].loser] = true;
                lock_count++;
            }
        }
        // 3rd, if graph_limit is reached, we shouldn't lock the last pair anymore
    }
    // lock_count is not a global variable so I will transfer its content to pair_count
    pair_count = lock_count;
    return;
}

// Print the winner of the election
void print_winner(void)
{
    /*
    :) tideman.c exists
    :) tideman compiles
    :) vote returns true when given name of candidate
    :) vote returns false when given name of invalid candidate
    :) vote correctly sets rank for first preference
    :) vote correctly sets rank for all preferences
    :) record_preferences correctly sets preferences for first voter
    :) record_preferences correctly sets preferences for all voters
    :) add_pairs generates correct pair count when no ties
    :) add_pairs generates correct pair count when ties exist
    :) add_pairs fills pairs array with winning pairs
    :) add_pairs does not fill pairs array with losing pairs
    :) sort_pairs sorts pairs of candidates by margin of victory
    :) lock_pairs locks all pairs when no cycles
    :) lock_pairs skips final pair if it creates cycle
    :) lock_pairs skips middle pair if it creates a cycle
    :) print_winner prints winner of election when one candidate wins over all others
    :( print_winner prints winner of election when some pairs are tied
        print_winner did not print winner of election
    */
    for (int i = 0; i < pair_count; i++) // pair_count has the lock_count total
    {
        int winner_defeated = 0;

        for (int j = i + 1; i < pair_count; j++)
        {
            if (locked[pairs[i].winner][pairs[i].loser] == true)
                if(pairs[i].winner == pairs[j].loser)
                    winner_defeated++;
        }
        if (!winner_defeated)
        {
            printf("%s\n", candidates[pairs[i].winner]);
            return;
        }
        else
            winner_defeated = 0; // reset for next locked pair
    }
    return;
}
