#include "Akinator.h"
#include "VisualAkinatorDump.h"
#include "stdlog.h"

#include <errno.h>

using namespace tree;
using namespace data;

//! @todo safeCalloc, safeFopen,, safeRealloc ??? 

#pragma GCC diagnostic ignored "-Wunused-parameter"
int main(const int argc, const char* argv[])
    {
    OpenLog();
       
    if (argc != 0) //! @todo
        printf("TO_DO arguments in main\n");
 
    DataBase data_base = {};
    SetDataBase(&data_base, "./DataBase/examples/test.ak");

    return LogMsgRet (FAILURE, "Ebat, успех !!!!\n");
    }