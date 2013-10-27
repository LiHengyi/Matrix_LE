/*
 * BasicMatrix.h
 *
 *  Created on: 2013��10��23��
 *      Author: �����
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

protected: //˽�б���
    size_t _ID;

    size_t _row;
    size_t _col;

    T** _element;
    T _ratio;

public: // ����/��������
    //�����캯��
    BasicMatrix<T>(const size_t& n);
    BasicMatrix<T>(const size_t& n, const T& val);
    BasicMatrix<T>(const size_t& n, const T** val_array);
    //һ������캯��
    BasicMatrix<T>(const size_t& m, const size_t& n);
    BasicMatrix<T>(const size_t& m, const size_t& n, const T& val);
    BasicMatrix<T>(const size_t& m, const size_t& n, const T** val_array);
    //�������캯��
    BasicMatrix<T>(BasicMatrix<T>& obj);
    BasicMatrix<T>(BasicMatrix<T>&& obj);

    //��������
    virtual ~BasicMatrix();

public: //����һԪ���������Ա����
    virtual BasicMatrix<T>& operator=(BasicMatrix<T>& obj);
    virtual BasicMatrix<T>& operator=(BasicMatrix<T>&& obj);

    virtual BasicMatrix<T>& operator+();
    virtual BasicMatrix<T>& operator-();

    virtual BasicMatrix<T>& operator()(const T& val);

public: //���ض�Ժ���������Ԫ
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

public: //��Ա����
    virtual T& at(size_t m, size_t n) throw(out_of_range);
};



/**
 * @���캯��
 */

//�����캯������ֵ��ֻ�����ڴ�
template<typename T>
BasicMatrix<T>::BasicMatrix(const size_t& n)
{
	this->_ID = BasicMatrix<T>::_ID_val.size();
	BasicMatrix<T>::_ID_val.push_back(1);

    this->_row = n;                                     //��
    this->_col = n;                                     //��
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

//һ�㷽���캯������ֵ��ֻ�����ڴ�
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

//�������캯��
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
 * @��������
 * �ڴ����������£�ÿ���½����󶼻���һ��ID�������IDҲ����һ����Ӧ�ļ�����
 * 					 ����ʱ���Ȼ��ü������Լ�1����ʾһ�����������������������
 * 					 ���㣨˵���Ѿ�û�ж��󣩣��������Դ�����������㣬����ָ��
 * 					 Ϊ��
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
 * @���������
 */

//��ֵ�����
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

//��ֵ�������������ʱ������ֵ
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
* @����������
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
* @��������ת��
*/
template<typename T> BasicMatrix<T>&
operator()(const T& val)
{
	return BasicMatrix<T>(1, val);
}

/*
* @���رȽ������
*/

//������������С����Լ�����Ԫ�ؾ���ȣ��򷵻�true�����򷵻�false
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

//������������С��л�����һԪ�ز���ȣ��򷵻�true�����򷵻�false
template<typename T> bool
operator!=(const BasicMatrix<T>& para_1st, const BasicMatrix<T>& para_2nd)
{
	return !(para_1st == para_2nd);
}

/*
* @���ض�Ԫ�����
*/

//��������������ӵ�ʱ�����в���ȣ������׳�invalid_argument�쳣
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

//�����������������ʱ�����в���ȣ������׳�invalid_argument�쳣
template<typename T> BasicMatrix<T>&
operator-(const BasicMatrix<T>& para_1st, const BasicMatrix<T>& para_2nd)
{
	return para_1st + (-para_2nd);
}

//�������A���в����ھ���B���У����Ҿ���A���в����ھ���B���У�Ҳ����˵����˷����ܽ���
//���׳�invalid_argument�쳣
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

//�������Ծ���
template<typename T> BasicMatrix<T>&
operator*(const T& para_1st, const BasicMatrix<T>& para_2nd)
{
	BasicMatrix<T> _temp_(para_2nd);
	_temp_._ratio *= para_1st;
	return _temp_;
}

//������Գ���
template<typename T> BasicMatrix<T>&
operator*(const BasicMatrix<T>& para_1st, const T& para_2nd)
{
	return para_2nd * para_1st;
}

/*
* @��Ա����
*/

//�������Ԫ�س�������Χ�����׳�out_of_range�쳣
//����λ��Ϊ(m, n)��Ԫ�أ���ѧ�ϣ�
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
