// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef BASE_DATA_HPP
#define BASE_DATA_HPP

#include <vector>

namespace Data
{
	//!
	//! \brief Attribute datum wrapper class for storing Various types of data.
	//! \tparam Type - data type
	template <typename Type>
	class BaseData
	{
	public:
		using ContainerType = std::vector<Type>;
		using Iterator = typename ContainerType::iterator;
		using ConstIterator = typename ContainerType::const_iterator;
		//! Default constructor
		BaseData() = default;
		//! Default destructor
		virtual ~BaseData() = default;
		//! Return iterator of the begin point.
		Iterator begin();
		//! Return iteartor of the end point
		Iterator end();
		//! Return const iterator of the begin point
		ConstIterator cbegin() const;
		//! Return const iterator of the begin point
		ConstIterator cend() const;
	protected:
		ContainerType _attributes;
	private:
	};

	using BaseDataI32 = BaseData<int>;
	using BaseDataF32 = BaseData<float>;
	using BaseDataF64 = BaseData<double>;
};

#include <Data/BaseData-Impl.hpp>
#endif //! end of BaseData.hpp