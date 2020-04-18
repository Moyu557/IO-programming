#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
    int fd;
    int size = 0;
    int n;          //read返回的字节数
    int buf[2048];

    //只读打开文件
    if ((fd = open("time.txt", O_RDONLY)) < 0)
    {
        if (errno == EEXIST)
        {
            perror("open");
        }
        else
        {
            perror("Other error");
        }
    }

    //循环读取
    while ((n = read(fd, buf, 1024)) > 0)
    {
        size += n;
    }

    printf("%d\n", size);
}
