#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    char buf[2018];

    if ((fd = open("test.txt", O_RDWR)) == -1)
    {
        perror("open");
        return -1;
    }

    lseek(fd, 0, SEEK_END);

    if (read(0, buf, 1024) == -1)
    {
        perror("read");
        return -1;
    }

    if (getc(0,fd) == -1)
    {
        perror("write");
        return -1;
    }

    close(fd);
}
