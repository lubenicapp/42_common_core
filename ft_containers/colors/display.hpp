#ifndef FT_CONTAINERS_DISPLAY_HPP
#define FT_CONTAINERS_DISPLAY_HPP

#include <stdlib.h>

#define color_black      0
#define color_dark_blue  1
#define color_dark_green 2
#define color_light_blue 3
#define color_dark_red   4
#define color_magenta    5
#define color_orange     6
#define color_light_gray 7
#define color_gray       8
#define color_blue       9
#define color_green     10
#define color_cyan      11
#define color_red       12
#define color_pink      13
#define color_yellow    14
#define color_white     15


void print_color(const int textcolor);
void print_color(const int textcolor, const int backgroundcolor);
void print_color_reset();
void println(const std::string& s="");
void print(const std::string& s="");
void print(const std::string& s, const int textcolor);
void print(const std::string& s, const int textcolor, const int backgroundcolor);
void print_no_reset(const std::string& s, const int textcolor);
void print_no_reset(const std::string& s, const int textcolor, const int backgroundcolor);

#endif //FT_CONTAINERS_DISPLAY_HPP
