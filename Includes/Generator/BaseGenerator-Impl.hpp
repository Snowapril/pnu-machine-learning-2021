// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#include <Utils/DataLoader.hpp>
#include <sstream>
#include <iterator>
#include <algorithm>

namespace Generator
{
	template <typename DataType>
	bool BaseGenerator<DataType>::LoadDataSet(const std::string& filename, bool exceptHeader)
	{
		std::vector<char> contents;
		Utils::DataLoader::LoadFile(filename, &contents);

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
		std::ostringstream osstr;
		std::copy(contents.begin(), contents.end(), std::ostream_iterator<char>(osstr));
		//! TODO(snowapril) : implement parsing csv data.
		(void)osstr;
		(void)exceptHeader;
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