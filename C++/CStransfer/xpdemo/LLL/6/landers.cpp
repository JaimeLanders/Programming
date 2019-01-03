#include "list.h"

bool list::duplicateData()
{
    bool found = false;

    if (head != NULL)
    {
        found = duplicateData(head);
    }

    return found;
}

bool list::duplicateData(node * head)
{
    bool found = false;

    if (head != NULL)
    {
        if (duplicateDataHelper(head->next, head->data) == true)
        {
            found = true;
        
        }
        else
        {
            found = duplicateData(head->next);
        }
    }

    return found;
}

bool list::duplicateDataHelper(node * head, int data)
{
    bool found = false;

    if (head != NULL)
    {
        if (head->data == data)
        {
            found = true;
        }
        else
        {
            found = duplicateDataHelper(head->next, data);
        }
    }

    return found;
}

