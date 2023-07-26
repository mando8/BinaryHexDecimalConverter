#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <iterator>

//Struct for Lookup Ttable
struct CodeLUT {
  char decodedChar; // this represents the actual character
  const char *binary; // this represents the binary code for the char
  const char *decimal; // this represents the decimal for the char
  const char *hex; // this represents the hex for the char
};

//the Lookup Table itself
const CodeLUT table[] = {
  { 'A', "01000001", "65", "41" },
  { 'B', "01000010", "66", "42" },
  { 'C', "01000011", "67", "43" },
  { 'D', "01000100", "68", "44" },
  { 'E', "01000101", "69", "45" },
  { 'F', "01000110", "70", "46" },
  { 'G', "01000111", "71", "47" },
  { 'H', "01001000", "72", "48" },
  { 'I', "01001001", "73", "49" },
  { 'J', "01001010", "74", "4A" },
  { 'K', "01001011", "75", "4B" },
  { 'L', "01001100", "76", "4C" },
  { 'M', "01001101", "77", "4D" },
  { 'N', "01001110", "78", "4E" },
  { 'O', "01001111", "79", "4F" },
  { 'P', "01010000", "80", "50" },
  { 'Q', "01010001", "81", "51" },
  { 'R', "01010010", "82", "52" },
  { 'S', "01010011", "83", "53" },
  { 'T', "01010100", "84", "54" },
  { 'U', "01010101", "85", "55" },
  { 'V', "01010110", "86", "56" },
  { 'W', "01010111", "87", "57" },
  { 'X', "01011000", "88", "58" },
  { 'Y', "01011001", "89", "59" },
  { 'Z', "01011010", "90", "5A" },
  { 'a', "01100001", "97", "61" },
  { 'b', "01100010", "98", "62" },
  { 'c', "01100011", "99", "63" },
  { 'd', "01100100", "100", "64" },
  { 'e', "01100101", "101", "65" },
  { 'f', "01100110", "102", "66" },
  { 'g', "01100111", "103", "67" },
  { 'h', "01101000", "104", "68" },
  { 'i', "01101001", "105", "69" },
  { 'j', "01101010", "106", "6A" },
  { 'k', "01101011", "107", "6B" },
  { 'l', "01101100", "108", "6C" },
  { 'm', "01101101", "109", "6D" },
  { 'n', "01101110", "110", "6E" },
  { 'o', "01101111", "111", "6F" },
  { 'p', "01110000", "112", "70" },
  { 'q', "01110001", "113", "71" },
  { 'r', "01110010", "114", "72" },
  { 's', "01110011", "115", "73" },
  { 't', "01110100", "116", "74" },
  { 'u', "01110101", "117", "75" },
  { 'v', "01110110", "118", "76" },
  { 'w', "01110111", "119", "77" },
  { 'x', "01111000", "120", "78" },
  { 'y', "01111001", "121", "79" },
  { 'z', "01111010", "122", "7A" },
  { '0', "00110000", "48", "30" },
  { '1', "00110001", "49", "31" },
  { '2', "00110010", "50", "32" },
  { '3', "00110011", "51", "33" },
  { '4', "00110100", "52", "34" },
  { '5', "00110101", "53", "35" },
  { '6', "00110110", "54", "36" },
  { '7', "00110111", "55", "37" },
  { '8', "00111000", "56", "38" },
  { '9', "00111001", "57", "39" },
  { ' ', "00100000", "32", "20" },
  { '\'', "00100111", "39", "27" },
  { '!', "00100001", "33", "21" },
  { '?', "00111111", "63", "3F" },
  { '.', "00101110", "46", "2E" },
  { ',', "00101100", "44", "2C" }
};

// size of lookup table
int size = sizeof(table) / sizeof(table[0]);

// Converts string to binary, decimal, or hex
std::string to_not_string(std::string strings, std::string type) {
    std::string ret = "";

    for (auto character : strings)
        for (int i = 0; i < size; i++)
            if (table[i].decodedChar == character)
                if (type == "binary")
                    ret = ret + table[i].binary + " ";
                else if (type == "decimal")
                    ret = ret + table[i].decimal + " ";
                else if (type == "hex")
                    ret = ret + table[i].hex + " ";

    std::cout << ret << std::endl;
    return ret;
}

std::vector<std::string> create_vector(std::string to_translate) {
    
    std::istringstream iss(to_translate);
    std::vector<std::string> vec{std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}};
    return vec;
}

std::string to_string_bin(std::string binary_code) {
    std::string ret = "";
    std::vector<std::string> binary_vec = create_vector(binary_code);

    for (auto bin : binary_vec)
        for (int i = 0; i < size; i++)
            if (table[i].binary == bin)
                ret += table[i].decodedChar;

    std::cout << ret << std::endl;
    return ret;
}

std::string to_string_dec(std::string decimal_code) {
    std::string ret = "";
    std::vector<std::string> decimal_vec = create_vector(decimal_code);

    for (auto bin : decimal_vec)
        for (int i = 0; i < size; i++)
            if (table[i].decimal == bin)
                ret += table[i].decodedChar;

    std::cout << ret << std::endl;
    return ret;
}

std::string to_string_hex(std::string hex_code) {
    std::string ret = "";
    std::vector<std::string> hex_vec = create_vector(hex_code);

    for (auto bin : hex_vec)
        for (int i = 0; i < size; i++)
            if (table[i].hex == bin)
                ret += table[i].decodedChar;

    std::cout << ret << std::endl;
    return ret;
}

int main() {
    std::string sample_text = "01100110 01101001 01101110 01100100 00100000 01100001 00100000 01101000 01101111 01100010 01100010 01111001 00100000 01100110 01101111 01110010 00100000 01100111 01101111 01100100 00100111 01110011 00100000 01110011 01100001 01101011 01100101";

    std::cout << std::endl;
    std::cout << "BINARY:" << std::endl;
    std::string sample_text_tostringbin = to_string_bin(sample_text);
    to_not_string(sample_text_tostringbin, "binary");
    std::cout << std::endl;

    std::cout << "DECIMAL:" << std::endl;
    std::string dec = to_not_string(sample_text_tostringbin, "decimal");
    std::string sample_text_tostringdec = to_string_dec(dec);
    std::cout << std::endl;
    

    std::cout << "HEX:" << std::endl;
    std::string hex = to_not_string(sample_text_tostringbin, "hex");
    std::string sample_text_tostringhex = to_string_hex(hex);
    std::cout << std::endl << std::endl;

    std::string user_input;
    std::cout << "Input a string: ";
    std::getline(std::cin, user_input);
    std::cout << "Binary: ";
    std::string user_input_tobinary = to_not_string(user_input, "binary");
    std::cout << "Decimal: ";
    std::string user_input_todecimal = to_not_string(user_input, "decimal");
    std::cout << "Hex: ";
    std::string user_input_tohex = to_not_string(user_input, "hex");
    std::cout << std::endl << "Translated Binary:" << std::endl;
    to_string_bin(user_input_tobinary);
    std::cout << "Translated Decimal:" << std::endl;
    to_string_dec(user_input_todecimal);
    std::cout << "Translated Hex:" << std::endl;
    to_string_hex(user_input_tohex);
    std::cout << std::endl;

    return 0;
}
