#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>

int main(int argc, char **argv)
{
  if (argc < 2)
    argv[1] = ".";

  DIR *dir;
  struct dirent *ent;
  dir = opendir(argv[1]);

  switch (errno) {
  case ENOTDIR: fprintf(stdout, "%s\n", argv[1]); break;
  case ENOENT: fprintf(stderr, "NO SUCH FILE OR DIRECTORY\n"); break;
  default:
    while ((ent = readdir(dir)) != NULL)
      fprintf(stdout, "%s ", ent->d_name);
    puts("");
    break;
  } closedir(dir);

  return 0;
}
