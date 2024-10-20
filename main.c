#include "ft_list.h"

void    cap_first(void *s)
{
    printf("-- %s --\n", (char *)s);
}

void    make_null(void **s)
{
    *s = NULL;
}


int main(void)
{
    t_list *list;
    // char   **strings;

    list = NULL;
    ft_list_push_back(&list, "zach");
    ft_list_push_back(&list, "aosh");
    ft_list_push_back(&list, "bick");
    ft_list_push_back(&list, "dsac");
    ft_list_push_back(&list, "cory");
// //    free(list);  segfault

    // printf(" oyesh %s \n", (char *)list->data);
    // free(list);
    // ft_list_remove_if(&list, "zach", strcmp, free);
    // ft_list_del_nth(&list, "lory", free);
    // ft_list_remove_if(&list, "zach", strcmp, free);

    t_list *list2;
    list2 = NULL;
    ft_list_push_back(&list2, "cat");
    ft_list_push_back(&list2, "fish");
    ft_list_push_back(&list2, "dog");

    ft_print_list(&list);
    // ft_list_reverse(list);
    // ft_list_reverse_fun(&list);
    // ft_list_push_pre_nth(list, "zb", );

    // ft_sorted_list_insert(&list, "zaa", strcmp);

    ft_sorted_list_merge(&list, list2, strcmp);


    ft_print_list(&list);

    // ft_list_sort(&list, strcmp);
    // ft_print_list(&list);
    // ft_print_list(&list2);

    // list = ft_list_push_strs(3, strings);
    // ft_list_del_first(&list);
    // ft_list_del_first(&list);
    // ft_list_del_last(&list);
    // ft_list_del_last(&list);
    // ft_list_del_last(&list);
    // ft_list_push_pre_nth(&list, "nick", "ichraq");
    // ft_list_clear(&list, free);
    // ft_list_del_nth(&list, "zach");
    // ft_list_reverse(&list);


    // ft_list_foreach(list, cap_first);
    // ft_list_foreach_if(list, cap_first, "josh", (int (*)(void *, void *))strcmp);
    // ft_list_find(list, "nick", strcmp);
    // ft_list_remove_if(&list, "nick", &strcmp, &free);


    // ft_list_clear(&list, free);
    // int j = 0;
    // while (j < 7)
    // {
    //     if (ft_list_at(list, j))
    //         printf("%s at node %d\n", (char *)(ft_list_at(list, j)->data), j);
    //     else
    //         printf("index %d out of list rang!\n", j);
    //     j++;
    // }

    // ft_print_list(&list);


    return (0);
}