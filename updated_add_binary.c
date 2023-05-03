// Given two binary strings a and b, return their sum as a binary string.

// Input: a = "11", b = "1"
// Output: "100"

// Input: a = "1010", b = "1011"
// Output: "10101"


// >>>>>> another version of my implementation of add_binary problem   <<<<<<


#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void ft_strrev(char *s)
{
    for(unsigned long i = 0; i< strlen(s)/2;i++)  // "unsigned long" is used to silent the warning when comparing i (int) 
    {                                             // and strlen(s)/2 (unsigned long)
        char tmp = s[i];
        s[i] = s[strlen(s) -1 -i];
        s[strlen(s) - 1 -i] = tmp;
    } 
  
}
char * addBinary(char * a, char * b){

    if (!a || !b)
        return (NULL);

    char *s = malloc(1);
    if (!s)
    return (NULL);

    int i = strlen(a) - 1;
    int j = strlen(b) - 1;
    int carry = 0;
    int k = 0;
    int sum = 0;
    while (i >= 0 || j >= 0)
    {
        sum = (sum > 1 ? 1 : 0) + (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0);
        i--;
        j--;
        s[k] = sum % 2 + '0';
        s = realloc(s, k + 2);
        if (!s)
        return (NULL);
        k++;
    }

    if (sum > 1)
    {
        s[k] = '1';
        s = realloc(s, k+2);
        s[k + 1] = 0;
    }
    else
        s[k] = 0;
    ft_strrev(s);
    return (s);

}

int main()
{
    char *a = addBinary("111", "1");
    printf("%s", a);
}