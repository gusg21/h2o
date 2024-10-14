//
// Created by Angus Goucher on 10/14/2024.
//

#pragma once

#include "H2OString.h"

namespace H2O {
    class Class;

    class Field {
    public:
        String ToString() const;

        Class* Type;
        String Name;
        void* Offset;
    };
}