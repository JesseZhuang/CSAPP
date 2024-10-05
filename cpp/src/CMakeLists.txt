file(GLOB_RECURSE INC_FILES ./*/*.hpp)
file(GLOB_RECURSE SRC_FILES ./*/*.cpp)

set(LIB_NAME ${CMAKE_PROJECT_NAME}_lib)
add_library(${LIB_NAME} INTERFACE)
target_sources(${LIB_NAME}
        PUBLIC
        ${INC_FILES}
        ${SRC_FILES}
)
