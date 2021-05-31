#include "_text.h"
#include <string.h>

void m(text txt, int line, int position)
{
    int cur_line = 0;

    node *current = txt->begin;
    while (current)
    {
        if (cur_line == line)
            break;
        current = current->next;
        cur_line++;
    }

//    if(((int)strlen(current->contents) < line) || current == 0)
//        printf("Error\n");

    if(line > (int)txt->length)
    {
            current = txt->end;
            position = (int)strlen(current->contents);
    }

    else if (position > (int)strlen(current->contents))
            position = (int)strlen(current->contents);
    txt->cursor->line = current;
    txt->cursor->position = position;
}
