//
// Created by Angus Goucher on 10/13/2024.
//

#include "String.h"
#include "Memory.h"

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
    Data = static_cast<CHAR*>(H2O::Memory::ZeroAllocate(Capacity));
    Size = 1;
    this->Capacity = Capacity;
}

H2O::String::~String() {
    H2O::Memory::Free(Data);
}

void H2O::String::Resize(U32 NewCapacity) {
    if (NewCapacity <= Capacity) {
        return;
    }


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
