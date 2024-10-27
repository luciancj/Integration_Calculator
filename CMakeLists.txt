cmake_minimum_required(VERSION 3.30)
project(Integration_Calculator)

set(CMAKE_CXX_STANDARD 26)

add_executable(Integration_Calculator main.c
        include/text_data.h
        src/menu_text.c
        include/menu_text.h
        src/integration_text.c
        include/integration_text.h
        src/menu_manager.c
        include/menu_manager.h
)
