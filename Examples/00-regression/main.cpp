// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <iostream>
#include <Generator/BaseGenerator.hpp>
#include <Learner/Regression.hpp>
#include <Layer/Initializer.hpp>
#include <Layer/Dense.hpp>
#include <Layer/Activation.hpp>
#include <memory>

int main(int argc, char* argv[])
{
	(void)argc; (void)argv;
	const bool verbose = true;

	const std::initializer_list<size_t> targetIndices = { 3 };
	auto trainSet = std::make_shared<Generator::BaseGenerator>(DATASETS_DIR "/3d100a.csv", targetIndices);
	auto testSet  = std::make_shared<Generator::BaseGenerator>(DATASETS_DIR "/3d100b.csv", targetIndices);

	Learner::Regression regressionLearner;
	regressionLearner.AddUnitLayer(std::make_shared<Layer::Dense<float>>(4, 1, Layer::Initializer::XavierUniform<float>));
	regressionLearner.AddUnitLayer(std::make_shared<Layer::Sigmoid<float>>());
	regressionLearner.Summarize();

	regressionLearner.TrainOnBatch(trainSet, verbose);

	std::vector<Math::FMatrix> prediction;
	regressionLearner.PredictOnBatch(testSet, &prediction);
	
	return 0;
}