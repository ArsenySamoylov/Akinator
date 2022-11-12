#include "AkGeneralFunctions.h"

#include "ArsLib.h"
#include "AkUtils.h"

int Guess (Node* node)
    {
    assert (node);

    if (!node->first_child && !node->second_child)
        {
        printf ("Вы загадали - %s ?\n", node->data);

        }

    printf ("%s?\n", node->data);
    printf ("Да или Нет ????\n");

    int YesOrNo = GetAnswer ();
    
    if (YesOrNo == YES)
        {
        Guess (node->first_child);
        }
    
    if (YesOrNo == NO)
        {
        Guess (node->second_child);
        }

    // printf ("Durak, (%s) это не ответ да или нет !!!! давай заново\n", );
    Guess (node);
    }