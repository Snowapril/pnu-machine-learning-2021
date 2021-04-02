// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef BASE_LEARNER_HPP
#define BASE_LEARNER_HPP

#include <Data/BaseData.hpp>
#include <Generator/BaseGenerator.hpp>
#include <vector>

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
		void Train(const Data::BaseData& data);
		//! Predict the target with one data.
		void Predict(const Data::BaseData& data, Data::BaseData& prediction);
		//! Train the learner with the given batch dataset
		void TrainOnBatch(const Generator::BaseGenerator& batchData);
		//! Predict the given batch dataset. In this case, there is no modification in parameters of the learner.
		void PredictOnBatch(const Generator::BaseGenerator& batchData, std::vector< Data::BaseData >& predictions);
	protected:
	private:
	};
};

#endif //! end of BaseLearner.hpp