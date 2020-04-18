#include <stdio.h>

int main(int argc, char* argv[])
{
    FILE* fps, *fpd;
    char buf[2048];
    int n;

    if (argc < 3)
    {
        printf("Usage: %s <src_file> <dst_file>\n", argv[0]);
        return -1;
    }

    if ((fps = fopen(argv[1], "r")) == NULL)
    {
        perror("fopen src file");
        return -1;
    }

    if ((fpd = fopen(argv[2], "w")) == NULL)
    {
        perror("fopen dst file");
        return -1;
    }

    while ((n = fread(buf, 1, 1024, fps)) > 0)
    {
        fwrite(buf, 1, 1024, fpd);
    }

    fclose(fps);
    fclose(fpd);

    return 0;
}
