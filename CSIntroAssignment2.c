
#include <stdio.h>
#include <limits.h>
int Question1(int);
void Question2(int);
int Question3(int);
void Question4(int);

void main()
{
	int n;
	printf("Question 1, enter n:");
	scanf_s("%d", &n);
	printf("%d", Question1(n));
	printf("Question 2, enter n:");
	scanf_s("%d", &n);
	Question2(n);
	printf("Question 3, enter n:");
	scanf_s("%d", &n);
	printf("%d", Question3(n));
	printf("Question 4, enter n:");
	scanf_s("%d", &n);
	Question4(n);

}

int Question1(int p_n)
{
	int n = p_n;
	int currentValue;
	int previousValue = -1;
	int currentRow = 1;
	int currentRowPosition = 1;
	int longestRow = 1;
	int longestRowPosition = 1;


	int count;
	
	for (count = 1;count <= n;count++)
	{
		scanf_s("%d", &currentValue);

		if ((currentValue != previousValue) || (count == n))
		{

			if (currentRow > longestRow)
			{
				longestRow = currentRow;
				longestRowPosition = currentRowPosition;
			}
			currentRowPosition = count;
			currentRow = 1;
		}
		else
		{

			currentRow++;
			if (currentRow > longestRow)
			{
				longestRow = currentRow;
				longestRowPosition = currentRowPosition;
			}

		}
		previousValue = currentValue;
	}
	return longestRowPosition;
}

void Question2(int p_n)
{
	struct Solution
	{
		int x;
		int y;
		int difference;
	};
	struct Solution BestSolution;
	BestSolution.x = 0;
	BestSolution.y = 0;
	BestSolution.difference = INT_MAX;

	int n = p_n;
	int i;
	int j;
	int xTimes3 = 0;
	int yTimes5 = 0;
	int currentDifference;
	for (i = 0;i <= n;i++)
	{
		yTimes5 = 0;
		for (j = 0;j <= n;j++)
		{

			if ((xTimes3 + yTimes5) == n)
			{
				currentDifference = abs((xTimes3 / 3) - (yTimes5 / 5));

				if(currentDifference<BestSolution.difference)
				{
					BestSolution.x = (xTimes3 / 3);
					BestSolution.y = (yTimes5 / 5);
					BestSolution.difference = currentDifference;
				}
			}
			yTimes5 += 5;
		}
		xTimes3 += 3;
	}
	if ((BestSolution.x != 0)||(BestSolution.y != 0))
	{
		printf("The best solution for 3x + 5y = %d is:\nx = %d\ny = %d"
			,n, BestSolution.x, BestSolution.y);
	}
	else 
	{
		printf("There is no solution.");
	}

}

int Question3(int p_n)
{
	int n = p_n;
	int temp = n;
	int sum = 0;
	int currentDigit;
	int currentProduct;
	int lengthOfN =0;
	int i;
	while (temp > 0)
	{
		lengthOfN++;
		temp /= 10;
	}
	temp = n;
	while(temp != 0)
	{
		currentDigit = temp % 10;
		currentProduct = currentDigit;
		temp /= 10;
		for (i = lengthOfN; i > 1;i--)
		{
			currentProduct = currentProduct * currentDigit;
		}
		sum += currentProduct;
	}
	if (sum == n)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void find_divisors_sum(int num, int* sum) 
{
	int i;
	*sum = 1;
	for (i = 2; i * i <= num; i++) {
		if (num % i == 0) {
			*sum += i;
			if (i != num / i) {
				*sum += num / i;
			}
		}
	}
}

void Question4(int p_n)
{
	int a, b, a_sum, b_sum;

	for (a = 2; a < p_n; a++) {
		find_divisors_sum(a, &a_sum);
		b = a_sum;

		if (b > a && b < p_n) {
			find_divisors_sum(b, &b_sum);
			if (b_sum == a) {
				printf("%d and %d are amicable.\n", a, b);
			}
		}
	}
}



