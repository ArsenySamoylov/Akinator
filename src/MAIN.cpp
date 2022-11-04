#include "Akinator.h"
#include "VisualAkinatorDump.h"
#include "my_log.h"

using namespace tree;
using namespace data;

int main(const int argc, const char* argv[])
    {
    OpenLog();

    if (argc != 0) //! @todo
        printf("TO_DO arguments in main\n");

    DataBase data_base = {};
    SetDataBase(&data_base, "./DataBase/examples/test.ak");

    return 0;
    }