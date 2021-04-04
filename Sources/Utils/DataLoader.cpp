// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Utils/DataLoader.hpp>
#include <iostream>
#include <fstream>

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
};