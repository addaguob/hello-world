import 'dart:ffi';
import 'dart:ffi' show calloc;

void main() {
  // Explore python's 28 bytes of int, whereas in C++ it is 4 bytes
  // >>> x = 5
  // >>> import sys
  // >>> print(sys.getsizeof(x), "bytes")
  // Create a pointer to an int
  Pointer<Int32> int32 = calloc<Int32>();
  Pointer<Int64> int64 = calloc<Int64>();
  
  // Get the size of the native types
  print('Size of Int32: ${sizeOf<Int32>()} bytes');  // Should print 4 bytes
  print('Size of Int64: ${sizeOf<Int64>()} bytes');  // Should print 8 bytes
  
  // Clean up the allocated memory
  calloc.free(int32);
  calloc.free(int64);
}