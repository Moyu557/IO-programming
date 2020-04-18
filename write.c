#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd;
    char buf[2048];

    //打开文件
    if ((fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666)) < 0)
    {
        perror("open");
        return -1;
    }

    //循环读取输入
    while (fgets(buf, 1024, stdin) != NULL)
    {
        //输入为quit
        if (strcmp("quit\n", buf) == 0)
            break;

        //将输入写入文件
        write(fd, buf, strlen(buf));
    }

    close(fd);
}
