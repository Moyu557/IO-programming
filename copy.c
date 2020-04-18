#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int src_fd, dst_fd;
    char buf[2048];

    //判断输入
    if (argc < 3)
    {
        printf("Usage: %s <src_file> <dst_file>\n", argv[0]);
        return -1;
    }

    //打开文件原文件
    if ((src_fd = open(argv[1], O_RDONLY | O_CREAT, 0666)) < 0)
    {
        perror("open");
        return -1;
    }

    //打开目标文件
    if ((dst_fd = open(argv[2], O_WRONLY | O_CREAT, 0666)) < 0)
    {
        perror("open");
        return -1;
    }

    //复制
    int n;
    while ((n = read(src_fd, buf, 1024)) > 0)
    {
        write(dst_fd, buf, n);
    }

    //关闭文件描述符
    close(src_fd);
    close(dst_fd);
}
