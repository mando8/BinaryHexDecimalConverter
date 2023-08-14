#ifndef LUT_H__
#define LUT_H__

#include <string>
#include <vector>

using namespace std;

class LookupTable {
public:
  // constructor, initialize class variables and pointers here if need.
  LookupTable();

  // deconstructor, if you are using shared_pointers you don't need to keep track of
  // freeing memory and you can leave this blank
  ~LookupTable();

  // used to convert string to any binary, decimal, or hex
  string to_not_string(string strings, string type);

  // used to convert binary to any text, decimal, or hex
  std::string to_string_bin(string binary_code, string type);

  // used to convert decimal to any binary, text, or hex
  string to_string_dec(string decimal_code, string type);

  // used to convert hex to any binary, decimal, or text
  string to_string_hex(string hex_code, string type);

private:
  // used to create vectors from strings
  vector<string> create_vector(string to_translate);
};

#endif  // LUT_H__
