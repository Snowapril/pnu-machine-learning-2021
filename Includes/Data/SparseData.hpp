// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef SPARSE_DATA_HPP
#define SPARSE_DATA_HPP

#include <Data/BaseData.hpp>

namespace Data
{
	template <typename Type>
	class SparseData final : public BaseData<Type>
	{
	public:
		using AttributeType = Type;
		using ContainerType = std::vector<AttributeType>;
		using Iterator = typename ContainerType::iterator;
		using ConstIterator = typename ContainerType::const_iterator;
		//! Default constructor
		SparseData() = default;
		//! Default destructor
		~SparseData() = default;
	protected:
	private:
	};

	using SparseDataI32 = SparseData<int>;
	using SparseDataF32 = SparseData<float>;
	using SparseDataF64 = SparseData<double>;
};

#include <Data/SparseData-Impl.hpp>
#endif //! end of SparseData.hpp