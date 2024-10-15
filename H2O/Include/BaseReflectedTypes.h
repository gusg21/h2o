//
// Created by Angus Goucher on 10/15/2024.
//

#pragma once

#include "BaseTypes.h"
#include "Class.h"

namespace H2O {

    namespace BaseReflectedTypes {
        H2O::Class* Z_U32_Class = nullptr;
        H2O::Class* Z_I32_Class = nullptr;

        H2O::Class* U32_GetClass() {
            if (Z_U32_Class == nullptr) {
                Z_U32_Class = new Class("U32", true);
            }
            return Z_U32_Class;
        }

        H2O::Class* I32_GetClass() {
            if (Z_I32_Class == nullptr) {
                Z_I32_Class = new Class("I32", true);
            }
            return Z_I32_Class;
        }
    }

}
