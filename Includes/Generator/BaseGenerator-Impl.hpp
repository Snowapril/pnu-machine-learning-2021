// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Utils/DataLoader.hpp>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <iostream>

namespace Generator
{
	template <typename DataType>
	bool BaseGenerator<DataType>::LoadDataSet(const std::string& filename, bool exceptHeader)
	{
		std::vector<char> contents;
		if (!Utils::DataLoader::LoadFile(filename, &contents))
		{
			std::cerr << "Failed to open " << filename << std::endl;
			return false;
		}

		const std::string& extension = filename.substr(filename.find_last_of('.'));
		if (extension == ".csv")
			return ParseCSVData(contents, exceptHeader);
		else if (extension == ".hdf5")
			return false;
		else
		{
			std::cerr << "Unknown dataset type : " << extension << std::endl;
			return false;
		}
	}

	template <typename DataType>
	bool BaseGenerator<DataType>::ParseCSVData(const std::vector<char>& contents, bool exceptHeader)
	{
		std::istringstream isstr(std::string(contents.begin(), contents.end()));
		
		std::string temp;
		if (!exceptHeader)
		{
			std::getline(isstr, temp);
			std::istringstream headerParser(temp);
			std::string header;
			while (std::getline(headerParser, header, ','))
				_headers.push_back(header);
		}

		while (std::getline(isstr, temp))
		{
			std::vector<typename DataType::AttributeType> data;
			std::istringstream valueParser(temp);
			std::string value;
			while (std::getline(valueParser, value, ','))
				data.push_back(static_cast<typename DataType::AttributeType>(std::stod(value)));
			_datasets.push_back(DataType(data));
		}

		return true;
	}

	template <typename DataType>
	typename BaseGenerator<DataType>::Iterator BaseGenerator<DataType>::begin()
	{
		return _datasets.begin();
	}

	template <typename DataType>
	typename BaseGenerator<DataType>::Iterator BaseGenerator<DataType>::end()
	{
		return _datasets.end();
	}

	template <typename DataType>
	typename BaseGenerator<DataType>::ConstIterator BaseGenerator<DataType>::cbegin() const
	{
		return _datasets.cbegin();
	}

	template <typename DataType>
	typename BaseGenerator<DataType>::ConstIterator BaseGenerator<DataType>::cend() const
	{
		return _datasets.cend();
	}
};