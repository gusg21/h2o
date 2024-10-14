//
// Created by Angus Goucher on 10/13/2024.
//

#include "H2OString.h"
#include "Memory.h"
#include "H2OMath.h"
#include "Log.h"

H2O::String::String() {
    // Initialize an empty string (one null termination byte)
    Data = static_cast<CHAR*>(H2O::Memory::ZeroAllocate(1));
    Size = 1;
    Capacity = 1;
}

H2O::String::String(const CHAR* CStr) {
    // Copy CStr to Data

    // TODO: Is it possible to do this O(n) instead of O(2n)?
    U32 CStrLength = MeasureCStrLength(CStr);

    Data = static_cast<CHAR*>(H2O::Memory::Allocate(CStrLength));
    H2O::Memory::Copy(Data, CStrLength, (void*)CStr);

    Size = CStrLength;
    Capacity = CStrLength;

}

H2O::String::String(U32 Capacity) {
    Size = 1;
    this->Capacity = Capacity;
    Data = static_cast<CHAR*>(H2O::Memory::ZeroAllocate(Capacity));
}

H2O::String::String(const H2O::String& Other) {
    Size = Other.Size;
    Capacity = Other.Capacity;
    Data = static_cast<CHAR*>(H2O::Memory::ZeroAllocate(Capacity));
    H2O::Memory::Copy(Data, Size, Other.Data);
}

H2O::String::~String() {
    H2O::Memory::Free(Data);

//    H2O::Log::Info("Cleaning string...");
}

void H2O::String::Reserve(U32 NewCapacity) {
    if (NewCapacity <= Capacity) {
        return;
    }

    U32 OldCapacity = Capacity;
    CHAR* OldData = Data;

    Capacity = NewCapacity;
    Data = static_cast<CHAR*>(H2O::Memory::Allocate(Capacity * sizeof(CHAR)));

    H2O::Memory::Copy(Data, OldCapacity, OldData);

    delete OldData;
}

U32 H2O::String::MeasureCStrLength(const CHAR* CStr) {
    const CHAR* Char = CStr;
    U32 Count = 0;

    while (*Char != '\0') {
        Count++;
        Char++;
    }

    return Count + 1;
}

void H2O::String::FromNumber(I32 Number) {
    if (Number == 0) {
        // Special case for "0".
        Capacity = 2;
        Size = Capacity;
        delete Data;
        Data = static_cast<CHAR*>(H2O::Memory::ZeroAllocate(Capacity));
        *Data = '0';
    } else {
        // Convert digits to integers and put them in the string.
        I32 DigitCount = H2O::Math::FloorToInt(H2O::Math::Log10(H2O::Math::Abs((float)Number))) + 1;
        I32 DigitCountWithoutNegative = DigitCount;
        if (Number < 0) {
            DigitCount += 1; // Account for "-".
        }

        Capacity = DigitCount + 1;
        Size = Capacity;
        delete Data;
        Data = static_cast<CHAR*>(H2O::Memory::ZeroAllocate(Capacity));
        CHAR* Char = Data;
        if (Number < 0) {
            // Add the "-".
            *Char = '-';
            Char++;
        }

        for (I32 Power = DigitCountWithoutNegative - 1; Power >= 0; --Power) {
            I32 Digit = (I32)(H2O::Math::Abs((float)Number) / H2O::Math::Pow(10, (float)Power)) % 10;
            *Char = '0' + static_cast<CHAR>(Digit);
            Char++;
        }
    }
}

H2O::String H2O::String::CreateFromNumber(I32 Number) {
    H2O::String Str {};
    Str.FromNumber(Number);
    return Str;
}

//H2O::String& H2O::String::operator=(H2O::String&& Other)  noexcept {
//    // Don't self-assign
//    if (this == &Other) return *this;
//
//    delete Data;
//    Capacity = Other.Capacity;
//    Size = Other.Size;
//    Data = static_cast<CHAR*>(H2O::Memory::ZeroAllocate(Capacity));
//    H2O::Memory::Copy(Data, Size, Other.Data);
//
//    return *this;
//}

H2O::String& H2O::String::operator+=(const H2O::String& Other) noexcept {
    U32 OldSize = Size;
    CHAR* OldData = Data;

    Size += Other.Size - 1;
    Capacity = H2O::Math::Max(Capacity, Size);
    Data = static_cast<CHAR*>(H2O::Memory::ZeroAllocate(Capacity));

    H2O::Memory::Copy(Data, OldSize, OldData);
    H2O::Memory::Copy(Data + OldSize - 1, Other.Size, Other.Data);
    // Copy over our null terminator, the other string should have one.

    return *this;
}
