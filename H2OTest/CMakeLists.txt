add_executable(H2OTest Source/Main.cc
        Include/Actor.h
)

add_subdirectory(../H2O H2O)

target_link_libraries(H2OTest PRIVATE H2O)