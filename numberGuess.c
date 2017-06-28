#include <stdio.h>
#include <stdlib.h>

int secret_number(int min_num, int max_num);

int main()
{
  int secretNumber = secret_number(1, 100);
  int guess;
  int chances;

  printf("*Welcome to numberGuess*\n");
  printf("I generated a random number between 1 - 100\n");
  printf("You have 10 chances.");

  for (chances = 10; chances > 0; chances--)
  {
    printf("Enter your guess! \n");
    scanf("%d", &guess);

    if (guess < secretNumber)
    {
      printf("Too small!\n");
      printf("You have %d chances left!\n", chances - 1);
    }
    else if (guess > secretNumber)
    {
      printf("Too big!\n");
      printf("You have %d chances left!\n", chances - 1);
    }
    else
    {
      printf("Congratulations! That was right!\n");
      break;
    }
  }

  printf("The secret number is: %d\n", secretNumber);
  return 0;
}

int secret_number(int min_num, int max_num)
{
  int result = 0, low_num = 0, hi_num = 0;

  if (min_num < max_num)
  {
    low_num = min_num;
    hi_num = max_num + 1;
  }
  else
  {
    low_num = max_num + 1;
    hi_num = min_num;
  }
  srand(time(NULL));
  result = (rand() & (hi_num - low_num)) + low_num;
  return result;
}
