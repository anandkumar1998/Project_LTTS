void view()
{
    int found = 0;
    s_StudentInfo ADDstudentdataINDATABASE = {0};
    FILE *fp = NULL;
    unsigned int countStudent = 1;
    headMessage("VIEW STUDENT DETAILS");
    fp = fopen(FILE_name,"rb");
    if(fp == NULL)
    {
        printf("error opening file\n");
        exit(1);
    }
    if (fseek(fp,FILE_HEADER_SIZE,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("ERROR WHILE READING  FILE\n");
        exit(1);
    }
    while (fread (&ADDstudentdataINDATABASE, sizeof(ADDstudentdataINDATABASE), 1, fp))
    {
        printf("\n\t\t\tStudent Count = %d\n\n",countStudent);
        printf("\t\t\tSTUDENT ID IS = %u\n",ADDstudentdataINDATABASE.student_id);
        printf("\t\t\tStudent name = %s",ADDstudentdataINDATABASE.studentname);
        printf("\t\t\tFather name = %s",ADDstudentdataINDATABASE.fath_na);
        printf("\t\t\tStudent Address = %s",ADDstudentdataINDATABASE.studentAddr);
        printf("\t\t\tStudent Admission Date(day/month/year) =  (%d/%d/%d)\n\n",ADDstudentdataINDATABASE.StudentJOININGDATE.dd,
               ADDstudentdataINDATABASE.StudentJOININGDATE.mm, ADDstudentdataINDATABASE.StudentJOININGDATE.yyyy);
        found = 1;
        ++countStudent;
    }
    fclose(fp);
    if(!found)
    {
        printf("\n\t\t\tNo Record");
    }
    printf("\n\n\t\t\tPress any key to go to main menu.....");
    fflush(stdin);
    getchar();
}