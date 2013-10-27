/*
 * BasicMatrix.h
 *
 *  Created on: 2013年10月23日
 *      Author: 李恒毅
 */

#ifndef MATRIX_H_INCLUDE_GUARD
#define MATRIX_H_INCLUDE_GUARD

#include <cstdlib>
#include <vector>
#include <stdexcept>

using std::vector;
using std::invalid_argument;
using std::out_of_range;

template<typename T>
class BasicMatrix
{
    static vector<size_t> _ID_val;

protected: //私有变量
    size_t _ID;

    size_t _row;
    size_t _col;

    T** _element;
    T _ratio;

public: // 构造/析构函数
    //方阵构造函数
    BasicMatrix<T>(const size_t& n);
    BasicMatrix<T>(const size_t& n, const T& val);
    BasicMatrix<T>(const size_t& n, const T** val_array);
    //一般矩阵构造函数
    BasicMatrix<T>(const size_t& m, const size_t& n);
    BasicMatrix<T>(const size_t& m, const size_t& n, const T& val);
    BasicMatrix<T>(const size_t& m, const size_t& n, const T** val_array);
    //拷贝构造函数
    BasicMatrix<T>(BasicMatrix<T>& obj);
    BasicMatrix<T>(BasicMatrix<T>&& obj);

    //析构函数
    virtual ~BasicMatrix();

public: //重载一元运算符，成员函数
    virtual BasicMatrix<T>& operator=(BasicMatrix<T>& obj);
    virtual BasicMatrix<T>& operator=(BasicMatrix<T>&& obj);

    virtual BasicMatrix<T>& operator+();
    virtual BasicMatrix<T>& operator-();

    virtual BasicMatrix<T>& operator()(const T& val);

public: //重载二院运算符，友元
    virtual friend bool
    operator==(const BasicMatrix<T>& para_1st, const BasicMatrix<T>& para_2nd)
    throw(invalid_argument);

    virtual friend bool
    operator!=(const BasicMatrix<T>& para_1st, const BasicMatrix<T>& para_2nd)
    throw(invalid_argument);

    virtual friend BasicMatrix<T>&
    operator+(const BasicMatrix<T>& para_1st, const BasicMatrix<T>& para_2nd)
    throw(invalid_argument);

    virtual friend BasicMatrix<T>&
    operator-(const BasicMatrix<T>& para_1st, const BasicMatrix<T>& para_2nd)
    throw(invalid_argument);

    virtual friend BasicMatrix<T>&
    operator*(const BasicMatrix<T>& para_1st, const BasicMatrix<T>& para_2nd)
    throw(invalid_argument);

    virtual friend BasicMatrix<T>&
    operator*(const T& para_1st, const BasicMatrix<T>& para_2nd);

    virtual friend BasicMatrix<T>&
    operator*(const BasicMatrix<T>& para_1st, const T& para_2nd);

public: //成员函数
    virtual T& at(size_t m, size_t n) throw(out_of_range);
};



/**
 * @构造函数
 */

//方阵构造函数，无值，只分配内存
template<typename T>
BasicMatrix<T>::BasicMatrix(const size_t& n)
{
	this->_ID = BasicMatrix<T>::_ID_val.size();
	BasicMatrix<T>::_ID_val.push_back(1);

    this->_row = n;                                     //行
    this->_col = n;                                     //列
    this->_element = new T*[n];
    for(size_t i = 0; i < n; ++i)
        this->_element[i] = new T[n];
    this->_ratio = 1;
}

//
template<typename T>
BasicMatrix<T>::BasicMatrix(const size_t& n, const T& val)
{
	this->_ID = BasicMatrix<T>::_ID_val.size();
	BasicMatrix<T>::_ID_val.push_back(1);

    this->_row = n;
    this->_col = n;
    this->_element = new T*[n];
    for(size_t i = 0; i < n; ++i)
    {
    	this->_element[i] = new T[n];
    	for(size_t j = 0; j < n; ++j)
    		this->_element[i][j] = val;
    }
    this->_ratio = 1;
}

//
template<typename T>
BasicMatrix<T>::BasicMatrix(const size_t& n, const T** val_array):
    BasicMatrix(n)
{
	this->_ID = BasicMatrix<T>::_ID_val.size();
	BasicMatrix<T>::_ID_val.push_back(1);

    this->_row = n;
    this->_col = n;
    this->_element = new T*[n];
    for(size_t i = 0; i < n; ++i)
    {
    	this->_element[i] = new T[n];
    	for(size_t j = 0; j < n; ++j)
    		this->_element[i][j] = val_array[i][j];
    }
    this->_ratio = 1;
}

//一般方阵构造函数，无值，只分配内存
template<typename T>
BasicMatrix<T>::BasicMatrix(const size_t& m, const size_t& n)
{
	this->_ID = BasicMatrix<T>::_ID_val.size();
	BasicMatrix<T>::_ID_val.push_back(1);

    this->_row = m;
    this->_col = n;
    this->_element = new T*[m];
    for(size_t i = 0; i < m; ++i)
        _element[i] = new T[n];
    this->_ratio = 1;
}

//
template<typename T>
BasicMatrix<T>::BasicMatrix(const size_t& m, const size_t& n, const T& val):
    BasicMatrix(m, n)
{
	this->_ID = BasicMatrix<T>::_ID_val.size();
	BasicMatrix<T>::_ID_val.push_back(1);

    this->_row = m;
    this->_col = n;
    this->_element = new T*[m];
    for(size_t i = 0; i < m; ++i)
    {
    	this->_element[i] = new T[n];
    	for(size_t j = 0; j < n; ++j)
    		this->_element[i][j] = val;
    }
    this->_ratio = 1;
}

//
template<typename T>
BasicMatrix<T>::BasicMatrix(const size_t& m, const size_t& n,
							const T** val_array)
{
	this->_ID = BasicMatrix<T>::_ID_val.size();
	BasicMatrix<T>::_ID_val.push_back(1);

    this->_row = m;
    this->_col = n;
    this->_element = new T*[m];
    for(size_t i = 0; i < m; ++i)
    {
    	this->_element[i] = new T[n];
    	for(size_t j = 0; j < n; ++j)
    		this->_element[i][j] = val_array[i][j];
    }
    this->_ratio = 1;
}

//拷贝构造函数
template<typename T>
BasicMatrix<T>::BasicMatrix(BasicMatrix<T>& obj)
{
	this->_ID = obj._ID;
	++BasicMatrix<T>::_ID_val.at(obj._ID);

    this->_row = obj._row;
    this->_col = obj._col;
    this->_element = obj._element;
    this->_ratio = obj._ratio;
}

template<typename T>
BasicMatrix<T>::BasicMatrix(BasicMatrix<T>&& obj)
{
	this->_ID = obj._ID;
	++BasicMatrix<T>::_ID_val.at(obj._ID);

    this->_row = obj._row;
    this->_col = obj._col;
    this->_element = obj._element;
    this->_ratio = obj._ratio;
}

/*
 * @析构函数
 * 内存管理策略如下：每个新建对象都会有一个ID，而这个ID也会有一个对应的计数器
 * 					 析构时首先会让计数器自减1（表示一个对象被析构），如果计数器
 * 					 归零（说明已经没有对象），则回收资源；若不等于零，则让指针
 * 					 为空
 */
template<typename T>
BasicMatrix<T>::~BasicMatrix()
{
	--BasicMatrix<T>::_ID_val.at(this->_ID);

	if(0 == this->_ID)
	{
		for(size_t i = this->_row; i < this->_row; ++i)
		{
			delete [] this->_element[i];
			this->_element[i] = nullptr;
		}
		delete [] this->_element;
		this->_element = nullptr;
	}
	else
		this->_element = nullptr;
}

/*
 * @运算符重载
 */

//赋值运算符
template<typename T> BasicMatrix<T>&
BasicMatrix<T>::operator=(BasicMatrix<T>& obj)
{
    if(&obj == this)
        return *this;

	this->_ID = obj._ID;
	++BasicMatrix<T>::_ID_val.at(obj._ID);

    this->_row = obj._row;
    this->_col = obj._col;
    this->_element = obj._element;
    this->_ratio = obj._ratio;

    return *this;
}

//赋值运算符，拷贝临时变量的值
template<typename T> BasicMatrix<T>&
BasicMatrix<T>::operator=(BasicMatrix<T>&& obj)
{
    if(&obj == this)
        return *this;

	this->_ID = obj._ID;
	++BasicMatrix<T>::_ID_val.at(obj._ID);

    this->_row = obj._row;
    this->_col = obj._col;
    this->_element = obj._element;
    this->_ratio = obj._ratio;

    return *this;
}

/*
* @重载正负号
*/
template<typename T> BasicMatrix<T>&
operator+()
{
	return *this;
}

template<typename T> BasicMatrix<T>&
operator-()
{
	this->_ratio *= -1;
	return *this;
}

/*
* @重载类型转换
*/
template<typename T> BasicMatrix<T>&
operator()(const T& val)
{
	return BasicMatrix<T>(1, val);
}

/*
* @重载比较运算符
*/

//如果两个矩阵行、列以及各个元素均相等，则返回true，否则返回false
template<typename T> bool
operator==(const BasicMatrix<T>& para_1st, const BasicMatrix<T>& para_2nd)
{
	if(para_1st._row != para_2nd._row || para_1st._col != para_2nd._col)
		return false;

	if(para_1st._element == para_2nd._element &&
	   para_1st._ratio == para_2nd._ratio)
		return true;

	for(size_t i = 0; i < para_2nd._row; ++i)
		for(size_t j = 0; j < para_2nd._col; ++j)
			if(para_1st._element[i][j] * para_1st._ratio !=
			   para_2nd._element[i][j] * para_2nd._ratio)
				return false;

	return true;
}

//如果两个矩阵行、列或者任一元素不相等，则返回true，否则返回false
template<typename T> bool
operator!=(const BasicMatrix<T>& para_1st, const BasicMatrix<T>& para_2nd)
{
	return !(para_1st == para_2nd);
}

/*
* @重载二元运算符
*/

//当两个矩阵不能相加的时候（行列不相等），会抛出invalid_argument异常
template<typename T> BasicMatrix<T>&
operator+(const BasicMatrix<T>& para_1st, const BasicMatrix<T>& para_2nd)
{
	try
	{
		if(para_1st._row != para_2nd._row || para_1st._col != para_2nd._col)
			throw invalid_argument("Two matrices do not match");
	}
	catch(invalid_argument&)
	{
		throw;
	}

	BasicMatrix<T> _temp_(para_1st._row, para_1st._col);
	for(size_t i = 0; i <  _temp_._row; ++i)
		for(size_t j = 0; j < _temp_._col; ++j)
			_temp_._element[i][j] = para_1st._element[i][j] * para_1st._ratio +
			                        para_2nd._element[i][j] * para_2nd._ratio;
	return _temp_;
}

//当两个矩阵不能相减的时候（行列不相等），会抛出invalid_argument异常
template<typename T> BasicMatrix<T>&
operator-(const BasicMatrix<T>& para_1st, const BasicMatrix<T>& para_2nd)
{
	return para_1st + (-para_2nd);
}

//如果矩阵A的行不等于矩阵B的列，并且矩阵A的列不等于矩阵B的行，也就是说矩阵乘法不能进行
//则抛出invalid_argument异常
template<typename T> BasicMatrix<T>&
operator*(const BasicMatrix<T>& para_1st, const BasicMatrix<T>& para_2nd)
{
	try
	{
		if(para_1st._row != para_2nd._col || para_1st._col != para_2nd._row)
			throw invalid_argument("Two matrices do not match");
	}
	catch(invalid_argument&)
	{
		throw;
	}

	BasicMatrix<T> _temp_(para_2nd._row, para_2nd._col);
	_temp_._ratio = para_1st._ratio * para_2nd._ratio;
	for(size_t i = 0; i < _temp_._row; ++i)
		for(size_t j = 0; j < _temp_._col; ++j)
		{
			_temp_._element[i][j] = static_cast<T>(0);
			for(size_t k = 0; k < para_1st._col; ++k)
				_temp_._element[i][j] += para_1st._element[i][k] *
										 para_2nd._element[k][j];
		}
	return _temp_;
}

//常数乘以矩阵
template<typename T> BasicMatrix<T>&
operator*(const T& para_1st, const BasicMatrix<T>& para_2nd)
{
	BasicMatrix<T> _temp_(para_2nd);
	_temp_._ratio *= para_1st;
	return _temp_;
}

//矩阵乘以常数
template<typename T> BasicMatrix<T>&
operator*(const BasicMatrix<T>& para_1st, const T& para_2nd)
{
	return para_2nd * para_1st;
}

/*
* @成员函数
*/

//如果请求元素超出矩阵范围，则抛出out_of_range异常
//返回位置为(m, n)的元素（数学上）
template<typename T> T&
at(size_t m, size_t n)
{
	try
	{
		if((0 == m) || (m >= this->_row) ||
		   (0 == n) || (n >= this->_col))
			throw out_of_range("Out of range.");
	}
	catch(out_of_range&)
	{
		throw;
	}

	return this->_element[m-1][n-1];
}

typedef BasicMatrix<double> Matrix;

#endif /* MATRIX_H_INCLUDE_GUARD */
