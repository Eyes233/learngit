#include "Set.h"

int main()
{
	Set a, b;
	InitSet(a); InitSet(b);
	//���Ծ����������  �ȼ���һ��
	for (int i = 0; i < 19; i++)
		AddSet(a, i);  //�ǲ���Ҫд�����ĳ�ʼ������  ʡȥ�жϵ������˷�  ����ͬ���Ĵ���֪ʶ���ж�ɾȥ
	for (int i = 5; i < 20; i++)
		AddSet(b, i);
	cout << "��һ�������е�Ԫ�ذ���" << endl;
	PrintSet(a);
	cout << "�ڶ��������е�Ԫ�ذ���" << endl;
	PrintSet(b);
	cout << "���������ϵĲ����ǣ�" << endl;
	PrintSet(Union(a, b));
	cout << "���������ϵĽ����ǣ�" << endl;
	PrintSet(Intersection(a,b));
	cout << "���������ϵĲ�ǣ�" << endl;
	PrintSet(DiffSet(a,b));    //�������ܲ����
	return 0;
}