// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef MATRIX_IMPL_HPP
#define MATRIX_IMPL_HPP

#include <cassert>

namespace Math
{
	template <typename Type>
	Matrix<Type>::Matrix(size_t M, size_t N, const Type& initialValue)
	{
		Resize(M, N, initialValue);
	}

	template <typename Type>
	Matrix<Type>::Matrix(const std::initializer_list<std::initializer_list<Type>>& list)
	{
		Set(list);
	}

	template <typename Type>
	Matrix<Type>::Matrix(const std::vector<RowType>& values)
	{
		Set(values);
	}

	template <typename Type>
	Matrix<Type>::Matrix(Matrix<Type>&& rmat)
	{
		this->_elements = std::move(rmat._elements);
		this->_numCol =  rmat._numCol;
		this->_numRow =  rmat._numRow;
	}

	template <typename Type>
	Matrix<Type>::Matrix(const Matrix<Type>& rmat)
	{
		this->_elements.assign(rmat.cbegin(), rmat.cend());
		this->_numCol = rmat._numCol;
		this->_numRow = rmat._numRow;
	}

	template <typename Type>
	Matrix<Type>& Matrix<Type>::operator=(Matrix<Type>&& rmat)
	{
		if (rmat != *this)
		{
			this->_elements = std::move(rmat._elements);
			this->_numCol = rmat._numCol;
			this->_numRow = rmat._numRow;
		}
		return *this;
	}

	template <typename Type>
	Matrix<Type>& Matrix<Type>::operator=(const Matrix<Type>& rmat)
	{
		if (rmat != *this)
		{
			this->_elements.assign(rmat.cbegin(), rmat.cend());
			this->_numCol = rmat._numCol;
			this->_numRow = rmat._numRow;
		}
		return *this;
	}

	template <typename Type>
	void Matrix<Type>::Resize(size_t M, size_t N, const Type& initialValue)
	{
		_numCol = M; _numRow = N;
		_elements.resize(_numRow, RowType(_numCol, initialValue));
	}

	template <typename Type>
	Matrix<Type> Matrix<Type>::Transposed() const
	{
		Matrix<Type> transposed(_numRow, _numCol);
		for (size_t i = 0; i < _numRow; ++i)
		for (size_t j = 0; j < _numCol; ++j)
			transposed[j][i] = _elements[i][j];
		return transposed;
	}

	template <typename Type>
	void Matrix<Type>::Set(const std::initializer_list<std::initializer_list<Type>>& list)
	{
		assert(list.size() > 0);
		_numRow = list.size();
		_numCol = list.begin()->size();
		_elements.reserve(_numRow);
		for (const auto& row : list)
			_elements.emplace_back(row);
	}

	template <typename Type>
	void Matrix<Type>::Set(const ContainerType& values)
	{
		assert(list.size() > 0);
		_numRow = values.size();
		_numCol = values.begin()->size();
		_elements.assign(values.begin(), values.end());
	}

	template <typename Type>
	void Matrix<Type>::SetRow(const RowType& data, size_t i)
	{
		assert(data.size() == _numCol);
		_elements[i] = data;
	}

	template <typename Type>
	void Matrix<Type>::SetColumn(const RowType& data, size_t i)
	{
		assert(data.size() == _numRow);
		size_t index = 0;
		for (const auto& value : data)
			_elements[index++][i] = value;
	}

	template <typename Type>
	template <typename E>
	Matrix<Type> Matrix<Type>::Mul(const Matrix<E>& matrix) const
	{
		assert(_numCol == matrix._numRow);
		Matrix<Type> resultMat(matrix._numCol, _numRow);

		for (size_t i = 0; i < resultMat._numRow; ++i)
			for (size_t j = 0; j < resultMat._numCol; ++j)
			{
				Type sum{ 0 };
				for (size_t k = 0; k < _numCol; ++k)
					sum += _elements[i][k] * matrix[k][j];
				resultMat[i][j] = sum;
			}

		return resultMat;
	}

	template <typename Type>
	const Matrix<Type> Matrix<Type>::operator+(const Type& scalar) const
	{
		Matrix<Type> matrix(*this);
		matrix += scalar;
		return matrix;
	}

	template <typename Type>
	const Matrix<Type> Matrix<Type>::operator-(const Type& scalar) const
	{
		Matrix<Type> matrix(*this);
		matrix -= scalar;
		return matrix;
	}

	template <typename Type>
	const Matrix<Type> Matrix<Type>::operator*(const Type& scalar) const
	{
		Matrix<Type> matrix(*this);
		matrix *= scalar;
		return matrix;
	}

	template <typename Type>
	const Matrix<Type> Matrix<Type>::operator/(const Type& scalar) const
	{
		Matrix<Type> matrix(*this);
		matrix /= scalar;
		return matrix;
	}

	template <typename Type>
	Matrix<Type>& Matrix<Type>::operator+=(const Type& scalar)
	{
		for (auto& row : _elements)
		for (auto& value : row)
			value += scalar;
		return *this;
	}

	template <typename Type>
	Matrix<Type>& Matrix<Type>::operator-=(const Type& scalar)
	{
		for (auto& row : _elements)
		for (auto& value : row)
			value -= scalar;
		return *this;
	}

	template <typename Type>
	Matrix<Type>& Matrix<Type>::operator*=(const Type& scalar)
	{
		for (auto& row : _elements)
		for (auto& value : row)
			value *= scalar;
		return *this;
	}

	template <typename Type>
	Matrix<Type>& Matrix<Type>::operator/=(const Type& scalar)
	{
		constexpr Type kEpsilon = static_cast<Type>(1e-9);
		for (auto& row : _elements)
		for (auto& value : row)
			value /= (scalar + kEpsilon);
		return *this;
	}

	template <typename Type>
	template <typename E>
	const Matrix<Type> Matrix<Type>::operator+(const Matrix<E>& matrix) const
	{
		assert(_numCol == matrix._numCol && _numRow == matrix._numRow);
		Matrix<Type> resultMat(_numCol, _numRow);
		
		for (size_t i = 0; i < _numRow; ++i)
		for (size_t j = 0; j < _numCol; ++j)
			resultMat[i][j] = _elements[i][j] + matrix[i][j];

		return resultMat;
	}

	template <typename Type>
	template <typename E>
	const Matrix<Type> Matrix<Type>::operator-(const Matrix<E>& matrix) const
	{
		assert(_numCol == matrix._numCol && _numRow == matrix._numRow);
		Matrix<Type> resultMat(_numCol, _numRow);

		for (size_t i = 0; i < _numRow; ++i)
		for (size_t j = 0; j < _numCol; ++j)
			resultMat[i][j] = _elements[i][j] - matrix[i][j];

		return resultMat;
	}

	template <typename Type>
	template <typename E>
	const Matrix<Type> Matrix<Type>::operator*(const Matrix<E>& matrix) const
	{
		assert(_numCol == matrix._numCol && _numRow == matrix._numRow);
		Matrix<Type> resultMat(_numCol, _numRow);

		for (size_t i = 0; i < _numRow; ++i)
			for (size_t j = 0; j < _numCol; ++j)
				resultMat[i][j] = _elements[i][j] * matrix[i][j];

		return resultMat;
	}

	template <typename Type>
	template <typename E>
	Matrix<Type>& Matrix<Type>::operator+=(const Matrix<E>& matrix)
	{
		assert(_numCol == matrix._numCol && _numRow == matrix._numRow);

		for (size_t i = 0; i < _numRow; ++i)
		for (size_t j = 0; j < _numCol; ++j)
			_elements[i][j] += matrix[i][j];

		return *this;
	}

	template <typename Type>
	template <typename E>
	Matrix<Type>& Matrix<Type>::operator-=(const Matrix<E>& matrix)
	{
		assert(_numCol == matrix._numCol && _numRow == matrix._numRow);

		for (size_t i = 0; i < _numRow; ++i)
		for (size_t j = 0; j < _numCol; ++j)
			_elements[i][j] -= matrix[i][j];

		return *this;
	}

	template <typename Type>
	template <typename E>
	Matrix<Type>& Matrix<Type>::operator*=(const Matrix<E>& matrix)
	{
		assert(_numCol == matrix._numCol && _numRow == matrix._numRow);

		for (size_t i = 0; i < _numRow; ++i)
		for (size_t j = 0; j < _numCol; ++j)
			_elements[i][j] *= matrix[i][j];

		return *this;
	}

	template <typename Type>
	typename Matrix<Type>::RowType& Matrix<Type>::operator[](size_t i)
	{
		assert(0 <= i && i < _numRow);
		return _elements[i];
	}

	template <typename Type>
	const typename Matrix<Type>::RowType& Matrix<Type>::operator[](size_t i) const
	{
		assert(0 <= i && i < _numRow);
		return _elements[i];
	}

	template <typename Type>
	Type& Matrix<Type>::operator()(size_t i, size_t j)
	{
		assert(0 <= i && i < _numRow && 0 <= j && j < _numCol);
		return _elements[i][j];
	}

	template <typename Type>
	const Type& Matrix<Type>::operator()(size_t i, size_t j) const
	{
		assert(0 <= i && i < _numRow && 0 <= j && j < _numCol);
		return _elements[i][j];
	}

	template <typename Type>
	size_t Matrix<Type>::Size() const
	{
		return _numRow * _numRow;
	}

	template <typename Type>
	size_t Matrix<Type>::Col() const
	{
		return _numCol;
	}

	template <typename Type>
	size_t Matrix<Type>::Row() const
	{
		return _numRow;
	}

	template <typename Type>
	typename Matrix<Type>::Iterator Matrix<Type>::begin()
	{
		return _elements.begin();
	}

	template <typename Type>
	typename Matrix<Type>::Iterator Matrix<Type>::end()
	{
		return _elements.end();
	}

	template <typename Type>
	typename Matrix<Type>::ConstIterator Matrix<Type>::cbegin() const
	{
		return _elements.cbegin();
	}

	template <typename Type>
	typename Matrix<Type>::ConstIterator Matrix<Type>::cend() const
	{
		return _elements.cend();
	}
};

#endif //! end of Matrix-Impl.hpp
