#include <stdio.h>

int main()
{
    FILE* fp;
    int count = 0;      //打开的文件数

    while (fp = fopen("test.txt", "r"))
    {
        ++count;
    }

    printf("Open file number is %d.\n", count);
}
