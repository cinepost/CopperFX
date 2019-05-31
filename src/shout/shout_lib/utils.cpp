#include <regex>
#include <cstdlib>

#include "utils.h"

std::string expandEnvVars(std::string text)
{
    static const std::regex env_re{R"--(\$\{([^}]+)\})--"};
    std::smatch match;
    while (std::regex_search(text, match, env_re)) {
        auto const from = match[0];
        auto const var_name = match[1].str().c_str();
        text.replace(from.first, from.second, std::getenv(var_name));
    }
    return text;
}