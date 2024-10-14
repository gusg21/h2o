//
// Created by Angus Goucher on 10/13/2024.
//

#pragma once

#include "BaseTypes.h"
#include "Memory.h"
#include "Object.h"
#include "Array.generated.h"

#define H2O_ARRAY_DEFAULT_CAPACITY 2

namespace H2O {
    /**
     * A dynamic array.
     */
    template <typename ItemType>
    class Array : public Object {
        DECLARE_CLASS(Array, Object, 0);

    public:
        Array();
        explicit Array(U32 Capacity);

        void Reserve(U32 NewCapacity);

        /**
         * Add an item to the end of the array.
         * @param Item The item to add.
         */
        void Add(ItemType Item);

        /**
         * Gets a pointer to the first element of the array.
         * @return A pointer to the first element.
         */
        ItemType* GetFirst() const;

        /**
         * Gets a pointer to the last element of the array.
         * @return A pointer to the last element.
         */
        ItemType* GetLast() const;

        /**
         * Converts the array to a string.
         * @return A string representing the array.
         */
        String ToString();

        /**
         * The raw data itself.
         */
        ItemType* Data = nullptr;

        /**
         * How many items are currently in the array?
         */
        U32 Size = 0;

        /**
         * How many items do we have memory allocated for?
         */
        U32 Capacity = 0;
    };

    template<typename ItemType>
    Array<ItemType>::Array() {
        // Empty array.
        Size = 0;
        Capacity = H2O_ARRAY_DEFAULT_CAPACITY;
        Data = static_cast<ItemType*>(H2O::Memory::Allocate(Capacity * sizeof(ItemType)));
    }

    template<typename ItemType>
    Array<ItemType>::Array(U32 Capacity) {
        Size = 0;
        this->Capacity = Capacity;
        Data = static_cast<ItemType*>(H2O::Memory::Allocate(Capacity * sizeof(ItemType)));
    }

    template<typename ItemType>
    void Array<ItemType>::Reserve(U32 NewCapacity) {
        if (NewCapacity <= Capacity) return;

        U32 OldCapacity = Capacity;
        ItemType* OldData = Data;

        Capacity = NewCapacity;
        Data = static_cast<ItemType*>(H2O::Memory::Allocate(Capacity * sizeof(ItemType)));

        H2O::Memory::Copy(Data, OldCapacity * sizeof(ItemType), OldData);

        delete OldData;
    }

    template<typename ItemType>
    void Array<ItemType>::Add(ItemType Item) {
        if (Size + 1 > Capacity)
            Reserve(Capacity * 2);

        // Add to the array
        Data[Size] = Item;
        Size++;
    }

    template<typename ItemType>
    ItemType* Array<ItemType>::GetFirst() const {
        return Data;
    }

    template<typename ItemType>
    ItemType* Array<ItemType>::GetLast() const {
        return Data + Size - 1;
    }

    template<typename ItemType>
    String Array<ItemType>::ToString() {
        String Str {};
        Str += "[S: ";
        Str += String::CreateFromNumber(Size);
        Str += ", \tC: ";
        Str += String::CreateFromNumber(Capacity);
        Str += "] ";

        for (U32 i = 0; i < Size; i++) {
            Str += String::CreateFromNumber(Data[i]);
            Str += ", ";
        }
        return Str;
    }
}
