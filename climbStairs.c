// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps.
// In how many distinct ways can you climb to the top?

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps

// Input: n = 3
// Output: 3
// Explanation: There are three ways to climb to the top.
// 1. 1 step + 1 step + 1 step
// 2. 1 step + 2 steps
// 3. 2 steps + 1 step

#include <stdlib.h>
#include <stdio.h>

int climbStairs(int n)
{
    if (n <= 3)
        return (n);
    int *save = malloc(n * sizeof(int));
    save[0] = 1;
    save[1] = 2;
    for(int i = 2; i < n  ; i++)
        save[i] = save[i - 1] + save[i -2];
    return (save[n-1]);
}
int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d\n", climbStairs(n));
    return 0;
}