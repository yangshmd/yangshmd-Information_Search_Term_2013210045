#include "term.h"
#include "BinaryTree3.h"
#include "BinarySearchTree3.h"
#include "AVLRebalance.h"

void Parsing(FILE* fp_read, FILE* fp_write)
{
	char temp_line[SIZE];
	int check = FALSE;

	while (fgets(temp_line, sizeof(temp_line), fp_read) != NULL)
	{
		strlwr(temp_line);

		if (strncmp(temp_line, "<docno>", strlen("<docno>")) == 0)
		{
			strupr(temp_line);
			fputs("[DOCNO] : ", fp_write);
			fputs(temp_line, fp_write);
		}

		if (strncmp(temp_line, "<headline>", strlen("<headline>")) == 0)
		{
			temp_line[strlen(temp_line) - 1] = ' ';
			fputs("[HEADLINE] : ", fp_write);
			check = TRUE;
		}
		if (strncmp(temp_line, "</headline>", strlen("</headline>")) == 0)
		{
			check = FALSE;
		}

		if (strncmp(temp_line, "<text>", strlen("<text>")) == 0)
		{
			temp_line[strlen(temp_line) - 1] = ' ';
			fputs("[TEXT] : ", fp_write);
			check = TRUE;
		}
		if (strncmp(temp_line, "</text>", strlen("</text>")) == 0)
		{
			check = FALSE;
		}
		
		if (check == TRUE)
		{
			fputs(temp_line, fp_write);
		}
	}
}

void Remove_Stopword(FILE* fp_read, FILE* fp_write, FILE* fp_stopword)
{
	char tempArray[SIZE];
	char* ptr;
	BTreeNode* rootNode;

	BSTMakeAndInit(&rootNode);

	// stopword를 AVL Tree에 저장.
	while (fgets(tempArray, sizeof(tempArray), fp_stopword) != NULL)
	{
		BSTInsert(&rootNode, tempArray);
	}
	
	//BSTShowAll(rootNode);

	 //불용어 검색 후 제거하면서 바로바로 다시 저장.
	while (fgets(tempArray, sizeof(tempArray), fp_read) != NULL)
	{
		tempArray[strlen(tempArray) - 1] = '\0';

		ptr = strtok(tempArray, " ``,._-''?!()$");
		while (ptr != NULL)
		{
			if (BSTSearch(rootNode, ptr) == NULL)	// BST 결과가 NULL 이라는 것은 불용어 아니라는 얘기
			{
				fputs(ptr, fp_write);
				fputs(" ", fp_write);
			}
			ptr = strtok(NULL, " ``,._-''?!()$");
		}

		fputs("\n", fp_write);
	}
}