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

  // used to convert binary to string
  string to_string_bin(string binary_code);

  // used to convert decimal to string
  string to_string_dec(string decimal_code);

  // used to convert hex to string
  string to_string_hex(string hex_code);

private:
  // used to create vectors from strings
  vector<string> create_vector(string to_translate);
};

#endif  // LUT_H__
