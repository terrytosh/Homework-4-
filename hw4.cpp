#include "recursive.h"
#include "hw4.h"

int accumulate(list_t l, int (*fn)(int, int), int base) {
  if (list_isEmpty(l)) {
    return base;
  } else {
    return accumulate(list_rest(l), fn, fn(base, list_first(l)));
  }
}

int sum(list_t list, int sum_of_list) {
  if (list_isEmpty(list)) {
    return sum_of_list;
  }
  sum_of_list += list_first(list);
  return sum(list_rest(list), sum_of_list);
}

int product(list_t list, int product_of_list){
  if (list_isEmpty(list)) {
    return product_of_list;
  }
  product_of_list *= list_first(list);
  return product(list_rest(list), product_of_list);
}