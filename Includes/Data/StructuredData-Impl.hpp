// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

namespace Data
{
	template <typename Type>
	StructuredData<Type>::StructuredData(size_t num, AttributeType initialValue)
		: BaseData<Type>(num, initialValue)
	{
		//! Do nothing
	}

	template <typename Type>
	StructuredData<Type>::StructuredData(const std::initializer_list<AttributeType>& list)
		: BaseData<Type>(list)
	{
		//! Do nothing
	}

	template <typename Type>
	StructuredData<Type>::StructuredData(const std::vector<AttributeType>& values)
		: BaseData<Type>(values)
	{
		//! Do nothing
	}
};