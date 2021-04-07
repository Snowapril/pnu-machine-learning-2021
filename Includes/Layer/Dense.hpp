// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef DENSE_HPP
#define DENSE_HPP

#include <Layer/BaseLayer.hpp>
#include <Layer/Initializer.hpp>
#include <iostream>

namespace Layer
{
	template <typename Type>
	class Dense : public BaseLayer<Type>
	{
	public:
		//! Default constructor
		Dense(size_t M, size_t N, WeightInitializer<Type> initializer = Initializer::Constant<Type>)
		{
			_weights.Resize(M, N);
			initializer(_weights, 0.0f);
		}
		//! Default destructor
		~Dense() = default;
		//! Forward propagation
		OutputType Forward(const InputType& input) const override
		{
			return _weights.Mul(input);
		}
		//! Backward propagation
		OutputType Backward(const InputType& input) const override
		{
			// TODO(snowapril) : implement weight derivation
			return _weights.Mul(input);
		}
		//! Verbose print this layer
		void VerbosePrint() const override
		{
			std::cout << "Dense\t\t\t" << "(" << _weights.Col() << ", " << _weights.Row() << ")\t\t\t" 
					  << _weights.Col() * _weights.Row() << std::endl;
		}
	protected:
		Math::Matrix<Type> _weights;
	};
};

#endif //! end of Dense.hpp
