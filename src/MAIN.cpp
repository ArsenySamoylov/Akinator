#include "Akinator.h"

using namespace tree;
using namespace data;

//! @todo safeCalloc, safeFopen,, safeRealloc ??? 

#pragma GCC diagnostic ignored "-Wunused-parameter"
int main(const int argc, const char* argv[])
    {
    OpenLog();
       
    // assertlog (NULL, E2BIG, return LogMsgRet ( FAILURE, "BIG COCK!"));

    if (argc != 0) //! @todo
        argv[0]; // ! @todo TODO
 
    DataBase data_base = {};
    SetDataBase(&data_base, "./DataBase/examples/test.ak");

    //VisualDump (&data_base);
   
    return LogMsgRet (SUCCESS, "Ebat, успех !!!!\n");
    }