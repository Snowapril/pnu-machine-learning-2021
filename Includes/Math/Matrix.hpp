// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <initializer_list>
#include <array>

namespace Math
{
	//!
	//! \brief static sized M x N matrix.
	//! 
	//! This class defined matrix with static size M x N.
	//! 
	//! \tparam Type - matrix element type
	//! \tparam M - The number of columns
	//! \tparam N - The number of rows
	//! 
	template <typename Type, size_t M, size_t N>
	class Matrix
	{
	public:
		static_assert(M > 0, "Number of rows for the static sized matrix must be greater than zero");
		static_assert(N > 0, "Number of colums for the static sized matrix must be greater than zero");
		using ContainerType = std::array<Type, M* N>;
		using Iterator = typename ContainerType::iterator;
		using ConstIterator = typename ContainerType::const_iterator;
		//! Default constructor
		//! \warning This will generate zero matrix, not the unit diagonal matrix.
		Matrix() = default;
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
		//! Default destructor
		~Matrix() = default;
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
		//! Returns reference of i-th element
		Type& operator[](size_t i);
		//! Returns const reference of i-th element
		const Type& operator[](size_t i) const;
		//! Returns reference of (i * M + j)th element
		Type& operator()(size_t i, size_t j);
		//! Returns const reference of (i * M + j)th element
		const Type& operator()(size_t i, size_t j) const;
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
	};
};

#include <Math/Matrix-Impl.hpp>
#endif //! end of Matrix.hpp