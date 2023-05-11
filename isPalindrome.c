// A phrase is a palindrome if, after converting all uppercase
// letters into lowercase letters and removing all non-alphanumeric
// characters, it reads the same forward and backward. Alphanumeric
// characters include letters and numbers.

// Given a string s, return true if it is a palindrome,
// or false otherwise.

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.

// Input: s = "0P"
// Output: false

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int ft_valid(int c)
{
    if (isalpha(c) || isdigit(c))
        return (1);
    return (0);
}

bool isPalindrome(char * s){
    if (!s)
        return (true);

    int i = 0;
    int j = strlen(s);
    int m = strlen(s) - 1;
    while (i < j && m >= 0)
    {
       int c = tolower(s[i]);
       int k = tolower(s[m]);
       if (ft_valid(c) && ft_valid(k))
       {
           if (c != k)
             return (false);
            i++;
            m--;
       }
       else if (ft_valid(c) && !ft_valid(k))
            m--;
       else
            i++;
    }
    return (true);
}

int main()
{
    printf("%d", isPalindrome("A man, a plan, a canal: Panama"));
}

