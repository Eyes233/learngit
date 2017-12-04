#pragma once
#include<stdlib.h>
struct ParkingNode {  //栈元素 
	int n;   //车号
	int t;	 //入栈时间
	int sequ; //停车顺序
};
struct Stack { //说实话，如果是照着别人的思路写的 其实还是没有掌握
	ParkingNode *base;
	ParkingNode *top;
	int size;
	

};   //第一次学习，第二次就是练习  第三次熟练

void InitStack(Stack &S, int n) //初始化栈 根据参数确定容量容量
{
	S.base = (ParkingNode*)malloc(n * sizeof(ParkingNode));
	S.top = S.base;
	S.size = n;
}

void Push(Stack &S, ParkingNode e)
{
	*S.top++ = e;
}

void Pop(Stack &S,ParkingNode &e)
{
	e = *--S.top;
}
bool StcakFull(Stack &S)
{
	if (S.top - S.base >= S.size)
		return 1;
	else return 0;
}