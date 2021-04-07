// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef BASE_LAYER_HPP
#define BASE_LAYER_HPP

#include <Math/Matrix.hpp>
#include <type_traits>

namespace Layer
{
	template <typename Type>
	class BaseLayer
	{
	public:
		using InputType = Math::Matrix<Type>;
		using OutputType = Math::Matrix<Type>;
		//! Default constructor
		BaseLayer() = default;
		//! Default destructor
		virtual ~BaseLayer() = default;
		//! Forward propagation
		virtual OutputType Forward(const InputType& input) const = 0;
		//! Backward propagation
		virtual OutputType Backward(const InputType& input) const = 0;
		//! Verbose print this layer
		virtual void VerbosePrint() const = 0;
	protected:
	};
};

#endif //! end of BaseLayer.hpp
