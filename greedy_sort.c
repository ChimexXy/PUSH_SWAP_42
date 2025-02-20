// #include "push_swap.h"

// // // Push all elements except the last 3 to stack B
// // void move_to_b(t_list **a, t_list **b)
// // {
// //     while (lst_count(*a) > 3) // Keep last 3 in A
// //     {
// //         int best_index = find_best_move(*a, *b);
// //         rotate_to_top(a, best_index); // Bring element to top
// //         push_b(a, b); // Push to B
// //     }
// // }

// // // Move all elements from B back to A in sorted order
// // void move_back_to_a(t_list **a, t_list **b)
// // {
// //     while (*b)
// //     {
// //         int best_pos = find_best_position_in_a(*a, (*b)->content);
// //         rotate_to_top(a, best_pos);  // Rotate A to best insertion position
// //         push_a(a, b);  // Push top of B to A
// //     }
// // }

// // // Find the index where the number should be inserted in A
// // int find_best_position_in_a(t_list *a, int number)
// // {
// //     int index = 0;
// //     int best_index = 0;
// //     int best_value = INT_MAX;
// //     t_list *temp = a;

// //     while (temp)
// //     {
// //         if (temp->content > number && temp->content < best_value)
// //         {
// //             best_value = temp->content;
// //             best_index = index;
// //         }
// //         temp = temp->next;
// //         index++;
// //     }

// //     // If no suitable place is found, insert at the end
// //     if (best_value == INT_MAX)
// //         return 0;
// //     return best_index;
// // }

// // // Find index of smallest number in A
// // int find_min_index(t_list *a)
// // {
// //     int min = INT_MAX, index = 0, min_index = 0;
// //     t_list *temp = a;

// //     while (temp)
// //     {
// //         if (temp->content < min)
// //         {
// //             min = temp->content;
// //             min_index = index;
// //         }
// //         temp = temp->next;
// //         index++;
// //     }
// //     return min_index;
// // }

// // // Rotate stack so the given index moves to the top
// // void rotate_to_top(t_list **stack, int index)
// // {
// //     int size = lst_count(*stack);
    
// //     if (index <= size / 2)
// //     {
// //         while (index-- > 0)
// //             rotate_a(stack);
// //     }
// //     else
// //     {
// //         while (index++ < size)
// //             reverse_rotate_a(stack);
// //     }
// // }

// // // Find the position of a number in stack A
// // int find_index(t_list *stack, int number)
// // {
// //     int index = 0;
// //     while (stack)
// //     {
// //         if (stack->content == number)
// //             return index;
// //         stack = stack->next;
// //         index++;
// //     }
// //     return -1;
// // }

// // // Find where a number should be inserted in B
// // int find_best_position_in_b(t_list *b, int number)
// // {
// //     int index = 0;
// //     int best_index = 0;
// //     int best_value = INT_MIN;
// //     t_list *temp = b;

// //     while (temp)
// //     {
// //         if (temp->content < number && temp->content > best_value)
// //         {
// //             best_value = temp->content;
// //             best_index = index;
// //         }
// //         temp = temp->next;
// //         index++;
// //     }

// //     // If no suitable place is found, insert at the top
// //     if (best_value == INT_MIN)
// //         return 0;
// //     return best_index;
// // }

// // // Calculate the number of moves needed to push an element from A to B
// // int calculate_moves(t_list *a, t_list *b, int index)
// // {
// //     int a_moves = 0;
// //     int b_moves = 0;
// //     int size_a = lst_count(a);
// //     int size_b = lst_count(b);
    
// //     // Moves needed to bring index to top of A
// //     if (index <= size_a / 2)
// //         a_moves = index; // Rotate up (ra)
// //     else
// //         a_moves = size_a - index; // Rotate down (rra)

// //     // Moves needed to find the best position in B
// //     t_list *tmp = get_nth(a, index);
// //     int best_b_pos = find_best_position_in_b(b, tmp->content);
// //     if (best_b_pos <= size_b / 2)
// //         b_moves = best_b_pos; // Rotate up (rb)
// //     else
// //         b_moves = size_b - best_b_pos; // Rotate down (rrb)

// //     // Return the total moves needed
// //     return a_moves + b_moves;
// // }

// // // Get the nth element from the list
// // t_list *get_nth(t_list *stack, int n)
// // {
// //     t_list *tmp = stack;
// //     while (n-- > 0 && tmp)
// //         tmp = tmp->next;
// //     return tmp;
// // }

// // // Find the position of the best move (minimizing operations)
// // int find_best_move(t_list *a, t_list *b)
// // {
// //     int min_moves = INT_MAX;
// //     int best_index = 0;
// //     int index = 0;
// //     t_list *temp = a;

// //     while (temp)
// //     {
// //         int moves = calculate_moves(a, b, index);
// //         if (moves < min_moves)
// //         {
// //             min_moves = moves;
// //             best_index = index;
// //         }
// //         temp = temp->next;
// //         index++;
// //     }
// //     return best_index;
// // }

// // // Main greedy sort function
// // void greedy_sort(t_list **a, t_list **b)
// // {
// //     move_to_b(a, b); // Push most elements to B
// //     sort_3_num(a);   // Sort the remaining 3 elements in A
// //     move_back_to_a(a, b); // Move everything back to A
// //     rotate_to_top(a, find_min_index(*a)); // Final alignment
// // }


// // Push all elements except last 3 to stack B
// void move_to_b(t_list **a, t_list **b)
// {
//     while (lst_count(*a) > 3) // Keep last 3 in A
//     {
//         int best_index = find_best_move(*a, *b);
//         rotate_to_top(a, best_index); // Bring element to top
//         push_b(a, b); // Push to B
//     }
// }

// // Move all elements from B back to A in sorted order
// void move_back_to_a(t_list **a, t_list **b)
// {
//     while (*b)
//     {
//         int best_pos = find_best_position_in_a(*a, (*b)->content);
//         rotate_to_top(a, best_pos); // Rotate A to best insertion position
//         push_a(a, b); // Push top of B to A
//     }
// }

// // Find the index where the number should be inserted in A
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

// // Find the index of the smallest number in A
// int find_min_index(t_list *a)
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

// // Rotate stack so the given index moves to the top
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

// // Find where a number should be inserted in B
// int find_best_position_in_b(t_list *b, int number)
// {
//     int index = 0, best_index = 0;
//     int best_value = INT_MIN;
//     t_list *temp = b;

//     while (temp)
//     {
//         if (temp->content < number && temp->content > best_value)
//         {
//             best_value = temp->content;
//             best_index = index;
//         }
//         temp = temp->next;
//         index++;
//     }

//     // If the number is smaller than all in B, insert it at the top
//     return (best_value == INT_MIN) ? index : best_index;
// }

// // Calculate the number of moves needed to push an element from A to B
// int calculate_moves(t_list *a, t_list *b, int index)
// {
//     int a_moves = 0, b_moves = 0;
//     int size_a = lst_count(a);
//     int size_b = lst_count(b);

//     // Moves needed to bring index to top of A
//     a_moves = (index <= size_a / 2) ? index : size_a - index;

//     // Get nth element safely
//     t_list *tmp = get_nth(a, index);
//     if (!tmp) 
//         return INT_MAX; // Safety check for NULL

//     int best_b_pos = find_best_position_in_b(b, tmp->content);
//     b_moves = (best_b_pos <= size_b / 2) ? best_b_pos : size_b - best_b_pos;

//     return a_moves + b_moves;
// }

// // Get the nth element from the list
// t_list *get_nth(t_list *stack, int n)
// {
//     t_list *tmp = stack;
//     while (n-- > 0 && tmp)
//         tmp = tmp->next;
//     return tmp;
// }

// // Find the position of the best move (minimizing operations)
// int find_best_move(t_list *a, t_list *b)
// {
//     int min_moves = INT_MAX, best_index = 0, index = 0;
//     t_list *temp = a;

//     while (temp)
//     {
//         int moves = calculate_moves(a, b, index);
//         if (moves < min_moves)
//         {
//             min_moves = moves;
//             best_index = index;
//         }
//         temp = temp->next;
//         index++;
//     }
//     return best_index;
// }

// // Main greedy sort function
// void greedy_sort(t_list **a, t_list **b)
// {
//     move_to_b(a, b); // Push most elements to B
//     sort_3_num(a);   // Sort the remaining 3 elements in A
//     move_back_to_a(a, b); // Move everything back to A
//     rotate_to_top(a, find_min_index(*a)); // Final alignment
// }
