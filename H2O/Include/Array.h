//
// Created by Angus Goucher on 10/13/2024.
//

#pragma once

#include "BaseTypes.h"
#include "Memory.h"

#define H2O_ARRAY_DEFAULT_CAPACITY 2

namespace H2O {
    /**
     * A dynamic array.
     */
    template <typename ItemType>
    class Array {
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

        H2O::Memory::Copy(Data, OldCapacity, OldData);

        delete OldData;
    }

    template<typename ItemType>
    void Array<ItemType>::Add(ItemType Item) {
        // TODO: Reserve more than enough to make one-after-another additions faster?
        Reserve(Size + 1);

        // Add to the array
        Data[Size] = Item;
        Size++;

//        static_assert(Size < Capacity, "Array size is too big for the capacity!");
    }
}
