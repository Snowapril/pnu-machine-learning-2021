// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Learner/BaseLearner.hpp>

namespace Learner
{
	void BaseLearner::Train(const Data::StructuredDataF32& data)
	{
		(void)data;
	}

	void BaseLearner::Predict(const Data::StructuredDataF32& data, Data::StructuredDataF32* prediction)
	{
		(void)data;
		(void)prediction;
	}

	void BaseLearner::TrainOnBatch(const Generator::BaseGenerator<Data::StructuredDataF32>& batchData)
	{
		(void)batchData;
	}

	void BaseLearner::PredictOnBatch(const Generator::BaseGenerator<Data::StructuredDataF32>& batchData,
									 std::vector< Data::StructuredDataF32 >* predictions)
	{
		(void)batchData;
		(void)predictions;
	}
};