//
// Created by Angus Goucher on 10/13/2024.
//

#include "BaseTypes.h"
#include "Class.h"
#include "String.h"
#include "Log.h"
#include "Array.h"

I16 main(I16 ArgumentCount, CHAR* Arguments[]) {
    H2O::String Str1 = H2O::String("Hello World!");

    H2O::Log::Info(Str1);

    H2O::Array<U32> Numbers {};
    for (U32 i = 0; i < 20; ++i) {
        Numbers.Add(i);
        H2O::Log::Info(H2O::String());
    }

    return 0;
}