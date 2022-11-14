#include "AkGeneralFunctions.h"

#include "ArsLib.h"
#include "AkUtils.h"

int Guess (Node* node)
    {
    assert (node);

    if (!node->first_child && !node->second_child)
        return GuessResult (node);

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

    if (YesOrNo == QUIT)
        {
        printf ("Я больше не буду гадать\n");

        return QUIT; 
        }

    printf ("Durak, это не ответ Да или Нет !!!! давай заново\n");
    
    return Guess (node);
    }

int GuessResult (Node* node)
    {
    assert(node);

    printf("Вы загадали- %s?\n", node->data);

    int result = GetAnswer ();

    if (result == YES)
        {
        printf ("Я же говорил, что угадаю !\n");

        log ("Akinator guessed (%s)\n", node->data);
        return YES;
        }

    if (result == NO)
        {
        printf ("Тысяча чертей!, что же такое Вы тогда загадали?\n");

        char answer[ANSWER_LNGT] = "";
        scanf ("%s", answer);

        printf ("Чем же %s отличается от %s?\n", answer, node->data);

        char differrence[ANSWER_LNGT] = "";
        scanf ("%s", differrence);

        printf ("Хотите добавить %s в базу ?\n", answer);

        result = GetAnswer ();

        if (result == YES)
            if (AddToBase (node, differrence, answer) != SUCCESS)
                printf ("Упссс сомесинг вент вронг ай кант добавить то датабазе\n");
        
        return NO;
        }

    printf ("Вы загадил какую-то хрень\n");
    return FAILURE;
    }