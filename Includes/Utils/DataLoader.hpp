// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef DATA_LAODER_HPP
#define DATA_LAODER_HPP

#include <vector>
#include <string>

namespace Utils
{
	class DataLoader
	{
	public:
		static bool LoadFile(const std::string& filename, std::vector<char>* contents, bool binaryFlag = false);
	};
};

#endif //! end of BaseLearner.hpp