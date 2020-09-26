/*
----Psuedocode----
sum():
Determine base case, so if the list is empty return
the sum. If the list is not empty, add the value
of the first element in the list to sum and then
recursively call sumHelper(list minus first element, sum)

product():
Determine base case, so if the list is empty return
the product. If the list is not empty, multiply the value
of the first element in the list to product and then
recursively call productHelper(list minus first element, product)

*/
#include "recursive.h"
#include "hw4.h"

int sumHelper(list_t list, int sum) {
  if(list_isEmpty(list)) {
    return sum;
  }
  sum += list_first(list);
  return sumHelper(list_rest(list), sum);
}

int productHelper(list_t list, int product) {
  if(list_isEmpty(list)) {
    return product;
  }
  product *= list_first(list);
  return productHelper(list_rest(list), product);
}

list_t reverseHelper(list_t list, list_t output_list) {
  if(list_isEmpty(list)) {
    return output_list;
  }
  output_list = list_make(list_first(list), list);
  list_print(output_list);
  return reverseHelper(list_rest(list), output_list);
}

int accumulate(list_t l, int (*fn)(int, int), int base) {
  if (list_isEmpty(l)) {
    return base;
  } else {
    return accumulate(list_rest(l), fn, fn(base, list_first(l)));
  }
}

int sum(list_t list) {
  return sumHelper(list, 0);
}

int product(list_t list){
  return productHelper(list, 1);
}

list_t reverse(list_t list) {
  list_t output_list = list_make();
  return reverseHelper(list, output_list);
}