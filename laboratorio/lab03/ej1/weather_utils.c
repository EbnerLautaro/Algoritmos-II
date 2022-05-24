#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"

// array_helpers.h incluye:
// - <stdbool.h>
// - weather.h
// A su vez, weather.h incluye:
// - <stdio.h>

int lowest_historical_temp(WeatherTable array)
{
    int min;
    for (unsigned int year = 0; year < YEARS; year++) // una iteracion por cada año
    {
        for (unsigned int month = 0; month < MONTHS; month++) // una iteracion por cada mes de cada año
        {
            for (unsigned int day = 0; day < DAYS; day++) // una iteracion por cada dia de cada mes de cada año
            {
                if (year == 0 && month == 0 && day == 0)
                {
                    min = array[year][month][day]._min_temp;
                }
                else if (min > array[year][month][day]._min_temp)
                {
                    min = array[year][month][day]._min_temp;
                }
            }
        }
    }
    return min;
}

void highest_temp_by_year(WeatherTable array, int out[YEARS])
{
    int max;
    for (unsigned int year = 0; year < YEARS; year++)
    {
        for (unsigned int month = 0; month < MONTHS; month++) // una iteracion por cada mes de cada año
        {
            for (unsigned int day = 0; day < DAYS; day++) // una iteracion por cada dia de cada mes de cada año
            {
                if (month == 0 && day == 0)
                {
                    max = array[year][month][day]._max_temp;
                }
                else if (max < array[year][month][day]._max_temp)
                {
                    max = array[year][month][day]._max_temp;
                }
            }
        }
        out[year] = max; // asignamos el maximo por cada año
    }
}

int total_rainfall_by_month(WeatherTable array, int year, month_t month)
{
    int total = 0;
    for (unsigned int day = 0; day < DAYS; day++)
    {
        total = total + array[year][month][day]._rainfall;      
    }

    return total;
}

void max_monthly_rainfall_by_year(WeatherTable array, month_t out[YEARS]) {

    // retorna el mes en el que mas precipitaciones hubo en cada año

    month_t max_month;
    for (unsigned int year = 0; year < YEARS; year++)
    {
        for (month_t month = 0; month <= december; month++)
        {
            if (month == january)
            {
                max_month = month;
            } else if (total_rainfall_by_month(array, year, max_month) < total_rainfall_by_month(array, year, month)) {
                max_month = month;
            }
        }  
        out[year] = max_month;
    }
}


