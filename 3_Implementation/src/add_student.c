#include<stdio.h>
void add_student()
{
    s_StudentInfo ADDstudentdataINDATABASE = {0};
    FILE *fp = NULL;
    int stat = 0;
    fp = fopen(FILE_name,"ab+");
    if(fp == NULL)
    {
        printf("error opening file\n");
        exit(1);
    }
    headMessage("ADD ANY NEW STUDENT");
    printf("\n\n\t\t\tENTER THE DETAILS:");
    printf("\n\t\t\t--------------------------------------\n");
    printf("\n\t\t\tSTUDENT ID IS  = ");
    fflush(stdin);
    scanf("%u",&ADDstudentdataINDATABASE.student_id);
    do
    {
        printf("\n\t\t\tFather name  = ");
        fflush(stdin);
        fgets(ADDstudentdataINDATABASE.fath_na,MAX_FATHER_name,stdin);
        stat = isnameValid(ADDstudentdataINDATABASE.fath_na);
        if (!stat)
        {
            printf("\n\t\t\tIT CONTAIN INVALID LETTER. TRY AGAIN.");
        }
    }
    while(!stat);
    do
    {
        printf("\n\t\t\tStudent name  = ");
        fflush(stdin);
        fgets(ADDstudentdataINDATABASE.studentname,Max_Stud_name,stdin);
        stat = isnameValid(ADDstudentdataINDATABASE.studentname);
        if (!stat)
        {
            printf("\n\t\t\tIT CONTAIN INVALID LETTER. TRY AGAIN.");
        }
    }
    while(!stat);
    do
    {
        printf("\n\t\t\tStudent Address  = ");
        fflush(stdin);
        fgets(ADDstudentdataINDATABASE.stu_addr,MAX_FATHER_name,stdin);
        stat = isnameValid(ADDstudentdataINDATABASE.stu_addr);
        if (!stat)
        {
            printf("\n\t\t\tIT CONTAIN INVALID LETTER. TRY AGAIN.");
        }
    }
    while(!stat);
    do
    {
      
        printf("\n\t\t\tDATE FORMAT (day/month/year): ");
        scanf("%d/%d/%d",&ADDstudentdataINDATABASE.studentJoiningDate.dd,&ADDstudentdataINDATABASE.studentJoiningDate.mm,&ADDstudentdataINDATABASE.studentJoiningDate.yyyy);
        
        stat = isValidDate(&ADDstudentdataINDATABASE.studentJoiningDate);
        if (!stat)
        {
            printf("\n\t\t\tENTER A VALID DATE.\n");
        }
    }
    while(!stat);
    fwrite(&ADDstudentdataINDATABASE,sizeof(ADDstudentdataINDATABASE), 1, fp);
    fclose(fp);
}