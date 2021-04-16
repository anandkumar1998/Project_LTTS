#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_FATHER_name 50 // Macro related to the students info
#define Max_Stud_name 50
#define Max_Stud_Addr 300
#define FILE_HEADER_SIZE  sizeof(sFileHeader)
#define Max_Year  9999 //Used macro
#define Min_Year  1900
#define MAX_USER 30
#define MAX_PASS  20
#define FILE_name  "studentRecordSystem.bin"

int is_Exists(const char *path)
{
    FILE *fp = fopen(path, "rb");
    int stat = 0;
    if (fp != NULL)
    {
        stat = 1;
        fclose(fp);
    }
    return stat;
}


typedef struct
{
    int yyyy;
    int mm;
    int dd;
} Date;
typedef struct
{
    char username[MAX_USER];
    char password[MAX_PASS];
} sFileHeader;
typedef struct
{
    unsigned int student_id; 
    char fath_na[MAX_FATHER_name];
    char studentname[Max_Stud_name];
    char stu_addr[Max_Stud_Addr];
    Date studentJoiningDate;
} s_StudentInfo;
void printMessageCenter(const char* message)
{
    int len =0;
    int pos = 0;
    len = (78 - strlen(message))/2;
    printf("\t\t\t");
    for(pos =0 ; pos < len ; pos++)
    {
      printf(" ");
    }
    printf("%s",message);
}
void headMessage(const char *message)
{
    system("cls");

    printf("\n\t\t\t Student Management System");

    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}
void welmes()
{
    headMessage("www.aticleworld.com");
    printf("\n\n\n\n\n");

    printf("\n\t\t\t        =                  WELCOME                  =");
    printf("\n\t\t\t        =                    TO                     =");
    printf("\n\t\t\t        =               Student Record              =");
    printf("\n\t\t\t        =                 MANAGEMENT                =");
    printf("\n\t\t\t        =                   SYSTEM                  =");
    printf("\n\n\n\t\t\t Input any key");
    getch();
}

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

int  IsLeapYear(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}
int isValidDate(Date *validDate)
{
    
    if (validDate->yyyy > Max_Year ||
            validDate->yyyy < Min_Year)
        return 0;
    if (validDate->mm < 1 || validDate->mm > 12)
        return 0;
    if (validDate->dd < 1 || validDate->dd > 31)
        return 0;
   
    if (validDate->mm == 2)
    {
        if (IsLeapYear(validDate->yyyy))
            return (validDate->dd <= 29);
        else
            return (validDate->dd <= 28);
    }
    
    if (validDate->mm == 4 || validDate->mm == 6 ||
            validDate->mm == 9 || validDate->mm == 11)
        return (validDate->dd <= 30);
    return 1;
}

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
        printf("\t\t\tStudent Address = %s",ADDstudentdataINDATABASE.stu_addr);
        printf("\t\t\tStudent Admission Date in DD/MM/YYYY =  (%d/%d/%d)\n\n",ADDstudentdataINDATABASE.studentJoiningDate.dd,
               ADDstudentdataINDATABASE.studentJoiningDate.mm, ADDstudentdataINDATABASE.studentJoiningDate.yyyy);
        found = 1;
        ++countStudent;
    }
    fclose(fp);
    if(!found)
    {
        printf("\n\t\t\tNo Student Record Found");
    }
    printf("\n\n\t\t\tEnter any key to go back.");
    fflush(stdin);
    getchar();
}
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
    (found)? printf("\n\t\t\tStudent Record has been deleted successfully."):printf("\n\t\t\tRecord not found");
    fclose(fp);
    fclose(tmpFp);
    remove(FILE_name);
    rename("tmp.bin",FILE_name);
}
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
        printf("\n\t\t\tError in updating password.\n");
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
    printf("\n\t\t\tPassword has been changed.");
    printf("\n\t\t\ttlog_in Again:");
    fflush(stdin);
    getchar();
    exit(1);
}
void menu()
{
    int ch = 0;
    do
    {
        headMessage("SUB MENU");
        printf("\n\n\n\t\t\t1.Admit new Student");
        printf("\n\t\t\t2.Search in Database");
        printf("\n\t\t\t3.View Student in Database");
        printf("\n\t\t\t4.Delete Student from Database");
        printf("\n\t\t\t5.Update Login Password");
        printf("\n\t\t\t0.Exit");
        printf("\n\n\n\t\t\tInput your Choice => ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            add_student();
            break;
        case 2:
            find_student();
            break;
        case 3:
            view();
            break;
        case 4:
            delete();
            break;
        case 5:
            cred_upd();
            break;
        case 0:
            printf("\n\n\t\t\tTHANKS\n\n\n\n\n");
            exit(1);
            break;
        default:
            printf("\n\n\n\t\t\tINPUT INVALID.TRY AGAIN");
        }                                          
    }
    while(ch!=0);                                      
}
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

int main()
{
    initially();
    welmes();
    log_in();
    return 0;
}

