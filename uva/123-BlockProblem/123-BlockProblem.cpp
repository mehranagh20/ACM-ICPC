#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
typedef struct st
{
	bool isOnTop;
	char *stack;
	st *next;
	st *before;
}stBlock;
short int nBlocks;
stBlock ** blocks;
void makeApart(int a)
{
	stBlock* tmp = blocks[a]->next;
	while (tmp != NULL)
	{
		tmp->before = NULL;
		tmp->isOnTop = false;
		if (tmp->next != NULL)
		{
			tmp = tmp->next;
			tmp->before->next = NULL;
		}
		else
			break;
	}
}
int isMovable(char *a, char *b)
{
	int bToMv = strtod(a, NULL); int moveToB = strtod(b, NULL);
	stBlock* tmp = blocks[bToMv]->next;
	while (tmp != NULL)
	{
		if (strcmp(b, tmp->stack) == 0)
			return 0;
		tmp = tmp->next;
	}
	tmp = blocks[bToMv]->before;
	while (tmp != NULL)
	{
		if (strcmp(b, tmp->stack) == 0)
			return 0;
		tmp = tmp->before;
	}
	return 1;
}
void mvOnto(char *a, char * b)
{
	int bToMv = strtod(a, NULL); int moveToB = strtod(b, NULL);
	if (blocks[bToMv]->isOnTop == true)
		blocks[bToMv]->before->next = NULL;
	makeApart(bToMv);
	makeApart(moveToB);
	blocks[bToMv]->next = NULL;
	blocks[bToMv]->isOnTop = true;
	blocks[moveToB]->next = blocks[bToMv];
	blocks[bToMv]->before = blocks[moveToB];
}
void mvOver(char *a, char * b)
{
	int bToMv = strtod(a, NULL); int moveToB = strtod(b, NULL);
	if (blocks[bToMv]->isOnTop == true)
		blocks[bToMv]->before->next = NULL;
	makeApart(bToMv);
	blocks[bToMv]->next = NULL;
	blocks[bToMv]->isOnTop = true;
	stBlock *temp = blocks[moveToB];
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = blocks[bToMv];
	blocks[bToMv]->before = temp;
}
void pOnto(char *a, char * b)
{
	int bToMv = strtod(a, NULL); int moveToB = strtod(b, NULL);
	if (blocks[bToMv]->isOnTop == true)
		blocks[bToMv]->before->next = NULL;
	blocks[bToMv]->isOnTop = true;
	makeApart(moveToB);
	blocks[moveToB]->next = blocks[bToMv];
	blocks[bToMv]->before = blocks[moveToB];
}
void pOver(char *a, char * b)
{
	int bToMv = strtod(a, NULL); int moveToB = strtod(b, NULL);
	if (blocks[bToMv]->isOnTop == true)
		blocks[bToMv]->before->next = NULL;
	blocks[bToMv]->isOnTop = true;
	stBlock *temp = blocks[moveToB];
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = blocks[bToMv];
	blocks[bToMv]->before = temp;
}
int main()
{
	char *fT, *a, *sT, *b;
	using namespace std;
	char command[30];
	scanf("%hd", &nBlocks);
	while (getchar() != '\n');
	blocks = (stBlock **)malloc(sizeof(stBlock*)*nBlocks);
	for (int i = 0; i < nBlocks; i++)
	{
		blocks[i] = (stBlock*)malloc(sizeof(stBlock));
		blocks[i]->stack = (char *)malloc(sizeof(char) * 3);
		sprintf(blocks[i]->stack, "%hd", i);
		blocks[i]->stack[2] = '\0';
		blocks[i]->isOnTop = false;
		blocks[i]->next = NULL; blocks[i]->before = NULL;
	}
	while (true)
	{
		cin.getline(command, 29);
		if (strcmp(command, "quit") == 0)
		{
			break;
		}
		fT = strtok(command, " ");
		a = strtok(NULL, " ");
		sT = strtok(NULL, " ");
		b = strtok(NULL, " ");
		if (isMovable(a, b) == 0)
			continue;
		if (strcmp(a, b) == 0)
			continue;
		if (strcmp(fT, "move")==0)
		{
			if (strcmp(sT, "over") == 0)
				mvOver(a, b);
			else
				mvOnto(a, b);
		}
		else
		{
			if (strcmp(sT, "over")==0)
				pOver(a, b);
			else
				pOnto(a, b);
		}
	}
	for (int i = 0; i < nBlocks; i++)
	{
		printf("%d:", i);
		stBlock *temp = blocks[i];
		if (temp->isOnTop == false)
		{
			while (temp != NULL)
			{
				printf(" %s", temp->stack);
				temp = temp->next;
			}
		}
		puts("");
	}
	return 0;
}