// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef CROSS_FOLD_GENERATOR_HPP
#define CROSS_FOLD_GENERATOR_HPP

#include <Generator/BaseGenerator.hpp>

namespace Generator
{
	class CrossFoldGenerator : public BaseGenerator
	{
	public:
		using DataType = Math::FMatrix;
		using ContainerType = std::vector<DataType>;
		using Iterator = typename ContainerType::iterator;
		using ConstIterator = typename ContainerType::const_iterator;
		using BatchType = std::pair<ConstIterator, ConstIterator>;
		//! Default constructor
		CrossFoldGenerator() = default;
		//! Default destructor
		~CrossFoldGenerator() = default;
		//! Generate begin, end point pair of the input dataset vector in one epoch
		BatchType GetInputBatch(size_t epochIdx) override;
		//! Generate begin, end point pair of the label dataset vector in one epoch
		BatchType GetLabelBatch(size_t epochIdx) override;
	protected:
	private:
	};
};

#endif //! end of CrossFoldGenerator.hpp