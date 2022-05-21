#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

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

void basicConfigurations(char colorSetting[])
{
  setlocale(LC_ALL, "spanish");
  SetConsoleCP(1252);
  SetConsoleOutputCP(1252);
  system(colorSetting);
}

time_t getCurrentTime()
{
  time_t rawTime;
  return time(&rawTime);
}

char *getLocaleCurrentTime(time_t *rawTime)
{
  struct tm *timeinfo;
  timeinfo = localtime(&rawTime);
  return asctime(timeinfo);
}

#endif