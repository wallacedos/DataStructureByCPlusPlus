#ifndef LINEARLIST_H
#define LINEARLIST_H

/********************************************************************************************************************************
文件名： linearList.h
功能描述： 线性表的虚基类，抽象父类，功能函数均为纯虚函数。
参考资料：萨尼.《数据结构、算法与应用C++语言描述第二版》[M].北京：机械工业出版社，2019.
日期：2021/6/19
版权：2021-2025
作者：闫英伟

历史：1. 2021/6/19新建linearList头文件；

********************************************************************************************************************************/

#include <iostream>

using namespace std;

namespace DSLib
{
	template<class T>
	class linearList
	{
	public:
		virtual ~linearList() {};        // 虚析构函数，在派生类中具体化
		virtual bool empty() const = 0;  // 纯虚函数，若线性表为空，返回true，否则返回false
		virtual int size() const = 0;    // 纯虚函数，返回线性表的大小，即线性表中元素的个数

		// 纯虚函数，返回线性表中索引为theIndex处的元素
		virtual T& get(int theIndex) const = 0;   
		// 纯虚函数，返回线性表中元素theElement第一次出现时的索引，若线性表中没有该元素，则返回-1
		virtual int indexOf(const T& theElement) const = 0; 
		// 纯虚函数，删除线性表中索引为theIndex的元素，原线性表中索引为theIndex后的元素向前移动一个位置
		virtual void erase(int theIndex) = 0;
		// 纯虚函数，在线性表中索引为theIndex位置处插入一个元素，原线性表中索引为theIndex及后的元素向后移动一个位置
		virtual void insert(int theIndex, const T& theElement) = 0;
		// 纯虚函数，把线性表插入至输出流out
		virtual void output(ostream& out) const = 0;
	};
}
#endif


