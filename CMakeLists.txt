cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME chuanchuankou)

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME}
        Core/LCD/piccc.h
        Core/LCD/tct.c
        Core/LCD/delay.c
        Core/LCD/lcd_ex.c
        Core/LCD/lcd.c
        Core/LCD/led.c
        Core/LCD/sys.c
        Core/Src/adc.c
        Core/Inc/adc.h
        Core/Src/ASCIIdisplay.c
        Core/Inc/ASCIIdisplay.h
        Core/DHT11/dht11.c
        Core/DHT11/dht11.h
)

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

# Include directories setup
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    Core/LCD
    Core/DHT11
)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths
)

# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here
)

# Link libraries
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user libraries here
)

# Link sources
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here
)

# Linker script
target_link_options(${CMAKE_PROJECT_NAME} PRIVATE
    # Add linker script here
)
