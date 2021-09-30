cmake_minimum_required(VERSION 3.5)

#########################################################################################
# Define the TargetName which will be the name of the lib/exe that is created by this file.
# This is also the name of the cmake 'Target'
#########################################################################################
SET (TargetName ConsoleExample)

#########################################################################################
# Define a project name if none is given so a generated solution has an appropriate name
# A project name may have already been defined at a higher level in the build hierarchy
# A project name not necessarily need to be given for every library thats built
#########################################################################################
if (NOT PROJECT_NAME)
	project(${TargetName})
endif()

# Enable C++11 on linux
set (CMAKE_CXX_STANDARD 11)

#########################################################################################
# Files
#########################################################################################

# Files required to build
set (SOURCE_FILES console.cpp)

#######################################################################################
# Includes and libs
#######################################################################################

# Enable pthread library
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread")

include_directories(../KromekDriver/include ../SpectrometerDriver)
add_executable(${TargetName} ${SOURCE_FILES})

target_link_libraries(${TargetName} SpectrometerDriver)

# Structure the vs output folders
#set_target_folder(${TargetName})
