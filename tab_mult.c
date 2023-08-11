#include <unistd.h>
int _valid_numbers(int argc, char **argv) {
    
    int i;

    i = 1;
    while (i < argc) {
        int j = 0;
        if (argv[i][j] == '+' || argv[i][j] == '-')
            j++;
        while (argv[i][j]) {
            
            if (argv[i][j] > '9' || argv[i][j] < '0') {
                printf("Error: %s is not a valid input\n", argv[i]);
                return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}

void ft_putNbr(long n) {
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
    long int result = 0;
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
	if (_valid_numbers(argc, argv))
		return 1;
        long int number = ft_atoi(argv[1]);
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
