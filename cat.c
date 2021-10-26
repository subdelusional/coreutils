#include <stdlib.h>
#include <stdio.h>

void lfile(FILE*);

int main(int argc, char** argv)
{
	int i;
	FILE* f_ptr;
	
	i = 1;
	f_ptr = argc > 1 ? fopen(argv[i], "r") : stdin;

	if (argc > 2) {
		while (i < argc) {
			f_ptr = fopen(argv[i], "r");
			lfile(f_ptr); 
			i++;
		}
	} else lfile(f_ptr);
	
	return 0;
}

void lfile(FILE* f)
{
	char buf[BUFSIZ];
	while (fgets(buf, sizeof(buf), f) != NULL)
		fprintf(stdout, "%s", buf);
}
