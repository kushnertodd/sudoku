#include <iostream>
#include <string>
using namespace std;
class V1 {
protected:
  int i;
public:
  V1() : i(0) {}
  virtual void a(string msg) {
    i++;
    print("V1", msg, &i);
  }
  void b(string msg) {
    i += 3;
    print("V1", msg, &i);
  }
  void print(string msg1, string msg2, int* j) {
    cout << msg1 << msg2 << " i: " << i << " &i: " << j << endl;
  }
};
class V1_1 : public V1 {
public:
  // inherits its own instance of i
  virtual void a(string msg) {
    i += 2;
    print("V1_1", msg, &i);
  }
  virtual void b(string msg) {
    i += 4;
    print("V1_1", msg, &i);
  }
};
int main(int argc, char **argv) {
  V1* v1 = new V1();
  V1_1* v1_1 = new V1_1();
  v1->a("v1->a()");
  v1_1->a("v1_1->a()");
  v1 = v1_1;
  v1->a("v1 = V1_1->a()");
  V1* v1a = new V1();
  V1_1* v1_1a = new V1_1();
  v1a->b("v1a->b()");
  v1_1a->b("v1a->b()");
}
