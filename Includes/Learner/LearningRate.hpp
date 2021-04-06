// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef LAERNING_RATE_HPP
#define LAERNING_RATE_HPP

#include <vector>
#include <functional>

namespace Learner
{
	namespace LearningRate
	{
		template <typename Type, typename = std::enable_if_t<std::is_floating_point_v<Type>>>
		using LearningRateFunc = std::function<Type(const Type&, size_t)>;

		//!
		//! \brief return constant learning rate 
		//! \tparam Type - learning rate value type
		//! 
		template <typename Type, typename = std::enable_if_t<std::is_floating_point_v<Type>>>
		Type Constant(const Type& initialLearningRate, size_t epoch)
		{
			(void)epoch;
			return initialLearningRate;
		}

		//!
		//! \brief return decaying learning rate with training epoch number.
		//! \tparam Type - learning rate value type
		//! 
		//! decaying degree is 1000 / (1000 + t)
		//! 
		template <typename Type, typename = std::enable_if_t<std::is_floating_point_v<Type>>>
		Type Decaying(const Type& initialLearningRate, size_t epoch)
		{
			return	initialLearningRate * (1000 / static_cast<Type>(1000 + epoch));
		}
	};
};

#endif //! end of LearningRate.hpp