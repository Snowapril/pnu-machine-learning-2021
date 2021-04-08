// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef BASE_LEARNER_HPP
#define BASE_LEARNER_HPP

#include <Generator/BatchGenerator.hpp>
#include <Math/Matrix.hpp>
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
		//! Train the learner with the given batch dataset
		void TrainOnBatch(const Generator::BatchGenerator& batchData, size_t numEpoch, bool verbose = true);
		//! Predict the target with one data.
		void Predict(const Math::FMatrix& data, Math::FMatrix* prediction);
		//! Predict the given batch dataset. In this case, there is no modification in parameters of the learner.
		void PredictOnBatch(const Generator::BatchGenerator& batchData, std::vector<Math::FMatrix>* predictions);
		//! Summarize the model
		virtual void Summarize() const = 0;
	protected:
		//! Train on given input matrix and label matrix
		virtual void OnTrain(const Math::FMatrix& input, const Math::FMatrix& label) = 0;
		//! Make prediction on given input matrix and retunrs it.
		virtual Math::FMatrix OnPredict(const Math::FMatrix& input) = 0;
	private:
	};
};

#endif //! end of BaseLearner.hpp