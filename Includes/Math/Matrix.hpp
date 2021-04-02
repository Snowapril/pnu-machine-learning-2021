// Copyright (c) 2021, Jihong Shin

// We are making my contributions/submissions to this project solely in our
// personal capacity and are not conveying any rights to any intellectual
// property of any third parties.

#ifndef MATRIX_HPP
#define MATRIX_HPP

namespace Math
{
	template <typename Type, size_t M, size_t N>
	class Matrix
	{
	public:
		static_assert(M > 0, "Number of rows for the static sized matrix must be greater than zero");
		static_assert(N > 0, "Number of colums for the static sized matrix must be greater than zero");
		//! Default constructor
		//! \warning This will generate zero matrix, not the unit diagonal matrix.
		Matrix() = default;
		//! Default destructor
		~Matrix() = default;
	protected:
	private:
	};
};

#endif //! end of Matrix.hpp