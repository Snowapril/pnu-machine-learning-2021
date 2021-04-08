// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Learner/BaseLearner.hpp>

namespace Learner
{
	void BaseLearner::TrainOnBatch(const Generator::BatchGenerator& batchData, size_t batchSize, bool verbose)
	{
		size_t iteration = batchData.GetNumData();
		for (size_t it = 0; it < iteration; it += batchSize)
		{
			const auto batch = batchData.GetBatchData(batchSize, it);
			OnTrain(batch.first, batch.second);
		}
		(void)verbose;
	}

	void BaseLearner::Predict(const Math::FMatrix& data, Math::FMatrix* prediction)
	{
		(void)data;
		(void)prediction;
	}

	void BaseLearner::PredictOnBatch(const Generator::BatchGenerator& batchData, std::vector<Math::FMatrix>* predictions)
	{
		(void)batchData;
		(void)predictions;
	}
};