//
// Created by Angus Goucher on 10/14/2024.
//

#include "Field.h"
#include "Class.h"

H2O::String H2O::Field::ToString() const {
    H2O::String Str {};

    Str += "Field: (Name: ";
    Str += Name;
    Str += ", Type: ";
    Str += Type->ToString();
    Str += ")";

    return Str;
}
