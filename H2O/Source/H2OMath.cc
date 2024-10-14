//
// Created by Angus Goucher on 10/13/2024.
//

#include "H2OMath.h"

#include <math.h>

float H2O::Math::Abs(float X) {
    return ::fabsf(X);
}

I32 H2O::Math::Abs(I32 X) {
    return ::abs(X);
}

float H2O::Math::Log10(float X) {
    return ::log10f(X);
}

float H2O::Math::Floor(float X) {
    return ::floorf(X);
}

I32 H2O::Math::FloorToInt(float X) {
    return static_cast<I32>(Floor(X));
}

float H2O::Math::LogE(float X) {
    return ::logf(X);
}

float H2O::Math::Pow(float Base, float Exponent) {
    return ::powf(Base, Exponent);
}

