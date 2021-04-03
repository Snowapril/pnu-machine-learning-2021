// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef MINI_BATCH_GENERATOR_HPP
#define MINI_BATCH_GENERATOR_HPP

#include <Generator/BaseGenerator.hpp>

namespace Generator
{
	template <typename DataType = Data::StructuredDataF32>
	class MiniBatchGenerator : public BaseGenerator<DataType>
	{
	public:
		//! Default constructor
		MiniBatchGenerator() = default;
		//! Default destructor
		~MiniBatchGenerator() = default;
	protected:
	private:
	};
};

#include <Generator/MiniBatchGenerator-Impl.hpp>
#endif //! end of MiniBatchGenerator.hpp