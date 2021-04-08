#include "pch.h"

#include <Generator/BatchGenerator.hpp>

TEST_CASE("BatchGenerator test")
{
    Generator::BatchGenerator testSet;
    CHECK(testSet.LoadDataSet(DATASETS_DIR "/3d10000.csv", { 3 }) == true);
}