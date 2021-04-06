// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.
#include <Generator/CrossFoldGenerator.hpp>

namespace Generator
{
	CrossFoldGenerator::BatchType CrossFoldGenerator::GetInputBatch(size_t epochIdx)
	{
		(void)epochIdx;
		return std::make_pair(_inputs.begin(), _inputs.end());
	}

	CrossFoldGenerator::BatchType CrossFoldGenerator::GetLabelBatch(size_t epochIdx)
	{
		(void)epochIdx;
		return std::make_pair(_labels.begin(), _labels.end());
	}
};