/***************************************************************************************************************************************************
*Author         :Atul Zalke
*Date           :Sat 17 Oct 2018
*File           :display_output.c
*Title          :To display  the results.
*Description    :When all the words are searched the ouput list is formed. In this the file with max count
		:(representing maximum word match ) can be selected and displayed. For advanced searched,
		:(weightage of words stored in database linkedlist) can also be used. So the results will be more
		:accurate.
****************************************************************************************************************************************************/
#include "inverted_search.h"

int display_output(hash_table *head)
{
	int buff = 0;
	Slist *temp;
	if (temp == NULL)
	{
		return EMPTY;
	}
	for (int i = 0; i < 26; i++)
	{
		if (head->index[i] == NULL)
		{
			continue;
		}
		printf("#%d  ", i);
		for (temp = head->index[i]; temp != NULL; temp = temp->link)
		{
			printf("[%s]", temp->word);
			printf(" %d time/s in ", temp->file_table->word_count);
			printf(" File: [%s] ", temp->file_table->file_name);
			printf("%d file/s\t", temp->file_count);
		}
		buff++;
		putchar('\n');
	}
	putchar('\n');
	if (buff != 0)
		return SUCCESS;
	else
		return EMPTY;
}
