#ifndef ARRAYLISTNOSTL_H
#define ARRAYLISTNOSTL_H

/********************************************************************************************************************************
文件名： arrayListNoSTL.h
功能描述： 继承自虚基类linearList，并对其中每个函数实例化。
参考资料：萨尼.《数据结构、算法与应用C++语言描述第二版》[M].北京：机械工业出版社，2019.
日期：2021/6/19
版权：2021-2025
作者：闫英伟

历史：1. 2021/6/19新建arrayListNoSTL头文件，加入基本函数；
      2. 2021/7/17按参考资料课后习题的要求，丰富了线性表的功能，即加入了其他一些功能函数；
	  3. 2021/8/8进一步地丰富了线性表的功能，增加了其他一些功能函数；

********************************************************************************************************************************/

#include<iostream>
#include<sstream>
#include<string>

#include "sdf.h"
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
		void trimToSize();                                     // 使数组的长度等于max{listSize,1}
		void setSize(int theSize);                             // 使线性表的大小等于指定的大小
		T& operator [](int i) const;                           // 重载[]操作符
		bool operator==(const arrayListNoSTL<T> &theList) const;  // 重载==操作符
		bool operator!=(const arrayListNoSTL<T>& theList) const;  // 重载!=操作符
		bool operator<(const arrayListNoSTL<T>& theList) const;   // 重载<操作符
		void push_back(const T& theElement);                      // 把元素插到线性表的右端
		void pop_back();                                          // 把线性表右端的元素删除
		void swap(arrayListNoSTL<T>& theList);                    // 交换两个线性表
		void reserve(const int theCapacity);                      // 把数组的容量改为当前容量和theCapacity的较大者
		T setA(int theIndex, const T& theElement);                // 设置索引为theIndex处的元素为theElement，并返回原来的元素
		void clear();                                             // 清空线性表
		void removeRange(int start, int end);                     // 删除索引范围为[start, end)的元素
		int lastIndexOf(const T& theElement) const;               // 返回指定元素最后出现时的索引
		void reverse();                                           // 原地颠倒线性表的元素
		void leftShift(int i);                                    // 把线性表的元素向左移动i个位置
		void circularShift(int i);                                // 把线性表循环移动i个位置
		void half();                                              // 隔一个删除一个

		// arrayListNoSTL的迭代器
		class iterator;
		iterator begin() { return iterator(element); }
		iterator end() { return iterator(element + listSize); }

		// 生成一个新的线性表，从a的第0个元素开始，交替地包含a和b的元素
		void meld(const arrayListNoSTL<T>& a, const arrayListNoSTL<T>& b);   

		// a和b是类arrayListNoSTL的两个对象，且它们的元素从左到右非递减有序，利用归并排序算法生成一个新的
		// 线性表，使其包含a和b的所有元素
		void merge(const arrayListNoSTL<T>& a, const arrayListNoSTL<T>& b);

		// 生成两个线性表a和b，a包含*this中索引为偶数的元素，b包含其余的元素
		void split(arrayListNoSTL<T>& a, arrayListNoSTL<T>& b);


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

		element[--listSize].~T();  // 调用类型T的析构函数
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

	template<class T>
	void arrayListNoSTL<T>::trimToSize()
	{
		// 使数组的长度等于max{listSize,1}
		if (arrayLength == listSize)   // 若数组的长度arrayLength与线性表的长度相等，直接返回
		{
			return;
		}

		if (listSize == 0)          // 若线性表的长度为0，需要将数组的长度调整为1
		{
			delete [] element; // 释放原数组空间
			element = new T[1];
			arrayLength = 1;
			return;
		}

		// 其他情况，arrayLength大于listSize时，需要改变数组的长度
		changeLength1D(element, listSize, listSize);
		arrayLength = listSize;
	}

	template<class T>
	void arrayListNoSTL<T>::setSize(int theSize)
	{
		if (theSize < 0 || theSize>this->capacity())  // 若参数小于0，或者大于数组的长度，需要抛异常
		{
			// 无效的参数theSize
			ostringstream s;
			s << "parameter theSize = " << theSize<< "is illegal. It must be in the range of 0 to "<<this->capacity()<<".";
			throw illegalParameterValue(s.str());
		}

		if (listSize <= theSize)  
		{
			return;
		}
		else
		{
			for (int i = theSize; i < listSize; i++)
			{
				element[i].~T();   // 调用类型T的析构函数，释放多余的线性表元素
			}
			listSize = theSize;
		}
	}

	// 重载操作符[]
	template <class T>
	T& arrayListNoSTL<T>::operator [](int i) const
	{
		checkIndex(i);
		return element[i];
	}

	template <class T>
	bool arrayListNoSTL<T>::operator== (const arrayListNoSTL<T>& theList) const
	{
		bool ret = false;
		if (this->listSize != theList.size())   // 若两个线性表的长度不相等，直接返回false
		{
			return ret;
		}

		ret = true;
		for (int i = 0; i < this->listSize; i++)
		{
			if (this->element[i] != theList[i])
			{
				ret = false;
				return ret;
			}
		}

		return ret;
	}

	template<class T> 
	bool arrayListNoSTL<T>::operator!= (const arrayListNoSTL<T>& theList) const
	{
		return !(*this == theList);
	}

	template<class T>
	bool arrayListNoSTL<T>::operator< (const arrayListNoSTL<T>& theList) const
	{
		bool ret = false;
		if (this->listSize != theList.size())   // 若两个线性表的长度不相等，直接返回false
		{
			return ret;
		}

		ret = true;
		for (int i = 0; i < this->listSize; i++)
		{
			if (this->element[i]>=theList[i])
			{
				ret = false;
				return ret;
			}
		}

		return ret;
	}

	template<class T> 
	void arrayListNoSTL<T>::push_back(const T& theElement)
	{
		// 确定线性表的空间是否够用
		if (listSize == arrayLength)
		{   // 线性表的空间不够，则对原线性表的空间作扩展
			changeLength1D(element, arrayLength, 2 * arrayLength);
			arrayLength *= 2;
		}
		
		this->element[listSize] = theElement;
		listSize++;
	}

	template<class T>
	void arrayListNoSTL<T>::pop_back()
	{
		if (this->listSize == 0)
		{
			// 线性表已经空了
			ostringstream s;
			s << "the list is empty()";
			throw exceptionInfo(s.str());
		}

		listSize--;
		this->element[listSize].~T();   // 调用类型T的析构函数
	}

	template<class T>
	void arrayListNoSTL<T>::swap(arrayListNoSTL<T>& theList)
	{
		int temp = 0;
		temp = arrayLength;
		arrayLength = theList.arrayLength;
		theList.arrayLength = temp;
		
		temp = listSize;
		listSize = theList.listSize;
		theList.listSize = temp;

		T* p = element;
		element = theList.element;
		theList.element = p;

		p = NULL;
	}

	template<class T> 
	void arrayListNoSTL<T>::reserve(const int theCapacity)
	{
		if (this->arrayLength>= theCapacity)
		{
			return;
		}

		changeLength1D(element, listSize, theCapacity);
		arrayLength = theCapacity;
	}

	template<class T>
	T arrayListNoSTL<T>::setA(int theIndex, const T& theElement)
	{
		checkIndex(theIndex);
		T ret = element[theIndex];
		element[theIndex] = theElement;
		return ret;
	}

	template<class T>
	void arrayListNoSTL<T>::clear()
	{
		delete [] element;  // 释放原数组空间
		T* temp = new T[arrayLength];
		element = temp;
		listSize = 0;
	}

	template<class T>
	void arrayListNoSTL<T>::removeRange(int start, int end)
	{
		if (start < 0 || end > listSize)
			throw illegalIndex();

		if (start >= end) // 直接返回
			return;

		// 移动end之后的元素
		copy(element + end, element + listSize, element + start);

		// 释放之后的元素
		int newSize = listSize - end + start;
		for (int i = newSize; i < listSize; i++)
			element[i].~T();

		listSize = newSize;
	}

	template<class T>
	int arrayListNoSTL<T>::lastIndexOf(const T& theElement) const
	{
		int theIndex = -1;
		for (int i = listSize - 1; i >= 0; i--)
		{
			if (element[i] == theElement)
			{
				theIndex = i;
				return theIndex;
			}
		}
		return theIndex;
	}

	template<class T>
	void arrayListNoSTL<T>::reverse()
	{
		for (int i = 0; i < (listSize / 2); i++)
		{
			swapElement(element + i, element + listSize - i - 1);
		}
	}

	template<class T>
	void arrayListNoSTL<T>::leftShift(int i)
	{
		if (i <0 || i>listSize)
		{
			// 无效的参数i
			ostringstream s;
			s << "parameter i = " <<i<< "is illegal. It must be in the range of 0 to " << listSize<< ".";
			throw illegalParameterValue(s.str());
		}

		int newSize = 0;
		if (i<= listSize)
		{
			newSize = listSize - i;
			copy(element + i, element + listSize, element);
		}

		// 剩余元素作析构
		for (int i = newSize; i < listSize; i++)
			element[i].~T();

		listSize = newSize;
	}

	template<class T>
	void arrayListNoSTL<T>::circularShift(int i)
	{
		if (i<0 || i>listSize)
		{
			// 无效的参数i
			ostringstream s;
			s << "parameter i = " << i << "is illegal. It must be in the range of 0 to " << listSize << ".";
			throw illegalParameterValue(s.str());
		}

		T* s = new T[i];    // 创建辅助数组s
		for (int k = 0; k < i; k++)
		{
			s[k] = element[k];
		}

		for (int k = 0; k < (listSize - i); k++)
		{
			element[k] = element[k + i];
		}

		for (int k = (listSize - i); k < listSize; k++)
		{
			element[k] = s[k - listSize + i];
		}
		delete[]s;
		s = NULL;
	}

	template<class T>
	void arrayListNoSTL<T>::half()
	{
		int newListSize = (listSize + 1) / 2;
		for (int i = 0; i < newListSize; i++)
		{
			element[i] = element[2 * i];
		}

		for (int i = newListSize; i < listSize; i++)
		{
			element[i].~T();
		}
		
		listSize = newListSize;
	}

	// 线性表的迭代器
	template<class T>
	class arrayListNoSTL<T>::iterator
	{
	public:
		typedef bidirectional_iterator_tag iterator_category;
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;

		// 构造函数
		iterator(T* thePosition = 0) { position = thePosition; }

		// 解引用操作符
		T& operator*() const { return *position; }
		T* operator->() const { return &*position; }

		// 自增
		iterator& operator++()   // 前置自增
		{
			++position; return *this;
		}
		iterator operator++(int) // 后置自增
		{
			iterator old = *this;
			++position;
			return old;
		}

		// 自减
		iterator& operator--()   // 前置自减
		{
			--position; return *this;
		}
		iterator operator--(int) // 后置自减
		{
			iterator old = *this;
			--position;
			return old;
		}

		// !=和==操作符的定义函数
		bool operator!=(const iterator right) const
		{
			return position != right.position;
		}
		bool operator==(const iterator right) const
		{
			return position == right.position;
		}
	protected:
		T* position;
	};  

	template<class T>
	void arrayListNoSTL<T>::meld(const arrayListNoSTL<T>& a, const arrayListNoSTL<T>& b)
	{
		delete[]element;
		int aListSize = a.listSize;
		int bListSize = b.listSize;

		int newListSize = aListSize + bListSize;

		// 确定线性表的空间是否够用
		if (newListSize> arrayLength)
		{
			arrayLength = newListSize;
		}

		listSize = newListSize;
		element = new T[arrayLength];

		if (aListSize == bListSize)
		{
			for (int i = 0; i < aListSize; i++)
			{
				element[2*i] = a.element[i];
				element[2 * i + 1] = b.element[i];
			}
		}
		else if (aListSize > bListSize)
		{
			for (int i = 0; i < bListSize; i++)
			{
				element[2 * i] = a.element[i];
				element[2 * i + 1] = b.element[i];
			}
			copy(a.element+bListSize, a.element+aListSize, element+(2 * bListSize));
		}
		else if (aListSize < bListSize)
		{
			for (int i = 0; i < aListSize; i++)
			{
				element[2 * i] = a.element[i];
				element[2 * i + 1] = b.element[i];
			}
			copy(b.element + aListSize, b.element + bListSize, element + (2 * aListSize));
		}
		else
		{
			// 触发未定义的异常
			ostringstream s;
			s <<"the program has triggered an undefined exception...";
			throw undefinedException(s.str());
		}
	}

	template<class T>
	void arrayListNoSTL<T>::merge(const arrayListNoSTL<T>& a, const arrayListNoSTL<T>& b)
	{
	    int ca = 0;                       // 线性表a的游标
		int cb = 0;                       // 线性表b的游标
		int ct = 0;                       // 当前线性表的游标
		
	    // 释放当前线性表，并为当前线性表重新申请内存空间
		delete[] element;
		arrayLength = a.listSize + b.listSize;
		element = new T[arrayLength];

		// 由a到b作归并
		while ((ca < a.listSize) && (cb < b.listSize))
			if (a.element[ca] <= b.element[cb])
				element[ct++] = a.element[ca++];
			else
				element[ct++] = b.element[cb++];

		// 处理剩余元素
		copy(a.element + ca, a.element + a.listSize, element + ct);
		ct += a.listSize - ca;
		copy(b.element + cb, b.element + b.listSize, element + ct);
		ct += b.listSize - cb;

		listSize = ct;
	}

	template<class T>
	void arrayListNoSTL<T>::split(arrayListNoSTL<T>& a, arrayListNoSTL<T>& b)
	{
		int aListSize = (listSize + 1) / 2;
		int bListSize = listSize - aListSize;
		delete[]a.element;
		delete[]b.element;

		int aArrayLength = aListSize > a.arrayLength ? aListSize : a.arrayLength;
		int bArrayLength = bListSize > b.arrayLength ? bListSize : b.arrayLength;

		a.element = new T[aArrayLength];
		b.element = new T[bArrayLength];
		a.arrayLength = aArrayLength;
		b.arrayLength = bArrayLength;
		a.listSize = aListSize;
		b.listSize = bListSize;

		for (int i = 0; i < aListSize; i++)
		{
			a.element[i] = element[2 * i];
		}

		for (int i = 0; i < bListSize; i++)
		{
			b.element[i] = element[2 * i + 1];
		}
	}
}
#endif

