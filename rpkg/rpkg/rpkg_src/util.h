#pragma once
#include <string>
#include <vector>

class util
{
public:
    static std::vector<std::string> parse_input_filter(std::string input_string);
    static std::string to_upper_case(std::string s);
    static std::string to_lower_case(std::string s);
    static std::string remove_all_string_from_string(std::string input_string, std::string to_remove);
    static std::string uint64_t_to_hex_string(uint64_t bytes8);
    static std::string uint32_t_to_hex_string(uint32_t bytes4);
    static std::string uint16_t_to_hex_string(uint16_t bytes2);
    static std::string uint8_t_to_hex_string(uint8_t bytes1);
    static std::string uint64_t_to_string(uint64_t bytes8);
    static std::string uint32_t_to_string(uint32_t bytes4);
    static std::string uint16_t_to_string(uint16_t bytes2);
    static std::string uint8_t_to_string(uint8_t bytes1);
    static std::string int32_t_to_string(int32_t bytes4);
    static std::string float_to_string(float bytes4);
};