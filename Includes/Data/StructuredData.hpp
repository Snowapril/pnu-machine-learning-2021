// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef STRUCTURED_DATA_HPP
#define STRUCTURED_DATA_HPP

#include <Data/BaseData.hpp>

namespace Data
{
	template <typename Type>
	class StructuredData final : public BaseData<Type>
	{
	public:
		using AttributeType = typename Type;
		using ContainerType = std::vector<AttributeType>;
		using Iterator = typename ContainerType::iterator;
		using ConstIterator = typename ContainerType::const_iterator;
		//! Default constructor
		StructuredData() = default;
		//! Default destructor
		~StructuredData() = default;
	protected:
	private:
	};

	using StructuredDataI32 = StructuredData<int>;
	using StructuredDataF32 = StructuredData<float>;
	using StructuredDataF64 = StructuredData<double>;
};

#include <Data/StructuredData-Impl.hpp>
#endif //! end of StructuredData.hpp