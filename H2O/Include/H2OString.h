//
// Created by Angus Goucher on 10/13/2024.
//

#pragma once

#include "BaseTypes.h"

namespace H2O {
    /**
     * A text string.
     */
    class String {
    public:
        /**
         * Allocate an empty string.
         */
        String();

        /**
         * Copy a raw byte string into this string.
         * @param CStr The bytes to copy from.
         */
        String(const CHAR* CStr);

        /**
         * Allocates an empty string with a given capacity.
         * @param Capacity
         */
        explicit String(U32 Capacity);

        /**
         * Copy constructor.
         */
        String(const String& Other);

        /**
         * Clean up the string.
         */
        ~String();

        /**
         * Move operator.
         */
//        String& operator=(String&& Other) noexcept;

        /**
         * Concatenation operator.
         */
        String& operator+=(const String& Other) noexcept;

        /**
         * Increases the capacity - does not affect size.
         * @param NewCapacity The new capacity.
         */
        void Reserve(U32 NewCapacity);

        /**
         * Populate this string with the text representing a number.
         * @param Number
         * @return
         */
        void FromNumber(I32 Number);

        /**
         * Create a string representing a given integer.
         * @param Number The integer to represent.
         * @return The string.
         */
        static String CreateFromNumber(I32 Number);

        /**
         * Calculate the number of bytes up including the null terminator.
         * @param CStr The bytes to measure.
         * @return The number of bytes.
         */
        static U32 MeasureCStrLength(const CHAR* CStr);

        /**
         * The raw bytes.
         */
        CHAR* Data = nullptr;

        /**
         * The size (including the null terminator) of the string.
         */
        U32 Size = 0;

        /**
         * The number of bytes we have allocated for this string.
         */
        U32 Capacity = 0;
    };

//    /**
//     * An interface that defines a conversion to a string.
//     */
//    class Stringable {
//    public:
//        virtual void ToString() = 0;
//    };
}