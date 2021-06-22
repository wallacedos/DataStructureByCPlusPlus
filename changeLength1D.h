// change the length of an array

#ifndef CHANGELENGTH1D_H
#define CHANGELENGTH1D_H

/********************************************************************************************************************************
文件名： changeLength1D.h
功能描述：在线性表存储空间不够时，扩展线性表的内存，即扩展动态数组的长度。
参考资料：萨尼.《数据结构、算法与应用C++语言描述第二版》[M].北京：机械工业出版社，2019.
日期：2021/6/19
版权：2021-2025
作者：闫英伟

历史：1. 2021/6/19新建changeLength1D头文件；

********************************************************************************************************************************/
#include "myExceptions.h"

using namespace std;

namespace DSLib
{
	int min(int a, int b)
	{
		return a < b ? a : b;
	}

	template<class T>
	void changeLength1D(T*& a, int oldLength, int newLength)
	{
		if (newLength < 0)
			throw illegalParameterValue("new length must be >= 0");

		T* temp = new T[newLength];              // 新数组
		int number = min(oldLength, newLength);  // 需要复制的元素个数
		copy(a, a + number, temp);
		delete[] a;                              // 释放内存
		a = temp;
	}
}
#endif
