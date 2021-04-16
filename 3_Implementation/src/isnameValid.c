int isnameValid(const char *name)
{
    int correctname = 1;
    int len = 0;
    int index = 0;
    len = strlen(name);
    for(index =0; index <len ; ++index)
    {
        if(!(isalpha(name[index])) && (name[index] != '\n') && (name[index] != ' '))
        {
            correctname = 0;
            break;
        }
    }
    return correctname;
}