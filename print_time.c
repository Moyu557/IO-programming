#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int main()
{
    FILE* fp;
    int line = 0;   //记录行号
    char buf[64];   //获取文件的一行，进行记录
    time_t t;       //获取秒数
    struct tm* tm;  //本地时间转换的指针

    //打开文件
    if ((fp = fopen("time.txt", "a+")) == NULL)
    {
        perror("fopen");
        return -1;
    }

    //先读取源文件中的内容确定line的值，再写入新内容
    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
       // if (buf[strlen(buf) - 1] == '\n')   //保证读完一行
        //{
            ++line;
        //}
    }

    while (1)
    {
        //获取系统时间
        t = time(NULL);

        //将系统时间转换成本地时间
        tm = localtime(&t);  

        //将本地时间写入文件
        fprintf(fp, "%3d,%d-%2d-%2d-%2d-%2d-%2d\n", ++line, 
               tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
               tm->tm_hour, tm->tm_min, tm->tm_sec);

        //文件是全缓冲，所以强制刷新流
        fflush(fp);

        //睡眠1秒，便于写入文件
        sleep(1);
    }
}
