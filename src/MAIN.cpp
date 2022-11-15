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
    
    int status = OpenDataBase(&data_base, "./DataBase/sample.ak");
    if (status != SUCCESS)
        return MsgRet (FAILURE, "CAN'T OPEN DATA BASE\n");

    Greeting ();

    int cmd_code = 0;
    do 
        { 
        printf ("Вводи первую букву (или слово полностью) нужной вам команды:\n");
        PrintCmd ();

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

    UpdateDataBase (&data_base);
    // CLOSEDATABASE

    return LogMsgRet (SUCCESS, "Ebat, успех !!!!\n");
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const char GREETING_TEXT [] = "Привет молодой \n";
                        //  "Дай угадаю: ты хочешь поиграть? \n"
                        //  "Ну что же, разминай свои конечности и выбирай режим:\n\n";

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
