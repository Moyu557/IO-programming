#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    struct stat buf;    //文件属性
    int n;
    struct tm* tp;

    if (argc < 2)
    {
        printf("Usage: %s <file>\n", argv[0]);
        return -1;
    }

    //获取文件属性
    if (lstat(argv[0], &buf) < 0)
    {
        perror("lstat");
        return -1;
    }

    //获得文件的类型
    switch (buf.st_mode & S_IFMT)
    {
    case S_IFREG:
        printf("-");
        break;
    case S_IFDIR:
        printf("d");
        break;
    }

    //获得文件的权限
    for (n = 8; n >= 0; --n)
    {
        if (buf.st_mode & (1 << n))
        {
            switch (n % 3)
            {
            case 2:
                printf("r");
                break;
            case 1:
                printf("w");
                break;
            case 0:
                printf("x");
                break;
            }
        }
        else
        {
            printf("-");
        }
    }

    //文件大小
    printf("  %lu", buf.st_size);
    
    //时间
    tp = localtime(&buf.st_mtime);
    printf("   %d-%2d-%2d", tp->tm_year + 1900, tp->tm_mon + 1, 
          tp->tm_mday);

    //打印文件名
    printf("   %s\n", argv[1]);

}
