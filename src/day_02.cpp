#include "aoc2022.hpp"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fmt::print(stderr, "Missing filename argument!\n");
        exit(1);
    }
    auto const data = read_to_string(argv[1]);

    auto part1_strategy = data 
        | lines 
        | rv::transform([](auto &&rng) {
            auto moves = rng | r::to<std::string>;
            return std::make_pair(
                moves.at(0) - 'A',   // them
                moves.at(2) - 'X');  // us
            });

    auto score = [](auto &&strategy) {
        return r::accumulate(strategy
            | rv::transform([](auto &&game) {
                auto them = game.first;
                auto us = game.second;
                return us + 1  // shape
                    + [&]{     // win/tie/loose
                        if((them + 1) % 3 == us) {
                            return 6;
                        } else if(them == us) {
                            return 3;
                        }
                        return 0;
                    }();
                }),
                0
            );
    };

    // second number is outcome instead of out move, calculate our move
    auto part2_strategy = part1_strategy 
        | rv::transform([](auto &&game) {
            auto them = game.first;
            auto outcome = game.second;
            auto us = [&]{
                if(outcome == 0) {                 // loose
                    switch(them) {
                        case 0: return 2;
                        default: return them - 1;
                    } 
                } else if (outcome == 1) {         // tie
                    return them;
                }
                return (them + 1) % 3;             // win
            }();
            return std::make_pair(
                them,
                us
            );
        });

    fmt::print("part1 score = {}\n", score(part1_strategy));
    fmt::print("part2 score = {}\n", score(part2_strategy));
}
