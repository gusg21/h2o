//
// Created by Angus Goucher on 10/13/2024.
//

#include "H2OString.h"

namespace H2O {
    namespace Log {

        void Info(const H2O::String& Text);
        void Warning(const H2O::String& Text);
        void Error(const H2O::String& Text);

        void Assert(bool Condition, const H2O::String& Message);

    }
}
