add_library(H2O STATIC

        Source/Class.cc
        Source/H2OString.cc
        Source/Memory.cc
        Source/Log.cc
        Source/Object.cc
        Source/H2OMath.cc
        Source/Field.cc
        Source/H2OString.generated.cpp

        Include/H2OString.h
        Include/BaseTypes.h
        Include/Memory.h
        Include/Log.h
        Include/Object.h
        Include/Array.h
        Include/H2OMath.h
        Include/Field.h
        Include/BaseReflectedTypes.h
        Include/BaseMacros.h

)

target_include_directories(H2O PUBLIC Include)
