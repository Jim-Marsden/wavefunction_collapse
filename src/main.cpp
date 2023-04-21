//
// Created by jim on 4/20/23.
//

#include <fmt/format.h>
#include <vector>

int main() try {
    std::vector<int>{}.at(34);
    throw std::runtime_error("oh no!");
} catch (std::exception const & exception){

    thread_local constexpr auto error_str{R"as(An unrecoverable error has been caught:

{}
)as"};
    fmt::println(stderr, error_str, exception.what());
}