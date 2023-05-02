// Given a string s consisting of words and spaces, 
// return the length of the last word in the string.

// A word is a maximal substring
// consisting of non-space characters only.

#include <stdio.h>
#include <string.h>
int lengthOfLastWord(char * s)
{
    if (!s || s[0] == 0)
        return (0);
    int i = 0;
    int j = strlen(s) - 1;
    while(s[j] == ' ')
        j--;
    while(j >= 0 && s[j] != ' ')
    {
        j--;
        i++;
    }
    return (i);
}
int main()
{
    printf("%d\n", lengthOfLastWord("luffy is still joyboy"));
}