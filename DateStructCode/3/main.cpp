#include<stdio.h>
#include<string.h>
#include"queue.h"
#include"stack.h"
int main()
{
	char c=0; //状态
	int n; // 车号
	int t; //时间
	char s[100] = {"123"};
	while (c != 'E')
	{
		scanf_s("%s", &s,100);
		printf("%s \n", s);
		int length = strlen(s);
		int j = 0;
		for (int i = 0; i <length; i++)
		{
			
			switch (s[i])
			{
			case 'A':
				c = s[i];
				break;
			case 'D':
				c = s[i];
				break;
			case 'E':
				c = s[i];
				break;
			default:
				if ('0'<=s[i]&&s[i]<='9')//数字处理太麻烦了是不是要找库函数方便计算？
				{	if('0' <= s[i+1] && s[i] <= '9')
					if (j == 0)
					{
						n = s[i];
						j++;
						break;
					}
					if (j==1)
					{
						t = s[i];
						j = 0;
						break;
					}
				}
				else
					break;
				
			case ')':
				if (c=='A')
				{
					printf("%c  %d  %d\n",c,n-'0',t-'0');
					break;
				}
				if (c=='D')
				{
					printf("%c  %d  %d\n", c, n - '0', t - '0');

					break;
				}
			}
			if (c=='E')
			{
				break;
			}
		}
	}
	

}