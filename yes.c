#include <stdio.h>

int main(int argc, char **argv)
{
    argv[1] = argc < 2 ? "y" : argv[1];
    while (1)
        printf("%s\n", argv[1]);
    return 0;
}
