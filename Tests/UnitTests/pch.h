//
// pch.h
// Header for standard system include files.
//

#pragma once

#include <iostream>
#include <cmath>
#include <doctest/doctest.h>

#define CHECK_EQUAL(v1, v2) CHECK((v1) == (v2))
#define CHECK_EQUAL_EPSILON(v1, v2, eps) CHECK(std::fabs((v1) - (v2)) <= eps)