//
// Created by Angus Goucher on 10/13/2024.
//

#include "Memory.h"

#include <stdlib.h>

void* H2O::Memory::Allocate(U32 Size) {
    return ::malloc(Size);
}

void* H2O::Memory::ZeroAllocate(U32 Size) {
    void* Allocation = Allocate(Size);
    char* AllocationBytes = static_cast<char*>(Allocation);

    for (U32 i = 0; i < Size; ++i) {
        AllocationBytes[i] = 0;
    }

    return Allocation;
}

void H2O::Memory::Free(void* Memory) {
    ::free(Memory);
}

void H2O::Memory::Copy(void* To, U32 ToSize, void* From) {
    char* ToBytes = static_cast<char*>(To);
    char* FromBytes = static_cast<char*>(From);

    // Copy byte by byte
    for (U32 i = 0; i < ToSize; ++i) {
        ToBytes[i] = FromBytes[i];
    }
}


