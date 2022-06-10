#ifndef CALC_TOTAL_SALES_H
#define CALC_TOTAL_SALES_H

#include "../data/bills.c"
#include "../lib/utils.h"
#include <stdio.h>
#include <time.h>
#include <locale.h>

void calculateTotalSalesForTimeSpan(int since)
{
  bill_node *current = bills->head;
  double sumTotal = 0;
  while (current != NULL)
  {
    if (current->value->date >= since)
    {
      printf("#%d: %.2f\n", current->value->number, current->value->total);
      sumTotal = sumTotal + current->value->total;
    }
    current = current->next;
  }
  printf("Ventas totales: $%.2f\n", sumTotal);
}

time_t elapsedTimeToday()
{
  time_t offset = timeOffset();
  time_t currentTime = getCurrentTime() + offset;
  int secondsInDay = 24 * 60 * 60;
  return currentTime % secondsInDay;
}

time_t getStartOfTodayTime()
{
  time_t currentTime = getCurrentTime();
  time_t timeToday = elapsedTimeToday();
  return currentTime - timeToday;
}

void calculateTotalSalesForToday()
{
  time_t currentTime = getCurrentTime();
  printf("\nHora actual: %s \n", getLocaleCurrentTimeFor(&currentTime));
  time_t since = getStartOfTodayTime();
  printf("Total de ordenes desde: %s\n", getLocaleCurrentTimeFor(&since));
  calculateTotalSalesForTimeSpan(since);
}

#endif
