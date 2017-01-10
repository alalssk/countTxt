// counttxt.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX 5050
int main(){
	char buf[MAX], tmp[MAX];
	int len = 0;
	int i = 0;
	int tcount = 0, scount = 0;
	FILE *fp = fopen("b.txt", "rt"); //나눌 파일열기포인터
	if ((fp = fopen("b.txt", "r")) == NULL)
	{
		perror("b.txt :");
		exit(1);
	}


	while (1)
	{
		fgets(buf, MAX, fp);
		len = strlen(buf);
		if (len == 0) break;


		for (i = 0; i<len; i++)//
		{
			if (buf[i] >= 32 && buf[i] <= 126)//
			{

				tcount++;
			}
			else scount++;

		}
		buf[0] = '\0';//널문자 파일의 끝을 알림

	}

	fclose(fp);


	tcount += scount / 2;
	printf("%d\n", tcount);

	return 0;
}

