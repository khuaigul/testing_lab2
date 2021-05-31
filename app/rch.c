/*
    Хуснутдинова Айгуль, 22107
    Удаление символа справа от позиции курсора
*/

#include "_text.h"
#include <string.h>


void rch(text txt)
{
    node *current = txt->begin;
    /*
        ищем строку, в которой находится курсор
    */
    while(current)
    {
        if (txt->cursor->line == current)
            break;
        current = current->next;
    }
    /*
        Сдвигаем все элементы строки на 1 влево, начиная с элемента после курсора
    */
    for (int i = txt->cursor->position; i < (int)strlen(current->contents)-1; i++)
    {
        current->contents[i] = current->contents[i+1];
    }
    if (txt->cursor->position != (int)strlen(current->contents))
        current->contents[(int)strlen(current->contents)-1] = '\0';
}
