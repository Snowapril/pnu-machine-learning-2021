// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.
#include <Generator/MiniBatchGenerator.hpp>

namespace Generator
{
	void MiniBatchGenerator::SetBatchCount(size_t batchCount)
	{
		_numBatch = batchCount;
	}

	MiniBatchGenerator::BatchType MiniBatchGenerator::GetInputBatch(size_t epochIdx)
	{
		(void)epochIdx;
		return std::make_pair(_inputs.begin(), _inputs.end());
	}

	MiniBatchGenerator::BatchType MiniBatchGenerator::GetLabelBatch(size_t epochIdx)
	{
		(void)epochIdx;
		return std::make_pair(_labels.begin(), _labels.end());
	}
};