
#include <stdio.h>

int main()
{
	int n;
	int count = 1;
	int currentValue;
	int previousValue;
	int longestRowPosition;
	int currentRowLength=0;
	int longestRowLength=0;
	int i;
	scanf_s("%d", &n);
	for (i=1;i<=n;i++)
	{
		scanf_s("%d", &currentValue);
		if (count == 1)
		{
			previousValue = currentValue;
		}
		if (currentValue==previousValue)
		{
			longestRowPosition = count-i;
		}
		else 
		{
			count = 0;
		}
		previousValue = currentValue;
		count++;
	}

}
