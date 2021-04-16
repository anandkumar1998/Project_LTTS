void cred_upd(void)
{
    sFileHeader fileHeaderInfo = {0};
    FILE *fp = NULL;
    unsigned char username[MAX_USER] = {0};
    unsigned char password[MAX_PASS] = {0};
    headMessage("Update Credential");
    fp = fopen(FILE_name,"rb+");
    if(fp == NULL)
    {
        printf("error opening file\n");
        exit(1);
    }
    fread (&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    if (fseek(fp,0,SEEK_SET) != 0)
    {
        fclose(fp);
        printf("\n\t\t\tFacing issue while updating password\n");
        exit(1);
    }
    printf("\n\n\t\t\tNew Username:");
    fflush(stdin);
    fgets(username,MAX_USER,stdin);
    printf("\n\n\t\t\tNew Password:");
    fflush(stdin);
    fgets(password,MAX_PASS,stdin);
    strncpy(fileHeaderInfo.username,username,sizeof(username));
    strncpy(fileHeaderInfo.password,password,sizeof(password));
    fwrite(&fileHeaderInfo,FILE_HEADER_SIZE, 1, fp);
    fclose(fp);
    printf("\n\t\t\tYour Password has been changed successfully");
    printf("\n\t\t\ttlog_in Again:");
    fflush(stdin);
    getchar();
    exit(1);
}