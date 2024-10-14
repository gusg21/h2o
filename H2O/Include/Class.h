//
// Created by Angus Goucher on 10/13/2024.
//

#pragma once

#include "H2OString.h"
#include "Array.h"
#include "Field.h"

#define DECLARE_CLASS(CLASS, SUPER, CLASS_FLAGS) \
    public:                                             \
        static constexpr U32 ClassFlags=U32(CLASS_FLAGS);   \
        typedef SUPER Super;                                \
        typedef CLASS ThisClass;                            \
        static Class* GetClass();                           \

namespace H2O {
    class Class {
    public:
        Class(const H2O::String& Name);

        /**
         * Convert this class to a string.
         * @return The string.
         */
        String ToString() const;

        /**
         * The name of this class.
         */
        H2O::String Name = "UnknownClass";

        /**
         * The fields in this class.
         */
        H2O::Array<Field*> Fields {};
    };
}