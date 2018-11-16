/***************************************************************************************************************************************************
*Author         :Atul Zalke
*Date           :Sat 17 Oct 2018
*File           :search.c
*Title          :To search the words.
*Description    :Each word is now used to search in the linkedlist. The word has to be compared with
		:each word in the linked list. When found, the file details can be retrieved. Since the
		:linkedlist is in sorted order, the complexity of searching the word in the complete list
		:can be avoided. While string comparison, if the word in linkedlist is greater than the
		:word to be search, it shows the word doesnt exists in the list,
****************************************************************************************************************************************************/
#include "inverted_search.h"

int search(hash_table *head, char const *word)
{
	Slist *temp;
	int buff = 0, condition = 0;
	for (int i = 0; i < 26; i++)
	{
		for (temp = head->index[i]; temp != NULL; temp = temp->link)
		{
			if (strcasecmp(temp->word, word) == 0)
			{
				if (buff == 0)
				{
					printf("\nWord is in %d file/s\n\n", temp->file_count);
					buff++;
					condition++;
				}
				printf("  [%s]  ", temp->word);
				printf("%d  ", temp->file_table->word_count);
				printf("%s\n", temp->file_table->file_name);
			}
		}
	}
	putchar('\n');
	if (condition != 0)
		return SUCCESS;
	else
		return FAILURE;
}
