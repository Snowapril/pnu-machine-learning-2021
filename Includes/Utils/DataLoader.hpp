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
		//! load file and pass the contents to given vector argument.
		static bool LoadFile(const std::string& filename, std::vector<char>* contents, bool binaryFlag = false);
		//! interpret the contents as CSV format and parse string contents
		static bool ParseContentsFromCSV(const std::vector<char>& contents, std::vector<std::vector<std::string>>* parsedContents, bool exceptHeader);
	};
};

#endif //! end of BaseLearner.hpp