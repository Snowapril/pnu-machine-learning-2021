// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef INITIALIZER_HPP
#define INITIALIZER_HPP

#include <Math/Matrix.hpp>
#include <type_traits>
#include <functional>

namespace Layer
{
	template <typename Type, typename = std::enable_if_t<std::is_floating_point_v<Type>>>
	using WeightInitializer = std::function<void(Math::Matrix<Type>&, const Type&)>;

	namespace Initializer
	{
		//!
		//! \brief initialize weight matrix with constant value 
		//! \tparam Type - weight matrix data type
		//! \param weight - target weight matrix
		//! \param constant - constant value for initialized weight value
		//! 
		template <typename Type, typename = std::enable_if_t<std::is_floating_point_v<Type>>>
		void Constant(Math::Matrix<Type>& weight, const Type& constant)
		{
			for (size_t i = 0; i < weight.Row(); ++i)
				for (size_t j = 0; j < weight.Col(); ++j)
					weight[i][j] = constant;
		}

		//!
		//! \brief initialize weight matrix with xavier uniform distribution
		//! \tparam Type - weight matrix data type
		//! \param weight - target weight matrix
		//! \param constant - xavier uniform distribution parameter
		//! 
		template <typename Type, typename = std::enable_if_t<std::is_floating_point_v<Type>>>
		void XavierUniform(Math::Matrix<Type>& weight, const Type& parameter)
		{
			// TODO(snowapril) : must implement xavier uniform initialization.

			for (size_t i = 0; i < weight.Row(); ++i)
				for (size_t j = 0; j < weight.Col(); ++j)
					weight[i][j] = parameter;
		}
	};
};

#endif //! end of Initializer.hpp