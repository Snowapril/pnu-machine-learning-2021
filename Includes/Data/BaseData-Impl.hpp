// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

namespace Data
{
	template <typename Type>
	BaseData<Type>::BaseData(size_t num, AttributeType initialValue)
	{
		Resize(num, initialValue);
	}

	template <typename Type>
	BaseData<Type>::BaseData(const std::initializer_list<AttributeType>& list)
	{
		Set(list);
	}

	template <typename Type>
	typename BaseData<Type>::AttributeType& BaseData<Type>::operator[](size_t i)
	{
		return _attributes[i];
	}

	template <typename Type>
	const typename BaseData<Type>::AttributeType& BaseData<Type>::operator[](size_t i) const
	{
		return _attributes[i];
	}

	template <typename Type>
	typename BaseData<Type>::AttributeType& BaseData<Type>::operator()(size_t i)
	{
		return _attributes[i];
	}

	template <typename Type>
	const typename BaseData<Type>::AttributeType& BaseData<Type>::operator()(size_t i) const
	{
		return _attributes[i];
	}

	template <typename Type>
	void BaseData<Type>::Resize(size_t num, AttributeType initialValue)
	{
		_attributes.resize(num, initialValue);
	}

	template <typename Type>
	void BaseData<Type>::Set(const std::initializer_list<AttributeType>& list)
	{
		_attributes.assign(list);
	}

	template <typename Type>
	const BaseData<Type> BaseData<Type>::operator+(const AttributeType& scalar)
	{
		BaseData<Type> data(*this);
		data += scalar;
		return data;
	}

	template <typename Type>
	const BaseData<Type> BaseData<Type>::operator-(const AttributeType& scalar)
	{
		BaseData<Type> data(*this);
		data -= scalar;
		return data;
	}

	template <typename Type>
	const BaseData<Type> BaseData<Type>::operator*(const AttributeType& scalar)
	{
		BaseData<Type> data(*this);
		data *= scalar;
		return data;
	}

	template <typename Type>
	const BaseData<Type> BaseData<Type>::operator/(const AttributeType& scalar)
	{
		BaseData<Type> data(*this);
		data /= scalar;
		return data;
	}

	template <typename Type>
	BaseData<Type>& BaseData<Type>::operator+=(const AttributeType& scalar)
	{
		for (auto& value : _attributes)
			value += scalar;
		return *this;
	}

	template <typename Type>
	BaseData<Type>& BaseData<Type>::operator-=(const AttributeType& scalar)
	{
		for (auto& value : _attributes)
			value -= scalar;
		return *this;
	}

	template <typename Type>
	BaseData<Type>& BaseData<Type>::operator*=(const AttributeType& scalar)
	{
		for (auto& value : _attributes)
			value *= scalar;
		return *this;
	}

	template <typename Type>
	BaseData<Type>& BaseData<Type>::operator/=(const AttributeType& scalar)
	{
		constexpr Type kEpsilon = static_cast<Type>(1e-9);
		for (auto& value : _attributes)
			value /= (scalar + kEpsilon);
		return *this;
	}


	template <typename Type>
	size_t BaseData<Type>::Size() const
	{
		return _attributes.size();
	}

	template <typename Type>
	typename BaseData<Type>::Iterator BaseData<Type>::begin()
	{
		return _attributes.begin();
	}

	template <typename Type>
	typename BaseData<Type>::Iterator BaseData<Type>::end()
	{
		return _attributes.end();
	}

	template <typename Type>
	typename BaseData<Type>::ConstIterator BaseData<Type>::cbegin() const
	{
		return _attributes.cbegin();
	}

	template <typename Type>
	typename BaseData<Type>::ConstIterator BaseData<Type>::cend() const
	{
		return _attributes.cend();
	}
};