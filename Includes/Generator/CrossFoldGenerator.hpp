// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CROSS_FOLD_GENERATOR_HPP
#define CROSS_FOLD_GENERATOR_HPP

#include <Generator/BaseGenerator.hpp>

namespace Generator
{
	template <typename DataType = Data::StructuredDataF32>
	class CrossFoldGenerator : public BaseGenerator<DataType>
	{
	public:
		//! Default constructor
		CrossFoldGenerator() = default;
		//! Default destructor
		~CrossFoldGenerator() = default;
	protected:
	private:
	};
};

#include <Generator/CrossFoldGenerator-Impl.hpp>
#endif //! end of CrossFoldGenerator.hpp