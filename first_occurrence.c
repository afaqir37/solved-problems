// Given two strings needle and haystack, 
// return the index of the first occurrence of needle in 
// haystack, or -1 if needle is not part of haystack.

#include <stdio.h>
int strStr(char * haystack, char * needle)
{
    int i = 0;
    int j = 0;
    int save_index;
    
    while(haystack[i])
    {
        j = 0;
        if (haystack[i] == needle[j])
        {
        save_index = i;
        while(needle[j] && haystack[i] && haystack[i] == needle[j])
        {
            if (needle[j+1] == 0)
                return (i - j);
            i++;
            j++;
        }
        i = save_index + 1;
        }
        else
            i++;
        
    }
    return (-1);
}

int main()
{
    printf("%d\n", strStr("leetiocode", "io"));
}