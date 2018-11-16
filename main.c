/***************************************************************************************************************************************************
*Author		:Atul Zalke
*Date		:Sat 17 Oct 2018
*File		:main.c
*Title		:Driver function
*Description	:This function acts like the driver function for the project inverted search
****************************************************************************************************************************************************/
#include "inverted_search.h"


int main()
{
	system("clear");
	FILE *fp, *fs;
	int opt, ch;// fi_count = 0;
	char file_name[20];
	char word[20] = {'\0'};
	char search_word[20];
	static int count;
	hash_table head;
	for (int i = 0; i < 26; i++)
	{
		head.index[i] = NULL;
	}

	while (1)
	{
		int flag = 0, i = 0, tab = 0;

		printf("1. Create Database\n");
		printf("2. Display Database\n");
		printf("3. Search\n");
		printf("4. Save Database\n");
		printf("5. Delet database\n");
		printf("6. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &opt);
		__fpurge(stdin);
		switch (opt)
		{
			case 1:
				system("clear");
				printf("\n\tEnetr file name: ");
				scanf("%s", file_name);
				fp = fopen(file_name, "r");
				if (fp == NULL)
				{
					perror("File Open");
					printf("\n\n\ttry Again......!\n\n");
					break;
				}
				if (file_check(&head, file_name) == SUCCESS)
				{
					break;	
				}
				while ((ch = fgetc(fp)) != EOF)
				{
					if (ch == ' ' || ch == '\n' || ch == '\0' || ch == '\t')
					{
						flag = 0;
					}
					else
					{
						flag = 1;
					}
					if (flag == 1)
					{
						*(word + i) = (char)ch;
						i++;
					}
					else
					{
						tab = 1;
						i = 0;
					}
					if (tab == 1)
					{
						if (create_database(&head, word, file_name) != SUCCESS)
						{
							perror("create_database");
						}
						tab = 0;
						memset(word, '\0', 20);
					}
				}
				printf("\n\tDatabase Created\n\n");
				break;

			case 2:
					if(display_output(&head) == EMPTY)
					{
						printf("\n\tList is Empty\n\n");	
					}
				break;
			case 3:
				printf("Enetr word: ");
				scanf("%s", search_word);
					if(search(&head, search_word) != SUCCESS)
					{
						printf("\n\tWord not found\n\n");
					}
					break;

			case 4:
					if(save_db(&head, fs) == SUCCESS)
					{
						printf("\n\tfile saved in database.txt\n\n");
						break;
					}
					else
					{
						printf("File not saved\n\n");
					}
					break;
			case 5:
					for(int i = 0; i < 26; i++)
					{
						head.index[i] = NULL;
					}
					printf("\n\t!!Database is Cleared!!\n\n");
					break;
			case 6:
				exit(1);
			default:
				printf("Try again..........\n");
		}

	}
}
