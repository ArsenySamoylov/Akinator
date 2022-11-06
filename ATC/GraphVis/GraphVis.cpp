#include "GraphVis.h"

static FILE* Dot = NULL; 


   
// void VisualDump ()
//     {   
//     const char* graph = GetImage(list);
//     AddGraphToHlog(graph);

//     return;
//     }

const char* GetImage ()
    {
    static int num_of_img = 0;

    char      dot_file [MAX_GRAPH_NAME_LENGTH + 16] = {};
    snprintf (dot_file, MAX_GRAPH_NAME_LENGTH, "graphics/dot/list_num_%d.dot", ++num_of_img);
    //printf   ("(%s)\n", dot_file);
    
    OpenDot (dot_file);
    if (!Dot) return NULL;

    SetDot        ();

    // THIS COULD BE THE PLACE FOR YOUR FUNCTION

    SetEndDot     ();

    static char image_name [IMAGE_NAME_LENGTH + 16] = {}; // change for prefix
    snprintf   (image_name,  IMAGE_NAME_LENGTH, "graphics/%d.png", num_of_img);
   
    char      system_command [SYSTEM_COMMAND_LENGTH + 16] = {};
    snprintf (system_command, SYSTEM_COMMAND_LENGTH, "dot -T png -o %s %s", image_name, dot_file);
    //$s(system_command)

    system   (system_command);
    
    CloseDot ();
    return image_name;
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////
void SetDot ()
    {
    if (!Dot) return;

    set_func_name;

    DotPrint("digraph \n{\n");
    DotPrint("rankdir = LR\n");

    return;
    }

void SetEndDot ()
    {
    if (!Dot)   return;

    set_func_name;

    DotPrint("\n}"); 

    fflush(Dot);

    return;   
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////
void DotPrint (const char* format, ...)
    {
    va_list ptr;
    va_start(ptr, format);

    vfprintf (Dot, format, ptr);

    return;
    }

FILE* OpenDot (const char* path)
    {
    if (!path)  return NULL;
    return Dot = fopen (path, "wb"); 
    }

void CloseDot ()
    {
    fclose (Dot);

    Dot = NULL;
    return; 
    }


// //////////////////////////////////////////////////////////////////////////////////////////////////////////////
// void SetNodesArr (ArsList* list)
//     {
//     if (!Dot)   return;
//     if (!list)  return;

//     //VERIFICATE

//     set_func_name;
//     DotPrint("\tsubgraph cluster_node_arr\n\t{\n\t\tbgcolor=lightgray\n");

//     node* node_arr   = list->node_arr;
//     int nodes_number = list->nodes_number;
//     int capacity     = list->capacity;

//     /////////////////////////////////////////////////////////////////node array
//     //*********************** nodes initialization
//     // zero node
//     DotPrint( "\t\tzero_node  [shape = Mrecord label = \"Zero node | {<head> head %d} | {data %0X} | {<tail> tail %d}\"]\n\n", 
//                  node_arr->next, node_arr->data, node_arr->prev);

//     for (index_t i = 1; i < capacity + 1; i++)  
//         PrintNode(node_arr + i, i);

//     //*********************** connect nodes
//     // zero node
//     for (index_t i = 0; i < nodes_number + 1; i++) 
//         ConnectNodes(i, i+1);

//     DotPrint("\n");
//     //*********************** connect prev and next
//     // zero node
//     // what if tail is zero?

//     for (int i = 0; i < nodes_number + 1; i++)
//         ConnectPrevAndNext (node_arr + i, i);

//     DotPrint("\t}\n");
//     return;    
//     }

// void SetListStatus(ArsList* list)
//     {
//     if (!Dot)  return;
//     if (!list) return;

//     set_func_name;

//     DotPrint("\tLIST [shape = Mrecord label = \"List status:  | \\\n" 
//              "\t\t{Capacity %d} | {Active nodes %d} | {%s}\"]",      
//                 list->capacity,  list->nodes_number, list->shuffle_status == SHUFFLED ? "SHUFFLED" : "LINEAR");  

//     DotPrint("\n");

//     return;
//     }

// void ConnectPrevAndNext (node* node_ptr, index_t node_num)
//     {
//     if (!node_ptr) return DotPrint("\t\tLox\n");

//     // head and tail
//     if (!node_num)
//         {
//         DotPrint("\t\tzero_node:<head> -> node%d  [label = \"head\"]\n",   node_ptr->next);
//         DotPrint("\t\tzero_node:<tail> -> node%d  [label = \"tail\"]\n\n", node_ptr->prev);

//         return;
//         }
//     // prev
//     if (node_ptr->prev == -1)
//         {
//         //DotPrint("\t\tnode%d [label = \"FREE NODE\"]\n", node_num);
//         return;
//         }
//     else if (node_ptr->prev == 0)
//         {
//         DotPrint("\t\tnode%d:<prev%d> -> zero_node [arrowhead = normal]\n\n",
//                     node_num, node_num);   
//         }
//     else    
//         {
//         DotPrint("\t\tnode%d:<prev%d> -> node%d [arrowhead = normal]\n\n",
//                     node_num, node_num, node_ptr->prev);                
//         }

//     /*
//         DotPrint((node_ptr->prev)?
//                  "\t\tnode%d:<prev%d> -> zero_node [arrowhead = normal]\n\n" : 
//                  "\t\tnode%d:<prev%d> -> node%d [arrowhead = normal]\n\n",
//                     node_num, node_num, node_ptr->prev);                
//     */

//     // next
//     if (node_ptr->next == 0)
//         {
//         DotPrint("\t\tnode%d:<next%d> -> zero_node [arrowhead = normal]\n\n",
//                     node_num, node_num);    
//         }
//     else 
//         {
//         DotPrint("\t\tnode%d:<next%d> -> node%d        [arrowhead = normal]\n", 
//                     node_num, node_num, node_ptr->next);   
//         }
    
//     return;
//     }


// void ConnectNodes (index_t first, index_t second)
//     {
//     if (!first)
//         return DotPrint ("\n\t\tzero_node -> node1     [weight = 301,  style = \"invis\"]\n");

//     if (!second)
//         return DotPrint ("\n\t\t CAN'T CONNECT NODE (%d) WITH ZERO NODE\n", first);
    
//     DotPrint("\t\tnode%d -> node%d     [weight = 301,  style = \"invis\"]\n", 
//                    first,   second); 
//     return;
//     }


// void PrintNode (node* node_ptr, index_t node_num)
//     {
//     CHECK_PTR_RET(node_ptr, return);

//     if (node_ptr->prev == -1)
//         {
//          DotPrint("\t\tnode%d [shape = circle label = \"Я свободен \\n Вашей маме зять не нужен? \"]\n",               
//                      node_num);                              
//         }
//     else
//         {
//          DotPrint("\t\tnode%d [shape = Mrecord label = \"%d \\nnode | {<next%d> next %d} | {data %d} | {<prev%d> prev %d}\"]\n",    
//                      node_num,              node_num, node_num, node_ptr->next, node_ptr->data, node_num, node_ptr->prev);                                
//         }

//     return;
//     }    
 