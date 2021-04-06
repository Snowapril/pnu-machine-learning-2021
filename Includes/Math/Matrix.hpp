// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <initializer_list>
#include <vector>

namespace Math
{
	//!
	//! \brief dynamic sized matrix.
	//! 
	//! This class defined matrix with dynamic size matrix
	//! 
	//! \tparam Type - matrix element type
	//! 
	template <typename Type>
	class Matrix
	{
	public:
		using RowType = std::vector<Type>;
		using ContainerType = std::vector<RowType>;
		using Iterator = typename ContainerType::iterator;
		using ConstIterator = typename ContainerType::const_iterator;
		//! Default constructor
		//! \warning This will generate zero sized matrix (actually it is not a matrix)
		Matrix() = default;
		//! 
		//! \brief Generate initialized matrix with given column length and row length
		//! \param M - number of columns (width)
		//! \param N - number of rows (height)
		//! 
		Matrix(size_t M, size_t N, const Type& initialValue = 0);
		//!
		//! \brief constructs a matrix with given initializer list \p list
		//! 
		//! This constructpr will build a matrix with given initializer list \p list
		//! such as
		//! 
		//! \code{.cpp}
		//! Matrix<float, 3, 4> mat = {
		//!		{1.0f, 2.0f, 3.0f, 4.0f},
		//!		{2.0f, 3.0f, 4.0f, 5.0f},
		//!		{3.0f, 4.0f, 5.0f, 6.0f}
		//! };
		//! \endcode
		//! 
		//! \param list - initializer list that should be copy to the new matrix.
		//! 
		Matrix(const std::initializer_list<std::initializer_list<Type>>& list);
		//! Initialize _attributes with given vector values.
		Matrix(const std::vector<RowType>& values);
		//! Default destructor
		~Matrix() = default;
		//! 
		//! \brief Set the matrix with the new column length and row length.
		//! \param M - number of columns (width)
		//! \param N - number of rows (height)
		//! 
		void Resize(size_t M, size_t N, const Type& initialValue = 0);
		//!
		//! \brief constructs a matrix with given initializer list \p list
		//! 
		//! This constructpr will build a matrix with given initializer list \p list
		//! such as
		//! 
		//! \code{.cpp}
		//! Matrix<float, 3, 4> mat = {
		//!		{1.0f, 2.0f, 3.0f, 4.0f},
		//!		{2.0f, 3.0f, 4.0f, 5.0f},
		//!		{3.0f, 4.0f, 5.0f, 6.0f}
		//! };
		//! \endcode
		//! 
		//! \param list - initializer list that should be copy to the new matrix.
		//! 
		void Set(const std::initializer_list<std::initializer_list<Type>>& list);
		//! Initialize _attributes with given vector values.
		void Set(const std::vector<RowType>& values);
		//! Set elements of the i-th row
		void SetRow(const RowType& data, size_t i);
		//! Set element of the i-th column
		void SetColumn(const RowType& data, size_t i);
		//! Returns new matrix + input scalar
		const Matrix<Type> operator+(const Type& scalar);
		//! Returns new matrix - input scalar
		const Matrix<Type> operator-(const Type& scalar);
		//! Returns new matrix * input scalar
		const Matrix<Type> operator*(const Type& scalar);
		//! Returns new matrix / input scalar
		const Matrix<Type> operator/(const Type& scalar);
		//! Returns this matrix + input scalar
		Matrix<Type>& operator+=(const Type& scalar);
		//! Returns this matrix - input scalar
		Matrix<Type>& operator-=(const Type& scalar);
		//! Returns this matrix * input scalar
		Matrix<Type>& operator*=(const Type& scalar);
		//! Returns this matrix / input scalar
		Matrix<Type>& operator/=(const Type& scalar);
		//! Returns new matrix + input scalar
		template <typename E>
		const Matrix<Type> operator+(const Matrix<E>& matrix);
		//! Returns new matrix - input matrix
		template <typename E>
		const Matrix<Type> operator-(const Matrix<E>& matrix);
		//! Returns new matrix * input matrix
		template <typename E>
		const Matrix<Type> operator*(const Matrix<E>& matrix);
		//! Returns this matrix + input matrix
		template <typename E>
		Matrix<Type>& operator+=(const Matrix<E>& matrix);
		//! Returns this matrix - input matrix
		template <typename E>
		Matrix<Type>& operator-=(const Matrix<E>& matrix);
		//! Returns this matrix * input matrix
		template <typename E>
		Matrix<Type>& operator*=(const Matrix<E>& matrix);
		//! Returns reference of i-th element
		RowType& operator[](size_t i);
		//! Returns const reference of i-th element
		const RowType& operator[](size_t i) const;
		//! Returns reference of (i * M + j)th element
		Type& operator()(size_t i, size_t j);
		//! Returns const reference of (i * M + j)th element
		const Type& operator()(size_t i, size_t j) const;
		//! Returns the total number of elements in this matrix.
		size_t Size() const;
		//! Returns the number of elements in one column
		size_t Col() const;
		//! Returns the number of elements in one row.
		size_t Row() const;
		//! Return iterator of the begin point.
		Iterator begin();
		//! Return iteartor of the end point
		Iterator end();
		//! Return const iterator of the begin point
		ConstIterator cbegin() const;
		//! Return const iterator of the begin point
		ConstIterator cend() const;
	protected:
	private:
		ContainerType _elements;
		size_t _numCol{ 0 }, _numRow{ 0 };
	};

	//! Matrix type aliasings
	using FMatrix = Matrix<float>;
	using DMatrix = Matrix<double>;
};

#include <Math/Matrix-Impl.hpp>
#endif //! end of Matrix.hpp