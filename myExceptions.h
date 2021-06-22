// exception classes for various error types

#ifndef MYEXCEPTIONS_H
#define MYEXCEPTIONS_H

/********************************************************************************************************************************
文件名： myExceptions.h
功能描述：自定义异常类，在需要的时候抛异常。
参考资料：萨尼.《数据结构、算法与应用C++语言描述第二版》[M].北京：机械工业出版社，2019.
日期：2021/6/19
版权：2021-2025
作者：闫英伟

历史：1. 2021/6/19新建myExceptions头文件；

********************************************************************************************************************************/
#include <string>
#include <iostream>

using namespace std;

namespace DSLib
{
	// 非法参数异常类
	class illegalParameterValue
	{
	public:
		illegalParameterValue(string theMessage = "Illegal parameter value")
		{
			message = theMessage;
		}
		void outputMessage() { cout << message << endl; }
	private:
		string message;
	};

	// 输入数据非法
	class illegalInputData
	{
	public:
		illegalInputData(string theMessage = "Illegal data input")
		{
			message = theMessage;
		}
		void outputMessage() { cout << message << endl; }
	private:
		string message;
	};

	// 索引值非法
	class illegalIndex
	{
	public:
		illegalIndex(string theMessage = "Illegal index")
		{
			message = theMessage;
		}
		void outputMessage() { cout << message << endl; }
	private:
		string message;
	};

	// 矩阵索引值非法
	class matrixIndexOutOfBounds
	{
	public:
		matrixIndexOutOfBounds
		(string theMessage = "Matrix index out of bounds")
		{
			message = theMessage;
		}
		void outputMessage() { cout << message << endl; }
	private:
		string message;
	};

	// 矩阵尺寸不匹配
	class matrixSizeMismatch
	{
	public:
		matrixSizeMismatch(string theMessage =
			"The size of the two matrics doesn't match")
		{
			message = theMessage;
		}
		void outputMessage() { cout << message << endl; }
	private:
		string message;
	};

	// 栈空异常
	class stackEmpty
	{
	public:
		stackEmpty(string theMessage =
			"Invalid operation on empty stack")
		{
			message = theMessage;
		}
		void outputMessage() { cout << message << endl; }
	private:
		string message;
	};

	// 队列为空时的异常
	class queueEmpty
	{
	public:
		queueEmpty(string theMessage =
			"Invalid operation on empty queue")
		{
			message = theMessage;
		}
		void outputMessage() { cout << message << endl; }
	private:
		string message;
	};

	// 哈希表已满时的异常
	class hashTableFull
	{
	public:
		hashTableFull(string theMessage =
			"The hash table is full")
		{
			message = theMessage;
		}
		void outputMessage() { cout << message << endl; }
	private:
		string message;
	};

	// 图中的边权重值未定义
	class undefinedEdgeWeight
	{
	public:
		undefinedEdgeWeight(string theMessage =
			"No edge weights defined")
		{
			message = theMessage;
		}
		void outputMessage() { cout << message << endl; }
	private:
		string message;
	};

	// 方法未定义
	class undefinedMethod
	{
	public:
		undefinedMethod(string theMessage =
			"This method is undefined")
		{
			message = theMessage;
		}
		void outputMessage() { cout << message << endl; }
	private:
		string message;
	};
}
#endif

