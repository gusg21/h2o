//
// Created by Angus Goucher on 10/13/2024.
//

#pragma once

#include <String.h>

#define DECLARE_CLASS(CLASS, SUPER, CLASS_FLAGS) \
    public:                                             \
        static constexpr U32 ClassFlags=U32(CLASS_FLAGS);   \
        typedef SUPER Super;                                \
        typedef CLASS ThisClass;                            \
        static Class* GetClass();                           \

namespace H2O {
    class Class {
    public:
        Class() = delete;

        H2O::String Name;
    };
}