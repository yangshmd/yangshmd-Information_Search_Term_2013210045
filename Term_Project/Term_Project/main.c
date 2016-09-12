#include <stdio.h>
#include <string.h>
#include "term.h"

int main(void)
{
	char temp_line[SIZE];
	int check = FALSE;

	FILE* fp_read = fopen("19980601_APW_ENG", "rt");
	FILE* fp_write = fopen("(Extracted)19980601_APW_ENG", "wt");

	// FILE* fp = fopen("test.txt", "rt");

	while (fgets(temp_line, sizeof(temp_line), fp_read) != NULL)
	{
		if (strncmp(temp_line, "<DOCNO>", sizeof(char)*strlen("<DOCNO>")) == 0)
		{
			printf("%s", temp_line);
			fputs(temp_line, fp_write);
		}

		if (strncmp(temp_line, "<HEADLINE>", sizeof(char)*strlen("<HEADLINE>")) == 0)
			check = TRUE;
		if (strncmp(temp_line, "</HEADLINE>", sizeof(char)*strlen("</HEADLINE>")) == 0)
		{
			printf("%s", temp_line);
			fputs(temp_line, fp_write);
			check = FALSE;
		}

		if (strncmp(temp_line, "<TEXT>", sizeof(char)*strlen("<TEXT>")) == 0)
			check = TRUE;
		if (strncmp(temp_line, "</TEXT>", sizeof(char)*strlen("</TEXT>")) == 0)
		{
			printf("%s", temp_line);
			fputs(temp_line, fp_write);
			check = FALSE;
		}
				
		if (check == TRUE)
		{
			printf("%s", temp_line);
			fputs(temp_line, fp_write);
		}
	}

	fclose(fp_read);
	fclose(fp_write);

	return 0;
}