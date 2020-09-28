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

accumulate():

reverse():

append():

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
  output_list = list_make(list_first(list), output_list);
  return reverseHelper(list_rest(list), output_list);
}

list_t appendHelper(list_t first, list_t second, list_t output_list) {
  if(!list_isEmpty(first)) {
    output_list = list_make(list_first(first), output_list);
    return appendHelper(list_rest(first), second, output_list);
  }
  else if(!list_isEmpty(second)) {
    output_list = list_make(list_first(second), output_list);
    return appendHelper(first, list_rest(second), output_list);
  }
  return reverse(output_list);
}

list_t oddHelper(list_t list, list_t output_list) {
  if(list_isEmpty(list)) {
    return reverse(output_list);
  }
  if(list_first(list) % 2 != 0) {
    output_list = list_make(list_first(list), output_list);
  }
  return oddHelper(list_rest(list), output_list);
}

list_t evenHelper(list_t list, list_t output_list) {
  if(list_isEmpty(list)) {
    return reverse(output_list);
  }
  if(list_first(list) % 2 == 0) {
    output_list = list_make(list_first(list), output_list);
  }
  return evenHelper(list_rest(list), output_list);
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

list_t append(list_t first, list_t second) {
  list_t output_list = list_make();
  return appendHelper(first, second, output_list);
}

list_t filter_odd(list_t list) {
  list_t output_list = list_make();
  return oddHelper(list, output_list);
}

list_t filter_even(list_t list) {
  list_t output_list = list_make();
  return evenHelper(list, output_list);
}