//
// Created by Angus Goucher on 10/13/2024.
//

#pragma once

#include "H2OString.h"
#include "BaseTypes.h"
#include "Object.h"

namespace H2O {
namespace Test {

    class Actor : H2O::Object {
        DECLARE_CLASS();

    public:
        String Name {};
        U32 Width {};
        U32 Height {};
    };

};
};