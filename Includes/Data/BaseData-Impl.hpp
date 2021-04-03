// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

namespace Data
{
	template <typename Type>
	typename BaseData<Type>::Iterator BaseData<Type>::begin()
	{
		return _attributes.begin();
	}

	template <typename Type>
	typename BaseData<Type>::Iterator BaseData<Type>::end()
	{
		return _attributes.end();
	}

	template <typename Type>
	typename BaseData<Type>::ConstIterator BaseData<Type>::cbegin() const
	{
		return _attributes.cbegin();
	}

	template <typename Type>
	typename BaseData<Type>::ConstIterator BaseData<Type>::cend() const
	{
		return _attributes.cend();
	}
};