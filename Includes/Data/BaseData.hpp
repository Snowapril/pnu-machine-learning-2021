// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef BASE_DATA_HPP
#define BASE_DATA_HPP

#include <vector>

namespace Data
{
	//!
	//! \brief Attribute datum wrapper class for storing Various types of data.
	//! \tparam Type - data type
	template <typename Type>
	class BaseData
	{
	public:
		using AttributeType = typename Type;
		using ContainerType = std::vector<AttributeType>;
		using Iterator = typename ContainerType::iterator;
		using ConstIterator = typename ContainerType::const_iterator;
		//! Default constructor
		BaseData() = default;
		//! Generate the base data with give number of attributes
		BaseData(size_t num, AttributeType initialValue = 0);
		//!
		//! \brief constructs a base data with initializer list \p list
		//! 
		//! This constructpr will build a base data with given initializer list \p list
		//! such as
		//! 
		//! \code{.cpp}
		//! BaseData<float> mat = {1.0f, 2.0f, 3.0f, 4.0f};
		//! \endcode
		//! 
		//! \param list - initializer list that should be copy to the new base data.
		//! 
		BaseData(const std::initializer_list<AttributeType>& list);
		//! Default destructor
		virtual ~BaseData() = default;
		//! Returns reference of i-th element
		AttributeType& operator[](size_t i);
		//! Returns const reference of i-th element
		const AttributeType& operator[](size_t i) const;
		//! Returns reference of i-th element
		AttributeType& operator()(size_t i);
		//! Returns const reference of i-th element
		const AttributeType& operator()(size_t i) const;
		//! Resize the number of attributes
		void Resize(size_t num, AttributeType initialValue = 0);
		//!
		//! \brief constructs a base data with initializer list \p list
		//! 
		//! This constructpr will build a base data with given initializer list \p list
		//! such as
		//! 
		//! \code{.cpp}
		//! BaseData<float> mat = {1.0f, 2.0f, 3.0f, 4.0f};
		//! \endcode
		//! 
		//! \param list - initializer list that should be copy to the new base data.
		//! 
		void Set(const std::initializer_list<AttributeType>& list);
		//! Returns new data row + input scalar
		const BaseData<Type> operator+(const AttributeType& scalar);
		//! Returns new data row - input scalar
		const BaseData<Type> operator-(const AttributeType& scalar);
		//! Returns new data row * input scalar
		const BaseData<Type> operator*(const AttributeType& scalar);
		//! Returns new data row / input scalar
		const BaseData<Type> operator/(const AttributeType& scalar);
		//! Returns this data row + input scalar
		BaseData<Type>& operator+=(const AttributeType& scalar);
		//! Returns this data row - input scalar
		BaseData<Type>& operator-=(const AttributeType& scalar);
		//! Returns this data row * input scalar
		BaseData<Type>& operator*=(const AttributeType& scalar);
		//! Returns this data row / input scalar
		BaseData<Type>& operator/=(const AttributeType& scalar);
		//! Returns the total number of elements in this data
		size_t Size() const;
		//! Return iterator of the begin point.
		Iterator begin();
		//! Return iteartor of the end point
		Iterator end();
		//! Return const iterator of the begin point
		ConstIterator cbegin() const;
		//! Return const iterator of the begin point
		ConstIterator cend() const;
	protected:
		ContainerType _attributes;
	private:
	};

	using BaseDataI32 = BaseData<int>;
	using BaseDataF32 = BaseData<float>;
	using BaseDataF64 = BaseData<double>;
};

#include <Data/BaseData-Impl.hpp>
#endif //! end of BaseData.hpp