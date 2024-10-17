#include <iostream>
#include <cstring>

int calculateSpaces(int currentRow, int mid, int rows)
{
  int spaces;
  if (rows % 2 == 1)
    spaces = (2 * (mid - currentRow)) - 2;
  else
    spaces = (2 * (mid - currentRow)) - 3;
  return spaces;
}
bool isNegative(char *str)
{
  bool negative = false;
  if (*str == '-')
  {
    std::cout << "Cannot draw Pattern to negative input" << '\n';
    negative = true;
  }
  return negative;
}
bool isZero(char *str)
{
  bool zero = false;
  if (strcmp(str, "0") == 0)
  {
    std::cout << "Input cannot be zero" << '\n';
    zero = true;
  }
  return zero;
}
bool inputValidation(char *str)
{
  bool isValid = true;
  if (str[0] == '+')
  {
    str++;
  }
  if (isNegative(str))
  {
    isValid = false;
  }
  if (isZero(str))
  {
    isValid = false;
  }
  while (*str != '\0')
  {
    if (!isdigit(*str) && (*str != ' '))
    {
      std::cout << "Invalid input!!! Enter only integer" << '\n';
      isValid = false;
      break;
    }
    if (*str == ' ')
    {
      std::cout << "Invalid input!!! Input should not contain any spaces" << '\n';
      isValid = false;
      break;
    }
    str++;
  }
  return isValid;
}
void printNumbers(int currentRow)
{
  for (int column = 0; column <= currentRow; column++)
  {
    if (column % 2 == 0)
      std::cout << 1 << " ";
    else
      std::cout << 0 << " ";
  }
}

void printTopPattern(int currentRow, int mid, int rows)
{
  printNumbers(currentRow);
  int spaces = calculateSpaces(currentRow, mid, rows);
  for (int column = 0; column <= spaces; column++)
  {
    std::cout << "  ";
  }
  printNumbers(currentRow);
  std::cout << '\n';
}

void printMidPattern(int rows)
{
  for (int currentRow = 0; currentRow < rows; currentRow++)
  {
    if (currentRow % 2 == 0)
      std::cout << 1 << " ";
    else
      std::cout << 0 << " ";
  }
  std::cout << '\n';
}

void printBottomPattern(int currentRow, int rows, int mid)
{
  printNumbers(mid - 1);
  int spaces = ((2 * currentRow) - rows - 1);
  for (int column = 0; column <= spaces; column++)
  {
    std::cout << "  ";
  }
  printNumbers(mid - 1);
  std::cout << '\n';
}

void printPatternOdd(int rows, int mid)
{

  if (rows % 2 == 1)
  {
    for (int currentRow = 0; currentRow < rows; currentRow++)
    {
      if (currentRow < mid)
      {
        printTopPattern(currentRow, mid, rows);
      }
      else if (currentRow == mid)
      {
        printMidPattern(rows);
      }
      else
      {
        printBottomPattern(currentRow, rows, mid);
        mid--;
      }
    }
  }
}

void printPatternEven(int rows, int mid)
{
  for (int currentRow = 0; currentRow < rows; currentRow++)
  {
    if (currentRow < mid)
    {
      printTopPattern(currentRow, mid, rows);
    }

    else
    {
      printBottomPattern(currentRow, rows, mid);
      mid--;
    }
  }
}

int getinput()
{
  int max_length = 10;
  char input[max_length]{};
  int rows;
  std::cout << "enter the number of rows" << "\n";
  std::cin.getline(input, max_length);

  if (inputValidation(input))
  {
    rows = atoi(input);
    return rows;
  }
  else
  {
    return getinput();
  }
}
int main()
{
  int rows = getinput();
  std::cout << "The Pattern for the given input " << rows << " is:" << '\n';
  int mid = (rows / 2);
  if (rows % 2 == 0)
  {
    printPatternEven(rows, mid);
  }
  else
  {
    printPatternOdd(rows, mid);
  }
}
