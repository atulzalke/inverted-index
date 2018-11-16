#ifndef MAIN_H
#define MAIN_H

#include<stdio.h>
#include<stdio_ext.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define FAILURE -1
#define EMPTY 5
#define DATA_NOT_FOUND -2
#define SUCCESS 0

#define CREATE_DATABASE 1
#define DISPLAY_DATABASE 2
#define UPDATE_DATABASE 3
#define SEARCH 4
#define SAVE_DATABASE 5

typedef char data_t;

typedef struct file_table
{
	int word_count;
	char *file_name;
	struct file_table *tab_link;
}Slist_file_table;

typedef struct node
{
	int file_count;
	struct node *link;
	char *word;
	Slist_file_table *file_table;
}Slist;

typedef struct index_t
{
	Slist *index[26];
}hash_table;

int create_database(hash_table *head, char const *word, char const *file_name);
int file_check(hash_table *head, char const *file_name);
int search(hash_table *head, char const *word);
int save_db(hash_table *head, FILE *fd);
int display_output(hash_table *head);

#endif
