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
		bool parsingResult = true;
		if (extension == ".csv")
			parsingResult = Utils::DataLoader::ParseContentsFromCSV(contents, &parsedContents, exceptHeader);
		else if (extension == ".hdf5")
			parsingResult = false;
		else
		{
			std::cerr << "Unknown dataset type : " << extension << std::endl;
			parsingResult = false;
		}

		if (!parsingResult) return false;

		for (const auto& words : parsedContents)
		{
			const size_t numInput = words.size() - targetIndices.size(), numLabel = targetIndices.size();
			Math::FMatrix input(numInput, 1), label(numLabel, 1);
			size_t inputIdx = 0, labelIdx = 0;
			for (size_t i = 0; i < words.size(); ++i)
			{
				const float value = std::stof(words[i]);
				if (std::find(targetIndices.begin(), targetIndices.end(), i) == targetIndices.end())
					input[0][inputIdx++] = value;
				else
					label[0][labelIdx++] = value;
			}
			_inputs.emplace_back(std::move(input));
			_labels.emplace_back(std::move(label));
		}

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