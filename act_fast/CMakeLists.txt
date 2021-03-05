cmake_minimum_required(VERSION 2.6)
PROJECT(Act_Fast)

#add_executable("${PROJECT_NAME}" 
#        airborne/modules/computer_vision/lib/vision/act_fast.cpp
#        airborne/modules/computer_vision/lib/vision/fast_rosten.cpp
#        airborne/modules/computer_vision/lib/vision/image.cpp
#        airborne/modules/computer_vision/lib/vision/lucas_kanade.cpp
#        )

set(ActFast_HEADERS
        state.hpp
        include/std.hpp
        include/message_pragmas.hpp
        airborne/math/pprz_algebra.hpp
        airborne/math/pprz_algebra_float.hpp
        airborne/math/pprz_algebra_int.hpp
        airborne/math/pprz_geodetic.hpp
        airborne/math/pprz_geodetic_float.hpp
        airborne/math/pprz_geodetic_int.hpp
        airborne/math/pprz_orientation_conversion.hpp
        airborne/math/pprz_trig_int.hpp
        airborne/modules/computer_vision/lib/v4l/v4l2.hpp
        airborne/modules/computer_vision/lib/vision/fast_rosten.hpp
        airborne/modules/computer_vision/lib/vision/image.hpp
        airborne/modules/computer_vision/lib/vision/lucas_kanade.hpp
        )

set(ActFast_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/airborne/modules/computer_vision/lib/vision/act_fast.cpp
        airborne/modules/computer_vision/lib/vision/fast_rosten.cpp
        airborne/modules/computer_vision/lib/vision/image.cpp
        airborne/modules/computer_vision/lib/vision/lucas_kanade.cpp
        )

find_package (OpenCV 2.4.11 EXACT REQUIRED)

add_library(
        act_fast
        ${ActFast_SRC}
        ${ActFast_HEADERS}
        ${OpenCV_LIBS}
)

target_include_directories(act_fast PUBLIC 
                ${CMAKE_CURRENT_SOURCE_DIR};
                ${CMAKE_CURRENT_SOURCE_DIR}/include;
                ${CMAKE_CURRENT_SOURCE_DIR}/airborne/lib/vision;
                ${CMAKE_CURRENT_SOURCE_DIR}/airborne;
                ${CMAKE_CURRENT_SOURCE_DIR}/airborne/math;airborne/modules/computer_vision;
                ${OpenCV_INCLUDE_DIRS})
#target_link_libraries(${PROJECT_NAME}
#                      ${OpenCV_LIBS})
#install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
#install(FILES "act_fast.cpp" DESTINATION airborne/math/modules/computer/vision/lib/vision/)

#set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE C)
