# This tells the CMake which version will be required to run this config.
cmake_minimum_required(VERSION 3.10) 


# This tells the CMake what would you want to name your Project.
project(MiniDFS)


# This indicates the version number of the C++ that needs to be used.
set(CMAKE_CXX_STANDARD 17)


# This is where you declare the location where you keep
include_directories(${PROJECT_SOURCE_DIR}/include) 
include_directories(${PROJECT_SOURCE_DIR}/include/Crow/include)




# This automatically grab all .cpp files from src/ folder and nodes/ 
file(GLOB_RECURSE SOURCE "src/*.cpp" "nodes/*.cpp")

# Create executable
add_executable(server ${SOURCE})

# Link pthreads (needed by Crow)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(server Threads::Threads)