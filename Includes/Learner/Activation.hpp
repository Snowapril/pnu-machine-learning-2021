// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef ACTIVATION_HPP
#define ACTIVATION_HPP

#include <type_traits>
#include <functional>
#include <cmath>

namespace Learner
{
	namespace Activation
	{
		template <typename Type, typename = std::enable_if_t<std::is_floating_point_v<Type>>>
		using ActivationFunc = std::function<Type(const Type&)>;

		template <typename Type, typename = std::enable_if_t<std::is_floating_point_v<Type>>>
		class Sigmoid
		{
		public:
			inline static Type Forward(const Type& val)
			{
				return 1 / static_cast<Type>(1 + std::exp(-val));
			}

			inline static Type Backward(const Type& val)
			{
				const Type forwardSigmoidCache = Forward(val);
				return forwardSigmoidCache * (1 - forwardSigmoidCache);
			}
		};

		template <typename Type, typename = std::enable_if_t<std::is_floating_point_v<Type>>>
		class TanH
		{
		public:
			inline static Type Forward(const Type& val)
			{
				return std::tanh(val);
			}

			inline static Type Backward(const Type& val)
			{
				const Type fowardTanHCache = Forward(val);
				return 1 - fowardTanHCache * fowardTanHCache;
			}
		};

		template <typename Type, typename = std::enable_if_t<std::is_floating_point_v<Type>>>
		class ReLU
		{
		public:
			inline static Type Forward(const Type& val)
			{
				return val >= 0 ? val : 0;
			}

			inline static Type Backward(const Type& val)
			{
				return val >= 0 ? 1 : 0;
			}
		};
	};
};

#endif //! end of Activation.hpp
