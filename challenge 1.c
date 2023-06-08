#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NULL_PTR 1
#define INCORRECT 2
#define SUCCESS 0

struct my_date {
  int date;
  int month;
  int year;
};

typedef int status_t;

status_t string_to_date_converter(char* input_string, struct my_date* result_date) {
  // Check if the input string is NULL
  if (input_string == NULL) {
    return NULL_PTR;
  }

  // Check if the result date is NULL
  if (result_date == NULL) {
    return NULL_PTR;
  }

  // Split the input string into three parts: date, month, and year
  char* date_str = strtok(input_string, "-");
  char* month_str = strtok(NULL, "-");
  char* year_str = strtok(NULL, "-");

  // Check if the date, month, and year strings are all present
  if (date_str == NULL || month_str == NULL || year_str == NULL) {
    return INCORRECT;
  }

  // Convert the date, month, and year strings to integers
  int date = atoi(date_str);
  int month = atoi(month_str);
  int year = atoi(year_str);

  // Check if the date, month, and year values are valid
  if (date < 1 || date > 31 || month < 1 || month > 12 || year < 1900 || year > 2099) {
    return INCORRECT;
  }

  // Set the values of the result date structure
  result_date->date = date;
  result_date->month = month;
  result_date->year = year;

  // Return SUCCESS
  return SUCCESS;
}

int main() {
  struct my_date date;
  char input_string[100];

  // Get the input string from the user
  printf("Enter a date in the format DD-MM-YYYY: ");
  fgets(input_string, 100, stdin);

  // Convert the input string to a date
  status_t status = string_to_date_converter(input_string, &date);

  // Check the status of the conversion
  if (status == SUCCESS) {
    printf("The date is %02d/%02d/%04d\n", date.date, date.month, date.year);
  } else {
    printf("The date is not in a valid format.\n");
  }

  return 0;
}