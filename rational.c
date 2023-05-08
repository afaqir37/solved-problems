// It may need some optimizations and it's not fully tested
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct rational
{
    int numerator;
    int denominator;
} rational_t;

rational_t add(rational_t r1, rational_t r2);
rational_t subtract(rational_t r1, rational_t r2);
rational_t multiply(rational_t r1, rational_t r2);
rational_t divide(rational_t r1, rational_t r2);
rational_t absolute(rational_t r1);
rational_t exp_rational(rational_t r1, int n);
float      exp_real(int x, rational_t r);
rational_t reduce(rational_t r);
int        gcd(int a, int b);

int gcd(int a, int b)
{
    int i = 1;
    int divider;
    while (i <= a && i <= b)
    {
        if (a % i == 0 && b % i == 0)
            divider = i;
        i++;
    }
    return (divider);
}
rational_t add(rational_t r1, rational_t r2)
{
    rational_t result;
    result.numerator = r1.numerator * r2.denominator + r2.numerator * r1.denominator;
    result.denominator = r1.denominator * r2.denominator;

    result.numerator /= gcd(result.numerator, result.denominator);
    result.denominator /= gcd(result.numerator, result.denominator);
    if (result.denominator < 0)
    {
        result.denominator *= -1;
        result.numerator *= -1;
    }
    return (result);
}
rational_t subtract(rational_t r1, rational_t r2)
{
    rational_t result;
    result.numerator = r1.numerator * r2.denominator - r2.numerator * r1.denominator;
    result.denominator = r1.denominator * r2.denominator;

    result.numerator /= gcd(result.numerator, result.denominator);
    result.denominator /= gcd(result.numerator, result.denominator);
    if (result.denominator < 0)
    {
        result.denominator *= -1;
        result.numerator *= -1;
    }
    return (result);
}
rational_t multiply(rational_t r1, rational_t r2)
{
    if (!r1.denominator || !r2.denominator)
        exit(1);
    rational_t result;
    result.numerator = r1.numerator * r2.numerator;
    result.denominator = r1.denominator * r2.denominator;
    result.numerator /= gcd(result.numerator, result.denominator);
    result.denominator /= gcd(result.numerator, result.denominator);
    if (result.denominator < 0)
    {
        result.denominator *= -1;
        result.numerator *= -1;
    }
    return (result);
}
rational_t divide(rational_t r1, rational_t r2)
{
    if (!r1.denominator || !r2.denominator || !r2.numerator)
        exit(1);
    rational_t result;
    result.numerator = r1.numerator * r2.denominator;
    result.denominator = r1.denominator * r2.numerator;
    result.numerator /= gcd(result.numerator, result.denominator);
    result.denominator /= gcd(result.numerator, result.denominator);
    if (result.denominator < 0)
    {
        result.denominator *= -1;
        result.numerator *= -1;
    }
    return (result);
}
rational_t absolute(rational_t r1)
{
    if (r1.denominator == 0)
        exit(1);
    rational_t result;
    if (r1.numerator < 0)
        result.numerator = r1.numerator * (-1);
    if (r1.denominator < 0)
        result.denominator = r1.denominator * (-1);
    return (result);
}
rational_t exp_rational(rational_t r, int n)
{
    rational_t result;
    result.numerator = pow(r.numerator, n);
    result.denominator = pow(r.denominator, n);
    return (result);
}
rational_t reduce(rational_t r)
{
    rational_t result;
    result.numerator = r.numerator / gcd(r.numerator, r.denominator);
    result.denominator = r.denominator / gcd(r.numerator, r.denominator);
    if (result.denominator < 0)
    {
        result.denominator *= -1;
        result.numerator *= -1;
    }
    return (result);
}
float exp_real(int x, rational_t r)
{
    float result = pow(x, 1 / r.denominator);
    float new_result = pow(result, r.numerator);
    return (new_result);
}
#include <stdio.h>
int main()
{
    rational_t r1 = {2, 0};
    rational_t r2 = {4, 0};
    rational_t d = absolute(r1);
    printf("%d %d", d.numerator, d.denominator);
}
