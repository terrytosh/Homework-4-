#include<iostream>
#include "recursive.h"
#include "hw4.h"

using namespace std;

bool ListEqual(list_t l1, list_t l2)
    // EFFECTS: returns true if l1 and l2 are equal, false otherwise
{
    // If either are empty, both must be empty for equality
    if (list_isEmpty(l1) || list_isEmpty(l2)) {
	return (list_isEmpty(l1) && list_isEmpty(l2));
    }

    if (list_first(l1) != list_first(l2)) {
	return false;
    } else {
	return ListEqual(list_rest(l1), list_rest(l2));
    }
}

bool notByFour(int i)
{
    return (i%4);
}

int main() {
    list_t original = list_make();
    list_t rotated = list_make();
    list_t testlist = list_make();

    const int largest = 7;
    const int steps = 4+largest;

    bool answer = true;

    for (int i = largest-1; i>=0; i--) {
      original = list_make(i, original);
      rotated = list_make((i+steps)%largest, rotated);
    }

    //testlist = rotate(original, steps);
    bool results  = ListEqual(testlist, rotated);

  list_print(rotated);
  list_print(testlist);
  list_t testlist2 = list_make();
  for(int i = 0; i < 4; i++) {
    testlist2 = list_make(i, testlist2);
  }
  list_print(testlist2);
  cout << endl;

  list_t test = chop(testlist2, 2);
  list_print(test);
  cout << endl;

  cout << fib(6) << endl;
  cout << fib_tail(6) << endl;

}