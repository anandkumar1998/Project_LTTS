void menu()
{
    int choice = 0;
    do
    {
        headMessage("MAIN MENU");
        printf("\n\n\n\t\t\t1.ADD STUDENT");
        printf("\n\t\t\t2.SEARCH STUDENT");
        printf("\n\t\t\t3.VIEW STUDENT");
        printf("\n\t\t\t4.DELETE STUDENT");
        printf("\n\t\t\t5.UPDATE PASSWORD");
        printf("\n\t\t\t0.EXIT");
        printf("\n\n\n\t\t\tEnter choice => ");
        scanf("%d",&choice);
        switch(choice)
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
    while(choice!=0);                                      
}