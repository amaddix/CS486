

#include <iostream>
#include <cstring>
#include <fstream>
#include <cctype>
#include <cstdlib>
#include <cstddef>
#include <ctime>

using namespace std;



struct node
{

  bool dirt;
  int id;

  node * left;
  node * right;
  node * down;
  node * up;

};
