// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef BATCH_GENERATOR_HPP
#define BATCH_GENERATOR_HPP

#include <Math/Matrix.hpp>
#include <string>
#include <vector>

namespace Generator
{
	class BatchGenerator
	{
	public:
		using DataType = Math::FMatrix;
		using ContainerType = std::vector<DataType>;
		using Iterator = typename ContainerType::iterator;
		using ConstIterator = typename ContainerType::const_iterator;
		using BatchType = std::pair<DataType, DataType>;
		//! Default constructor
		BatchGenerator() = default;
		//! Constructure with dataset informations
		BatchGenerator(const std::string& filename, const std::initializer_list<size_t>& targetIndices, bool exceptHeader = true);
		//! Default destructor
		~BatchGenerator() = default;
		//! Load the generator from the dataset file.
		bool LoadDataSet(const std::string& filename, const std::initializer_list<size_t>& targetIndices, bool exceptHeader = true);
		//! Returns input & label vector batch data according to given epochIndex.
		BatchType GetBatchData(size_t batchSize, size_t idx) const;
		//! Returns iteration count for given batch size.
		size_t GetNumData() const;
	private:
		ContainerType _inputs;
		ContainerType _labels;
		size_t _inputLength{ 0 }, _labelLength{ 0 };
		size_t _numData{ 0 };
	};
};

#endif //! end of BatchGenerator.hpp