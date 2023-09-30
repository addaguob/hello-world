#include <cstdio>

class A {
  public:
    int int_a;
    char const * string_b = "";
    int int_c;
  public:
    void setia(int int_a) { }
};

int main() {
  A a;
  a.int_a = 1;
  a.string_b = "Two";
  a.int_c = 3;
  printf("int_a is %d\nsb is %s\nic is %d", a.int_a, a.string_b, a.int_c);
  int x;
  printf("--> %i", x);
  return 0;
}
