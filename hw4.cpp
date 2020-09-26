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