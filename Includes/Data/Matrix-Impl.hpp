// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <cassert>

namespace Data
{
	template <typename DataType>
	Matrix<DataType>::Matrix(size_t M, size_t N, typename DataType::AttributeType initialValue)
	{
		Resize(M, N, initialValue);
	}

	template <typename DataType>
	Matrix<DataType>::Matrix(const std::initializer_list<DataType>& list)
	{
		Set(list);
	}

	template <typename DataType>
	Matrix<DataType>::Matrix(const std::vector<DataType>& values)
	{
		Set(values);
	}

	template <typename DataType>
	void Matrix<DataType>::Resize(size_t M, size_t N, typename DataType::AttributeType initialValue)
	{
		_numCol = M; _numRow = N;
		_elements.resize(_numRow);
		for (auto& row : _elements)
			row.Resize(_numCol, initialValue);
	}

	template <typename DataType>
	void Matrix<DataType>::Set(const std::initializer_list<DataType>& list)
	{
		assert(list.size() > 0);
		_elements.assign(list);
		_numRow = _elements.size(); 
		_numCol = _elements.front().Size();
	}

	template <typename DataType>
	void Matrix<DataType>::Set(const std::vector<DataType>& values)
	{
		assert(list.size() > 0);
		_elements.assign(values.begin(), values.end());
		_numRow = _elements.size();
		_numCol = _elements.front().Size();
	}

	template <typename DataType>
	void Matrix<DataType>::SetRow(const DataType& data, size_t i)
	{
		assert(data.Size() == _numCol);
		_elements[i] = data;
	}

	template <typename DataType>
	void Matrix<DataType>::SetColumn(const std::initializer_list<typename DataType::AttributeType>& list, size_t i)
	{
		assert(list.size() == _numRow);
		size_t index = 0;
		for (const auto& data : list)
			_elements[index++][i] = data;
	}

	template <typename DataType>
	const Matrix<DataType> Matrix<DataType>::operator+(const typename DataType::AttributeType& scalar)
	{
		Matrix<DataType> matrix(*this);
		matrix += scalar;
		return matrix;
	}

	template <typename DataType>
	const Matrix<DataType> Matrix<DataType>::operator-(const typename DataType::AttributeType& scalar)
	{
		Matrix<DataType> matrix(*this);
		matrix -= scalar;
		return matrix;
	}

	template <typename DataType>
	const Matrix<DataType> Matrix<DataType>::operator*(const typename DataType::AttributeType& scalar)
	{
		Matrix<DataType> matrix(*this);
		matrix *= scalar;
		return matrix;
	}

	template <typename DataType>
	const Matrix<DataType> Matrix<DataType>::operator/(const typename DataType::AttributeType& scalar)
	{
		Matrix<DataType> matrix(*this);
		matrix /= scalar;
		return matrix;
	}

	template <typename DataType>
	Matrix<DataType>& Matrix<DataType>::operator+=(const typename DataType::AttributeType& scalar)
	{
		for (auto& row : _elements)
			row += scalar;
		return *this;
	}

	template <typename DataType>
	Matrix<DataType>& Matrix<DataType>::operator-=(const typename DataType::AttributeType& scalar)
	{
		for (auto& row : _elements)
			row -= scalar;
		return *this;
	}

	template <typename DataType>
	Matrix<DataType>& Matrix<DataType>::operator*=(const typename DataType::AttributeType& scalar)
	{
		for (auto& row : _elements)
			row *= scalar;
		return *this;
	}

	template <typename DataType>
	Matrix<DataType>& Matrix<DataType>::operator/=(const typename DataType::AttributeType& scalar)
	{
		for (auto& row : _elements)
			row /= scalar;
		return *this;
	}

	template <typename DataType>
	template <typename E>
	const Matrix<DataType> Matrix<DataType>::operator+(const Matrix<E>& matrix)
	{
		assert(_numCol == matrix._numCol && _numRow == matrix._numRow);
		Matrix<DataType> resultMat(_numCol, _numRow);
		
		for (size_t i = 0; i < _numRow; ++i)
		for (size_t j = 0; j < _numCol; ++j)
			resultMat[i][j] = _elements[i][j] + matrix[i][j];

		return resultMat;
	}

	template <typename DataType>
	template <typename E>
	const Matrix<DataType> Matrix<DataType>::operator-(const Matrix<E>& matrix)
	{
		assert(_numCol == matrix._numCol && _numRow == matrix._numRow);
		Matrix<DataType> resultMat(_numCol, _numRow);

		for (size_t i = 0; i < _numRow; ++i)
		for (size_t j = 0; j < _numCol; ++j)
			resultMat[i][j] = _elements[i][j] - matrix[i][j];

		return resultMat;
	}

	template <typename DataType>
	template <typename E>
	const Matrix<DataType> Matrix<DataType>::operator*(const Matrix<E>& matrix)
	{
		assert(_numCol == matrix._numRow);
		Matrix<DataType> resultMat(matrix._numCol, _numRow);

		for (size_t i = 0; i < resultMat._numRow; ++i)
		for (size_t j = 0; j < resultMat._numCol; ++j)
		{
			typename DataType::AttributeType sum{ 0 };
			for (size_t k = 0; k < _numCol; ++k)
				sum += _elements[i][k] * matrix[k][j];
			resultMat[i][j] = sum;
		}

		return resultMat;
	}

	template <typename DataType>
	template <typename E>
	Matrix<DataType>& Matrix<DataType>::operator+=(const Matrix<E>& matrix)
	{
		assert(_numCol == matrix._numCol && _numRow == matrix._numRow);

		for (size_t i = 0; i < _numRow; ++i)
		for (size_t j = 0; j < _numCol; ++j)
			_elements[i][j] += matrix[i][j];

		return *this;
	}

	template <typename DataType>
	template <typename E>
	Matrix<DataType>& Matrix<DataType>::operator-=(const Matrix<E>& matrix)
	{
		assert(_numCol == matrix._numCol && _numRow == matrix._numRow);

		for (size_t i = 0; i < _numRow; ++i)
		for (size_t j = 0; j < _numCol; ++j)
			_elements[i][j] -= matrix[i][j];

		return *this;
	}

	template <typename DataType>
	DataType& Matrix<DataType>::operator[](size_t i)
	{
		assert(0 <= i && i < _numRow);
		return _elements[i];
	}

	template <typename DataType>
	const DataType& Matrix<DataType>::operator[](size_t i) const
	{
		assert(0 <= i && i < _numRow);
		return _elements[i];
	}

	template <typename DataType>
	typename DataType::AttributeType& Matrix<DataType>::operator()(size_t i, size_t j)
	{
		assert(0 <= i && i < _numRow && 0 <= j && j < _numCol);
		return _elements[i][j];
	}

	template <typename DataType>
	const typename DataType::AttributeType& Matrix<DataType>::operator()(size_t i, size_t j) const
	{
		assert(0 <= i && i < _numRow && 0 <= j && j < _numCol);
		return _elements[i][j];
	}

	template <typename DataType>
	size_t Matrix<DataType>::Size() const
	{
		return _numRow * _numRow;
	}

	template <typename DataType>
	size_t Matrix<DataType>::Col() const
	{
		return _numCol;
	}

	template <typename DataType>
	size_t Matrix<DataType>::Row() const
	{
		return _numRow;
	}

	template <typename DataType>
	typename Matrix<DataType>::Iterator Matrix<DataType>::begin()
	{
		return _elements.begin();
	}

	template <typename DataType>
	typename Matrix<DataType>::Iterator Matrix<DataType>::end()
	{
		return _elements.end();
	}

	template <typename DataType>
	typename Matrix<DataType>::ConstIterator Matrix<DataType>::cbegin() const
	{
		return _elements.cbegin();
	}

	template <typename DataType>
	typename Matrix<DataType>::ConstIterator Matrix<DataType>::cend() const
	{
		return _elements.cend();
	}
};