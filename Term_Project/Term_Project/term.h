#include <stdio.h>
#include <string.h>

#define SIZE	100

#define TRUE	1
#define FALSE	0

void Parsing(FILE* fp_read, FILE* fp_write);
void Remove_Stopword(FILE* fp_read, FILE* fp_write, FILE* fp_stopword);