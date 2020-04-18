#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE* fp;

    if (argc < 2)
    {
        printf("Usage: %s <dst_file>\n", argv[0]);
        return -1;
    }

    //打开文件
    if ((fp = fopen("test.txt", "r+")) == NULL)
    {
        perror("fopen");
        return -1;
    }

    //定位到文件末尾
    fseek(fp, 0, SEEK_END);

    //返回大小
    printf("%ld\n", ftell(fp));

    return 0;
}
