// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Generator/BaseGenerator.hpp>
#include <Utils/DataLoader.hpp>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <iostream>

namespace Generator
{
	BaseGenerator::BaseGenerator(const std::string& filename, const std::initializer_list<size_t>& targetIndices, bool exceptHeader)
	{
		if (!LoadDataSet(filename, targetIndices, exceptHeader))
			std::exit(1);
	}

	bool BaseGenerator::LoadDataSet(const std::string& filename, const std::initializer_list<size_t>& targetIndices, bool exceptHeader)
	{
		std::vector<char> contents;
		if (!Utils::DataLoader::LoadFile(filename, &contents))
		{
			std::cerr << "Failed to open " << filename << std::endl;
			return false;
		}

		const std::string& extension = filename.substr(filename.find_last_of('.'));
		std::vector<std::vector<std::string>> parsedContents;
		if (extension == ".csv")
			return Utils::DataLoader::ParseContentsFromCSV(contents, &parsedContents, exceptHeader);
		else if (extension == ".hdf5")
			return false;
		else
		{
			std::cerr << "Unknown dataset type : " << extension << std::endl;
			return false;
		}

		// TODO(snowapril) : Parse the data from the parsed contents.
		(void)targetIndices;
		return true;
	}

	BaseGenerator::BatchType BaseGenerator::GetInputBatch(size_t epochIdx)
	{
		(void)epochIdx;
		return std::make_pair(_inputs.begin(), _inputs.end());
	}

	BaseGenerator::BatchType BaseGenerator::GetLabelBatch(size_t epochIdx)
	{
		(void)epochIdx;
		return std::make_pair(_labels.begin(), _labels.end());
	}
};