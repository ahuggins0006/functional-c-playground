#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

auto lambdaFn = [](int value)->int{
    return value + 1;
};

auto fxsquare = [](int x) -> int {
                  return x * x;
                };

//For Each
template <typename Collection, typename unop>
void for_each(Collection col, unop op){
  std::for_each(col.begin(),col.end(),op);
}

//Map
template <typename Collection, typename unop>
Collection map(Collection col, unop op) {
  std::transform(col.begin(), col.end(), col.begin(), op);
  return col;
}

//LISP
template <int ...>
struct mySum;

template<>
struct mySum<>{
  static const int value = 0;
};

template<int head, int ... tail>
struct mySum<head, tail...>{
  static const int value = head + mySum<tail...>::value;
};

main() {
  int retLambda = fxsquare(100);

  //cout << retLambda << endl;

  auto lambda_echo = [](int i) {cout << i << endl;};
  std::vector<int> col{20,24,37,42,23,45,37};

  //for_each(col, lambda_echo);

  auto addOne = [](int i) {return i+1;};
  auto returnCol = map(col, addOne);
  //for_each(returnCol, lambda_echo);


  int sum = mySum<1,2,3>::value;
  cout << sum <<endl;

}

