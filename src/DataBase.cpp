#include "DataBase.h"

#include "ArsLib.h"

static void LogNode (const Node* node);

int SetDataBase (DataBase* data_base, const char* path)
    {
    assertlog (data_base, EFAULT, exit(FAILURE));
    assertlog (path,      ENOENT, exit(FAILURE)); // MB in this case open new data base ??? 

    const char* buffer = GetSrcFile(path);
    assertlog (buffer, ENOENT, \
          return  MsgRet (FAILURE, "Can't find data base in path: %s\n", path)); //  MsgNoRet ("TO do: in this case create std empty data base\n") 


    BinaryTree* data_tree = (BinaryTree*) calloc (1, sizeof(data_tree[0]));
    assertlog (data_tree, ENOMEM, return FAILURE);

    Ctor(data_tree);

    BufferToTreeDataBase (data_tree, buffer);

    data_base->buffer    = buffer;
    data_base->data_tree = data_tree;

    return LogMsgRet (SUCCESS, "Data base setted succesfuly (from path: %s)\n\n", path);
    }


int BufferToTreeDataBase (BinaryTree* data_tree, const char* buffer)
    {
    assertlog (data_tree, EFAULT, exit(FAILURE));
    assertlog (buffer,    EINVAL, exit(FAILURE));

    // check that data_tree is empty
    if (data_tree->size)
        return MsgRet (FAILURE, "DataTree must be empty\n");

    // setting everything to start parsing
    buffer = SkipSpaces(buffer);

    Node* current_node = NULL;
    int number_of_nodes = 0;

    // parsing
    while (*buffer)
        {
        if (*buffer == '{')
            {
            Node* new_node = (Node*) calloc (1, sizeof(new_node[0]));
            CHECK_STDERR(new_node, return BAD_CALLOC);

            new_node->parent = current_node;

            buffer = SkipSpaces (++buffer);       // should I free new_node in case of error ??? 
           
            if (*buffer != '"')
                return ParsingErrorMessage (SYNTAX_ERROR, "After { (opening braket) must be \"statement\" in this brakets - \"\n", buffer);

            int n = 0;

            int status = sscanf (++buffer, "%[^\"]%n", new_node->data, &n);

            if (!status)
                return ParsingErrorMessage (SYNTAX_ERROR, "sscanf could't read this line\n", buffer);
            
            if (!n)
                return ParsingErrorMessage (SYNTAX_ERROR, "\"statement\" is empty\n", buffer);

            if (*(buffer + n) != '"')
                return ParsingErrorMessage (SYNTAX_ERROR, "\"statement\" missing closig \" bracket \n", buffer);

            buffer = SkipSpaces(buffer + n + 1);

            new_node->first_child  = NULL;
            new_node->second_child = NULL;

            current_node = new_node;
            number_of_nodes++;

            LogNode (current_node);
            }

        if (*buffer == '}')
            {
            Node* prev_node = current_node->parent;

            // if prev_node is NULL, than current_node is root
            if (!prev_node)
                {
                buffer = SkipSpaces(++buffer);   

                continue;
                }

            if (!prev_node->first_child)
                 prev_node->first_child = current_node;

            else 

                if (!prev_node->second_child)
                     prev_node->second_child = current_node;

                else
                    {
                    printf ("Error in line : ");
                    printl ( buffer, '\n');
                    printf ("Data tree node can't have more then two children\n");

                    return FAILURE;
                    }
                
            // (prev_node->first_child == NULL) ? prev_node->first_child : prev_node->second_child = current_node;
            LogNode (prev_node);

            current_node = prev_node;
            
            buffer = SkipSpaces(++buffer);
            }
        
        if (*buffer != '}' && *buffer != '{')
            {
            printf ("Unknown character %c\n In line: ", *buffer);
            printl ( buffer, '\n');

            return SYNTAX_ERROR; 
            }
        }
    
    // setting everything after parsing

    // check that current_node is root
    log ("\nROOT:::::::::::::::::::::::::::::\n");
    LogNode (current_node);
    log (  ":::::::::::::::::::::::::::::::::\n\n");

    if (current_node->parent)
        return LogMsgRet (FAILURE, "Erro occurred, current_node must have NULL parent\n");

    data_tree->root = current_node;
    data_tree->size = number_of_nodes;

    return SUCCESS;
    }


int ParsingErrorMessage (int return_value, const char* message, const char* buffer)
    {
    printf ("Error in line : ");
    printl (buffer, '\n');
    printf ("%s", message);

    return return_value;
    }


static void LogNode (const Node* node)
    {
    log ("\nparent: %p\nData: (%s)\nAddress: %p\n\tFChild: %p \t Schild: %p\n", node->parent,
                node->data, node, node->first_child, node->second_child);
}                                                                       