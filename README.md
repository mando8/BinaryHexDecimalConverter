# BinaryHexDecimalConverter
Used to convert strings to Binary, Decimal, or Hex and back

Go to /build and run `cmake ..` After do `make`

Next you can do `./run_tests` or `./run_app`

(all commands run inside /build)


This was run and tested in VSCode.

## Common Error
If `make` fails with: `‘dummy’ may be used uninitialized` just go to gtest-death-test.cc and set `dummy = 0;`
