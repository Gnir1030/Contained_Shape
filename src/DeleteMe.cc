#include <iostream>
using namespace std;

// only here to generate a compiler warning - delete this file

void branch(bool flag) 
{
  if (flag) {
    return;
  }
  cout << "missing branch" << endl;
}

static void uncalled() 
{
}