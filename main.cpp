/********************************************************************************************************************************
文件名： main.cpp
功能描述：主函数，用以测试相关功能函数与数据结构类。更多信息，可关注微信公众号地震成像与模拟，当中的专辑《算法与数据结构》的文章
		  给出了关于本程序中每个测试例子的详细描述。
参考资料：萨尼.《数据结构、算法与应用C++语言描述第二版》[M].北京：机械工业出版社，2019.
版本：1.0
日期：2021/5/1
版权：2021-2025
作者：闫英伟

历史：1. 2021/5/1加入了“深入理解指针与递归函数”的测试例子；
	  2. 2021/5/9加入了“基本排序方法”文章的测试例子；
	  3. 2021/5/23加入了“认识迭代器”文章的测试例子；
	  4. 2021/6/20加入了“线性表（一）：数组描述”文章的测试例子；
	  5. 2021/7/17加入了“线性表（二）：丰富功能”文章的测试例子；
	  6. 2021/8/8加入了“线性表（三）：丰富功能”文章的测试例子；

********************************************************************************************************************************/

#include <iostream>          // C++标准输入输出流头文件

// #include "sdf.h"         // 文章01、02需要引用的自定义头文件

//#include <vector>          // 文章03需要引用的头文件

#include "arrayListNoSTL.h"

using namespace std;
using namespace DSLib;   // 所有自定义类与函数所在的命名空间

int main()
{
// 01-0： 深入理解指针部分, 若需要运行该部分内容，请将最后的有效代码块注释掉
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


//01-1： 深入理解递归函数部分，若需要运行该部分内容，请将最后的有效代码块注释掉
	/*
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
	*/

// 02： 经典排序方法的测试程序，若需要运行该部分内容，请将最后的有效代码块注释掉
	/*
	int num[5] = {1,2,0,2,3};
	int* a = new int[5];
	cout << "待排序数组为：" << endl;
	for (int i = 0; i < 5; i++)
	{
		a[i] = num[i];
		cout << a[i] << " ";
	}
	cout << endl;

	int r[5] = { 0 };
	calcRank(a, 5, r);
	rearrange(a, 5, r);
	cout << "原地重排方法的排序结果：" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	// 对数组a重新赋值
	for (int i = 0; i < 5; i++)
	{
		a[i] = num[i];
	}
	bubbleSort(a, 5);
	cout << "冒泡排序方法的排序结果：" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	// 对数组a重新赋值
	for (int i = 0; i < 5; i++)
	{
		a[i] = num[i];
	}
	selectionSort(a, 5);
	cout << "选择排序方法的排序结果：" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	// 对数组a重新赋值
	for (int i = 0; i < 5; i++)
	{
		a[i] = num[i];
	}
	insertionSort(a, 5);
	cout << "插入排序方法的排序结果：" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	delete[] a; a = NULL;
	*/

// 03: 认识迭代器，若需要运行该部分内容，请将最后的有效代码块注释掉
	/*
	int x[3] = { 3,2,1};
	cout << "使用指针遍历数组x：" << endl;
	for (int* y = x; y != x + 3; y++) // 用指针y遍历数组x
	{
		cout <<*y<< " ";
	}
	cout << endl;

	vector<int> v1(x, x + 3);  // 把地址区间[x,x+3)中存储的内容拷贝给v1
	vector<int>::iterator i;
	cout << "使用迭代器逐个访问一维向量v1的元素：" << endl;
	for (i = v1.begin(); i != v1.end(); i++)
	{
		cout<< *i<< " ";
	}
	cout << endl;


	vector<int> v2(v1.begin() + 1, v1.end());  // 把地址区间[v1.begin()+1, v1.end())拷贝给v2
	cout << "使用迭代器逐个访问一维向量v2的元素：" << endl;
	for (i = v2.begin(); i != v2.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;

	int m = 3;
	int n = 2;
	vector<vector<int>> v3(m, vector<int>(n, 0));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v3[i][j] = (i+1) * (j+1);   // 赋值
		}
	}

	vector<vector<int>>::iterator rowIter;  // 二维向量的行迭代器
	vector<int>::iterator colIter;          // 每一行的迭代器
	cout << "使用迭代器逐个访问二维向量v3的元素：" << endl;
	for (rowIter=v3.begin();rowIter!=v3.end();rowIter++)
	{
		for (colIter = (*rowIter).begin(); colIter != (*rowIter).end(); colIter++)
		{
			cout << *colIter << " ";
		}
		cout << endl;
	}
	*/

// 04 线性表（一）：数组描述，若需要运行该部分内容，请将最后的有效代码块注释掉
    /*
	linearList<double>* x = new arrayListNoSTL<double>(20);
	arrayListNoSTL<int> y(2), z;

	// 测试容量函数
	cout << "Capacity of x, y and z = "
		<< ((arrayListNoSTL<double>*) x)->capacity() << ", "
		<< y.capacity() << ", "
		<< z.capacity() << endl;


	// 测试线性表的尺寸(线性表中元素的个数）函数
	cout << "Initial size of x, y, and z = "
		<< x->size() << ", "
		<< y.size() << ", "
		<< z.size() << endl;

	// 测试empty函数
	if (x->empty()) cout << "x is empty" << endl;
	else cout << "x is not empty" << endl;
	if (y.empty()) cout << "y is empty" << endl;
	else cout << "y is not empty" << endl;

	// 测试插入函数
	y.insert(0, 2);
	y.insert(1, 6);
	y.insert(0, 1);
	y.insert(2, 4);
	y.insert(3, 5);
	y.insert(2, 3);
	cout << "Inserted 6 integers, list y should be 1 2 3 4 5 6" << endl;
	cout << "Size of y = " << y.size() << endl;
	cout << "Capacity of y = " << y.capacity() << endl;
	if (y.empty()) cout << "y is empty" << endl;
	else cout << "y is not empty" << endl;
	y.output(cout);
	cout << endl << "Testing overloaded <<" << endl;
	cout << y << endl;

	// 测试indexOf函数
	int index = y.indexOf(4);
	if (index < 0) cout << "4 not found" << endl;
	else cout << "The index of 4 is " << index << endl;

	index = y.indexOf(7);
	if (index < 0) cout << "7 not found" << endl;
	else cout << "The index of 7 is " << index << endl;

	// 测试get函数
	cout << "Element with index 0 is " << y.get(0) << endl;
	cout << "Element with index 3 is " << y.get(3) << endl;

	// 测试set函数
	int num0 = y.get(0);
	int num3 = y.get(3);
	y.set(0, 15); y.set(3, 15);
	cout << "Element with index 0 is " << y.get(0) << endl;
	cout << "Element with index 3 is " << y.get(3) << endl;
	y.set(0, num0); y.set(3, num3); // 恢复为原来线性表的元素

	// 测试erase函数
	y.erase(1);
	cout << "Element 1 erased" << endl;
	cout << "The list is " << y << endl;
	y.erase(2);
	cout << "Element 2 erased" << endl;
	cout << "The list is " << y << endl;

	cout << "Size of y = " << y.size() << endl;
	cout << "Capacity of y = " << y.capacity() << endl;
	if (y.empty()) cout << "y is empty" << endl;
	else cout << "y is not empty" << endl;

	try { y.insert(-3, 0); }
	catch (illegalIndex e)
	{
		cout << "Illegal index exception" << endl;
		cout << "Insert index must be between 0 and list size" << endl;
		e.outputMessage();
	}

	// 测试拷贝构造函数
	arrayListNoSTL<int> w(y);
	y.erase(0);
	y.erase(0);
	cout << "w should be old y, new y has first 2 elements removed" << endl;
	cout << "w is " << w << endl;
	cout << "y is " << y << endl;

	// 继续插入操作
	y.insert(0, 4);
	y.insert(0, 5);
	y.insert(0, 6);
	y.insert(0, 7);
	cout << "y is " << y << endl;
	*/


// 05 线性表（二）：丰富功能，若需要运行该部分内容，请将最后的有效代码块注释掉
    /*
    arrayListNoSTL<int> y(10);   
	y.trimToSize();             // 测试trimToSize函数 数组的长度此时会变成1
	cout << "y.capacity() = "<<y.capacity() << endl;
	cout << endl;

	// 向线性表中插入元素
	y.insert(0, 1);
	y.insert(1, 2);
	y.insert(2, 3);
	y.insert(3, 4);
	y.insert(4, 5);

	y.setSize(3);   // 测试setSize函数，此时线性表的长度会变为3

	for (int i = 0; i < y.size(); i++)
	{
		cout <<"y["<<i<<"] = "<< y[i] << endl;   // 只输出1,2,3 
	}
	cout << endl;

	// 测试操作符[]函数
	int a = y[2]; cout << "a = " << a << endl; 
	y[2] = 10;
	cout << "y[2] = " << y[2] << endl;
	cout << endl;

	// 测试操作符==、!=和<函数
	arrayListNoSTL<int> w(y);
	cout << "w==y is "<<(w == y)<< endl;     // 此时结果是true
	w[1] = 10;
	cout << "w!=y is " << (w != y) << endl;  // 此时结果会是true
	cout << "w<y is " << (w < y) << endl;    // 此时结果是false
	cout << endl;

	// 测试push_back和pop_back函数
	y.push_back(5);
	y.push_back(6);
	y.push_back(7);
	y.push_back(8);

	for (int i = 0; i < y.size(); i++)
	{
		cout << "y[" << i << "] = " << y[i] << endl; // 会输出1,2,10,5,6,7,8
	}

	y.pop_back();
	y.pop_back();

	for (int i = 0; i < y.size(); i++)
	{
		cout << "y[" << i << "] = " << y[i] << endl; // 会输出1,2,10,5,6
	}
	cout << endl;

	// 测试swap函数
	y.swap(w);
	for (int i = 0; i < w.size(); i++)
	{
		cout << "w[" << i << "] = " << w[i] << endl; // 会输出1,2,10,5,6
	}
	cout << endl;

	// 测试reserve函数
	y.reserve(100);
	cout << "y.capacity() = " << y.capacity() << endl;
	cout << endl;

	// 测试setA函数
	a = y.setA(2, 101);
	cout << "a = " << a << "  y[2] = " << y[2] << endl;
	cout << endl;

	// 测试clear函数
	y.clear();
	cout << "The size of the list is " << y.size() << endl;
	cout << endl;

	// 测试removeRange函数
	y.insert(0, 1);
	y.insert(1, 2);
	y.insert(2, 3);
	y.insert(3, 4);
	y.insert(4, 5);
	y.insert(5, 6);

	y.removeRange(2, 4);
	for (int i = 0; i < y.size(); i++)
	{
	    cout << "y[" << i << "] = " << y[i] << endl; // 会输出1,2,5,6
	}
	cout << endl;

	// 测试lastIndexOf函数
	int theIndex = y.lastIndexOf(5);
	cout << "theIndex = " << theIndex << endl;
	*/
 

    // 06 线性表（三）：丰富功能，
    arrayListNoSTL<int> y(10);
	arrayListNoSTL<int> a(3);
	arrayListNoSTL<int> b(5);
	a.push_back(2); a.push_back(1);
	b.push_back(3); b.push_back(4); b.push_back(5); b.push_back(6);

	a.reverse();  // 原地颠倒线性表对象a的元素
	cout << "Test for reverse function..." << endl;
	for (int i = 0; i < a.size(); i++)
	{
		cout << "a[" << i << "] = " << a[i] << endl;
	}
	cout << endl;

	b.leftShift(1);  // 把线性表对象b的元素向左移动1个位置
	cout << "Test for leftShift function..." << endl;
	for (int i = 0; i < b.size(); i++)
	{
		cout << "b[" << i << "] = " << b[i] << endl;
	}
	cout << endl;

	b.circularShift(2);  // 把线性表b的元素循环移动2个位置
	cout << "Test for circularShift function..." << endl;
	for (int i = 0; i < b.size(); i++)
	{
		cout << "b[" << i << "] = " << b[i] << endl;
	}
	cout << endl;

	b.half();  // 对线性表b的元素隔一个删除一个
	cout << "Test for half function..." << endl;
	for (int i = 0; i < b.size(); i++)
	{
		cout << "b[" << i << "] = " << b[i] << endl;
	}
	cout << endl;

	arrayListNoSTL<int>::iterator iter;    // 定义线性表的迭代器
	cout << "Test for arrayListNoSTL<T>::iterator..." << endl;
	for (iter = b.begin(); iter != b.end(); iter++)
	{
		cout << *iter << endl;
	}
	cout << endl;

	y.meld(a, b);    //生成一个新的线性表，从a的第0个元素开始，交替地包含a和b的元素
	cout << "Test for meld funtion..." << endl;
	for (int i = 0; i <y.size(); i++)
	{
		cout <<"y["<<i<<"] = "<< y[i] << "\t";
	}
	cout << endl<<endl;

	b[0] = 1; b[1] = 3;     // 对b中的元素重新赋值
	y.merge(a, b);          // 利用归并排序算法，使其包括非递减线性表a和b的所有元素
	cout << "Test for merge funtion..." << endl;
	for (int i = 0; i < y.size(); i++)
	{
		cout << "y[" << i << "] = " << y[i] << "\t";
	}
	cout << endl;

	y.split(a, b);   // 生成两个线性表a和b，a包含y中索引为偶数的元素，b包含其余的元素
	cout << "Test for split function..." << endl;
	for (int i = 0; i < a.size(); i++)
	{
		cout << "a[" << i << "] = " << a[i] << endl;
	}
	for (int i = 0; i < b.size(); i++)
	{
		cout << "b[" << i << "] = " << b[i] << endl;
	}

	return 0;
}