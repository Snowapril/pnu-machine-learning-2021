// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef BASE_LEARNER_HPP
#define BASE_LEARNER_HPP

#include <Math/Matrix.hpp>
#include <Generator/BaseGenerator.hpp>
#include <memory>

namespace Learner
{
	class BaseLearner
	{
	public:
		//! Default constructor
		BaseLearner() = default;
		//! Default destructor
		virtual ~BaseLearner() = default;
		//! Train the learner with one data
		void Train(const Math::FMatrix& data);
		//! Predict the target with one data.
		void Predict(const Math::FMatrix& data, Math::FMatrix* prediction);
		//! Train the learner with the given batch dataset
		void TrainOnBatch(const std::shared_ptr<Generator::BaseGenerator>& batchData);
		//! Predict the given batch dataset. In this case, there is no modification in parameters of the learner.
		void PredictOnBatch(const std::shared_ptr<Generator::BaseGenerator>& batchData,
							std::vector<Math::FMatrix>* predictions);
	protected:
	private:
	};
};

#endif //! end of BaseLearner.hpp