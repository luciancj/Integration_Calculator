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
struct textRows bannerRegulaFalsi = {regula_falsi, 4};

const char *right_riemann_sum[] = {
        ANSI_COLOR_GREEN
        "┏┳┓┓     ┳┓•  ┓    ┳┓•             ┏┓",
        " ┃ ┣┓┏┓  ┣┫┓┏┓┣┓╋  ┣┫┓┏┓┏┳┓┏┓┏┓┏┓  ┗┓┓┏┏┳┓",
        " ┻ ┛┗┗   ┛┗┗┗┫┛┗┗  ┛┗┗┗ ┛┗┗┗┻┛┗┛┗  ┗┛┗┻┛┗┗",
        "             ┛"
        ANSI_COLOR_RESET
};
struct textRows bannerRightRiemannSum = {right_riemann_sum, 3};

const char *left_riemann_sum[] = {
        ANSI_COLOR_GREEN
        "┏┳┓┓     ┓   ┏   ┳┓•             ┏┓",
        " ┃ ┣┓┏┓  ┃ ┏┓╋╋  ┣┫┓┏┓┏┳┓┏┓┏┓┏┓  ┗┓┓┏┏┳┓",
        " ┻ ┛┗┗   ┗┛┗ ┛┗  ┛┗┗┗ ┛┗┗┗┻┛┗┛┗  ┗┛┗┻┛┗┗"
        ANSI_COLOR_RESET
};
struct textRows bannerLeftRiemannSum = {left_riemann_sum, 3};

const char *midpoint_riemann_sum[] = {
        ANSI_COLOR_GREEN
        "┏┳┓┓     ┳┳┓• ┓    •     ┳┓•             ┏┓",
        " ┃ ┣┓┏┓  ┃┃┃┓┏┫┏┓┏┓┓┏┓╋  ┣┫┓┏┓┏┳┓┏┓┏┓┏┓  ┗┓┓┏┏┳┓",
        " ┻ ┛┗┗   ┛ ┗┗┗┻┣┛┗┛┗┛┗┗  ┛┗┗┗ ┛┗┗┗┻┛┗┛┗  ┗┛┗┻┛┗┗"
        ANSI_COLOR_RESET
};
struct textRows bannerMidpointRiemannSum = {midpoint_riemann_sum, 4};

const char *trapezoidal_rule[] = {
        ANSI_COLOR_GREEN
        "┏┳┓           • ┓  ┓  ┳┓  ┓",
        " ┃ ┏┓┏┓┏┓┏┓┓┏┓┓┏┫┏┓┃  ┣┫┓┏┃┏┓",
        " ┻ ┛ ┗┻┣┛┗ ┗┗┛┗┗┻┗┻┗  ┛┗┗┻┗┗",
        "       ┛"
        ANSI_COLOR_RESET
};
struct textRows bannerTrapezoidalRule = {trapezoidal_rule, 4};

const char *secant_method[] = {
        ANSI_COLOR_GREEN
        "┏┓          ┳┳┓   ┓    ┓",
        "┗┓┏┓┏┏┓┏┓╋  ┃┃┃┏┓╋┣┓┏┓┏┫",
        "┗┛┗ ┗┗┻┛┗┗  ┛ ┗┗ ┗┛┗┗┛┗┻"
        ANSI_COLOR_RESET
};
struct textRows bannerSecantMethod = {secant_method, 3};
