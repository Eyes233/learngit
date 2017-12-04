#pragma once
#include<stdlib.h>
struct QueueNode {
	int n;//车号
	QueueNode * next;
};
struct Queue {
	QueueNode * front;
	QueueNode * rear;
};

void InitQueue(Queue &Q)
{
	Q.front=(QueueNode*)malloc(sizeof(QueueNode));
	Q.rear = Q.front;
}

void EnQueue(Queue &Q, QueueNode e) //入队
{
	QueueNode *p = (QueueNode*)malloc(sizeof(QueueNode));
	p->n = e.n;  p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;


}

void DeQueue(Queue &Q, int &n)// 出队返回 车牌号
{
	QueueNode *p = Q.front->next;
	Q.front->next = p->next;
	n = p->n;
	free(p);
}

bool QueueEmpty(Queue &Q)
{
	if (Q.front == Q.rear)
		return 1;
	else return 0;
}