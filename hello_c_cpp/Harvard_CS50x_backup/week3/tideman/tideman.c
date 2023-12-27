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

    int graph_limit = pair_count - 1;

    for (int i = 0; i < pair_count; i++) // loop from strongest pairs[i].winner
    {
        // lock first pair since there's no locked pairs yet
        if (i == 0)
            locked[pairs[i].winner][pairs[i].loser] = true;
        else
        {
            // traverse back to first locked pair and then intermediate pairs up to before current pair
            bool no_cycle_found = true;
            int current_winner = pairs[i].winner;     //                            3
            int current_loser = pairs[i].loser;       //                            1
            int locked_past_winner = pairs[0].winner; //      1
            int locked_past_loser = pairs[0].loser;   //      0
                                       //                     0     1       2      i3
                                       //              pairs 1,0----0,2----2,3----3,1
                                       //                     0     j1      2
            for (int j = 0; j < i; j++)//                    T      T       T
            {
                if (locked[pairs[j].winner][pairs[j].loser])
                {
                    if (j == 0)
                    { // check if loser was a winner of the first pair
                        if (current_loser == locked_past_winner)
                            no_cycle_found = false; // potential cycle found
                        else
                            no_cycle_found = true;

                    }
                    else if (j > 0)
                    {
                        current_winner = pairs[j].winner;
                        current_loser = pairs[j].loser;
                        locked_past_winner = pairs[j - 1].winner;
                        locked_past_loser = pairs[j - 1].loser;

                        if (current_winner == locked_past_loser && no_cycle_found == false)
                            no_cycle_found = false; // potential cycle found
                        else
                            no_cycle_found = true;
                    }
                }
                if (no_cycle_found)
                {
                    if (i == graph_limit)
                    {
                        locked[pairs[i].winner][pairs[i].loser] = false;
                        break;
                    }
                    else
                    {
                        locked[pairs[i].winner][pairs[i].loser] = true;
                        break;
                    }
                }
            }
        }
    }

    // print pairs matrix
    printf("print pairs matrix\n");
    for (int i = 0; i < pair_count; i++)
    {
        printf("%i: [%i][%i]: ", i, pairs[i].winner, pairs[i].loser);
        if (locked[pairs[i].winner][pairs[i].loser])
            printf("T\n");
        else
            printf("F\n");
    }
    printf("-------------------\n");
    return;
}

// Print the winner of the election
void print_winner(void)
{

    // in printing winner over all
    // just add one integer to pref_count each [i][j] or preferences
    // if pref_count > 0, then we have a loser
    // else we have a winner


    for (int i = 0; i < candidate_count; i++)
    {
        bool no_arrow = false;

        for (int j = 0; j < candidate_count; j++)
        {
            // check if there's a line or rows that has no arrow
            // a b, b c, c a
            if (locked[j][i] == false)
            {
                no_arrow = true;
            }
            else
                no_arrow = false;
        }
        if (no_arrow)
        {
            printf("%s\n", candidates[i]);
            break;
        }
    }
    return;
}
