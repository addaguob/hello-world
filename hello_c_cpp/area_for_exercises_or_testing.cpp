#include <cstdio>

class A {
  public:
    int ia;
    char const * sb = "";
    int ic;
  public:
    void setia(int ia) { }
};

int main() {
  A a;
  a.ia = 1;
  a.sb = "Two";
  a.ic = 3;
  printf("ia is %d\nsb is %s\nic is %d", a.ia, a.sb, a.ic);
  int x;
  printf("--> %i", x);
  return 0;
}
