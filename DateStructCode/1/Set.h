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
}Set;			//���϶���

void InitSet(Set &s)  //��ʼ��  ����һ���ռ���
{
	s.elem = (ElemType *)malloc(SET_INIT_SIZE * sizeof(ElemType));
	if (!s.elem)
		exit(0);
	s.length = 0;
	s.setsize = SET_INIT_SIZE;
}

int ifexist(Set &s, ElemType e) //�ж�һ��Ԫ���Ƿ��ڼ����д��ڲ�����λ��  ���±�+1��   ��׼ȷ Ӧ��Ϊ find
{
	for (int i = 0; i <s.length; i++)
	{
		if (e == s.elem[i])
			return i + 1;  // �����±��һ
	}
	return 0;
}



void AddSet(Set &s, ElemType e)  //�򼯺�������һ��Ԫ�ص�������
{								//�� ĳЩ�����µ����� �жϵ������˷� ����������ܵ�ȡ�ᣩ
	if (ifexist(s, e))
		cout<<e<<"�Ѵ���"<<endl;

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
void DeleSet(Set &s, ElemType e)  //ɾ��������ĳһԪ��
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


void PrintSet(Set &s)   //��ӡ����Ԫ��
{
	for (int i = 0; i < s.length; i++)
		cout << s.elem[i] << "  ";
	cout << endl<<endl;
}

Set Union(Set a, Set b)//��
{
	Set c;
	InitSet(c);
	for (int i = 0; i < a.length; i++)
		AddSet(c, a.elem[i]);
	for (int i = 0; i < b.length; i++)
	{
		if (ifexist(c, b.elem[i]));
		else
			AddSet(c, b.elem[i]);  //�������˷�  û�й�ϵ��  ����b�ӵ�c ����b��Ԫ����c�в����ڵ�ǰ����   ����AddSet������ ����Ҫ�ж�һ�飩
	}
	return c;
}
Set Intersection(Set a, Set b)//��
{
	Set c;
	InitSet(c);
	for (int i = 0; i < a.length; i++)
	{
		if (ifexist(b, a.elem[i]))
			AddSet(c, a.elem[i]);  //��������������   c������ǿյ�   �ж�Ҳ���˷�
	}
	return c;
}
Set DiffSet(Set a, Set b)//�� a-b
{
	Set c;
	InitSet(c);
	for (int i = 0; i < a.length; i++)
		AddSet(c, a.elem[i]);
	for (int i = 0; i < Intersection(a, b).length; i++)   //������ �������� Ч�� �һ��ɻ�ܵ�  ��Щ�Ȳ�����  ʵ����˵��  �����������õ�ϰ��
	{
		DeleSet(c, Intersection(a, b).elem[i]);
	}
	return c;
}

//��ʵ�����ǿ��Խ����  ����̫��Ͷ��ȡ����     Ϊ�˴���򵥣���ʵҲû�򵥶��٣�������������˷�̫����
//��Ȼ��ȫû�б�Ҫ   �Ͳ��õ��õ����Ĳ���
