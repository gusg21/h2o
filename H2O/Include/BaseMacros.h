//
// Created by Angus Goucher on 10/15/2024.
//

#pragma once

namespace H2O {
    class Class;
}

#define OFFSET_OF(Type, Member) ((void*)&(((Type*)(nullptr))->Member))

#define DECLARE_CLASS()             \
    public:                         \
        static Class* GetClass();   \
    protected:                      \
        static Class* Z_Class;      \

// If you get a warning about T not being (T), it's wrong.
#define DECLARE_CLASS_T(T)          \
    public:                         \
        template<typename T>        \
        static Class* GetClass();   \
    protected:                      \
        static Class* Z_Class;      \