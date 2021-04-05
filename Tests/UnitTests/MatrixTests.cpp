#include "pch.h"

#include <Data/Matrix.hpp>

TEST_CASE("Matrix access Test")
{
    Data::Matrix<Data::BaseDataF32> matrix{
        {1.0f, 2.0f, 3.0f, 4.0f},
        {3.0f, 5.0f, 7.0f, 9.0f}
    };

    CHECK_EQUAL_EPSILON(matrix[1][2], 7.0f, 1e-9f);
}

TEST_CASE("Matrix multiplication Test")
{
    Data::Matrix<Data::BaseDataF32> mat1{
        {1.0f, 2.0f, 3.0f, 4.0f}
    };

    Data::Matrix<Data::BaseDataF32> mat2{
        {1.0f}, 
        {1.0f}, 
        {1.0f}, 
        {1.0f}
    };

    auto resultMat = mat1 * mat2;

    CHECK_EQUAL_EPSILON(resultMat(0, 0), 10.0f, 1e-9f);
}

TEST_CASE("Matrix addition Test")
{
    Data::Matrix<Data::BaseDataF32> mat1{
        {1.0f, 2.0f, 3.0f, 4.0f}
    };

    Data::Matrix<Data::BaseDataF32> mat2{
        {1.0f, 2.0f, 3.0f, 4.0f}
    };

    auto resultMat = mat1 + mat2;

    CHECK_EQUAL_EPSILON(resultMat(0, 2), 6.0f, 1e-9f);
}

TEST_CASE("Matrix substraction Test")
{
    Data::Matrix<Data::BaseDataF32> mat1{
        {1.0f, 2.0f, 3.0f, 4.0f}
    };

    Data::Matrix<Data::BaseDataF32> mat2{
        {1.0f, 2.0f, 3.0f, 4.0f}
    };

    auto resultMat = mat1 - mat2;

    CHECK_EQUAL_EPSILON(resultMat(0, 2), 0.0f, 1e-9f);
}

TEST_CASE("Matrix scalar multiplication Test")
{
    Data::Matrix<Data::BaseDataF32> matrix{
        {1.0f, 2.0f, 3.0f, 4.0f},
        {3.0f, 5.0f, 7.0f, 9.0f}
    };

    matrix *= 10;

    CHECK_EQUAL_EPSILON(matrix(1, 2), 70.0f, 1e-9f);
}

TEST_CASE("Matrix scalar addition Test")
{
    Data::Matrix<Data::BaseDataF32> matrix{
        {1.0f, 2.0f, 3.0f, 4.0f},
        {3.0f, 5.0f, 7.0f, 9.0f}
    };

    matrix += 10;

    CHECK_EQUAL_EPSILON(matrix(1, 2), 17.0f, 1e-9f);
}

TEST_CASE("Matrix scalar substraction Test")
{
    Data::Matrix<Data::BaseDataF32> matrix{
        {1.0f, 2.0f, 3.0f, 4.0f},
        {3.0f, 5.0f, 7.0f, 9.0f}
    };

    matrix -= 10;

    CHECK_EQUAL_EPSILON(matrix(1, 2), -3.0f, 1e-9f);
}

TEST_CASE("Matrix scalar division Test")
{
    Data::Matrix<Data::BaseDataF32> matrix{
        {1.0f, 2.0f, 3.0f, 4.0f},
        {3.0f, 5.0f, 7.0f, 9.0f}
    };

    matrix /= 10;

    CHECK_EQUAL_EPSILON(matrix(1, 2), 0.7f, 1e-9f);
}

TEST_CASE("Matrix SetRow Test")
{
    Data::Matrix<Data::BaseDataF32> matrix{
        {1.0f, 2.0f, 3.0f, 4.0f},
        {3.0f, 5.0f, 7.0f, 9.0f}
    };

    matrix.SetRow({ 0.0f, 0.0f, 0.0f, 0.0f }, 1);

    CHECK_EQUAL_EPSILON(matrix(1, 2), 0.0f, 1e-9f);
}

TEST_CASE("Matrix SetColumn Test")
{
    Data::Matrix<Data::BaseDataF32> matrix{
        {1.0f, 2.0f, 3.0f, 4.0f},
        {3.0f, 5.0f, 7.0f, 9.0f}
    };

    matrix.SetColumn({ 0.0f, 0.0f }, 2);

    CHECK_EQUAL_EPSILON(matrix(1, 2), 0.0f, 1e-9f);
}