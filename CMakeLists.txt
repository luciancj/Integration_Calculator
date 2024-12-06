cmake_minimum_required(VERSION 3.30)
project(Integration_Calculator C)

set(CMAKE_C_STANDARD 23)

add_executable(Integration_Calculator
        main.c
        src/integration_text.c
        src/menu_manager.c
        src/menu_text.c
        src/text_utils.c
        src/parser.c
        src/integration.c
        include/integration.h
        include/parser.h
        src/user_input.c
        include/user_input.h
        main.h)
