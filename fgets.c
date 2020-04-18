#include <stdio.h>

int main()
{
    char buf[2048];

    while (fgets(buf, 1024, stdin) != NULL)
    {
        fputs(buf, stdout);
    }
}
