/*
index = 0.0588 * L - 0.296 * S - 15.8
where L is the average number of letters per 100 words in the text,
and S is the average number of sentences per 100 words in the text.
*/
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count(int count_type, string text);
int issentence_punct(char byte);
void reading_level(string text);

int main(void)
{
    // Prompt the user for a string of text
    string text = get_string("Text: ");

    // Calculate grade
    reading_level(text);
}

int count(int count_type, string text)
{
    int len = strlen(text);
    int letter_count = 0;
    int word_count = 0;
    int sentence_count = 0;

    int letters_found = 0; // prevent 'space' abuse
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letters_found++;
            letter_count++;
        }
        else if (isspace(text[i]) && letters_found)
        {
            word_count++;      // word found, space counts
            letters_found = 0; // reset word found to none
        }
        else if (issentence_punct(text[i]) && letters_found)
        {
            word_count++;      // word found by sentece punct
            sentence_count++;  // sentence found
            letters_found = 0; // reset word found to none
        }
        else
        { // for last word without \n
            if ((i >= len - 1) && letters_found)
            {
                word_count++;      // word found, space counts
                letters_found = 0; // reset word found to none
            }
        }
    }

    if (count_type == 1)
        return letter_count;
    else if (count_type == 2)
        return word_count;
    else if (count_type == 3)
        return sentence_count;
    else
        return 400400; // inspired by internet: BAD REQUEST :)
}

int issentence_punct(char byte)
{
    if (byte == '.' || byte == '!' || byte == '?')
        return 1;
    else
        return 0;
}

void reading_level(string text)
{
    // count param numbers" 1 = letters, 2 = words, 3 = sentences
    const int LETTERS = 1;
    const int WORDS = 2;
    const int SENTENCES = 3;
    int total_letters = count(LETTERS, text);
    int total_words = count(WORDS, text);
    int total_sentences = count(SENTENCES, text);

    // printf("%i letters\n", total_letters);
    // printf("%i words\n", total_words);
    // printf("%i sentences\n", total_sentences);

    float L = (float) total_letters / total_words * 100;   // average number of letters per 100 words
    float S = (float) total_sentences / total_words * 100; // average number of sentences per 100 words
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);
    // printf("%.2f = 0.0588 * %f - 0.296 * %f - 15.8\n", index, L, S);
    if (index < 1)
        printf("Before Grade 1\n");
    else if (index >= 16)
        printf("Grade 16+\n");
    else
        printf("Grade %i\n", grade);
}
