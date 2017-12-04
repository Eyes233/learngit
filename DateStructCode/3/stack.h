#pragma once
#include<stdlib.h>
struct ParkingNode {  //ջԪ�� 
	int n;   //����
	int t;	 //��ջʱ��
	int sequ; //ͣ��˳��
};
struct Stack { //˵ʵ������������ű��˵�˼·д�� ��ʵ����û������
	ParkingNode *base;
	ParkingNode *top;
	int size;
	

};   //��һ��ѧϰ���ڶ��ξ�����ϰ  ����������

void InitStack(Stack &S, int n) //��ʼ��ջ ���ݲ���ȷ����������
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