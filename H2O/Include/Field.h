//
// Created by Angus Goucher on 10/14/2024.
//

#pragma once

#include "H2OString.h"

namespace H2O {
    class Class;

    class Field {
    public:
        Field() = default;
        Field(Class* Type, const String& Name, void* Offset);

        /**
         * Get a string describing this field.
         * @return The string.
         */
        String ToString() const;

        /**
         * The next field in the linked list.
         */
        Field* NextField = nullptr;

        /**
         * The class representing the type of this field.
         */
        Class* Type = nullptr;

        /**
         * The field's name.
         */
        String Name = "Unknown";

        /**
         * The offset of this field within the class containing it.
         */
        void* Offset = nullptr;
    };
}