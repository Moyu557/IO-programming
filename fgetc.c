#include <stdio.h>

int main()
{
    char c;
    while ((c = fgetc(stdin)) != EOF)
    {
        fputc(c, stdout);
    }
}
