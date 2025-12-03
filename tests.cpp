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
