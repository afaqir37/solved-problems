/*

I made a program in C that checks if a positive number's binary form is a palindrome. 
If the binary number is a palindrome and its length is even, it prints "YES". 
If it's only a palindrome, it prints "yes". 
If it's neither a palindrome nor has an even length, it prints "no".

*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    
    int num = atoi(argv[1]);
    int copy = num;
    int result = 0;
    int check = 0;
    int counter = 0;

    // I used this for loop to print the binary representation of the number "num"
    // for (int i = 31; i >= 0; i--) 
    // {
    //     int bin = (num >> i) & 1;
    //     if (bin || check) {
    //         printf("%d", bin);
    //         check = 1;
    //     }
    // }
    // printf("\n");
    
    
    while (num > 0)
    {
        result = result * 2 + num % 2;
        num /= 2;
        counter++;
    }

    if (copy == result && counter % 2 == 0)
        printf("YES");
    else if (copy == result)
        printf("yes");
    else
        printf("no");


    return 0;
}