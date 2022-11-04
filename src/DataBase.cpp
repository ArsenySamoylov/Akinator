#include "DataBase.h"


namespace data{

int SetDataBase (DataBase* data_base, const char* path)
    {
    CHECK_STDERR(data_base, return NULL_PTR);
    CHECK_STDERR(path,      return NULL_PTR);  // MB in this case open new data base ??? 

    const char* buffer = GetSrcFile(path);
    if (!buffer)
        {
        printf ("Can't find data base in path: %s\n", path);
        printf ("TO do: in this case create std empty data base\n");

        return FAILURE;
        }

    DataTree* data_tree = (BinaryTree*) calloc (1, sizeof(data_tree[0]));
    CHECK_STDERR(data_tree, return BAD_CALLOC);

    Ctor(data_tree);

    BufferToTreeDataBase (data_tree, buffer);



    //data_base->buffer = buffer;

    return SUCCESS;
    }


int BufferToTreeDataBase (DataTree* data_tree, const char* buffer)
    {
    CHECK_STDERR(data_tree,  return NULL_PTR);
    CHECK_STDERR(buffer,     return NULL_PTR);

    // check that data_tree is empty
    if (data_tree->size)
        return MessageReturn (FAILURE, "DataTree must be empty\n");

    // setting everything to start parsing
    buffer = SkipSpaces(buffer);

    Node* current_node = NULL;
    int number_of_nodes = 0;

    // parsing
    while (!buffer)
        {
        if (*buffer == '{')
            {
            Node* new_node = (Node*) calloc (1, sizeof(new_node[0]));
            CHECK_STDERR(new_node, return BAD_CALLOC);

            new_node->parent = current_node;

            buffer = SkipSpaces (buffer);       // should I free new_node in case of error ??? 
            if (*buffer != '"')
                return ParsingErrorMessage (SYNTAX_ERROR, "After { (opening braket) must be \"statement\" in this brakets - \"\n", buffer);

            int n = 0;

            int status = sscanf (buffer, "%s[^\"]%n", new_node->data, &n);

            if (!status)
                return ParsingErrorMessage (SYNTAX_ERROR, "sscanf could't read this line\n", buffer);

            if (!n)
                return ParsingErrorMessage (SYNTAX_ERROR, "\"statement\" is empty\n", buffer);

            if (*buffer != '"')
                return ParsingErrorMessage (SYNTAX_ERROR, "\"statement\" missing closig \" bracket \n", buffer);

            buffer = SkipSpaces(buffer + n + 1);

            new_node->first_child  = NULL;
            new_node->second_child = NULL;

            number_of_nodes++;
            }

        if (*buffer == '}')
            {
            // return to prev node
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
                    printl (buffer, '\n');
                    printf ("Data tree node can't have more then two children\n");

                    return FAILURE;
                    }
                
            // (prev_node->first_child == NULL) ? prev_node->first_child : prev_node->second_child = current_node;

            current_node = prev_node;

            buffer = SkipSpaces(++buffer);
            }
        }
    
    // setting everything after parsing

    // check that current_node is root
    if (!current_node->parent)
        return MessageReturn (FAILURE, "Erro occurred, current_node must have NULL parent\n");

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
}