#pragma once
#include<stdio.h>
#include<stdlib.h>


#define STACK_INIT_SIZE 100
#define STAKINCREMENT 10
#define ElemType Elem
struct Stack;
struct PosType;
struct Elem;
struct MazeType;

struct Route;

void InitStack(Stack &S);
bool IsEmpty(Stack &S);
void Pop(Stack &S, ElemType &e);
void Push(Stack &S, ElemType &e);
bool IfWall(PosType &p, MazeType &m);
void FootPrint(PosType &p, Route &r);
bool Ifgone(PosType &p, Route &r);
PosType Next(PosType &p, int d);
bool Pass(PosType &p, MazeType &m, Route &r);
int MazePath(MazeType &m, PosType &start, PosType &end);


//#define 
//�й� ��������  ����const��ʹ��


struct Stack {
	ElemType * base;
	ElemType * top;
	int stacksize;
};              
//ջ����
struct PosType {
	int x;
	int y;
};

struct Elem {
	PosType seat;
	int di;
};

struct MazeType {
	int maze[5][5];  //Ҳ��һ����10  ��ģ�Ƿ�ɿأ�//�ֶ������ģ
};

			//����


struct Route {
	PosType way[1000];
	int length = 0;
};




void InitStack(Stack &S)  //ջ��ʼ��
{
	S.base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}

bool IsEmpty(Stack &S)  //�п�
{
	if (S.top == S.base)
		return 1;
	else
		return 0;
}

void Pop(Stack &S, ElemType &e) // ��ջ
{
	if (IsEmpty(S))
		printf("The Stack is Empty\n");
	else
		e = *--S.top;
}

void Push(Stack &S, ElemType &e)  // ��ջ
{
	if (S.top - S.base >= S.stacksize)

	{
		S.base = (ElemType *)realloc(S.base,
			(STACK_INIT_SIZE + STAKINCREMENT) * sizeof(ElemType));
		S.top = S.base + S.stacksize; //Ϊʲô topָ��λ�������·���
		S.stacksize += STAKINCREMENT;							//֮���ı�
	}
	*S.top++ = e;  //һ��������   ָ��++ ���� 

}



void GetTop(Stack &S, ElemType &e)  //���ջ��Ԫ��
{
	if (IsEmpty(S))
		printf("The Stack is Empty\n");
	else
		e = *(S.top - 1);
}




void MkMaze(MazeType &m)
{
	m.maze[][]

}



bool Pass(PosType &p, MazeType &m, Route &r)//PASS	�ж��ܷ�ͨ��
{
	if (!IfWall(p, m) && !Ifgone(p, r)) //ǽ �Ƿ��߹� �Ƿ�ͨ
		return 1;
	else
		return 0;
}


bool IfWall(PosType &p, MazeType &m)
{

	if (m.maze[p.x][p.y] == 1)
		return 1;
	else
		return 0;
}

void FootPrint(PosType &p, Route &r) //�����㼣
{
	r.way[r.length ++] = p;
}

bool Ifgone(PosType &p, Route &r)
{
	for (int i = 0; i <r.length; i++)
	{
		if (p.x == r.way[i].x&&p.y == r.way[i].y)
			return 1;
		
	}
	return 0;
}
//void MarkPrint()   �� �㼣����һģһ����ȫ ����Ҫ

PosType Next(PosType &p, int  d)
{
	switch (d)
	{
	case 1:p.y++; break;
	case 2:p.x++; break;
	case 3:p.y--; break;
	case 4:p.x--; break;
	}
	return p;

}
//����ܲ��� �ѽ��



int MazePath(MazeType &m, PosType &start, PosType &end)
{
	Stack S;
	InitStack(S);
	Route r;
	PosType curpos;//��Ҫ�ߵ�����
	Elem e; //ջ��Ԫ�� 
	curpos = start;
	do
	{
		if (Pass(curpos, m, r))
		{
			FootPrint(curpos, r);
			Elem e = { curpos, 1 };
			Push(S, e);
			if (curpos.x == end.x&&curpos.y == end.y)
			{
				while (!IsEmpty(S))
				{
					Pop(S, e);
					printf("(%d,%d)-> ", e.seat.x, e.seat.y);
					
				}//�����յ� ��·����ӡ����
				return 1;

			}
			else
			{
				curpos = Next(curpos, 1);
			}
		}
		else
		{
			if (!IsEmpty(S))
			{
				Pop(S, e);
				/*while (e.di==4&&!!IsEmpty(S)) //���ٺ��ˣ�
				{

				}*/ //�Ȳ�д���Ի����е㲻һ����
				if (e.di == 4 && !IsEmpty(S))
					Pop(S, e);
				if (e.di < 4)
				{
					e.di++;
					Push(S, e);
					curpos = Next(e.seat, e.di);
				}
			}


		}

	} while (!IsEmpty(S));
	printf("�޽�");
	return 0;
//û���ҵ�·��
}