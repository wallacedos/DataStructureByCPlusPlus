#ifndef SDF_H
#define SDF_H

/********************************************************************************************************************************
文件名： sdf.h
功能描述：学习中文版萨尼.《数据结构、算法与应用C++语言描述第二版》过程中需要的自定义（不从属于某个类）函数，包含课后练习题答案和
          其他相关代码。更多内容，可关注微信公众号地震成像与模拟，当中的专辑《算法与数据结构》的文章给出了关于本程序中每个测试例
		  子的详细描述。
参考资料：萨尼.《数据结构、算法与应用C++语言描述第二版》[M].北京：机械工业出版社，2019.
日期：2021/5/1
版权：2021-2025
作者：闫英伟

历史：1. 2021/5/1加入了“深入理解指针与递归函数”文章的功能函数；
      2. 2021/5/9加入了“基本排序方法”文章的功能函数；

********************************************************************************************************************************/

#include <iostream>
#include <iterator>
#include<list>

using namespace std;

namespace DSLib
{
	// 2021/5/1日加入的功能函数
	template <class T>
	void permutations(T list[], const int k, const int m);
	int Fibonacci(const int n);
	int NonRecursionFibonacci(const int n);
	int Ackermann(const int i, const int j);
	int gcd(const int x, const int y);
	template <class T>
	bool xBelongA(T* a, T x, const int n);
	template <class T>
	void print_subset(const T* a, int* mark, const int i, const int n);
	void calcGrayCode(list<int>& result, const int& n);

	// 2021/5/9加入的功能函数
	template<class T> 
	void calcRank(const T a[], const int n, int r[]);
	template<class T>
	void rearrange(T a[], const int n, int r[]);
	template<class T> 
	void bubbleSort(T a[], const int n);
	template<class T> 
	void selectionSort(T a[], const int n);
	template<class T> 
	void insertionSort(T a[], const int n);
}

template <class T>
void DSLib::permutations(T list[], const int k, const int m)
{
	// 第一章程序1-32的代码，文版萨尼.《数据结构、算法与应用C++语言描述第二版》第28页
	// 生成list[0:m]的所有排列
	if (k == m)
	{
		copy(list, list + m + 1, ostream_iterator<T>(cout, ""));
		cout << endl;
	}
	else
	{
		for (int i = k; i <= m; i++)
		{
			swap(list[k], list[i]);
			permutations(list, k + 1, m);
			swap(list[k], list[i]);
		}
	}
}

int DSLib::Fibonacci(const int n)
{
	// 第一章练习题20的（1）求解代码，中文版萨尼.《数据结构、算法与应用C++语言描述第二版》第28页
	if (n == 1 || n == 2)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);

}

int DSLib::NonRecursionFibonacci(const int n)
{
	// 第一章练习题20的（3）求解代码，中文版萨尼.《数据结构、算法与应用C++语言描述第二版》第28页
	int a = 1;
	int b = 1;
	int c = 1;

	for (int i = 2; i < n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}

	return c;
}

int DSLib::Ackermann(const int i, const int j)
{
	// 第一章练习题22的求解代码，中文版萨尼.《数据结构、算法与应用C++语言描述第二版》第29页
	if (i == 1 && j >= 1)
	{
		return static_cast<int>(pow(2, j));
	}
	else if (i >= 2 && j == 1)
	{
		return Ackermann(i - 1, 2);
	}
	else
	{
		return Ackermann(i - 1, Ackermann(i, j - 1));
	}
}

int DSLib::gcd(const int x, const int y)
{
	// 第一章练习题23的求解代码，中文版萨尼.《数据结构、算法与应用C++语言描述第二版》第29页
	if (y == 0)
	{
		return x;
	}
	else if (y > 0)
	{
		return gcd(y, x%y);
	}
	else
	{
		throw "y cannot be negative.";
	}
}

template <class T>
bool DSLib::xBelongA(T* a, T x, const int n)
{
	// 第一章练习题24的求解代码，中文版萨尼.《数据结构、算法与应用C++语言描述第二版》第29页
	if (a[0]==x)
	{
		return true;
	}
	else if(n>1)
	{
		return xBelongA(a + 1, x, n - 1);
	}
	return false;
}

template <class T>
void DSLib::print_subset(const T* a, int* mark, const int i, const int n)
{
	// 第一章练习题25的求解代码，中文版萨尼.《数据结构、算法与应用C++语言描述第二版》第29页
	if (i == n)
	{
		int num = 0;
		cout << "{";
		for (int k = 0; k < n; k++)
		{
			if (mark[k] == 1 && num==0)
			{
				cout << a[k];
				num = num + 1;
			}
			else if (mark[k] == 1 && num != 0)
			{
				cout << "," << a[k];
			}
		}
		cout << "}";
		cout << endl;
		return;
	}

	mark[i] = 0;
	print_subset(a, mark, i + 1, n);
	mark[i] = 1;
	print_subset(a, mark, i + 1, n);
}

void DSLib::calcGrayCode(list<int>& result, const int& n)
{
	// 第一章练习题26的求解代码，中文版萨尼.《数据结构、算法与应用C++语言描述第二版》第29页
	if (n == 1)
	{
		result.push_back(1);
	}
	else if (n > 1)
	{
		calcGrayCode(result, n - 1);
		result.push_back(n);
		calcGrayCode(result, n - 1);
	}
}

template<class T>
void DSLib::calcRank(const T a[], const int n, int r[])
{
	// 第二章46页
	// 得到数组a[0:n-1]中每个元素的名次，并存在数组r中
	for (int i = 0; i < n; i++)
	{
		r[i] = 0;  // 初始化
	}
	for (int i = 0; i <(n-1); i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i]>a[j])
			{
				r[i]++;
			}
			else
			{
				r[j]++;
			}
		}
	}
}

template<class T>
void DSLib::rearrange(T a[], const int n, int r[])
{
	// 第二章50页
	// 根据数组a的名次信息数组r,重排数组a的元素
	for (int i = 0; i < n; i++)
	{
		while (r[i] != i)  // 防止自交换
		{
			int t = r[i];
			swap(a[i], a[t]);
			swap(r[i], r[t]);
		}
	}
}

template<class T>
void DSLib::bubbleSort(T a[], const int n)
{
	// 第二章52页
	// 及时终止的冒泡排序
	bool swapped = true;
	for (int i = n-1; i>0; i--)
	{
		swapped = false;
		for (int j = 0; j <i; j++)
		{
			if (a[j]>a[j+1])
			{
				swap(a[j], a[j+1]);
				swapped = true;  // 发生交换
			}
		}
	}

}

template<class T>
void DSLib::selectionSort(T a[], const int n)
{
	// 第二章第51页
	// 及时终止的选择排序
	int indexOfMax = 0;
	bool sorted = false;
	for (int size = n; size > 1 && !sorted; size--)
	{
		indexOfMax = 0;
		sorted = true;
		for (int i = 1; i < size; i++)
		{
			if (a[i]>=a[indexOfMax])
			{
				indexOfMax = i;
			}
			else
			{
				sorted = false; // 只要被执行一次说明数组是无序的
			}
		}
		swap(a[indexOfMax], a[size - 1]);
	}
}

template<class T>
void DSLib::insertionSort(T a[], const int n)
{
	// 第二章53页
	// 插入排序的程序
	int j = 0;
	T t = a[0];
	for (int i = 1; i < n; i++)
	{
		T t = a[i];
		for (j = i - 1; j >= 0 && a[j]>t; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = t;
	}
}

#endif
