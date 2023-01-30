#include<stdio.h>

int main()
{
    char s[]= "\033[0mhello";
    printf("%lu", sizeof(s));
}