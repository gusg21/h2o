//
// Created by Angus Goucher on 10/13/2024.
//

#pragma once

#include "BaseTypes.h"

namespace H2O {
    namespace Math {

        float Abs(float X);

        I32 Abs(I32 X);

        float Floor(float X);

        I32 FloorToInt(float X);

        float Log10(float X);

        float LogE(float X);

        template <typename T>
        T Min(T A, T B);

        template <typename T>
        T Max(T A, T B);

        float Pow(float Base, float Exponent);

    }
}

template<typename T>
T H2O::Math::Min(T A, T B) {
    return A < B ? A : B;
}

template<typename T>
T H2O::Math::Max(T A, T B) {
    return A > B ? A : B;
}
