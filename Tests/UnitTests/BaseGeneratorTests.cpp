#include "pch.h"

#include <Generator/BaseGenerator.hpp>

TEST_CASE("BaseGenerator test")
{
    Generator::BaseGenerator testSet;
    CHECK(testSet.LoadDataSet(DATASETS_DIR "3d10000.csv") == true);
}