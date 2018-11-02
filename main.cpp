#include "Queue.h"
#include "Registrar.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv)
{
  string fileName;
  if(argc != 2)
  {
    cerr << "Too many arguments." << endl;
    return 0;
  }
  else
  {
    fileName = argv[1];
  }

  cout << argv[1] << endl; //test
  Registrar start(fileName);
  start.simulate();
  return 0;
}
