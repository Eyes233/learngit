//顺序结构而不一定是数组 
//数组太死板 所以采用动态分配内存


#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"maze.h"
using namespace std;






//先按书上来   看别人的代码实在是。。。。


int main()
{
	MazeType m;         





	for (int i = 0; i < 5; i++)
	{
		for (int j=0; j < 5; j++)
			printf("%d  ", m.maze[i][j]);
		cout << endl;
	}
	PosType start = {1,1};
	PosType end = { 3,3 };
	cout << m.maze[1][1]<<endl;
	cout << m.maze[3][3]<<endl;


	MazePath(m, start, end);
	return 0;
}

