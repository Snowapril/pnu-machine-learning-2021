// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef BASE_GENERATOR_HPP
#define BASE_GENERATOR_HPP

#include <Data/StructuredData.hpp>
#include <string>
#include <vector>

namespace Generator
{
	template <typename DataType = Data::StructuredDataF32>
	class BaseGenerator
	{
	public:
		using HeaderType = std::vector<std::string>;
		using ContainerType = std::vector<DataType>;
		using Iterator = typename ContainerType::iterator;
		using ConstIterator = typename ContainerType::const_iterator;
		//! Default constructor
		BaseGenerator() = default;
		//! Default destructor
		virtual ~BaseGenerator() = default;
		//! Load the generator from the dataset file.
		bool LoadDataSet(const std::string& filename, bool exceptHeader = true);
		//! Return iterator of the begin point.
		Iterator begin();
		//! Return iteartor of the end point
		Iterator end();
		//! Return const iterator of the begin point
		ConstIterator cbegin() const;
		//! Return const iterator of the begin point
		ConstIterator cend() const;
	protected:
		HeaderType _headers;
		ContainerType _datasets;
	private:
		//! interpret the contents as CSV format and parse the data.
		bool ParseCSVData(const std::vector<char>& contents, bool exceptHeader);
	};
};

#include <Generator/BaseGenerator-Impl.hpp>
#endif //! end of BaseGenerator.hpp