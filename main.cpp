#include <stdio.h>
#include "Hashtable.h"

char splash();

void hastable_add();
void hastable_remove();
void hastable_check();

typedef enum
{
	MenuOption_INVALID = '\0',
	MenuOption_EXIT = 'q',
	MenuOption_ADD = '1',
	MenuOption_REMOVE = '2',
	MenuOption_CHECK = '3'
}MenuOption;

Hashtable ht;

int main()
{
	char option = ' ';
	while(option != MenuOption_EXIT)
	{
		option = splash();

		switch (option)
		{
			case MenuOption_ADD:
			{
				hastable_add();
				break;
			}
			case MenuOption_REMOVE:
			{
				hastable_remove();
				break;
			}
			case MenuOption_CHECK:
			{
				hastable_check();
				break;
			}
			case MenuOption_EXIT:
			{
				break;
			}
			default:
			{
				printf("Unknown Option: %x\n", option);
			}
		}
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	}
}

char splash()
{
	printf("-----------------------------------------\n");
	printf("-----------Steven's Hashtable------------\n");
	printf("-----------------------------------------\n");
	printf("------------------Stats------------------\n");
	printf("       %d Occupied Buckets               \n", ht.countOccupiedBuckets());
	printf("       %d Number of Elements             \n", ht.countElements());
	printf("------------------Options----------------\n");
	printf("       1 - Add Entry                     \n");
	printf("       2 - Remove Entry                  \n");
	printf("       3 - Check table for entry         \n");
	printf("       q - Exit                          \n");
	printf("                                         \n");
	printf("Option: ");

	char val = getchar();
	while(getchar() != '\n')
		;

	return val;
}

void hastable_add()
{
	char name[100];
	printf("Enter name to add: ");
	scanf("%s", name);
	while(getchar() != '\n')
		;

	ht.add(name);
}

void hastable_remove()
{
	char name[100];
	printf("Enter name to remove: ");
	scanf("%s", name);
	while(getchar() != '\n')
		;

	bool success = ht.remove(name);
	if(success)
	{
		printf("Sucessfully removed %s\n", name);
	}
	else
	{
		printf("Unable to find %s\n", name);
	}
}

void hastable_check()
{
	char name[100];
	printf("Enter name to check if exists: ");
	scanf("%s", name);
	while(getchar() != '\n')
		;

	bool contains = ht.contains(name);
	printf("\t%s %s Exist\n", name, contains ? "Does" : "Does Not");
	while(getchar() != '\n')
		;
}

