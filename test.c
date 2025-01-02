#include <stdio.h>
#include "bonus/ft_printf_bonus.h"

void test_minus_flag() {
    int num = 42;
    int a, b;

    // Test 1: Single minus flag
    a = printf("\n%-2d|\n", -1);
    b = ft_printf("\n%-2d|\n", -1);
    printf("Test 1 - a: %d, b: %d\n", a, b);

    // Test 2: Minus flag with zero padding
    a = printf("\n%-010d|\n", num);
    b = ft_printf("\n%-010d|\n", num);
    printf("Test 2 - a: %d, b: %d\n", a, b);

    // Test 3: Minus flag with width
    a = printf("\n%-10d|\n", num);
    b = ft_printf("\n%-10d|\n", num);
    printf("Test 3 - a: %d, b: %d\n", a, b);

    // Test 4: Minus flag with plus sign
    a = printf("\n%+-10d|\n", num);
    b = ft_printf("\n%+-10d|\n", num);
    printf("Test 4 - a: %d, b: %d\n", a, b);

    // Test 5: Minus flag with space
    a = printf("\n%- 10d|\n", num);
    b = ft_printf("\n%- 10d|\n", num);
    printf("Test 5 - a: %d, b: %d\n", a, b);

    // Test 6: Minus flag with width and zero padding
    a = printf("\n%-010d|\n", num);
    b = ft_printf("\n%-010d|\n", num);
    printf("Test 6 - a: %d, b: %d\n", a, b);
}

int main() {
    test_minus_flag();
    return 0;
}
