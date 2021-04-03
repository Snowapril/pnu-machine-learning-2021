// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <iostream>
#include <Generator/BaseGenerator.hpp>
#include <Learner/Regression.hpp>

int main(int argc, char* argv[])
{
	(void)argc; (void)argv;
	Learner::Regression regressionLearner;

	Generator::BaseGenerator trainSet, testSet;
	trainSet.LoadDataSet(DATASETS_DIR "/3d100a.csv");
	testSet .LoadDataSet(DATASETS_DIR "/3d100b.csv");

	regressionLearner.TrainOnBatch(trainSet);

	std::vector<Data::StructuredDataF32> prediction;
	regressionLearner.PredictOnBatch(testSet, &prediction);
	
	return 0;
}