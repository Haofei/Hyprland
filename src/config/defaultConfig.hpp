#pragma once

#include <string>

inline constexpr std::string_view AUTOGENERATED_PREFIX   = R"#(
# #######################################################################################
# AUTOGENERATED HYPRLAND CONFIG.
# EDIT THIS CONFIG ACCORDING TO THE WIKI INSTRUCTIONS.
# #######################################################################################

autogenerated = 1 # remove this line to remove the warning

)#";
inline constexpr char             EXAMPLE_CONFIG_BYTES[] = {
#embed "../../example/hyprland.conf"
};

inline constexpr std::string_view EXAMPLE_CONFIG = {EXAMPLE_CONFIG_BYTES, sizeof(EXAMPLE_CONFIG_BYTES)};
