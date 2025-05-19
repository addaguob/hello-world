import 'dart:ffi';

void main() {
  // Explore python's 28 bytes of int, whereas in C++ it is 4 bytes
  // >>> x = 5
  // >>> import sys
  // >>> print(sys.getsizeof(x), "bytes")
  
  // Get the size of native types
  print("Size of native Int8: ${Size.sizeOf<Int8>()} byte(s)");
  print("Size of native Int32: ${Size.sizeOf<Int32>()} byte(s)");
  print("Size of native Int64: ${Size.sizeOf<Int64>()} byte(s)");
}