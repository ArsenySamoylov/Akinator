#include "VisualDump.h"

void AddGraphToHlog(const char* image_name)
    {
    if (!image_name) return;

    hlog("\t<img src = \"%s\"\n", image_name);
    hlog("<hr>\n<hr>\n");
    }