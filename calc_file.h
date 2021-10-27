#include <stdio.h>
#include <stdlib.h>

void calc()
{
    char type;
    printf("Enter d for decimal operations and i for integer operation: ");
    scanf("%c", &type);
    if (type == 'i')
    {
        getchar();
        int a, b;
        printf("Enter first number: ");
        scanf("%d", &a);
        printf("Enter second number: ");
        scanf("%d", &b);
        char o;
        printf("Enter operation(+, -, /, *): ");
        getchar();
        scanf("%c", &o);
        if (o == '+')
        {
            printf("%d\n\n", a + b);
        }
        else if (o == '-')
        {
            printf("%d\n\n", a - b);
        }
        else if (o == '*')
        {
            printf("%d\n\n", a * b);
        }
        else if (o == '/')
        {
            printf("%d\n\n", a / b);
        }
    }
    else
    {
        getchar();
        float x, y;
        printf("Enter first number: ");
        scanf("%f", &x);
        printf("Enter second number: ");
        scanf("%f", &y);
        char o;
        printf("Enter operation(+, -, /, *): ");
        getchar();
        scanf("%c", &o);
        if (o == '+')
        {
            printf("%.2f\n\n", x + y);
        }
        else if (o == '-')
        {
            printf("%.2f\n\n", x - y);
        }
        else if (o == '*')
        {
            printf("%.2f\n\n", x * y);
        }
        else if (o == '/')
        {
            printf("%.2f\n\n", x / y);
        }
    }
}