#include<stdio.h>
void log_in()
{
    unsigned char username[MAX_USER] = {0};
    unsigned char password[MAX_PASS] = {0};
    int L=0;
    sFileHeader fileHeaderInfo = {0};
    FILE *fp = NULL;
    headMessage("log_in");
    fp = fopen(FILE_name,"rb");
    if(fp == NULL)
    {
        printf("error opening file\n");
        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fclose(fp);
    do
    {
        printf("\n\n\t\t\tUsername:");
        fgets(username,MAX_USER,stdin);
        printf("\n\t\t\t\tPassword:");
        fgets(password,MAX_PASS,stdin);
        if((!strcmp(username,fileHeaderInfo.username)) && (!strcmp(password,fileHeaderInfo.password)))
        {
            menu();
        }
        else
        {
            printf("\t\t\t\tlog_in Failed Enter Again Username & Password\n\n");
            L++;
        }
    }
    while(L<=3);
    if(L>3)
    {
        headMessage("log_in Failed");
        printf("\t\t\t\tSorry,Unknown User.");
        getch();
        system("cls");
    }
}
