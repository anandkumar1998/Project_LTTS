#include<stdio.h>
void initially()
{
    FILE *fp = NULL;
    int stat = 0;
    const char def_user[] ="1234\n";
    const char def_pass[] ="1234\n";
    sFileHeader fileHeaderInfo = {0};
    stat = is_Exists(FILE_name);
    if(!stat)
    {
      
        fp = fopen(FILE_name,"wb");
        if(fp != NULL)
        {
           
            strncpy(fileHeaderInfo.password,def_pass,sizeof(def_pass));
            strncpy(fileHeaderInfo.username,def_user,sizeof(def_user));
            fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
            fclose(fp);
        }
    }
}
