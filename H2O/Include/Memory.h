//
// Created by Angus Goucher on 10/13/2024.
//

#pragma once

#include "BaseTypes.h"

namespace H2O {
    namespace Memory {
        void* Allocate(U32 Size);
        void* ZeroAllocate(U32 Size);
        void Free(void* Memory);
        void Copy(void* To, U32 ToSize, void* From);
    }
}