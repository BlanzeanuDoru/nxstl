add_executable(examples examples.cpp)
target_compile_features(examples PRIVATE cxx_std_17)

target_link_libraries(examples PRIVATE nxstl)
