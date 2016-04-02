#include <stdio.h>
#include <iostream>
#include <array>
#include <list>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <dirent.h>
#include <math.h>
#include <iomanip>
//#include <openssl.h>

using namespace std;
list<int32_t> read_from_file(string filename)
{
  list<int32_t> v;
  ifstream infile;
  infile.open(filename);
  if (infile.fail()){
    cerr << "An error occured while  opening the file" << endl;
    cout << "Exiting...\n";
    exit(1);
  }
  int32_t neighbor;
  while (infile >> neighbor)
    {
      int32_t number = neighbor;
      v.push_back(number);
    }
  infile.close();
  return v;
}

int main()
{

  int N = 100;//number of items in first list
  int M = 1 + log2(N);//number of lists in total (should be log2(n)

  vector<list<int32_t> > L(M);

  printf("Initialization of CS555 Project!\n");
  printf("Jim's on board\n");
  /*
  ofstream list0;
  list0.open ("list0.txt");
  
  for (int i = 0; i < N; ++i)
    {
      int r = rand() % 100 + 1;
      L[0].push_back(r);
    }
  for (list<int>::iterator it = L[0].begin(); it != L[0].end(); ++it)
    list0 << *it << ' ';

  list0.close();

  std::cout << '\n';
  */
  L[0] = read_from_file("list0.txt");
  for (list<int>::iterator it = L[0].begin(); it != L[0].end(); ++it)
    cout << *it << ' ';
  
  cout << "\n\n";
  for (int i = 0; i < M; ++i)
    {
      L[i].push_back(1);
      cout << i << " ";
    }

  return 0;

  /*The following is a "find(x)" function from opendatastructures.org
  Node<T> findPredNode(T x) {
      Node<T> u = sentinel;
      int r = h;
      while (r >= 0) {
          while (u.next[r] != null && compare(u.next[r].x,x) < 0) 
              u = u.next[r];  // go right in list r
              r--;              // go down into list r-1
      }
      return u;
  }
  T find(T x) {
       Node<T> u = findPredNode(x);
       return u.next[0] == null ? null : u.next[0].x;
  }
  */

}


