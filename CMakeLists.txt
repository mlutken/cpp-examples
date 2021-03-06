project(cpp_examples)
set (main_exe_name "cpp_examples")


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set (OPTIMIZE_FLAGS "-O2 -g")
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set (OPTIMIZE_FLAGS "-O1 -g")
elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    set (OPTIMIZE_FLAGS "-O3")
endif()


#set(CMAKE_C_FLAGS "${OPTIMIZE_FLAGS}")
#set(CMAKE_CXX_FLAGS "${OPTIMIZE_FLAGS}")
#set(CMAKE_ASM_FLAGS "${OPTIMIZE_FLAGS}" )

add_executable(${main_exe_name}
    # ---------------
    # --- HEADERS ---
    # ---------------


    # --- HEADERS: Modern C++ for C programmers ---
    cpp_for_c_a1_sorting.h

    # --- HEADERS: Other C++ examples ---
    house/solid/our_house.h
    house/dep/my_house.h
    example1.h
    std_function_example1.h
    visitor_example0.h
    visitor_example1.h
    visitor_example2.h

    # --- HEADERS: utilities ---
    example_utils.h
    timer.h

    # Header only files (templates)
    visitor_template_cxx03.h
    visitor_template_cxx11.h

    # ---------------
    # --- SOURCES ---
    # ---------------

    # --- SOURCES: Modern C++ for C programmers ---
    cpp_for_c_a1_sorting.cpp

    # --- SOURCES: Other C++ examples ---
    house/solid/our_house.cpp
    house/dep/my_house.cpp
    example1.cpp
    std_function_example1.cpp
    visitor_example0.cpp
    visitor_example1.cpp
    visitor_example2.cpp

    # --- SOURCES: utilities ---
    example_utils.cpp
    timer.cpp

    # --- main.cpp ---
    main.cpp
    )

set (link_libs "tbb;pthread" )

target_link_libraries(${main_exe_name} "${link_libs}" )
