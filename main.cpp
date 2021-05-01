/********************************************************************************************************************************
文件名： main.cpp
功能描述：主函数，用以测试相关功能函数与数据结构类。更多信息，可关注微信公众号地震成像与模拟，当中的专辑《算法与数据结构》的文章
          给出了关于本程序中每个测试例子的详细描述。
参考资料：萨尼.《数据结构、算法与应用C++语言描述第二版》[M].北京：机械工业出版社，2019.
版本：1.0
日期：2021/5/1
版权：2021-2025
作者：闫英伟

历史：1.2021/5/1加入了“深入理解指针与递归函数”的测试例子。

********************************************************************************************************************************/

#include <iostream>

#include "sdf.h"

using namespace std;
using namespace DSLib;

int main()
{
	// 深入理解指针部分, 若需要运行该部分内容，请将最后的有效代码注释掉
	/*
	char c = 'c';
	char* pc = &c;   // 令指针pc指向char型变量c的首地址

	cout << "c = " << c << " *pc = " << *pc << " &c = " << (void*)&c << " pc = " << (void*)pc << endl;
	cout << "&c==pc " << ((void*)& c == (void*)pc) << endl;
	cout << "c = " << c << " *(&c) = " << *(&c) << " pc = " << (void*)pc << " *(&pc) = " << (void*)(*(&pc)) << endl;
	

	cout << "sizeof(char) = " << sizeof(char) <<" sizeof(c)="<<sizeof(c)<<endl;
	cout << "sizeof(char*) = " << sizeof(char*) << " sizeof(pc) = " << sizeof(pc) << endl;

	cout << endl;

	double d = 123.02;
	double* pd = NULL;  

	cout << "pd = " << pd << " &pd = " << &pd << endl;

	pd = &d; // 令指针指向double型变量的首地址

	// 指针所占内存的字节数依赖于编译平台，等于编译平台的一个机器字长度，若机器字长32位则只占4字节
	cout << "sizeof(double*) = " << sizeof(double*) << " sizeof(pd) = " << sizeof(pd) << endl;  
	cout << "d = " << d << endl;

	// *号起到解引用作用，像是一把钥匙，能够得到指针指向的变量；指针变量pd存储着变量d的地址，*pd则得到变量d
	*pd = 5.0 ;   // 代码中不使用变量d，而改变d的值
	cout << "d = " << d << endl;
	cout << endl;

	int num[5] = { 1,2,3,4,5 };  // 请记住数组存储在一块地址连续的内存中
	int* pi = num;   // 数组名num代表数组首地址，与&(num[0])等价

	// 验证数组的地址是连续的
	for (int i = 0; i < 5; i++)
	{
		cout <<"&num[i] = "<<&num[i] << endl;
	}

	// 代码中不使用数组num而打印出数组
	for (int i = 0; i < 5; i++)
	{
		cout << *(pi + i) << endl;  // pi指向数组的首地址，(pi+i)指向pi+i*sizeof(int)处的地址
	}
	*/

	// 深入理解递归函数
	char* s = new char[3];
	cout << "字符数组s为：";
	for (int i = 0; i < 3; i++)
	{
		s[i] = 'a' + i;   // 字符数组s成为｛'a','b','c'}
		cout << s[i];
	}
	cout << endl;
	cout << "输出字符数组的全排列：" << endl;
	permutations(s, 0, 2);   // 输出字符数组s的全排列

	cout << "使用递归求解Ackermann函数：" << endl;
	int result = Ackermann(2, 2); cout << result << endl;

	cout << "使用递归求解两个非负整数的最大公约数：" << endl;
	result = gcd(10, 15); cout << result << endl;

	cout << "使用递归求解元素x是否属于字符数组s：" << endl;
	cout << xBelongA(s, 'b', 3) << endl;

	cout << "输出字符数组s的所有子集：" << endl;
	int mark[3] = {0, 0, 0};
	print_subset(s, mark, 0, 3);
	delete[]s;  // 通过关键字new分配的空间，不使用时一定要delete

	cout << "输出格雷码位置变化序列:" << endl;
	list<int> r; 
	list<int>::iterator i;
	calcGrayCode(r, 3);
	
	for (i=r.begin();i!=r.end();i++)
	{
		if (i == r.begin())
		{
			cout << *i;
		}
		else
		{
			cout << " " << *i;
		}
	}
	return 0;
}