//
// Created by Angus Goucher on 10/13/2024.
//

#include "Class.h"
#include "Field.h"

H2O::Class::Class(const H2O::String& Name)
    : Name(Name), IsPrimitive(false) {
}

H2O::Class::Class(const H2O::String& Name, bool IsPrimitive)
    : Name(Name), IsPrimitive(IsPrimitive) {
}

H2O::String H2O::Class::ToString() const {
    H2O::String Str { };

    if (IsPrimitive) {
        Str += "(Primitive ";
        Str += Name;
        Str += ")";
    } else {
        Str += "(Class Name: ";
        Str += Name;
        Str += ", Fields: ";
        Field* ClassField = FieldHead;
        while (ClassField != nullptr) {
            Str += ClassField->ToString();
            ClassField = ClassField->NextField;
        }
        Str += ")";
    }



    return Str;
}

void H2O::Class::AddField(H2O::Field* field) {
    Field* ClassField = FieldHead;
    if (ClassField == nullptr) {
        FieldHead = field;
        return;
    }

    while (ClassField->NextField != nullptr) {
        ClassField = ClassField->NextField;
    }

    ClassField->NextField = field;
}

H2O::Field* H2O::Class::FindField(const H2O::String& FieldName) const {
    Field* ClassField = FieldHead;
    while (ClassField != nullptr) {
        if (ClassField->Name.ExactlyEquals(FieldName)) {
            return ClassField;
        }
        ClassField = ClassField->NextField;
    }
    return nullptr;
}


