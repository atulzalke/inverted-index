/***************************************************************************************************************************************************
*Author         :Atul Zalke
*Date           :Sat 17 Oct 2018
*File           :create_database.c
*Title          :To create the database
*Description    :The list of the files can be provided by storing all the file names in another file, FileList the names of the files which 
		:are to be documented are provided by this file. When a file is added or removed, FileList is changed accordingly.
		:So read the file names and start indexing.
****************************************************************************************************************************************************/
#include "inverted_search.h"

int create_database(hash_table *head, char const *word, char const *file_name)
{

/**************** index value *****************/	
	int index;
	if (*word >= 'a' && *word <= 'z')
		index = *word % 97;
	else
		index = *word % 65;


/**************** Ignore words ********************/
	char *ignore_word[] = {"the", "is", "are"};
	for (int i = 0; i < 3; i++)
	{
		if (strcasecmp(ignore_word[i], word) == 0)
			return SUCCESS;
	}


/*************** New File Table **************/
	Slist_file_table *new = malloc(sizeof(Slist_file_table));
	if (new == NULL)
	{
		perror("new");
		return FAILURE;
	}
	
	new->file_name = malloc(20);
	stpcpy(new->file_name, file_name);
	new->word_count = 1;
	new->tab_link =  NULL;


/*************** New node *******************/
	Slist *n_node = malloc(sizeof(Slist));
	if (n_node == NULL)
	{
		perror("n_node");
		return FAILURE;
	}

	n_node->word = malloc(20);
	stpcpy(n_node->word, word);
	n_node->file_count = 1;
	n_node->link = NULL;
	n_node->file_table = new;


/***************** Check Repeted words in the file ***************/
	Slist *check;
	for (int i = 0; i < 26; i++)
	{
		for (check = head->index[i]; check != NULL; check = check->link)
		{
			if (strcasecmp(check->file_table->file_name, file_name) == 0)
			{
				if (strcasecmp(check->word, word) == 0)
				{
					check->file_table->word_count++;
					return SUCCESS;
				}
			}
		}
	}


/******************** linke to hash table ***********/
	Slist *temp = head->index[index];
	if (temp == NULL)
	{
		head->index[index] = n_node;
		return SUCCESS;
	}
	else
	{
		/*********** if first time found ************/
		if (n_node->file_count == 1)
		{
			if (strcasecmp(temp->word, word) == 0)
			{	
				temp->file_count++;
				n_node->file_count++;
			}
		}
		/*********** if more than two time ********/
		while (temp->link)
		{
			//printf ("temp->word: %s\t word: %s\t", temp->word, word);
			//printf ("temp->link->word: %s\n", temp->link->word);
			if (strcasecmp(temp->word, word)==0)
			{
				temp->link->file_count++;
				n_node->file_count++;
			}
			temp = temp->link;
		}
		temp->link = n_node;
		
		return SUCCESS;
	}
	
/************* if nothing will happen ****************/
	return FAILURE;

}

/************** check existing file ******************/
int file_check(hash_table *head, char const *file_name)
{
	Slist *file_check;

	for(int i = 0; i < 26; i++)
	{
		for (file_check = head->index[i]; file_check != NULL; file_check = file_check->link)
		{
			if (strcmp(file_check->file_table->file_name, file_name) == 0)
			{
				printf("\n\tFile is already exist\n\n");
				return SUCCESS;
			}
		}
	}
	return FAILURE;
}
