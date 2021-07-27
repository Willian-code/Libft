#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == 0)
		return (ptr);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    // This pointer will hold the
    // base addres of the block created
    int *ptr;
    int n, i;

    // Get the number of elements for the array
    n = 5;
    printf("Enter number of elements: %d\n", n);

    // Dynamically allocate memory using calloc()
    ptr = (int *)ft_calloc(n, sizeof(int));

    // Check if the memory has been successfully
    // allocated by calloc or not
    if (ptr == NULL)
    {
        printf("Memory not allocated.\n");
        exit (0);
    }
    else
    {
        // Memory bas been successfully allocated
        printf("Memory successfully allocated using calloc.\n");

        // Get the elements of the array
        for (i = 0; i < n; i++)
            ptr[i] = i + 1;

        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; i++)
            printf("%d, ", ptr[i]);
    }
    return (0);
}

*/
