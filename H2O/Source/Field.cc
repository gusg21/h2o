//
// Created by Angus Goucher on 10/14/2024.
//

#include "Field.h"
#include "Class.h"

H2O::String H2O::Field::ToString() const {
    H2O::String Str { };

    Str += "(Field Name: ";
    Str += Name;
    Str += ", Type: ";
    Str += Type->ToString();
    Str += ", Offset: ";
    Str += String::CreateFromNumber((INTPTR)Offset);
    Str += ")";

    return Str;
}

H2O::Field::Field(H2O::Class* Type, const H2O::String& Name, void* Offset)
    : Type(Type), Name(Name), Offset(Offset) { }
