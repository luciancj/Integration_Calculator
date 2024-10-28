cmake_minimum_required(VERSION 3.10)  # 3.10 is sufficient for most setups
project(Integration_Calculator)

# Set C standard to C11 (change if using a different standard)
set(CMAKE_C_STANDARD 11)

# Specify include directories
include_directories(include)

# Gather source files (only .c files)
file(GLOB SOURCES "src/*.c")

# Define the executable with gathered sources
add_executable(Integration_Calculator main.c ${SOURCES})
