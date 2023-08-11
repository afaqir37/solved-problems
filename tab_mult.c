#include <unistd.h>
void ft_putNbr(int n) {
    if (n < 0)
    {
	n *= -1;
	write(1, "-", 1);
    }
    if (n >= 0 && n <= 9) {
        n += 48;
        write(1, &n, 1);
    }
    else {
        ft_putNbr(n / 10);
        ft_putNbr(n % 10);
    }
}

int ft_atoi(char *s) {
    int i = 0;
    int result = 0;
    int sign = 1;
    while (s[i])
    {
	if(s[i] == '-')
	{
		sign = -1;
		i++;
		continue;
	}
        result = result * 10 + (s[i] - 48);
        i++;
    }
    return (result * sign);
}
int main(int argc, char **argv) {
    if (argc != 2)
        write(1, "\n", 1);
    else {
        int number = ft_atoi(argv[1]);
	char i = '1';
	int sign = 0;
        while (i <= '9') {
            write(1, &i, 1);
            write(1, " * ", 3);
            ft_putNbr(number);
            write(1, " = ", 3);
            ft_putNbr(number * (i - 48));
            i++;
            write(1, "\n", 1);
        }



    }

}
