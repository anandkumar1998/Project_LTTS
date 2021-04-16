void find_student()
{
    int found = 0;
    int studentId =0;
    s_StudentInfo ADDstudentdataINDATABASE = {0};
    FILE *fp = NULL;
    fp = fopen(FILE_name,"rb");
    if(fp == NULL)
    {
        printf("\n\t\t\terror opening file\n");
        exit(1);
    }
    headMessage("SEARCH STUDENTS");
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tERROR\n");
        exit(1);
    }
    printf("\n\n\t\t\tEnter STUDENT ID IS NO to search:");
    fflush(stdin);
    scanf("%u",&studentId);
    while (fread (&ADDstudentdataINDATABASE, sizeof(ADDstudentdataINDATABASE), 1, fp))
    {
        if(ADDstudentdataINDATABASE.student_id == studentId)
        {
            found = 1;
            break;
        }
    }
    if(found)
    {
        printf("\n\t\t\tSTUDENT ID IS = %d\n",ADDstudentdataINDATABASE.student_id);
        printf("\n\t\t\tStudent name = %s",ADDstudentdataINDATABASE.studentname);
        printf("\t\t\tFather name = %s",ADDstudentdataINDATABASE.fath_na);
        printf("\n\t\t\tStudent Address = %s",ADDstudentdataINDATABASE.stu_addr);
        printf("\t\t\tStudent Admission Date in DD/MM/YYYY =  (%d/%d/%d)",ADDstudentdataINDATABASE.studentJoiningDate.dd,
               ADDstudentdataINDATABASE.studentJoiningDate.mm, ADDstudentdataINDATABASE.studentJoiningDate.yyyy);
    }
    else
    {
        printf("\n\t\t\tNo Student Found");
    }
    fclose(fp);
    printf("\n\n\n\t\t\tEnter any key to go back.");
    fflush(stdin);
    getchar();
}