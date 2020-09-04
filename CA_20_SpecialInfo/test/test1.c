/**
* test1.c
* @author bulbasaur
* @description 
* @created 2020-07-29T18:58:54.477Z+08:00
* @copyright None 
* None
* @last-modified 2020-07-29T18:58:58.380Z+08:00
*/

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
//杨辉三角的长度
#define Length 9
 
//返回需要打印的字符串
//s为数组
//index为当前的行数
char* getPrintLine(int nums[],int index,char *s)
{
	int i=0;
	int strs=0;
	index += 1;//具体的行数
	//填补指定的头部空格数
	for ( i = 0; i < Length - index; i++)
	{
		s[i] = ' ';
		strs++;
	}
	//加上自身+空格
	for (i = 0; i < index; i++)
	{
		if(i==0)
		{
			s[strs] = nums[i];
			strs++;
		}
		else
		{
			s[strs] =  ' ';
			strs++;
			s[strs] =  nums[i];
			strs++;
		}
	}
	s[strs]='\0';
	return s;
}
 
//输出杨辉三角
void main(void)
{
	//斜边都是由1组成的，其余的数都是它肩上的两数之和
	int s[Length][Length]={0},i,j;
	char str[100];
	//遍历每行
	for (i = 0; i < Length; i++)
	{
		//确定每行
		for (j = 0; j <= i; j++)
		{
			if(j==0 || i==j)
			{
				s[i][j] = 1; 
			}
			else
			{
				s[i][j]=s[i-1][j-1] + s[i-1][j];
			}
		}
	}
	//输出杨辉三角
	for ( i = 0; i < Length; i++)
	{
		char *a = getPrintLine(s[i],i,str);
		while (*a!='\0')
		{
			if(*a==' ')
			{
				printf(" ");
			}
			else
			{
				printf("%d",*a);
			}
			*a++;
		}
		printf("\r\n");
	}
	system("pause");
}