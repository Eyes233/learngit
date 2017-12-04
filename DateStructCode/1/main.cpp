#include "Set.h"

int main()
{
	Set a, b;
	InitSet(a); InitSet(b);
	//测试就用随机数了  先简单试一下
	for (int i = 0; i < 19; i++)
		AddSet(a, i);  //是不是要写单纯的初始化函数  省去判断的性能浪费  但是同样的代码知识把判断删去
	for (int i = 5; i < 20; i++)
		AddSet(b, i);
	cout << "第一个集合中的元素包括" << endl;
	PrintSet(a);
	cout << "第二个集合中的元素包括" << endl;
	PrintSet(b);
	cout << "这两个集合的并集是：" << endl;
	PrintSet(Union(a, b));
	cout << "这两个集合的交集是：" << endl;
	PrintSet(Intersection(a,b));
	cout << "这两个集合的差集是：" << endl;
	PrintSet(DiffSet(a,b));    //基本功能差不多了
	return 0;
}