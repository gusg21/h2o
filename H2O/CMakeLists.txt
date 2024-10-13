add_library(H2O STATIC

        Source/Class.cc
        Source/String.cc
        Source/Memory.cc

        Include/String.h
        Include/BaseTypes.h
        Include/Memory.h
        Include/Log.h
        Source/Log.cc
        Include/Object.h
        Source/Object.cc
        Include/Array.h

)

target_include_directories(H2O PUBLIC Include)
