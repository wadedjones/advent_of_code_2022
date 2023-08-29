#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 32

void day_01_part_02()
{
	FILE *fptr;
	char cal_list[MAX_INPUT];
	int n_max = 0; // new max calorie
	int e1, e2, e3; // top 3 elves
	e1 = e2 = e3 = 0;

	fptr = fopen("inputs/text_input_1.txt", "r");

	if (!fptr)
	{
		printf("File does not exist");
		return;
	}

	while (fgets(cal_list, MAX_INPUT, fptr))
	{
		if (*cal_list == '\n')
		{
			if (n_max < e1 && n_max < e2 && n_max < e3)
			{
				n_max = 0;
				continue;
			}
			else if (n_max > e1)
			{
				e2 = e1;
				e1 = n_max;
				n_max = 0;
				continue;
			}
			else if (n_max > e2)
			{
				e2 = n_max;
				n_max = 0;
				continue;
			}
			else if (n_max > e3)
			{
				e3 = n_max;
				n_max = 0;
				continue;
			}
		}
		else
		{
			n_max += atoi(cal_list);
		}
	}

	fclose(fptr);

	printf("E1: %i\n", e1);
	printf("E2: %i\n", e2);
	printf("E3: %i\n", e3);
	printf("Total: %i\n", e1 + e2 + e3);
}
