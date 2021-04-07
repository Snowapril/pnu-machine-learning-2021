// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Learner/BaseLearner.hpp>

namespace Learner
{
	void BaseLearner::Train(const Math::FMatrix& data, bool verbose)
	{
		(void)data;
		(void)verbose;
	}

	void BaseLearner::Predict(const Math::FMatrix& data, Math::FMatrix* prediction)
	{
		(void)data;
		(void)prediction;
	}

	void BaseLearner::TrainOnBatch(const std::shared_ptr<Generator::BaseGenerator>& batchData, bool verbose)
	{
		(void)batchData;
		(void)verbose;
	}

	void BaseLearner::PredictOnBatch(const std::shared_ptr<Generator::BaseGenerator>& batchData,
									 std::vector<Math::FMatrix>* predictions)
	{
		(void)batchData;
		(void)predictions;
	}
};