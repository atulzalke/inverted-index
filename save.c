/***************************************************************************************************************************************************
*Author         :Atul Zalke
*Date           :Sat 17 Oct 2018
*File           :save.c
*Title          :To display  the results.
*Description    :When all the words are searched the ouput list is formed. In this the file with max count
		:(representing maximum word match ) can be selected and displayed. For advanced searched,
		:(weightage of words stored in database linkedlist) can also be used. So the results will be more
		:accurate.
****************************************************************************************************************************************************/
#include "inverted_search.h"

int save_db(hash_table *head, FILE *fd)
{
	fd = fopen("database.txt", "w");
	if (fd == NULL)
	{
		perror("fopen: fd");
	}

	Slist *temp;
	if (temp == NULL)
	{
		return EMPTY;
	}
	for (int i = 0; i < 26; i++)
	{
		if (head->index[i] == NULL)
			continue;
		fprintf(fd,"#%d  ", i);
		for (temp = head->index[i]; temp != NULL; temp = temp->link)
		{
			fprintf(fd, "[%s]", temp->word);
			fprintf(fd, " %d time/s in ", temp->file_table->word_count);
			fprintf(fd, " File: [%s]     ", temp->file_table->file_name);
			fprintf(fd, "%d file/s\t", temp->file_count);
		}
		fprintf(fd, "\n");
	}
	fprintf(fd, "\n");
	return SUCCESS;
}
