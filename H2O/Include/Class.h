//
// Created by Angus Goucher on 10/13/2024.
//

#pragma once

#include "H2OString.h"
#include "Field.h"



namespace H2O {
    class Class {
    public:
        explicit Class(const H2O::String& Name);
        Class(const H2O::String& Name, bool IsPrimitive);

        /**
         * Convert this class to a string.
         * @return The string.
         */
        String ToString() const;

        /**
         * Register a new field on this Class.
         * @param field
         */
        void AddField(Field* field);

        /**
         * Find a field in this class' field linked list.
         * TODO: Useful place for a "Name" class instead of a "String"
         * @return A pointer to the field. Will return nullptr if not found.
         */
        Field* FindField(const String& FieldName) const;

        template<typename FieldType>
        FieldType ReadField()

        /**
         * The name of this class.
         */
        H2O::String Name = "UnknownClass";

        /**
         * The fields in this class.
         */
        Field* FieldHead { };

    protected:
        /**
         * Is this a primitive type?
         */
        bool IsPrimitive;
    };
}