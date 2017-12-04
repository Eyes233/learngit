#pragma once
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
#define SET_INIT_SIZE 100
#define SETINCREMENT 10
#define ElemType int
typedef struct {
	ElemType * elem;
	int length;
	int setsize;
}Set;			//集合定义

void InitSet(Set &s)  //初始化  创建一个空集合
{
	s.elem = (ElemType *)malloc(SET_INIT_SIZE * sizeof(ElemType));
	if (!s.elem)
		exit(0);
	s.length = 0;
	s.setsize = SET_INIT_SIZE;
}

int ifexist(Set &s, ElemType e) //判断一个元素是否在集合中存在并返回位置  （下标+1）   不准确 应该为 find
{
	for (int i = 0; i <s.length; i++)
	{
		if (e == s.elem[i])
			return i + 1;  // 返回下标加一
	}
	return 0;
}



void AddSet(Set &s, ElemType e)  //向集合中增加一个元素单纯增加
{								//和 某些条件下的增加 判断的性能浪费 （简洁与性能的取舍）
	if (ifexist(s, e))
		cout<<e<<"已存在"<<endl;

	else
	{
		if (s.length >= s.setsize)
		{
			ElemType *newbase = (ElemType *)realloc(s.elem, (s.setsize + SETINCREMENT) * sizeof(ElemType));
			s.elem = newbase;
			s.setsize = s.setsize + SETINCREMENT;
		}
		s.elem[s.length] = e;
		s.length++;
	}
}
void DeleSet(Set &s, ElemType e)  //删除集合中某一元素
{
	int position = ifexist(s, e);
	if (position)
	{
		for (int i = position - 1; i <s.length; i++)
		{
			s.elem[i] = s.elem[i + 1];
		}
		s.length--;
	}
}


void PrintSet(Set &s)   //打印集合元素
{
	for (int i = 0; i < s.length; i++)
		cout << s.elem[i] << "  ";
	cout << endl<<endl;
}

Set Union(Set a, Set b)//并
{
	Set c;
	InitSet(c);
	for (int i = 0; i < a.length; i++)
		AddSet(c, a.elem[i]);
	for (int i = 0; i < b.length; i++)
	{
		if (ifexist(c, b.elem[i]));
		else
			AddSet(c, b.elem[i]);  //有性能浪费  没有关系吧  （将b加到c 是在b中元素在c中不存在的前提下   但是AddSet函数中 还是要判断一遍）
	}
	return c;
}
Set Intersection(Set a, Set b)//交
{
	Set c;
	InitSet(c);
	for (int i = 0; i < a.length; i++)
	{
		if (ifexist(b, a.elem[i]))
			AddSet(c, a.elem[i]);  //都存在性能问题   c本身就是空的   判断也是浪费
	}
	return c;
}
Set DiffSet(Set a, Set b)//差 a-b
{
	Set c;
	InitSet(c);
	for (int i = 0; i < a.length; i++)
		AddSet(c, a.elem[i]);
	for (int i = 0; i < Intersection(a, b).length; i++)   //调函数 还是两次 效率 我怀疑会很低  这些先不考虑  实现在说？  还是养成良好的习惯
	{
		DeleSet(c, Intersection(a, b).elem[i]);
	}
	return c;
}

//其实问题是可以解决的  是我太想投机取巧了     为了代码简单，其实也没简单多少，但是真的性能浪费太多了
//既然完全没有必要   就不用调用单纯的插入
