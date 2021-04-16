void delete()
{
    int found = 0;
    int studentDelete = 0;
    sFileHeader fileHeaderInfo = {0};
    s_StudentInfo ADDstudentdataINDATABASE = {0};
    FILE *fp = NULL;
    FILE *tmpFp = NULL;
    headMessage("Delete Student Details");
    fp = fopen(FILE_name,"rb");
    if(fp == NULL)
    {
        printf("error opening file\n");
        exit(1);
    }
    tmpFp = fopen("tmp.bin","wb");
    if(tmpFp == NULL)
    {
        fclose(fp);
        printf("error opening file\n");
        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, tmpFp);
    printf("\n\t\t\tEnter STUDENT ID IS NO. for delete:");
    scanf("%d",&studentDelete);
    while (fread (&ADDstudentdataINDATABASE, sizeof(ADDstudentdataINDATABASE), 1, fp))
    {
        if(ADDstudentdataINDATABASE.student_id != studentDelete)
        {
            fwrite(&ADDstudentdataINDATABASE,sizeof(ADDstudentdataINDATABASE), 1, tmpFp);
        }
        else
        {
            found = 1;
        }
    }
    (found)? printf("\n\t\t\tRecord deleted successfully....."):printf("\n\t\t\tRecord not found");
    fclose(fp);
    fclose(tmpFp);
    remove(FILE_name);
    rename("tmp.bin",FILE_name);
}