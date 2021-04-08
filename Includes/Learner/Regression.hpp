// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef REGRESSION_HPP
#define REGRESSION_HPP

#include <Learner/BaseLearner.hpp>
#include <Learner/LearningRate.hpp>
#include <Layer/BaseLayer.hpp>
#include <vector>
#include <functional>

namespace Learner
{
	//! 
	//! \brief
	//! 
	class Regression : public BaseLearner
	{
	public:
		//! Default constructor
		Regression() = default;
		//! Default destructor
		~Regression() = default;
		//! Add unit calculation layer
		void AddUnitLayer(const std::shared_ptr<Layer::BaseLayer<float>>& layer);
		//! Set learning rate handler function
		void SetLearningRateHandler(LearningRate::LearningRateFunc<float> handler);
		//! Summarize the model
		void Summarize() const override;
	protected:
		//! Train on given input matrix and label matrix
		void OnTrain(const Math::FMatrix& input, const Math::FMatrix& label) override;
		//! Make prediction on given input matrix and retunrs it.
		Math::FMatrix OnPredict(const Math::FMatrix& input) override;

		std::vector<std::shared_ptr<Layer::BaseLayer<float>>> _layers;
		LearningRate::LearningRateFunc<float> _lrHandler { LearningRate::Constant<float> };
	protected:
	private:
	};
};

#endif //! end of Regression.hpp