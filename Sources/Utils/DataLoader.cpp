// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Utils/DataLoader.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

namespace Utils
{
	bool DataLoader::LoadFile(const std::string& filename, std::vector<char>* contents, bool binaryFlag)
	{
		std::ios::openmode openmode = binaryFlag ? std::ios::in | std::ios::ate | std::ios::binary :
												   std::ios::in | std::ios::ate;
		std::ifstream file(filename, openmode);

		if (file.is_open() == false)
		{
			std::cerr << "Failed to open file : " << filename << std::endl;
			return false;
		}
		
		size_t fileSize = static_cast<size_t>(file.tellg());
		contents->resize(fileSize);
		file.seekg(std::ios::beg);
		file.read(contents->data(), fileSize);
		
		file.close();
		return true;
	}

	bool DataLoader::ParseContentsFromCSV(const std::vector<char>& contents, std::vector<std::vector<std::string>>* parsedContents, bool exceptHeader)
	{
		std::istringstream isstr(std::string(contents.begin(), contents.end()));
		std::string temp;

		//! Remove first line of the csv file.
		if (exceptHeader) 
			std::getline(isstr, temp);

		//! Read one line from the csv file.
		while (std::getline(isstr, temp))
		{
			std::istringstream valueParser(temp);
			std::vector<std::string> datum;
			//! Split the string stripped with ','
			while (std::getline(valueParser, temp, ','))
				datum.push_back(temp);
			parsedContents->emplace_back(std::move(datum));
		}

		return true;
	}
};