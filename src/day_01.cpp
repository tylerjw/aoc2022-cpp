#include "aoc2022.hpp"

#include <vector>

int main(int argc, char *argv[]) {
    if(argc < 2) {
        fmt::print(stderr, "Missing filename argument!\n");
        exit(1);
    }
    auto const data = read_to_string(argv[1]);

    // Parse
    auto elf_calories =
        data
            | lines
            | rv::split("")
            | rv::transform([](auto&& rng) {
                return rng
                    | rv::transform(to_string)
                    | rv::transform(to_int);
            })
            | rv::transform([](auto&& rng){
                return r::accumulate(rng, 0);
            })
            | r::to<std::vector<int>>;
    ra::sort(elf_calories);

    // Part 1
    auto const max_calories = elf_calories.back();
    fmt::print("max_calories = {}\n", max_calories);

    // Part 2
    auto last_3 = r::accumulate(elf_calories | rv::take_last(3), 0);
    fmt::print("last 3 = {}\n", last_3);
}
