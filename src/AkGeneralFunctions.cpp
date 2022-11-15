#include "AkGeneralFunctions.h"

#include "ArsLib.h"
#include "AkUtils.h"
#include "LinuxColors.h"

int Guess (Node* node) 
    {
    assert (node);

    while (node->first_child || node->second_child)
        {  
        printf ("%s?\n", node->data);
        printf ("Да или Нет ????\n");

        int YesOrNo = GetAnswer ();
        
        if (YesOrNo == YES)
            {
            node = node->first_child;

            continue;
            }

        if (YesOrNo == NO)
            {
            node = node->second_child;

            continue;
            }

        if (YesOrNo == QUIT)
            {
            printf ("Я больше не буду гадать\n");

            return QUIT; 
            }

        printf ("Durak, это не ответ Да или Нет !!!! давай заново\n");
        }

    return GuessResult (node);
    }

int GuessResult (Node* node)
    {
    assert(node);

    printf("Вы загадали- %s?\n", node->data);

    int result = GetAnswer ();

    if (result == YES)
        {
        printf ("Я же говорил, что угадаю !\n\n");

        log ("Akinator guessed (%s)\n", node->data);
        return YES;
        }

    if (result == NO)
        {
        printf ("Тысяча чертей!, что же такое Вы тогда загадали?\n");

        char answer[ANSWER_LNGT] = "";
        scanf ("%s", answer);
        ClearBuffer ();

        printf ("Чем же " redcolor "%s\033[0m отличается от \033[92m%s\033[0m?\n", answer, node->data);

        char differrence[ANSWER_LNGT] = "";
        scanf ("%[^\n]", differrence);
             
        printf ("Хотите добавить \033[91m%s\033[0m в базу ?\n", answer);

        result = GetAnswer ();

        if (result == YES)
            if (AddToBase (node, differrence, answer) != SUCCESS)
                printf ("Упссс сомесинг вент вронг ай кант добавить то датабазе\n");
        
        return NO;
        }

    printf ("Вы загадил какую-то хрень\n");
    return FAILURE;
    }