// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef LOSS_HPP
#define LOSS_HPP

#include <Math/Matrix.hpp>
#include <type_traits>
#include <functional>

namespace Learner
{
	template <typename Type, typename = std::enable_if_t<std::is_floating_point_v<Type>>>
	using LossFunc = std::function<Math::Matrix<Type>(const Math::Matrix<Type>&, const Math::Matrix<Type>&)>;

	namespace Loss
	{
		template <typename Type, typename = std::enable_if_t<std::is_floating_point_v<Type>>>
		Math::Matrix<Type> MeanAbsoluteError(const Math::Matrix<Type>& prediction, const Math::Matrix<Type>& label)
		{
			// TODO(snowapril) : implement this loss function
			return prediction + label;
		}

		template <typename Type, typename = std::enable_if_t<std::is_floating_point_v<Type>>>
		Math::Matrix<Type> MeanSquaredError(const Math::Matrix<Type>& prediction, const Math::Matrix<Type>& label)
		{
			// TODO(snowapril) : implement this loss function
			return prediction + label;
		}
	};
};

#endif //! end of Loss.hpp