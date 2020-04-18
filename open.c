#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main()
{
    int fp;

    if ((fp = open("1.txt", O_RDWR | O_CREAT | O_EXCL, 0666)) < 0)
    {
        if (errno == EEXIST)
            perror("open");
        else
            perror("Other error");
        return -1;
    }

    close(fp);
}
