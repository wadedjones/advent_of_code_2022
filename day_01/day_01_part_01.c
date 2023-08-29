#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 32

void day_01_part_01()
{
	FILE *fptr;
	char cal_list[MAX_INPUT];
	int n_max = 0;
	int c_max = 0;

	fptr = fopen("inputs/text_input_1.txt", "r");

	if (!fptr)
	{
		printf("File does  not exist.");
		return;
	}

	while (fgets(cal_list, MAX_INPUT, fptr))
	{
		if (*cal_list == '\n')
		{
			if (n_max > c_max)
			{
				c_max = n_max;
			}
			n_max = 0;
		}
		else
		{
			n_max += atoi(cal_list);
		}
	}

	fclose(fptr);

	printf("C Max: %d\n", c_max);
}
