//----------------------------------------------------------
// CS161 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

using doctest::Approx;

#include <iostream>
using namespace std;

#include "stockFunctions.h"

const std::vector<double> TEST_VEC1 = {12.25, 12.15, 12.17, 12.20, 12.06};

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
  double minDrawdown = 0.0;

  for (int i = startDay + 1; i <= endDay; ++i){
    double current = values.at(i);
    if (current > maxSoFar){
      maxSoFar = current;
    } else{
      double drawdown = current - maxSoFar;
      if (drawdown < minDrawdown){
        minDrawdown = drawdown;
      }
    }
  }
  return minDrawdown;
}


TEST_CASE("percentChange")
{
  cout << "1: percentChange" << endl;
  CHECK(percentChange(TEST_VEC1, 1, 2) == Approx(0.164609));
}

TEST_CASE("highestValue")
{
  cout << "2: highestValue" << endl;
  CHECK(highestValue(TEST_VEC1, 1, 3) == Approx(12.20));
}

TEST_CASE("average")
{
  cout << "3: average" << endl;
  CHECK(average(TEST_VEC1, 1, 3) == Approx(12.173333));
}

TEST_CASE("standardDev")
{
  cout << "4: standardDev" << endl;
  CHECK(standardDev(TEST_VEC1, 1, 3) == Approx(0.0205480));
}

TEST_CASE("calculateChangeArray")
{
  cout << "5: getChangeVector" << endl;
  std::vector<double> changes = getChangeVector(TEST_VEC1);

  CHECK(changes.at(1) == Approx(-0.1));
}

TEST_CASE("parseData")
{
  cout << "6: parseData" << endl;

  const string csv = "1.1,12.3,4.6,-1.0";
  std::vector<double> TEST_ARR2 = parseData(csv);
  CHECK(TEST_ARR2.size() == 4);
  CHECK(TEST_ARR2.at(0) == Approx(1.1));
}

TEST_CASE("maxDrawdown")
{
  cout << "7: maxDrawdown" << endl;
  const std::vector<double> TEST_ARR2 = {10.0, 6.0,  20.0, 18.0,
                                         13.0, 11.0, 17.0};
  CHECK(maxDrawdown(TEST_ARR2, 0, 6) == Approx(-9));
}
