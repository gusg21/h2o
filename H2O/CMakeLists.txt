add_library(H2O STATIC

        Source/Class.cc
        Source/H2OString.cc
        Source/Memory.cc

        Include/H2OString.h
        Include/BaseTypes.h
        Include/Memory.h
        Include/Log.h
        Source/Log.cc
        Include/Object.h
        Source/Object.cc
        Include/Array.h
        Include/H2OMath.h
        Source/H2OMath.cc
        Include/Array.generated.h
        Include/Field.h
        Source/Field.cc

)

target_include_directories(H2O PUBLIC Include)
