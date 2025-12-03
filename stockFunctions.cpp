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

  for (int i = startDay + 1; i <= endDay; ++i){
    if (values.at(i) > best){
      best = values.at(i);
    }
  }
  return best;
}

//average value
double average(const std::vector<double>& values, int startDay, int endDay){
  double sum = 0.0;
  int count = endDay - startDay + 1;

  for (int i = startDay; i <= endDay; ++i){
    sum += values.at(i);
  }
  return sum / count;
}

//standard deviation
double standardDev(const std::vector<double>& values, int startDay, int endDay){
  double mean = average(values, startDay, endDay);
  int count = endDay - startDay + 1;

  double sumSqDiff = 0.0;
  for (int i = startDay; i <= endDay; ++i){
    double diff = values.at(i) - mean;
    sumSqDiff += diff *diff;
  }

  double variance = sumSqDiff / count;
  return std::sqrt(variance);
}

