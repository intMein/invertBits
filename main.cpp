#include <iostream>
#include <bitset>
#include <vector>
#include <random>
#include <limits>

void generate_bits(std::vector<uint8_t> &bits, size_t count)
{
    auto max = std::numeric_limits<uint8_t>::max();

    std::random_device device;
    std::uniform_int_distribution<uint8_t> randomizer(0, max);

    for (size_t i = 0; i < count; ++i) {
        bits.push_back(randomizer(device));
    }
}

void print_bits(const std::vector<uint8_t> &bits)
{
    for (const auto elem : bits) {
        std::bitset<8> bitset(elem);
        std::cout << bitset << ' ';
    }

    std::cout << std::endl;
}

int find_first_bit(uint8_t value)
{
    if (value == 0) {
        return -1;
    }

    return __builtin_ctz(value);
}

void invert_bits(std::vector<uint8_t> &bits, size_t count)
{
    for (auto &elem : bits) {
        if (count == 0) {
            break;
        }

        int first_bit = find_first_bit(elem);

        while (first_bit != -1 && count > 0) {
            elem ^= 1 << first_bit;
            --count;

            first_bit = find_first_bit(elem);
        }
    }
}

int main() {
    std::vector<uint8_t> bits;

    size_t bits_sz = 0;

    std::cout << "how many numbers to generate: " << std::endl;

    std::cin >> bits_sz;

    generate_bits(bits, bits_sz);
    print_bits(bits);

    std::cout << "how many bits need to be inverted: " << std::endl;

    size_t inverted_bits = 0;

    std::cin >> inverted_bits;

    invert_bits(bits, inverted_bits);

    std::cout << "inverted bits:" << std::endl;
    print_bits(bits);

    return 0;
}
