// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef ACTIVATION_HPP
#define ACTIVATION_HPP

#include <Layer/BaseLayer.hpp>
#include <iostream>
#include <cmath>

namespace Layer
{
	template <typename Type>
	class Activation : public BaseLayer<Type>
	{
	public:
		//! Default constructor
		Activation() = default;
		//! Default destructor
		~Activation() = default;
		//! Forward propagation
		virtual OutputType Forward(const InputType & input) const override = 0;
		//! Backward propagation
		virtual OutputType Backward(const InputType & input) const override = 0;
		//! Verbose print this layer
		virtual void VerbosePrint() const override = 0;
	};

	template <typename Type>
	class Sigmoid : public Activation<Type>
	{
	public:
		//! Default constructor
		Sigmoid() = default;
		//! Default destructor
		~Sigmoid() = default;
		//! Forward propagation
		OutputType Forward(const InputType & input) const override
		{
			const size_t M = input.Col(), N = input.Row();
			OutputType output(M, N);
			for (size_t i = 0; i < N; ++i)
			{
				for (size_t j = 0; j < M; ++j)
					output[i][j] = 1 / static_cast<Type>(1 + std::exp(-input[i][j]));
			}
			return output;
		}
		//! Backward propagation
		OutputType Backward(const InputType & input) const override
		{
			const size_t M = input.Col(), N = input.Row();
			OutputType output(M, N);
			for (size_t i = 0; i < N; ++i)
			{
				for (size_t j = 0; j < M; ++j)
				{
					const Type forwardSigmoidCache = 1 / static_cast<Type>(1 + std::exp(-input[i][j]));
					output[i][j] = forwardSigmoidCache * (1 - forwardSigmoidCache);
				}
			}
			return output;
		}
		//! Verbose print this layer
		void VerbosePrint() const override
		{
			std::cout << "Sigmoid\t\t\t" << std::endl;
		}
	};

	template <typename Type>
	class TanH : public Activation<Type>
	{
	public:
		//! Default constructor
		TanH() = default;
		//! Default destructor
		~TanH() = default;
		//! Forward propagation
		OutputType Forward(const InputType & input) const override
		{
			const size_t M = input.Col(), N = input.Row();
			OutputType output(M, N);
			for (size_t i = 0; i < N; ++i)
			{
				for (size_t j = 0; j < M; ++j)
				{
					output[i][j] = std::tanh(input[i][j]);
				}
			}
			return output;
		}
		//! Backward propagation
		OutputType Backward(const InputType & input) const override
		{
			const size_t M = input.Col(), N = input.Row();
			OutputType output(M, N);
			for (size_t i = 0; i < N; ++i)
			{
				for (size_t j = 0; j < M; ++j)
				{
					const Type fowardTanHCache = std::tanh(input[i][j]);
					output[i][j] = 1 - fowardTanHCache * fowardTanHCache;
				}
			}
			return output;
		}
		//! Verbose print this layer
		void VerbosePrint() const override
		{
			std::cout << "TanH\t\t\t" << std::endl;
		}
	};

	template <typename Type>
	class ReLU : public Activation<Type>
	{
	public:
		//! Default constructor
		ReLU() = default;
		//! Default destructor
		~ReLU() = default;
		//! Forward propagation
		OutputType Forward(const InputType & input) const override
		{
			const size_t M = input.Col(), N = input.Row();
			OutputType output(M, N);
			for (size_t i = 0; i < N; ++i)
			{
				for (size_t j = 0; j < M; ++j)
				{
					output[i][j] = input[i][j] >= 0 ? input[i][j] : 0;
				}
			}
			return output;
		}
		//! Backward propagation
		OutputType Backward(const InputType & input) const override
		{
			const size_t M = input.Col(), N = input.Row();
			OutputType output(M, N);
			for (size_t i = 0; i < N; ++i)
			{
				for (size_t j = 0; j < M; ++j)
				{
					output[i][j] = input[i][j] >= 0 ? 1 : 0;
				}
			}
		}
		//! Verbose print this layer
		void VerbosePrint() const override
		{
			std::cout << "ReLU\t\t\t" << std::endl;
		}
	};
};

#endif //! end of Activation.hpp
