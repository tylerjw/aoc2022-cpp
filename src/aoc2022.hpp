#include <range/v3/all.hpp>
#include <fmt/core.h>
#include <fmt/ranges.h>

#include <string>
#include <fstream>
#include <vector>
#include <string>

std::string read_to_string(std::string const& filename) {
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

template <typename T, typename Fn>
[[nodiscard]] constexpr auto operator|(T&& val, Fn&& fn) ->
    typename std::enable_if_t<std::is_invocable_v<Fn, T>, std::invoke_result_t<Fn, T>> {
    return std::invoke(std::forward<Fn>(fn), std::forward<T>(val));
}

namespace r = ranges;
namespace rv = r::views;
namespace ra = r::actions;

auto to_string_view = [](auto&& rng) {
    return std::string_view(&*rng.begin(), r::distance(rng));
};

auto to_string = [](auto&& rng) {
    return std::string(&*rng.begin(), r::distance(rng));
};

auto to_int = [](std::string const& str) {
    return std::stoi(str);
};

auto lines = [](auto&& rng) {
    return rng
        | rv::split('\n')
        | rv::transform(to_string_view);
};
