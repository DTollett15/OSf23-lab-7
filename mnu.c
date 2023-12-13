#include <stdio.h>
#include <stdlib.h>

// Define data structures and functions for your list and block_t

// ...

void allocate_memory(list_t *freeList, list_t *allocList, int pid, int size, int policy)
{
    // Implement memory allocation based on the specified policy
    // Update freeList and allocList accordingly
    // ...

    // Print allocation information
    printf("Allocated: PID %d, Size %d\n", pid, size);
}

void deallocate_memory(list_t *allocList, list_t *freeList, int pid, int policy)
{
    // Implement memory deallocation
    // Update allocList and freeList accordingly
    // ...

    // Print deallocation information
    printf("Deallocated: PID %d\n", pid);
}

list_t *coalesce_memory(list_t *freeList)
{
    // Implement coalescing to merge physically adjacent memory blocks
    // Update freeList accordingly
    // ...

    // Print coalescing information
    printf("Memory Coalesced\n");

    return freeList;
}

// Function to print the contents of the list
void print_list(list_t *list, char *message)
{
    // Implement function to print list content
    // ...
}

int main(int argc, char *argv[])
{
    // ...

    list_t *freeList = list_alloc();
    list_t *allocList = list_alloc();

    // ...

    for (i = 0; i < N; i++)
    {
        // ...

        if (inputdata[i][0] != -99999 && inputdata[i][0] > 0)
        {
            printf("ALLOCATE: %d FROM PID: %d\n", inputdata[i][1], inputdata[i][0]);
            allocate_memory(freeList, allocList, inputdata[i][0], inputdata[i][1], Memory_Mgt_Policy);
        }
        else if (inputdata[i][0] != -99999 && inputdata[i][0] < 0)
        {
            printf("DEALLOCATE MEM: PID %d\n", abs(inputdata[i][0]));
            deallocate_memory(allocList, freeList, abs(inputdata[i][0]), Memory_Mgt_Policy);
        }
        else
        {
            printf("COALESCE/COMPACT\n");
            freeList = coalesce_memory(freeList);
        }

        // ...

        print_list(freeList, "Free Memory");
        print_list(allocList, "\nAllocated Memory");
        printf("\n\n");
    }

    // ...

    return 0;
}
