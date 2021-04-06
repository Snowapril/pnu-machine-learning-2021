// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef BASE_GENERATOR_HPP
#define BASE_GENERATOR_HPP

#include <Math/Matrix.hpp>
#include <string>
#include <vector>

namespace Generator
{
	class BaseGenerator
	{
	public:
		using DataType = Math::FMatrix;
		using ContainerType = std::vector<DataType>;
		using Iterator = typename ContainerType::iterator;
		using ConstIterator = typename ContainerType::const_iterator;
		using BatchType = std::pair<ConstIterator, ConstIterator>;
		//! Default constructor
		BaseGenerator() = default;
		//! Constructure with dataset informations
		BaseGenerator(const std::string& filename, const std::initializer_list<size_t>& targetIndices, bool exceptHeader = true);
		//! Default destructor
		virtual ~BaseGenerator() = default;
		//! Load the generator from the dataset file.
		bool LoadDataSet(const std::string& filename, const std::initializer_list<size_t>& targetIndices, bool exceptHeader = true);
		//! Generate begin, end point pair of the input dataset vector in one epoch
		virtual BatchType GetInputBatch(size_t epochIdx);
		//! Generate begin, end point pair of the label dataset vector in one epoch
		virtual BatchType GetLabelBatch(size_t epochIdx);
	protected:
		ContainerType _inputs;
		ContainerType _labels;
	private:
	};
};

#endif //! end of BaseGenerator.hpp