#ifndef WEATHER_UTILS
#define WEATHER_UTILS
#include "weather.h"
#include "array_helpers.h"


// Month of max rainfall per year in the given table
void max_monthly_rainfall_by_year(WeatherTable array, month_t out[YEARS]);

int total_rainfall_by_month(WeatherTable array, int year, month_t month);

// Max temp per year in the given table
void highest_temp_by_year(WeatherTable array, int out[YEARS]);

// Menor temperatura minima registrada en todos los datos
int lowest_historical_temp(WeatherTable array);







#endif
