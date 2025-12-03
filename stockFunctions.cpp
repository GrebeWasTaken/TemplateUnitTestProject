#include "stockFunctions.h"
#include <cmath>
#include <cstdlib>
#include <sstream>

// calculates Percent change = ((end - start) / start) * 100
double percentChange(const std::vector<double>& values, int startDay,
                     int endDay)
{
  double start = values[startDay];
  double end = values[endDay];

  double change = (end - start) / start * 100;
  return change;
}

// finds highest value
double highestValue(const std::vector<double>& values, int startDay, int endDay)
{
  double best = values.at(startDay);

  for (int i = startDay + 1; i <= endDay; ++i) {
    if (values.at(i) > best) {
      best = values.at(i);
    }
  }
  return best;
}

// average value
double average(const std::vector<double>& values, int startDay, int endDay)
{
  double sum = 0.0;
  int count = endDay - startDay + 1;

  for (int i = startDay; i <= endDay; ++i) {
    sum += values.at(i);
  }
  return sum / count;
}

// standard deviation
double standardDev(const std::vector<double>& values, int startDay, int endDay)
{
  double mean = average(values, startDay, endDay);
  int count = endDay - startDay + 1;

  double sumSqDiff = 0.0;
  for (int i = startDay; i <= endDay; ++i) {
    double diff = values.at(i) - mean;
    sumSqDiff += diff * diff;
  }

  double variance = sumSqDiff / count;
  return std::sqrt(variance);
}

// comma seperated doubles to vectors
std::vector<double> parseData(const std::string& csv)
{
  std::vector<double> result;

  if (csv.empty()) {
    return result;
  }

  std::stringstream ss;
  for (char c : csv) {
    if (c == ',') {
      ss << ' ';
    } else {
      ss << c;
    }
  }

  double value;
  while (ss >> value) {
    result.push_back(value);
  }
  return result;
}

// vector of day to day changes
std::vector<double> getChangeVector(const std::vector<double>& values){
  std::vector<double> changes;

  if (values.empty()){
    return changes;
  }

  changes.resize(values.size());
  changes[0] = 0.0;

  for (std::size_t i = 1; i < values.size(); ++i){
    changes[i] = values[i] - values[i - 1];
  }
  
  return changes;
}

// finds maximum loss, returns negative, 0 if no decline
double maxDrawdown(const std::vector<double>& values, int startDay, int endDay){
  double maxSoFar = values.at(startDay);
  double minDrawdown = 0.0
}
