//
// Created by Angus Goucher on 10/13/2024.
//

#include "Class.h"
#include "Field.h"

H2O::Class::Class(const H2O::String& Name) {
    this->Name = Name;
}

H2O::String H2O::Class::ToString() const {
    H2O::String Str {};

    Str += "Class: ";
    Str += Name;
    Str += "\nFields: ";
    for (Field** ClassField = Fields.GetFirst(); ClassField <= Fields.GetLast(); ClassField++) {
        Str += (*ClassField)->ToString();
    }

    return Str;
}
