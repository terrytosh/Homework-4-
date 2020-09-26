#include<iostream>
#include "recursive.h"
#include "hw4.h"

using namespace std;

bool ListEqual(list_t l1, list_t l2)
    // EFFECTS: reeturns true of l1 and l2 are equal, false otherwise
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

  //testing sum
  int sum1 = sum(rotated);
  cout << endl << sum1 << endl;
  int sum2 = sum(testlist);
  cout << sum2 << endl; 

  //testing product
  //int product1 = product(rotated);
  //cout << product1 << endl;
  //int product2 = product(testlist);
  //cout << product2 << endl;

  list_t reversed = reverse(rotated);
  list_print(reversed);

}