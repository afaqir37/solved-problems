// Determine if a word or phrase is an isogram.

// An isogram (also known as a "non-pattern word") is a word or phrase without
// a repeating letter, however spaces and hyphens are allowed to appear multiple times.

// Examples of isograms:

// lumberjacks
// background
// downstream
// six-year-old
// The word isograms, however, is not an isogram, because the s repeats.



#include <stdio.h>
#include <stdbool.h>

bool    is_isogram(const char *phrase)
{
    if (!phrase)
        return (false);
    int letter_flag = 0;
    char sub;
    while (*phrase)
    {
        if (*phrase >= 'a' && *phrase <= 'z')
            sub = 'a';
        else if (*phrase >= 'A' && *phrase <= 'Z')
            sub = 'A';
        else
            sub = 'X';
        if (sub != 'X')
        {
            if ((letter_flag & (1 << (*phrase - sub))) != 0)
                return (false);
            else
                letter_flag |= (1 << (*phrase - sub));
        }
        phrase++;
    }
    return (true);
}

int main()
{
    printf("%d\n", is_isogram("up-to-date"));
}