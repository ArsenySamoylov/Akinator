#include "AkUtils.h"

#include "string.h"
#include "ArsLib.h"

void VisualDump (DataBase* data_base)
    {
    assert (data_base);

    const char* img = MakeImg ("sample", data_base->data_tree);
    AddImage (img);

    return;
    }

int IsAnswer (const char* answer, int ans_size)
    {
    assert(answer);

    #define CMD_DEF(cmd, num, cmd_name, code)              \
            if (!strnicmprus (answer, cmd_name, ans_size))    \
                return num;     
    
    #include "Commands.h"
    #undef CMD_DEF

    if (!strnicmprus (answer, "Да", ans_size))  
        return YES;     

    if (!strnicmprus (answer, "Нет", ans_size))  
        return NO;   

    return NOT_A_COMMAND;
    }

int IsYesOrNo (const char* text, int text_size)
    {
    assert (text);

    if (!strnicmp (text, "Да", text_size))  
        return YES;     

    if (!strnicmp (text, "Нет", text_size))  
        return NO;     
        
    return LOX;
    }

void PrintCmd ()
    {
    #define CMD_DEF(cmd, num, cmd_name, code) \
             printf ("\033[9%dm%s  \033[0m", rand() % 7 + 1, cmd_name);    
    #include "Commands.h"
    #undef CMD_DEF

    printf ("\n");

    return;
    }

int GetAnswer ()
    {
    static char answer [ANSWER_LNGT] = "";
    memset (answer, 0,  ANSWER_LNGT);

    int offset   = 0;
    int ans_size = 0;

    scanf ("%n%s%n", &offset, answer, &ans_size);
    log ("User entered: (%s)\n", answer);

    // clearing buffer
    while(getchar() != '\n');

    int ret_val = IsAnswer (answer, ans_size - offset - 1);
    log ("Akinator cmd: %d\n\n", ret_val);

    if (ret_val == NOT_A_COMMAND)
        printf ("Durak, (%s) это не команда\n", answer);
    
    return ret_val; 
    }

int AddToBase (Node* node, const char* difference, const char* new_ans)
    {
    assert(node); assert (difference); assert (new_ans);

    if (AddChildren (node) != SUCCESS)
        return FAILURE;

    strcpy (node->first_child ->data, new_ans);
    strcpy (node->second_child->data, node->data);
    
    strcpy (node->data, difference);

    return SUCCESS;
    }