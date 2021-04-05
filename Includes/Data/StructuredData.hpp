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
		//! Generate the base data with give number of attributes
		StructuredData(size_t num, AttributeType initialValue = 0);
		//!
		//! \brief constructs a base data with initializer list \p list
		//! 
		//! This constructpr will build a base data with given initializer list \p list
		//! such as
		//! 
		//! \code{.cpp}
		//! BaseData<float> mat = {1.0f, 2.0f, 3.0f, 4.0f};
		//! \endcode
		//! 
		//! \param list - initializer list that should be copy to the new base data.
		//! 
		StructuredData(const std::initializer_list<AttributeType>&list);
		//! Initialize _attributes with given vector values.
		StructuredData(const std::vector<AttributeType>& values);
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