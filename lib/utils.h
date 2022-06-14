#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <windows.h>


char ERROR_COLOR[100] = "color 4f";
char BASE_COLOR[100]  = "color 0f";

void clearBuffer(char *line)
{
  if (strchr(line, '\n') == NULL)
  {
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
      ;
  }
}

void remove_newline(char *line)
{
  int new_line = strlen(line) - 1;
  if (line[new_line] == '\n')
    line[new_line] = '\0';
}

void readString(char *line, int size)
{
  fgets(line, size, stdin);
  clearBuffer(line);
  remove_newline(line);
}

void waitUser()
{
  printf("Presione enter para continuar...");
  getchar();
}

void basicConfigurations()
{
  setlocale(LC_ALL, "spanish");
  // add support for money print
  setlocale(LC_NUMERIC, "");
  SetConsoleCP(1252);
  SetConsoleOutputCP(1252);
}

time_t getCurrentTime()
{
  time_t rawTime = time(NULL);
  return rawTime;
}

char *getLocaleCurrentTimeFor(time_t *rawTime)
{
  struct tm *timeinfo;
  timeinfo = localtime(rawTime);
  return asctime(timeinfo);
}


void clear_console_and_change_color(char color_config[]){
  system("cls");
  system(color_config);
}

int timeOffset()
{
  time_t gmt, rawtime = time(NULL);
  struct tm *ptm;

#if !defined(WIN32)
  struct tm gbuf;
  ptm = gmtime_r(&rawtime, &gbuf);
#else
  ptm = gmtime(&rawtime);
#endif
  // Request that mktime() looksup dst in timezone database
  ptm->tm_isdst = -1;
  gmt = mktime(ptm);

  return (int)difftime(rawtime, gmt);
}

char *lowerCaseString(char *str)
{
  int len = strlen(str);
  char *result = malloc(len + 1);
  strcpy(result, str);
  int i;
  for (i = 0; i < len; i++)
  {
    result[i] = tolower(result[i]);
  }
  return result;
}

#endif