#include <stdio.h>
#include "bonus/ft_printf_bonus.h"

void test_minus_flag() {
    int num = 42;
    int a, b;

    a = printf(" %-1c| %-2c| %-3c| \n", '0', 1, '1');
    b = ft_printf(" %-1c| %-2c| %-3c| \n", '0', 1, '1');
    printf(" Length: %d, %d\n", a, b);

    a = printf(" %-1c %-2c %-3c \n", ' ', ' ', ' ');
    b = ft_printf(" %-1c %-2c %-3c \n", ' ', ' ', ' ');
    printf(" Length: %d, %d\n", a, b);

    a = printf(" %-1c %-2c %-3c \n", '1', '2', '3');
    b = ft_printf(" %-1c %-2c %-3c \n", '1', '2', '3');
    printf(" Length: %d, %d\n", a, b);

    a = printf(" %-1c %-2c %-3c \n", '2', '1', 0);
    b = ft_printf(" %-1c %-2c %-3c \n", '2', '1', 0);
    printf(" Length: %d, %d\n", a, b);

    a = printf(" %-1c %-2c %-3c \n", 0, '1', '2');
    b = ft_printf(" %-1c %-2c %-3c \n", 0, '1', '2');
    printf(" Length: %d, %d\n", a, b);
}

int main() 
{
    test_minus_flag();
    return 0;
}
