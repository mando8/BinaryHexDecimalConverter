#ifndef LUT_H__
#define LUT_H__

#include <string>
#include <vector>

using namespace std;

//
//  This defines the names of various sorting functions and related
//  helper functions. You are required to implement all of these.
//
//  When the user calls the sorting functions, it is expected that the
//  output data is sorted in _nondecreasing_ order.  E.g.
//
//  input:  9, 5, 4, 1, 10, 5
//  output: 1, 4, 5, 5, 9, 10 
//

class LookupTable {
public:
  // constructor, initialize class variables and pointers here if need.
  LookupTable();

  // deconstructor, if you are using shared_pointers you don't need to keep track of
  // freeing memory and you can leave this blank
  ~LookupTable();

  // quicksort is the entry point for the quicksort routine. It should
  // use the quicksort_partition function. It is also recursive, so you
  // will call quicksort from inside the quicksort function.
  string to_not_string(string strings, string type);

  string to_string_bin(string binary_code);

  string to_string_dec(string decimal_code);

  string to_string_hex(string hex_code);

private:
  // used to create vectors from strings
  vector<string> create_vector(string to_translate);
};

#endif  // LUT_H__