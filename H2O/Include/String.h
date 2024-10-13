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
        explicit String(const CHAR* CStr);

        /**
         * Allocates an empty string with a given capacity.
         * @param Capacity
         */
        explicit String(U32 Capacity);

        /**
         * Clean up the string.
         */
        ~String();

        void Resize(U32 NewCapacity);

        /**
         * Calculate the number of bytes up including the null terminator.
         * @param CStr The bytes to measure.
         * @return The number of bytes.
         */
        static U32 MeasureCStrLength(const CHAR* CStr);

        static String FromNumber(U32 Number);

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

    String operator+(const String& Str1, const String& Str2) {

    }
}