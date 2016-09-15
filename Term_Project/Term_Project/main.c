#include <stdio.h>
#include "term.h"

int main(void)
{
	FILE* fp_stopword = fopen("stopword.txt", "rt");
	/*FILE* fp_read = fopen("19980601_APW_ENG", "rt");
	FILE* fp_read = fopen("test.txt", "r");
	FILE* fp_write = fopen("(Modified)19980601_APW_ENG", "wt");
	FILE* fp_write = fopen("(Modified)test.txt", "w");
	FILE* fp_write2 = fopen("(StopwordRemoved)19980601_APW_ENG", "wt");
	FILE* fp_write2 = fopen("(StopwordRemoved)test.txt", "w");*/

	FILE* fp_read = fopen("19980601_NYT", "r");
	FILE* fp_write = fopen("(Modified)19980601_NYT", "w");
	FILE* fp_write2 = fopen("(StopwordRemoved)19980601_NYT", "w");
	
	// 나중에 반복문 이용해서 모든 파일 처리

	Parsing(fp_read, fp_write);

	fflush(fp_write);
	//fp_write = fopen("(Modified)test.txt", "r");		// fflush 하고 다시 해줘야되네
	fp_write = fopen("(Modified)19980601_NYT", "rt");

	Remove_Stopword(fp_write, fp_write2, fp_stopword);

	fclose(fp_read);
	fclose(fp_write);
	fclose(fp_stopword);

	return 0;
}