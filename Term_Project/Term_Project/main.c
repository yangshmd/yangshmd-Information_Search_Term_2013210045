#include <stdio.h>
#include "term.h"

int main(void)
{
	FILE* fp_stopword = fopen("C:\\Users\\yangs\\OneDrive\\문서\\yangshmd-Information_Search_Term_2013210045\\Term_Project\\Term_Project\\stopword.txt", "r");
	
	FILE* fp_read = fopen("C:\\Users\\yangs\\OneDrive\\문서\\yangshmd-Information_Search_Term_2013210045\\Term_Project\\Term_Project\\ir_corpus\\APW\\1998\\19980601_APW_ENG", "r");
	FILE* fp_write = fopen("C:\\Users\\yangs\\OneDrive\\문서\\yangshmd-Information_Search_Term_2013210045\\Term_Project\\Term_Project\\RESULT\\APW\\1998\\(Modified)19980601_APW_ENG", "w");
	FILE* fp_write2 = fopen("C:\\Users\\yangs\\OneDrive\\문서\\yangshmd-Information_Search_Term_2013210045\\Term_Project\\Term_Project\\RESULT\\APW\\1998\\(StopwordRemoved)19980601_APW_ENG", "w");
	
	// 나중에 반복문 이용해서 모든 파일 처리

	Parsing(fp_read, fp_write);

	fflush(fp_write);
	fp_write = fopen("C:\\Users\\yangs\\OneDrive\\문서\\yangshmd-Information_Search_Term_2013210045\\Term_Project\\Term_Project\\RESULT\\APW\\1998\\(Modified)19980601_APW_ENG", "r");

	Remove_Stopword(fp_write, fp_write2, fp_stopword);

	fclose(fp_read);
	fclose(fp_write);
	fclose(fp_write2);
	fclose(fp_stopword);

	return 0;
}