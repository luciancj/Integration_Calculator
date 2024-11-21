#include "../include/text_utils.h"

const char *menu[] = {
        "╔══════════════════════════════════════╗",
        "║                Welcome               ║",
        "╠══════════════════════════════════════╣",
        "║           Choose an option:          ║",
        "║                                      ║",
        "║   "ANSI_COLOR_GREEN"/i - Interactive mode"ANSI_COLOR_RESET"              ║",
        "║   "ANSI_COLOR_GREEN"/p - Parameter mode"ANSI_COLOR_RESET"                ║",
        "║                                      ║",
        "╚══════════════════════════════════════╝"
};
struct textRows welcomeMenu = {menu, 9};

const char *parameter_mode_banner[] = {
        "╔══════════════════════════════════════╗",
        "║        Parameter mode - Choose:      ║",
        "╠══════════════════════════════════════╣",
        "║                                      ║",
        "║   "ANSI_COLOR_GREEN"/rf - Regula False."ANSI_COLOR_RESET"                ║",
        "║   "ANSI_COLOR_GREEN"/rr - The Right Riemann Sum"ANSI_COLOR_RESET"        ║",
        "║   "ANSI_COLOR_GREEN"/lr - The Left Riemann Sum"ANSI_COLOR_RESET"         ║",
        "║   "ANSI_COLOR_GREEN"/mr - The Midpoint Riemann Sum"ANSI_COLOR_RESET"     ║",
        "║   "ANSI_COLOR_GREEN"/tr - Trapezoidal Rule"ANSI_COLOR_RESET"             ║",
        "║   "ANSI_COLOR_GREEN"/sm - Secant Method."ANSI_COLOR_RESET"               ║",
        "║                                      ║",
        "╚══════════════════════════════════════╝"
};
struct textRows parameterModeBanner = {parameter_mode_banner, 12};

const char *interactive_mode_banner[] = {
        "╔══════════════════════════════════════╗",
        "║      Interactive mode - Choose:      ║",
        "╠══════════════════════════════════════╣",
        "║                                      ║",
        "║   "ANSI_COLOR_GREEN"/rf - Regula False."ANSI_COLOR_RESET"                ║",
        "║   "ANSI_COLOR_GREEN"/rr - The Right Riemann Sum"ANSI_COLOR_RESET"        ║",
        "║   "ANSI_COLOR_GREEN"/lr - The Left Riemann Sum"ANSI_COLOR_RESET"         ║",
        "║   "ANSI_COLOR_GREEN"/mr - The Midpoint Riemann Sum"ANSI_COLOR_RESET"     ║",
        "║   "ANSI_COLOR_GREEN"/tr - Trapezoidal Rule"ANSI_COLOR_RESET"             ║",
        "║   "ANSI_COLOR_GREEN"/sm - Secant Method."ANSI_COLOR_RESET"               ║",
        "║                                      ║",
        "╚══════════════════════════════════════╝"
};
struct textRows interactiveModeBanner = {interactive_mode_banner, 12};

const char *ask_file_name_banner[] = {
        "╔══════════════════════════════════════╗",
        "║ Type in the filename:                ║",
        "╚══════════════════════════════════════╝"
};
struct textRows askFileNameBanner = {ask_file_name_banner, 3};

const char *values_menu[] = {
        "╔════════════════════════╦══════════════════╗",
        "║ DESCRIPTION            ║ VALUE            ║",
        "╠════════════════════════╬══════════════════╣",
        "║ Segments               ║ "ANSI_COLOR_GREEN"100"ANSI_COLOR_RESET"              ║",
        "╠════════════════════════╬══════════════════╣",
        "║ Area                   ║ "ANSI_COLOR_GREEN"0.67"ANSI_COLOR_RESET"             ║",
        "╠════════════════════════╬══════════════════╣",
        "║ x_min                  ║ "ANSI_COLOR_GREEN"0.00"ANSI_COLOR_RESET"             ║",
        "╠════════════════════════╬══════════════════╣",
        "║ x_max                  ║ "ANSI_COLOR_GREEN"1.00"ANSI_COLOR_RESET"             ║",
        "╠════════════════════════╬══════════════════╣",
        "║ x_mean                 ║ "ANSI_COLOR_GREEN"0.50"ANSI_COLOR_RESET"             ║",
        "╠════════════════════════╬══════════════════╣",
        "║ x_delta_min            ║ "ANSI_COLOR_GREEN"0.00"ANSI_COLOR_RESET"             ║",
        "╠════════════════════════╬══════════════════╣",
        "║ x_delta_max            ║ "ANSI_COLOR_GREEN"0.01"ANSI_COLOR_RESET"             ║",
        "╠════════════════════════╬══════════════════╣",
        "║ y_min                  ║ "ANSI_COLOR_GREEN"0.00"ANSI_COLOR_RESET"             ║",
        "╠════════════════════════╬══════════════════╣",
        "║ y_max                  ║ "ANSI_COLOR_GREEN"1.00"ANSI_COLOR_RESET"             ║",
        "╠════════════════════════╬══════════════════╣",
        "║ y_mean                 ║ "ANSI_COLOR_GREEN"0.66"ANSI_COLOR_RESET"             ║",
        "╠════════════════════════╬══════════════════╣",
        "║ y_delta_min            ║ "ANSI_COLOR_GREEN"-0.02"ANSI_COLOR_RESET"            ║",
        "╠════════════════════════╬══════════════════╣",
        "║ y_delta_max            ║ "ANSI_COLOR_GREEN"0.00"ANSI_COLOR_RESET"             ║",
        "╚════════════════════════╩══════════════════╝"
};
struct textRows valuesMenu = {values_menu, 27};