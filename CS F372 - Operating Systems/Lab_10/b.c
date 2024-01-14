#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("----PRIORITY SCHEDULING----\nEnter Number of Processes: ");
    FILE *fptr = fopen("b.txt", "r");
    int input;
    fscanf(fptr, "%d", &input);

    int arrival_time[input];
    int burst_time[input];
    int priority[input];

    int total_time = 0;

    for (int i = 0; i < input; i++)
    {
        printf("Enter arrival time for process %d: ", i + 1);
        fscanf(fptr, "%d", &arrival_time[i]);
        printf("Enter burst time for process %d: ", i + 1);
        fscanf(fptr, "%d", &burst_time[i]);
        total_time += burst_time[i];
        printf("Enter priority for process %d: ", i + 1);
        fscanf(fptr, "%d", &priority[i]);
    }

    int preemptive;
    printf("Preemptive or Non-Preemptive (1/0):");
    fscanf(fptr, "%d", &preemptive);

    int gantt_chart[total_time];
    int final_time[input];
    int waiting_time[input];

    for (int i = 0; i < input; i++)
        waiting_time[i] = 0;

    if (preemptive == 1)
    {
        printf("\nYou have chosen preemptive scheduling :)\n");
        for (int timestep = 0; timestep < total_time; timestep++)
        {
            // We assume that the process with the lowest priority will be executed first
            // We assume that index i corresponds to the second i to i+1
            int min_priority_index = -1;

            for (int i = 0; i < input; i++)
            {
                if (arrival_time[i] <= timestep && burst_time[i] > 0)
                    if (priority[i] < priority[min_priority_index])
                    {
                        min_priority_index = i;
                    }
            }

            if (min_priority_index != -1)
            {
                gantt_chart[timestep] = min_priority_index + 1;
                final_time[min_priority_index] = timestep + 1;
                burst_time[min_priority_index]--;
            }
            else
            {
                gantt_chart[timestep] = -1;
            }

            for (int i = 0; i < input; i++)
            {
                if (i != min_priority_index && arrival_time[i] <= timestep && burst_time[i] > 0)
                {
                    waiting_time[i]++;
                }
            }
        }
    }
    else
    {
        printf("\nYou have chosen non-preemptive scheduling :)\n");
        int timestep = 0;
        while (timestep < total_time)
        {
            int min_priority_index = -1;

            for (int i = 0; i < input; i++)
            {
                if (arrival_time[i] <= timestep && burst_time[i] > 0)
                    if (priority[i] < priority[min_priority_index])
                    {
                        min_priority_index = i;
                    }
            }

            if (min_priority_index != -1)
            {
                for (int k = 0; k < burst_time[min_priority_index]; k++)
                {
                    gantt_chart[timestep + k] = min_priority_index + 1;
                }
                waiting_time[min_priority_index] = timestep - arrival_time[min_priority_index];
                timestep += burst_time[min_priority_index];
                final_time[min_priority_index] = timestep;
                burst_time[min_priority_index] = 0;
            }
            else
            {
                gantt_chart[timestep] = -1;
                timestep++;
            }
        }
    }

    printf("\nGantt Chart:\n");
    for (int i = 0; i < total_time; i++)
    {
        printf("%d ", gantt_chart[i]);
    }
    printf("\n");

    for (int i = 0; i < input; i++)
    {
        printf("Process %d: AT: %3d Priority: %3d FT: %3d WT: %3d TAT: %3d\n", i + 1, arrival_time[i], priority[i], final_time[i], waiting_time[i], final_time[i] - arrival_time[i]);
    }
}