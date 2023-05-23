cmake_minimum_required (VERSION 3.8)

project (dynamic-neural-field-composer 
    VERSION 1.0.0 
    DESCRIPTION "Sandbox repository to test the making of data structures available in the C++ std library.")

add_library(data-structures
	"src/array.cpp"
 "src/vector.cpp")
	
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET data-structures PROPERTY CXX_STANDARD 20)
endif()

target_include_directories(data-structures PUBLIC ${PROJECT_SOURCE_DIR}/include)

add_executable(launch-data-structures
    "src/data-structures.cpp"
)

target_link_libraries(launch-data-structures PRIVATE data-structures)