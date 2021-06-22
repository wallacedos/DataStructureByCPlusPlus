#ifndef ARRAYLISTNOSTL_H
#define ARRAYLISTNOSTL_H

/********************************************************************************************************************************
文件名： arrayListNoSTL.h
功能描述： 继承自虚基类linearList，并对其中每个函数实例化。
参考资料：萨尼.《数据结构、算法与应用C++语言描述第二版》[M].北京：机械工业出版社，2019.
日期：2021/6/19
版权：2021-2025
作者：闫英伟

历史：1. 2021/6/19新建arrayListNoSTL头文件；

********************************************************************************************************************************/

#include<iostream>
#include<sstream>
#include<string>

#include "linearList.h"
#include "myExceptions.h"
#include "changeLength1D.h"

using namespace std;

namespace DSLib
{
	template<class T>
	class arrayListNoSTL : public linearList<T>
	{
	public:
		// 构造函数，拷贝构造函数和析构函数
		arrayListNoSTL(int initialCapacity = 10);
		arrayListNoSTL(const arrayListNoSTL<T>&);
		~arrayListNoSTL() { delete[] element; }

		// 虚基类中声明的功能函数
		bool empty() const { return listSize == 0; }
		int size() const { return listSize; }
		T& get(int theIndex) const;
		int indexOf(const T& theElement) const;
		void erase(int theIndex);
		void insert(int theIndex, const T& theElement);
		void output(ostream& out) const;

		// 额外的方法
		int capacity() const { return arrayLength; }
		void set(int theIndex, const T& theElement);

	protected:
		void checkIndex(int theIndex) const; // 如果索引theIndex是无效的，抛出illegalIndex异常
		
		T* element;            // 1D数组指针
		int arrayLength;       // 1D数组的容量
		int listSize;          // 线性表中元素的个数
	};

	template<class T>
	arrayListNoSTL<T>::arrayListNoSTL(int initialCapacity)
	{   // 构造函数
		if (initialCapacity < 1)
		{
			ostringstream s;
			s << "Initial capacity = " << initialCapacity << " Must be > 0";
			throw illegalParameterValue(s.str());
		}
		arrayLength = initialCapacity;
		element = new T[arrayLength];
		listSize = 0;
	}

	template<class T>
	arrayListNoSTL<T>::arrayListNoSTL(const arrayListNoSTL<T>& theList)
	{   // 拷贝构造函数
		arrayLength = theList.arrayLength;
		listSize = theList.listSize;
		element = new T[arrayLength];

		// 复制线性表元素到当前线性表
		for (int i = 0; i < listSize; i++)
			element[i] = theList.element[i];
	}

	template<class T>
	void arrayListNoSTL<T>::checkIndex(int theIndex) const
	{   // 验证索引theIndex是否在0和listSize - 1之间.
		if (theIndex < 0 || theIndex >= listSize)
		{
			ostringstream s;
			s << "index = " << theIndex << " size = " << listSize;
			throw illegalIndex(s.str());
		}
	}

	template<class T>
	T& arrayListNoSTL<T>::get(int theIndex) const
	{   // 返回线性表中索引为theIndex的元素，若索引非法，则抛异常
		checkIndex(theIndex);
		return element[theIndex];
	}

	template<class T>
	int arrayListNoSTL<T>::indexOf(const T& theElement) const
	{   // 返回线性表中元素theElement第一次出现时的索引
	    // 在线性表中搜索元素theElement
		for (int i = 0; i < listSize; i++)
			if (element[i] == theElement) return i;

		// 没有出现元素theElement时，返回-1
		return -1;
	}

	template<class T>
	void arrayListNoSTL<T>::erase(int theIndex)
	{   // 删除线性表中索引为theIndex处的元素，若索引非法，则抛异常
		checkIndex(theIndex);

		// 索引theIndex合法，移动theIndex后的元素
		for (int i = theIndex + 1; i < listSize; i++)
			element[i - 1] = element[i];

		element[--listSize].~T();  // 调用类型T的析构函数，
	}

	template<class T>
	void arrayListNoSTL<T>::insert(int theIndex, const T& theElement)
	{   // 在索引为theIndex处插入元素theElement
		if (theIndex < 0 || theIndex > listSize)
		{   // 无效的索引theIndex
			ostringstream s;
			s << "index = " << theIndex << " size = " << listSize;
			throw illegalIndex(s.str());
		}

		// 有效的索引，确定线性表的空间是否够用
		if (listSize == arrayLength)
		{   // 线性表的空间不够，则对原线性表的空间作扩展
			changeLength1D(element, arrayLength, 2 * arrayLength);
			arrayLength *= 2;
		}

		// 索引theIndex及之后的元素右移一个位置
		for (int i = listSize - 1; i >= theIndex; i--)
			element[i + 1] = element[i];

		element[theIndex] = theElement;

		listSize++;
	}

	template<class T>
	void arrayListNoSTL<T>::output(ostream& out) const
	{   //把线性表中的元素插入到输出流out中
		for (int i = 0; i < listSize; i++)
			out << element[i] << "  ";
	}

	// 重载操作符<<
	template <class T>
	ostream& operator<<(ostream& out, const arrayListNoSTL<T>& x)
	{
		x.output(out); return out;
	}

	// 用元素theElement替换索引为theIndex的元素，若索引非法，则抛异常
	template <class T>
	void arrayListNoSTL<T>::set(int theIndex, const T& theElement)
	{
		checkIndex(theIndex);
		element[theIndex] = theElement;
	}
}
#endif

