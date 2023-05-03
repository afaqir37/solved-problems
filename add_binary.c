// Given two binary strings a and b, return their sum as a binary string.

// Input: a = "11", b = "1"
// Output: "100"

// Input: a = "1010", b = "1011"
// Output: "10101"

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

    char *s     = malloc(1);
    int  carry  = 0;
    int  i      = strlen(a) - 1;
    int  j      = strlen(b) - 1;
    int  k      = 0;
    char a_save;
    char b_save;
    while(i >= 0 || j >= 0)
    {
        if (i < 0 || j < 0)
        {
            if (i < 0)
            {
                a_save = '0';
                b_save = b[j];
            }
            if (j < 0)
            {
                b_save = '0';
                a_save = a[i];
            }
        }
        else
        {
            a_save = a[i];
            b_save = b[j];
        }
        
        if (a_save == '0' && b_save == '0' && carry == 0)
            s[k] = '0';
        else if (a_save == '0' && b_save == '0' && carry == 1)
        {
             carry = 0;
             s[k] = '1';
        }
        else if (a_save == '0' && b_save == '1' && carry == 0)
            s[k] = '1';
        else if (a_save == '0' && b_save == '1' && carry == 1)
            s[k] = '0';
        else if (a_save == '1' && b_save == '0' && carry == 0)
            s[k] = '1';
        else if (a_save == '1' && b_save == '0' && carry == 1)
            s[k] = '0';
        else if (a_save == '1' && b_save == '1' && carry == 0)
        {
            s[k] = '0';
            carry = 1;
        }
        else if (a_save == '1' && b_save == '1' && carry == 1)
            s[k] = '1';
        s = realloc(s, k+2);
        k++;
        i--;
        j--;
}
    if (carry == 1)
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
    printf("%s", addBinary("1111111", "1"));
}