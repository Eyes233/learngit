//˳��ṹ����һ�������� 
//����̫���� ���Բ��ö�̬�����ڴ�


#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"maze.h"
using namespace std;






//�Ȱ�������   �����˵Ĵ���ʵ���ǡ�������


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

