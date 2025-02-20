#include "push_swap.h"

// #define CHUNK_SIZE 20  // Adjust based on input size

// // Find the median of a stack
// int find_median(t_list *stack, int size)
// {
//     int *arr = lst_to_array(stack, size); // Convert list to array
//     quicksort(arr, 0, size - 1); // Sort array
//     int median = arr[size / 2]; // Middle value
//     free(arr);
//     return median;
// }

// // Convert linked list to array
// int *lst_to_array(t_list *stack, int size)
// {
//     int *arr = malloc(size * sizeof(int));
//     if (!arr) return NULL;
    
//     for (int i = 0; i < size; i++)
//     {
//         arr[i] = stack->content;
//         stack = stack->next;
//     }
//     return arr;
// }

//  int find_min_index(t_list *a)
// {
//     int min = INT_MAX, index = 0, min_index = 0;
//     t_list *temp = a;

//     while (temp)
//     {
//         if (temp->content < min)
//         {
//             min = temp->content;
//             min_index = index;
//         }
//         temp = temp->next;
//         index++;
//     }
//     return min_index;
// }


// int find_best_position_in_a(t_list *a, int number)
// {
//     int index = 0, best_index = 0;
//     int best_value = INT_MAX;
//     t_list *temp = a;

//     while (temp)
//     {
//         if (temp->content > number && temp->content < best_value)
//         {
//             best_value = temp->content;
//             best_index = index;
//         }
//         temp = temp->next;
//         index++;
//     }

//     // If the number is the biggest, insert it at the end
//     return (best_value == INT_MAX) ? index : best_index;
// }
// void rotate_to_top(t_list **stack, int index)
// {
//     int size = lst_count(*stack);

//     if (index <= size / 2)
//     {
//         while (index-- > 0)
//             rotate_a(stack);
//     }
//     else
//     {
//         index = size - index; // Fix reverse rotation count
//         while (index-- > 0)
//             reverse_rotate_a(stack);
//     }
// }
// // Push elements from A to B using chunk sorting
// void push_chunks_to_b(t_list **a, t_list **b)
// {
//     int size = lst_count(*a);
//     int num_chunks = size / CHUNK_SIZE + (size % CHUNK_SIZE != 0);
    
//     for (int i = 1; i <= num_chunks; i++)
//     {
//         int chunk_median = find_median(*a, lst_count(*a));

//         // Move numbers <= median to B
//         int count = lst_count(*a);
//         while (count--)
//         {
//             if ((*a)->content <= chunk_median)
//                 push_b(a, b);
//             else
//                 rotate_a(a);  // Keep bigger elements in A for later
//         }
//     }
// }

// // Move back to A (sorted order)
// void move_back_to_a(t_list **a, t_list **b)
// {
//     while (*b)
//     {
//         int best_pos = find_best_position_in_a(*a, (*b)->content);
//         rotate_to_top(a, best_pos);
//         push_a(a, b);
//     }
// }

// // Chunk-based sorting algorithm
// void chunk_sort(t_list **a, t_list **b)
// {
//     push_chunks_to_b(a, b); // Move in chunks
//     sort_3_num(a);          // Sort remaining small numbers
//     move_back_to_a(a, b);   // Move back in sorted order
//     rotate_to_top(a, find_min_index(*a)); // Final alignment
// }


// // Swap two integers
// void swap(int *a, int *b)
// {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// // Partition function for quicksort
// int partition(int *arr, int low, int high)
// {
//     int pivot = arr[high]; // Choose the last element as pivot
//     int i = low - 1;       // Pointer for the smaller element

//     for (int j = low; j < high; j++)
//     {
//         if (arr[j] <= pivot) // If element is smaller than pivot
//         {
//             i++;
//             swap(&arr[i], &arr[j]);
//         }
//     }
//     swap(&arr[i + 1], &arr[high]);
//     return i + 1;
// }

// Quicksort algorithm
// void quicksort(int *arr, int low, int high)
// {
//     if (low < high)
//     {
//         int pi = partition(arr, low, high); // Find partition index

//         quicksort(arr, low, pi - 1);  // Sort left subarray
//         quicksort(arr, pi + 1, high); // Sort right subarray
//     }
// }


int find_best_position_in_a(t_list *a, int number)
{
    int index = 0, best_index = 0;
    int best_value = INT_MAX;
    t_list *temp = a;

    while (temp)
    {
        if (temp->content > number && temp->content < best_value)
        {
            best_value = temp->content;
            best_index = index;
        }
        temp = temp->next;
        index++;
    }
    return best_index;
}
// Swap two integers
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for quicksort
int partition(int *arr, int low, int high)
{
    int pivot = arr[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quicksort algorithm
void quicksort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}


// Chunk sorting function
void chunk_sort(t_list **a, t_list **b)
{
    push_chunks_to_b(a, b);  // Split stack into chunks and push to b
    move_back_to_a(a, b);    // Move elements back to a in the correct order
    rotate_to_top(a, find_min_index(*a));  // Final adjustment if needed
}


int *lst_to_array(t_list *stack, int size)
{
    if (!stack || size == 0) return NULL;  // Handle empty stack

    int *arr = malloc(size * sizeof(int));
    if (!arr) return NULL;

    for (int i = 0; i < size; i++)
    {
        arr[i] = stack->content;
        stack = stack->next;
    }
    return arr;
}

// Split stack A into chunks and push to B
void push_chunks_to_b(t_list **a, t_list **b)
{
    int size = lst_count(*a);
    int chunk_size = size / ft_sqrt(size);

    if (chunk_size == 0) chunk_size = 1;  // Prevent division by zero

    int *arr = lst_to_array(*a, size);
    if (!arr) return;  // Prevent NULL array access

    quicksort(arr, 0, size - 1);

    for (int i = 0; i * chunk_size < size; i++)
    {
        // Get the median for the current chunk
        int median = arr[i * chunk_size + (chunk_size / 2)];
        t_list *tmp = *a;
        int index = 0;
        
        // Push elements to b based on median
        while (tmp)
        {
            if (tmp->content <= median)
            {
                rotate_to_top(a, index);
                push_b(a, b);
                tmp = *a;  // Reassign tmp after push
                index = 0; // Reset index to 0 after push
            }
            else
            {
                tmp = tmp->next;
                index++;
            }
        }
    }
    free(arr);
}

// Move elements back to A
void move_back_to_a(t_list **a, t_list **b)
{
    while (*b)
    {
        // Find the best position for each element from b
        int best_pos = find_best_position_in_a(*a, (*b)->content);
        rotate_to_top(a, best_pos);
        push_a(a, b);
    }
}

// Find index of the smallest number
int find_min_index(t_list *a)
{
    int min = INT_MAX, index = 0, min_index = 0;
    t_list *temp = a;

    while (temp)
    {
        if (temp->content < min)
        {
            min = temp->content;
            min_index = index;
        }
        temp = temp->next;
        index++;
    }
    return min_index;
}

// Rotate a certain index to the top
void rotate_to_top(t_list **stack, int index)
{
    int size = lst_count(*stack);
    if (index < size / 2)
    {
        while (index-- > 0)
            rotate_a(stack);  // Assuming rotate_a moves top element to bottom
    }
    else
    {
        while (index++ < size)
            reverse_rotate_a(stack);  // Assuming reverse_rotate_a moves bottom to top
    }
}

int ft_sqrt(int nb)
{
    if (nb <= 0)
        return 0; // Handle the case of zero or negative numbers gracefully
    
    int s = 1;
    while (s * s <= nb)
    {
        if (s * s == nb)
            return s;
        s++;
    }
    return s - 1;  // Return closest integer square root
}