// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef BASE_LEARNER_HPP
#define BASE_LEARNER_HPP

#include <Data/StructuredData.hpp>
#include <Generator/BaseGenerator.hpp>
#include <vector>
#include <type_traits>

namespace Learner
{
	namespace Activation
	{
		template <typename Type, typename = std::is_floating_point_v<Type>>
		inline Type ForwardSigmoid(const Type& val)
		{
			return 1 / static_cast<Type>(1 + std::exp(-val));
		}

		template <typename Type, typename = std::is_floating_point_v<Type>>
		inline Type BackwardSigmoid(const Type& val)
		{
			const Type forwardSigmoidCache = FowradSigmoid(val);
			return forwardSigmoidCache * (1 - forwardSigmoidCache);
		}

		template <typename Type, typename = std::is_floating_point_v<Type>>
		inline Type ForwardReLU(const Type& val)
		{
			return val >= 0 ? val : 0;
		}

		template <typename Type, typename = std::is_floating_point_v<Type>>
		inline Type BackwardReLU(const Type& val)
		{
			return val >= 0 ? 1 : 0;
		}

		template <typename Type, typename = std::is_floating_point_v<Type>>
		inline Type ForwardTanH(const Type& val)
		{
			return std::tanh(val);
		}

		template <typename Type, typename = std::is_floating_point_v<Type>>
		inline Type BackwardTanH(const Type& val)
		{
			const Type fowardTanHCache = ForwardTanH(val);
			return 1 - fowardTanHCache * fowardTanHCache;
		}
	};
};

#endif //! end of Activation.hpp