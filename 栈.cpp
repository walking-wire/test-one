
char * removeDuplicates(char * S)
{
    char * Stack = (char*)malloc(strlen(S)+1);
    int top = 0;
    for(int i = 0; i< strlen(S); i++)
    {
        Stack[top] = S[i];
        if(top >0 && Stack[top] == Stack[top-1])
        {
            top--;
            continue;
        }
        top++;
    }
    Stack[top] = '\0';
    return Stack;
}
