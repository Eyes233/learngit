

//#define 
//有关 参数传递  还有const的使用


struct Stack {
	ElemType * base;
	ElemType * top;
	int stacksize;
};                   //栈定义

struct MazeType {
	int maze[5][5];  //也不一定是10  规模是否可控？//手动输入规模
};

struct PosType {
	int x;
	int y;
};					//坐标

struct Elem {
	PosType seat;
	int di;
};

struct Route {
	PosType way[1000];
	int length = 0;
};




void InitStack(Stack &S)  //栈初始化
{
	S.base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
}

bool IsEmpty(Stack &S)  //判空
{
	if (S.top = S.base)
		return 1;
	else
		return 0;
}

void Pop(Stack &S, ElemType &e) // 出栈
{
	if (IsEmpty(S))
		printf("The Stack is Empty\n");
	else
		e = *--S.top;
}

void Push(Stack &S, ElemType e)  // 入栈
{
	if (S.top - S.base >= S.stacksize)

	{
		S.base = (ElemType *)realloc(S.base,
			(STACK_INIT_SIZE + STAKINCREMENT) * sizeof(ElemType));
		S.top = S.base + S.stacksize; //为什么 top指针位置在重新分配
		S.stacksize += STAKINCREMENT;							//之后会改变
	}
	*S.top++ = e;  //一步作两步   指针++ 右移 

}



void GetTop(Stack &S, ElemType &e)  //获得栈顶元素
{
	if (IsEmpty(S))
		printf("The Stack is Empty\n");
	else
		e = *(S.top - 1);
}








bool Pass(PosType &p, MazeType &m, Route &r)//PASS	判断能否通过
{
	if (!IfWall(p, m) && !Ifgone(p, r)) //墙 是否走过 是否不通
		return 0;
	else
		return 1;
}


bool IfWall(PosType &p, MazeType &m)
{

	if (m.maze[p.x][p.y] == 1)
		return 1;
	else
		return 0;
}

void FootPrint(PosType p, Route &r) //留下足迹
{
	r.way[r.length + 1] = p;
}

bool Ifgone(PosType p, Route &r)
{
	for (int i = 0; i <r.length; i++)
	{
		if (p.x == r.way[i].x&&p.y == r.way[i].y)
			return 1;
		else
			return 0;
	}
}
//void MarkPrint()   和 足迹操作一模一样完全 不需要

void Next(PosType &p, int d)
{
	switch (d)
	{
	case 1:p.x++; break;
	case 2:p.y++; break;
	case 3:p.x--; break;
	case 4:p.y--; break;
	}

}
//最后能不能 把结果



int MazePath(MazeType &m, PosType start, PosType end)
{
	Stack S;
	InitStack(S);
	Route r;
	PosType curpos;//正要走的坐标
	Elem e; //栈顶元素 
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
				while (!!IsEmpty(S))
				{
					Push(S, e);
					printf("->(%d,%d) ", e.seat.x, e.seat.y);
				}//到达终点 把路径打印出来
				return 1;
			}
			else
			{
				Next(curpos, 1);
			}
		}
		else
		{
			if (!IsEmpty(S))
			{
				Pop(S, e);
				/*while (e.di==4&&!!IsEmpty(S)) //快速后退？
				{

				}*/ //先不写试试还是有点不一样的
				if (e.di == 4 && !IsEmpty(S))
					Pop(S, e);
				if (e.di < 4)
				{
					e.di++;
					Push(S, e);
					Next(e.seat, e.di);
				}
			}


		}

	} while (!IsEmpty(S));
	printf("无解");
	return 0;//没有找到路径
}