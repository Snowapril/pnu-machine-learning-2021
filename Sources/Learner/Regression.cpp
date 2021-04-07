// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Learner/Regression.hpp>
#include <iostream>

namespace Learner
{
	void Regression::SetLearningRateHandler(LearningRate::LearningRateFunc<float> handler)
	{
		_lrHandler = handler;
	}

	void Regression::AddUnitLayer(const std::shared_ptr<Layer::BaseLayer<float>>& layer)
	{
		_layers.push_back(layer);
	}

	void Regression::Summarize() const
	{
		std::cout << "=====================Model Summary=====================" << std::endl;
		std::cout << "Layer\t\t\tShape\t\t\t#Param" << std::endl;
		std::cout << "-------------------------------------------------------" << std::endl;
		for (const auto& layer : _layers)
		{
			layer->VerbosePrint();
			std::cout << "-------------------------------------------------------" << std::endl;
		}
	}
};