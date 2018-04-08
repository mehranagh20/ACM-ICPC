#include<stdio.h>
#include<string.h>
unsigned int inB[9];
char *str[6];
int numOfMovements(int, int, int);
int main()
{
	unsigned int cmp[6];
	while (true)
	{
		str[0] = "BGC";
		str[1] = "BCG";
		str[2] = "GBC";
		str[3] = "CBG";
		str[4] = "GCB";
		str[5] = "CGB";
		for (int i = 0; i < 9; i++)
		{
			if (scanf("%u", &inB[i]) == EOF)
				return 0;
		}
		cmp[0] = numOfMovements(1, 4, 7);
		cmp[1] = numOfMovements(1, 7, 4);
		cmp[2] = numOfMovements(4 ,1, 7);
		cmp[3] = numOfMovements(4, 7, 1);
		cmp[4] = numOfMovements(7, 1, 4);
		cmp[5] = numOfMovements(7, 4, 1);
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 5; j++)
			{
				if (cmp[j] > cmp[j + 1])
				{
					char *charTmp = str[j];
					str[j] = str[j + 1];
					str[j + 1] = charTmp;
					int tmp = cmp[j];
					cmp[j] = cmp[j + 1];
					cmp[j + 1] = tmp;
				}
				else if (cmp[j] == cmp[j + 1] && strcmp(str[j], str[j+1])>0)
				{
					char *charTmp = str[j];
					str[j] = str[j + 1];
					str[j + 1] = charTmp;
					int tmp = cmp[j];
					cmp[j] = cmp[j + 1];
					cmp[j + 1] = tmp;
				}
			}
		printf("%s %u\n", str[0], cmp[0]);
	}
	return 0;
}
int numOfMovements(int a, int b,int c)//brown,green,clear
{
	int temp = 0;
	temp += inB[a] + inB[a+1] + inB[b-1] + inB[b+1] + inB[c-1] + inB[c];
	return temp;
}