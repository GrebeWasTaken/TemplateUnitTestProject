#include "stockFunctions.h"
#include <cmath>
#include <cstdlib>

//calculates Percent change = ((end - start) / start) * 100
double percentChange(const std::vector<double>& values, int startDay, int endDay){
  double start = values[startDay];
  double end = values[endDay];

  double change = (end - start) / start * 100;
  return change;
}

//finds highest value
double highestValue(const std::vector<double>& values, int startDay, int endDay){
  double best = values.at(startDay);

  for ()
}