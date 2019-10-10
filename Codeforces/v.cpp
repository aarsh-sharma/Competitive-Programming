
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[])
{
  registerValidation(argc, argv);
  // string valid = inf.readToken("[><^v]{1,100000}", "s");
  int n = inf.readInt();
  inf.readEoln();
  for (int i = 0; i < n; i++) {
    inf.readInt();
    inf.readSpace();
    inf.readInt();
    inf.readSpace();
    inf.readInt();
    inf.readSpace();
    inf.readInt();
    // if (i != n-1)
    inf.readEoln();
  }
  // inf.readEoln();
  inf.readEof();
}