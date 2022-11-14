#include "Akinator.h"

#include "DataBase.h"
#include "AkGeneralFunctions.h"
#include "AkUtils.h"

#include "ArsLib.h"

//! @todo think about safeCalloc, safeFopen,, safeRealloc ??? 

int main()
    {
    OpenLog ();
    OpenHtmlLog ();
 
    DataBase data_base = {};
    
    int SetDataBase (DataBase* data_base, const char* path);
    SetDataBase(&data_base, "./DataBase/examples/test.ak");

    Greeting ();

    int cmd_code = 0;
    do 
        { 
        printf ("Вводи первую букву (или слово полностью) нужной вам команды:\n");
        PrintCmd ();

        //char answer[ANSWER_LNGT] = "";

        // int  offset   = 0;
        // int  ans_size = 0;
        // scanf (" %n%s%n", &offset, answer, &ans_size);

        // while(getchar() != '\n');

        //log ("User entered: (%s)\n", answer);

        //cmd_code = IsAnswer(answer, ans_size - offset - 1); // cause russian character is 2 chars
        switch (cmd_code = GetAnswer ())
            {
            #define CMD_DEF(cmd, num, cmd_name, code)   \
                case num:                               \
                    {                                   \
                    code                                \
                                                        \
                    break;                              \
                    }                               

            #include "Commands.h"
            #undef CMD_DEF

            default:
                printf ("Lox\n");
                printf ("I don't know this command\n");

                break;
                }
        } while (cmd_code);

    return LogMsgRet (SUCCESS, "Ebat, успех !!!!\n");
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const char GREETING_TEXT [] = "Привет молодой \n"
                         "Дай угадаю: ты хочешь поиграть? \n"
                         "Ну что же, разминай свои конечности и выбирай режим:\n\n";

const char GOODBYE_TEXT []  = "Пока мой друг\n"
                         "Надеюсь ты наигрался со мной ;)\n";

void Greeting (void)
    {
    festsay (GREETING_TEXT);

    return;
    }
    
void GoodBye (void)
    {
    festsay (GOODBYE_TEXT);
    printf ("Еще увидимся, Брат\n");

    return;        
    }
