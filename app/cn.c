/*
    Хуснутдинова Айгуль, 22107
    смена мест текущей строки со следующей
*/

#include "_text.h"
#include <string.h>

void cn(text txt)
{
    node *current;

    /*
        Находим строку с курсором
    */
    current = txt->cursor->line;

    if (current == txt->end)
    {
        printf("Uncorrect data\n");
    }
    else if (current != txt->begin && current->next != txt->end)
    {

        current->next->previous = current->previous;
        current->previous->next = current->next;

        current->next->next->previous = current;
        current->previous = current->next;

        current->next = current->next->next;
        current->previous->next = current;
    }
    else if(current == txt->begin)
    {
        current->next->previous = 0;

        if (current->next != txt->end)
            current->next->next->previous=current;

        current->previous = current->next;

        if (current->next != txt->end)
            current->next = current->next->next;

        current->previous->next = current;
        txt->begin = current->previous;

        if (current->previous == txt->end)
        {
            current->next = 0;
            txt->end = current;
        }
    }
    else
    {
        current->previous->next = current->next;
        current->next->previous = current->previous;

        current->next->next = current;
        current->previous = current->next;

        current->next = 0;
        txt->end = current;
    }
}
