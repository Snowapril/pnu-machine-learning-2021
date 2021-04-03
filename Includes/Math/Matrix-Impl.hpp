// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <cassert>

namespace Math
{
	template <typename Type, size_t M, size_t N>
	Matrix<Type, M, N>::Matrix<Type, M, N>(const std::initializer_list<std::initializer_list<Type>>& list)
	{
		Set<Type, M, N>(list);
	}

	template <typename Type, size_t M, size_t N>
	void Matrix<Type, M, N>::Set(const std::initializer_list<std::initializer_list<Type>>& list)
	{
		(void)list;
		//! TODO(snowapril) : implement initialize matrix from list.
	}

	template <typename Type, size_t M, size_t N>
	Type& Matrix<Type, M, N>::operator[](size_t i)
	{
		assert(0 <= i && i < M* N);
		return _elements[i];
	}

	template <typename Type, size_t M, size_t N>
	const Type& Matrix<Type, M, N>::operator[](size_t i) const
	{
		assert(0 <= i && i < M* N);
		return _elements[i];
	}

	template <typename Type, size_t M, size_t N>
	Type& Matrix<Type, M, N>::operator()(size_t i, size_t j)
	{
		assert(0 <= i && i < N && 0 <= j && j < M);
		return _elements[i * M + j]
	}

	template <typename Type, size_t M, size_t N>
	const Type& Matrix<Type, M, N>::operator()(size_t i, size_t j) const
	{
		assert(0 <= i && i < N && 0 <= j && j < M);
		return _elements[i * M + j]
	}

	template <typename Type, size_t M, size_t N>
	typename Matrix<Type, M, N>::Iterator Matrix<Type, M, N>::begin()
	{
		return _datasets.begin();
	}

	template <typename Type, size_t M, size_t N>
	typename Matrix<Type, M, N>::Iterator Matrix<Type, M, N>::end()
	{
		return _datasets.end();
	}

	template <typename Type, size_t M, size_t N>
	typename Matrix<Type, M, N>::ConstIterator Matrix<Type, M, N>::cbegin() const
	{
		return _datasets.cbegin();
	}

	template <typename Type, size_t M, size_t N>
	typename Matrix<Type, M, N>::ConstIterator Matrix<Type, M, N>::cend() const
	{
		return _datasets.cend();
	}
};