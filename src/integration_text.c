#include "../include/text_utils.h"

const char *integration_calculator[] = {
        ANSI_COLOR_GREEN
        "┳            •      ┏┓  ┓   ┓",
        "┃┏┓╋┏┓┏┓┏┓┏┓╋┓┏┓┏┓  ┃ ┏┓┃┏┓┏┃┏┓╋┏┓┏┓",
        "┻┛┗┗┗ ┗┫┛ ┗┻┗┗┗┛┛┗  ┗┛┗┻┗┗┗┻┗┗┻┗┗┛┛",
        "       ┛"
        ANSI_COLOR_RESET
};
struct textRows printIntegrationBanner = {integration_calculator, 4};

const char *regula_falsi[] = {
        ANSI_COLOR_GREEN
        "┳┓      ┓    ┏┓  ┓ •",
        "┣┫┏┓┏┓┓┏┃┏┓  ┣ ┏┓┃┏┓",
        "┛┗┗ ┗┫┗┻┗┗┻  ┻ ┗┻┗┛┗",
        "     ┛              "
        ANSI_COLOR_RESET
};
struct textRows printRegulaFalsi = {regula_falsi, 4};

const char *right_riemann_sum[] = {
        ANSI_COLOR_GREEN
        "┏┳┓┓     ┳┓•  ┓    ┳┓•             ┏┓",
        " ┃ ┣┓┏┓  ┣┫┓┏┓┣┓╋  ┣┫┓┏┓┏┳┓┏┓┏┓┏┓  ┗┓┓┏┏┳┓",
        " ┻ ┛┗┗   ┛┗┗┗┫┛┗┗  ┛┗┗┗ ┛┗┗┗┻┛┗┛┗  ┗┛┗┻┛┗┗",
        "             ┛"
        ANSI_COLOR_RESET
};
struct textRows printRightRiemannSum = {right_riemann_sum, 3};

const char *left_riemann_sum[] = {
        ANSI_COLOR_GREEN
        "┏┳┓┓     ┓   ┏   ┳┓•             ┏┓",
        " ┃ ┣┓┏┓  ┃ ┏┓╋╋  ┣┫┓┏┓┏┳┓┏┓┏┓┏┓  ┗┓┓┏┏┳┓",
        " ┻ ┛┗┗   ┗┛┗ ┛┗  ┛┗┗┗ ┛┗┗┗┻┛┗┛┗  ┗┛┗┻┛┗┗"
        ANSI_COLOR_RESET
};
struct textRows printLeftRiemannSum = {left_riemann_sum, 3};

const char *midpoint_riemann_sum[] = {
        ANSI_COLOR_GREEN
        "┏┳┓┓     ┳┳┓• ┓    •     ┳┓•             ┏┓",
        " ┃ ┣┓┏┓  ┃┃┃┓┏┫┏┓┏┓┓┏┓╋  ┣┫┓┏┓┏┳┓┏┓┏┓┏┓  ┗┓┓┏┏┳┓",
        " ┻ ┛┗┗   ┛ ┗┗┗┻┣┛┗┛┗┛┗┗  ┛┗┗┗ ┛┗┗┗┻┛┗┛┗  ┗┛┗┻┛┗┗"
        ANSI_COLOR_RESET
};
struct textRows printMidpointRiemannSum = {midpoint_riemann_sum, 4};

const char *trapezoidal_rule[] = {
        ANSI_COLOR_GREEN
        "┏┳┓           • ┓  ┓  ┳┓  ┓",
        " ┃ ┏┓┏┓┏┓┏┓┓┏┓┓┏┫┏┓┃  ┣┫┓┏┃┏┓",
        " ┻ ┛ ┗┻┣┛┗ ┗┗┛┗┗┻┗┻┗  ┛┗┗┻┗┗",
        "       ┛"
        ANSI_COLOR_RESET
};
struct textRows printTrapezoidalRule = {trapezoidal_rule, 4};

const char *secant_method[] = {
        ANSI_COLOR_GREEN
        "┏┓          ┳┳┓   ┓    ┓",
        "┗┓┏┓┏┏┓┏┓╋  ┃┃┃┏┓╋┣┓┏┓┏┫",
        "┗┛┗ ┗┗┻┛┗┗  ┛ ┗┗ ┗┛┗┗┛┗┻"
        ANSI_COLOR_RESET
};
struct textRows printSecantMethod = {secant_method, 3};
