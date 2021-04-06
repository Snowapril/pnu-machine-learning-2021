// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef REGRESSION_HPP
#define REGRESSION_HPP

#include <Learner/BaseLearner.hpp>
#include <Learner/Activation.hpp>
#include <Learner/LearningRate.hpp>
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
		//!
		//! \brief simple dense layer structure
		//! \tparam Type - weight values type
		//! 
		template <typename Type, typename = std::enable_if_t<std::is_floating_point_v<Type>>>
		struct Dense
		{
			Math::Matrix<Type> weights;
			Activation::ActivationFunc<Type> activationForward;
			Activation::ActivationFunc<Type> activationBackward;
		};
		//! 
		//! \brief Add dense layer with matrix and activation function.
		//! \tparam ActivationType - this can be Activation::Sigmoid, Activation::ReLU, etc..
		//! \tparam WeightInitializer - this can be WeightInitializer::Zero or WeightInitializer::XavierUniform
		template <typename ActivationType, typename WeightInitializer>
		void AddDenseLayer(size_t numInput, size_t numOutput, WeightInitializer initializer)
		{
			if (!_denseLayers.empty())
				assert(_denseLayers.back().weights.Col() == numInput);

			Dense<float> denseLayer;
			denseLayer.weights.Resize(numInput, numOutput);
			initializer(denseLayer.weights);
			denseLayer.activationForward = ActivationType::Forward;
			denseLayer.activationBackward = ActivationType::Backward;
			_denseLayers.emplace_back(std::move(denseLayer));
		}
		//! Set learning rate handler function
		void SetLearningRateHandler(LearningRate::LearningRateFunc<float> handler);
	protected:
		std::vector< Dense<float> > _denseLayers;
		LearningRate::LearningRateFunc<float> _lrHandler { LearningRate::Constant<float> };
	protected:
	private:
	};
};

#endif //! end of Regression.hpp