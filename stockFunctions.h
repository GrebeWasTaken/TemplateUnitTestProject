//----------------------------------------------------------
// CS161 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

#ifndef STOCK_FUNCTIONS_H
#define STOCK_FUNCTIONS_H

#include <vector>
#include <string>

/**
 * @brief Calculates the percent change in value from startDay to endDay.
 * 
 * @param values vector of stock values.
 * @param startDay First day - inclusive.
 * @param endDay Last day - inclusive.
 * @return double Percent change from startDay to endDay.
 */
double percentChange(const std::vector<double>& values, int startDay, int endDay);


/**
 * @brief Calculates and returns the highest value of the stock
 *  in the range that starts at startDay and ends at endDay.
 * @param values vector of stock values
 * @param startDay First day - inclusive
 * @param endDay Last day - inclusive
 * @return Highest value found
 *
 * The start and end are both inclusive - the highest value might be one
 * of them.
 *
 * Given this vector: 12.25, 12.15, 12.17, 12.20, 12.06
 *
 * The highestValue from 1 through 3 is 12.20
 */
double highestValue(const std::vector<double>& values, int startDay, int endDay);


/**
 * @brief Find the average value within a range of days
 * @param values vector of stock values
 * @param startDay First day - inclusive
 * @param endDay Last day - inclusive
 * @return mean of values
 *
 * Given this vector: 12.25, 12.15, 12.17, 12.20, 12.06
 *
 * The average from 1 through 3 is ~12.17333333333333333
 */
double average(const std::vector<double>& values, int startDay, int endDay);


/**
 * @brief Find the standard deviation for the values within a range of days
 * @param values vector of stock values
 * @param startDay First day - inclusive
 * @param endDay Last day - inclusive
 * @return standard deviation of values
 *
 * Given this vector: 12.25,12.15,12.17,12.20,12.06
 *
 * The stddev from 1 through 3 is ~0.0205480466766
 *
 * How to calculate standard deviation - this is a "population" standard deviation.
 * 1) Calculate the average of the items.
 * 2) For each item, subtract the average value, then square this difference. 
 *    Sum up these values.
 * 3) Divide by the number of items.
 * 4) Take the square root.
 * 
 * https://www.khanacademy.org/math/statistics-probability/summarizing-quantitative-data/variance-standard-deviation-sample/a/population-and-sample-standard-deviation-review
 */
double standardDev(const std::vector<double>& values, int startDay, int endDay);


/**
 * @brief Parse a comma-separated list of doubles into a vector
 * @param csv comma-separated string of doubles (there will not be spaces between)
 * @return vector of parsed doubles
 *
 * Example: "1.1,12.3,4.6,-1.0" -> {1.1, 12.3, 4.6, -1.0}
 * 
 * Note: there is not a magic one-liner to do this.
 * Think in terms of "find the next comma, extract the substring up to that comma"
 * and repeat until done.
 * 
 */
std::vector<double> parseData(const std::string& csv);


/**
 * @brief Calculate the amount each element in values changed from the previous
 *        value and return the result vector. The change for the first element
 *        will always be considered to be 0.
 * @param values vector of stock values
 * @return vector of changes (same length as values)
 *
 * Given this vector with size 5: 12.25, 12.15, 12.17, 12.20, 12.06
 * changes should be set to:     0      -0.1   0.02   0.03   -0.14
 */
std::vector<double> getChangeVector(const std::vector<double>& values);


/**
 * @brief Calculates the worst drop in value that might be
 *        experienced by an investor during the indicated time period.
 * @param values vector of stock values
 * @param startDay First day - inclusive
 * @param endDay Last day - inclusive
 * @return The worst possible loss, expressed in $s. If the price never
 *          declines, returns 0.
 *
 * This function determines the worst possible investment situation within
 * a given time period. i.e. How much money you could possibly lose if you
 * bought at some point at or after startDay and then sold before or on endDay.
 *
 * Given this array with size 7: 10.0, 6.0, 20.0, 18.0, 13.0, 11.0, 17.0
 * The maxDrawDown from 0 to 6 is -9.0 (Buy on day 2, sell on day 5)
 * The maxDrawDown from 0 to 3 is -4.0 (Buy on day 0, sell on day 1)
 * The maxDrawDown from 3 to 5 is -7.0 (Buy on day 3, sell on day 5)
 * The maxDrawDown from 1 to 2 is 0 (No decline)
 */
double maxDrawdown(const std::vector<double>& values, int startDay, int endDay);


#endif // STOCK_FUNCTIONS_H
