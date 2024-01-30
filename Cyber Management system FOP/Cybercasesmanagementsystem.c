#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
struct admin
{
    char aname[20];
    int a_id;
    char a_password[16];
};
struct admin admin_record[15];
struct crimed
{
    int crime_code;
    char crime_name[20];
    char crime_pusishment[20];
};
struct crimed crime_data[15];
struct criminal
{
    char criminal_name[20];
    int criminal_id;
    int criminal_age;
    char criminal_NIC[15];
    char criminal_adress[50];
};
struct criminal criminal_record[100];
int number_records=20;
struct crime
{
    char c_name[20];
    char c_date[20];
    int crime_id;
    char victim_name[20];
    int victim_age;
    char cr_name[20];
    int cr_id;
};
struct crime Crime_records[100];
int i,j,n;
int success_login=0;
void optiondisplay(void)
{
    int i,j;
    gotoxy(40,5); //horizontal outer 2nd row
    for(i=0; i<17; i++)
    {
        if(i==0)
        {
            printf("");
        }
        else
            printf("\t\t\t\t\t\t\t\t\t\t  *");
        printf("\n");
    }
    gotoxy(40,6); //verital outer 1st row
    for(i=0; i<21; i++)
    {
        printf("*");
        printf(" ");
    }
    gotoxy(60,6);  //horizontal inner 2nd row
    for(i=0; i<15; i++)
    {
        if(i==0)
        {
            printf("");
        }
        else
            printf("\t\t\t\t\t\t\t\t\t\t*");
        printf("\n");
    }
    gotoxy(40,7);  //vertical inner 1st row
    for(i=0; i<20; i++)
    {
        printf("*");
        printf(" ");
    }

    gotoxy(40,6);     //horizontal inner 1st row
    for(i=0; i<=15; i++)
    {
        if(i==0 || i== 15)
        {
            printf("");
        }
        else
            printf("\t\t\t\t\t*");
        printf("\n");
    }
    gotoxy(50,8);
    printf("Enter your choice\n");
    gotoxy(50,10);
    printf("1-Add new record\n");
    gotoxy(50,12);//For adding new record
    printf("2-Search data\n");
    gotoxy(50,14);
    printf("3-Update record\n");
    gotoxy(50,16);
    printf("4-Delete Record\n");
    gotoxy(50,18);
    printf("5-Exit\n");
    printf("\n\n\n\n\n\n");
    gotoxy(40,20);
    for(i=0; i<20; i++) // verital inner 2nd row
    {
        printf("*");
        printf(" ");
    }
    gotoxy(1,6); //horizontal outer 1st row
    for(j=0; j<=15; j++)
    {
        printf("\t\t\t\t      *\n");

    }
    gotoxy(40,21); //vertical outer 2nd row
    for(i=0; i<21; i++)
    {
        printf("*");
        printf(" ");
    }

    printf("\n\n\n");

}
void gotoxy(short x, short y)
{
    COORD pos = {x,y};//sets co-ordinates in(x,y)
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
//Store Crime data(Crime name, id,date,) function starts from here
void storecrimedata(void)
{
    FILE* fp = fopen("crimedata.csv", "r");
    if (!fp)
        printf("Can't open file\n");

    else
    {
        char buffer[1024];
        int row, column;
        for (row=0; fgets(buffer,1024, fp); row++)
        {
            if (row == 0)
                continue;
            // Splitting the data
            char *value = strtok(buffer, ",");
            for (column = 0; value ; column++)
            {
                if (column==0)
                {
                    crime_data[row-1].crime_code = atoi(value);
                }
                if (column==1)
                {
                    memcpy(crime_data[row-1].crime_name, value, 20);
                }
                if (column==2)
                {
                    memcpy(crime_data[row-1].crime_pusishment, value, 20);
                }
                value = strtok(NULL, ",");
            }
        }
        fclose(fp);
    }
}
//Store Crime data(Crime name, id,date,) function end here
//Storing crime full data function starts from here
void storecrimerecord(void)
{
    FILE* fp = fopen("crimefullrecord.csv", "r");

    if (!fp)
        printf("Can't open file\n");

    else
    {
        char buffer[1024];
        int row, column;

        for (row=0; fgets(buffer,1024, fp); row++)
        {

            if (row == 0)
                continue;
            // Splitting the data
            char *value = strtok(buffer, ",");
            for (column = 0; value ; column++)
            {
                if (column==0)
                {
                    Crime_records[row-1].crime_id = atoi(value);
                }
                if (column==1)
                {
                    memcpy(Crime_records[row-1].c_name, value, 20);
                }
                if (column==2)
                {

                    memcpy(Crime_records[row-1].c_date, value, 20);
                }
                if (column==3)
                {
                    memcpy(Crime_records[row-1].cr_name, value, 20);
                }
                if (column==4)
                {
                    Crime_records[row-1].cr_id = atoi(value);
                }
                if (column==5)
                {
                    memcpy(Crime_records[row-1].victim_name, value, 20);
                }
                if (column==6)
                {
                    Crime_records[row-1].victim_age = atoi(value);
                }
                value = strtok(NULL, ",");
            }
        }
        //number_records=row-1;
        fclose(fp);
    }
}
//Storing crime data function ends here
//Storing Admiin function starts from here
void storeadmindata(void)
{
    FILE* fp = fopen("admindata.csv", "r");

    if (!fp)
        printf("Can't open file\n");
    else
    {
        char buffer[1024];
        int row, column;
        for (row=0; fgets(buffer,1024, fp); row++)
        {
            if (row == 0)
                continue;
            // Splitting the data
            char *value = strtok(buffer, ",");
            for (column = 0; value ; column++)
            {
                if (column==0)
                {
                    admin_record[row-1].a_id = atoi(value);
                }
                if (column==1)
                {
                    memcpy(admin_record[row-1].aname, value, 20);
                }
                if (column==2)
                {
                    memcpy(admin_record[row-1].a_password, value, 16);
                }
                value = strtok(NULL, ",");
            }
        }
        fclose(fp);
    }
}
// Storing adim data function ends here
//Storing criminal data starts from here
void storecriminaldata(void)
{
    FILE* fp = fopen("criminaldata.csv", "r");
    if (!fp)
        printf("Can't open file\n");

    else
    {
        char buffer[1024];
        int row, column;
        for (row=0; fgets(buffer,1024, fp); row++)
        {
            if (row == 0)
                continue;
            // Splitting the data
            char *value = strtok(buffer, ",");
            for (column = 0; value ; column++)
            {


                if (column==0)
                {
                    criminal_record[row-1].criminal_id = atoi(value);
                }
                if (column==1)
                {
                    memcpy(criminal_record[row-1].criminal_name, value, 20);
                }
                if (column==2)
                {
                    criminal_record[row-1].criminal_age = atoi(value);
                }
                if (column==3)
                {
                    memcpy(criminal_record[row-1].criminal_NIC, value, 20);
                }
                if (column==4)
                {
                    memcpy(criminal_record[row-1].criminal_adress, value, 20);
                }
                value = strtok(NULL, ",");
            }
        }
        fclose(fp);
    }
}
//storing Criminal data enda here
// Add new records function starts from here
void addrecord(void)
{
    int row;
    int temp;
    char temp1;
    printf("How many record you want to add: ");
    scanf("%d",&n);
    temp=number_records;
    number_records += n;

    FILE *fptr;
    fptr= fopen("crimefullrecord.csv", "a+");
    for(row=temp; row<number_records; row++)
    {
        printf("Enter Record for %d:\n",(row - temp)+1);
        printf("Enter Crime id: ");
        scanf("%d",&Crime_records[row].crime_id);
        printf("Enter Crime name: ");
        scanf("%c",&temp1);
        scanf("%[^\n]",&Crime_records[row].c_name);
        printf("Enter Crime date(eg:22/11/2001): ");
        scanf("%s",Crime_records[row].c_date);
        printf("Enter Criminal name: ");
        scanf("%c",&temp1);
        scanf("%[^\n]",&Crime_records[row].cr_name);
        printf("Enter Criminal id: ");
        scanf("%d",&Crime_records[row].cr_id);
        printf("Enter victim name: ");
        scanf("%c",&temp1);
        scanf("%[^\n]",&Crime_records[row].victim_name);
        printf("Enter victim age: ");
        scanf("%d",&Crime_records[row].victim_age);
        printf("\n");
        fprintf(fptr,"\n%d,%s,%s,%s,%d,%s,%d,", Crime_records[row].crime_id, Crime_records[row].c_name,Crime_records[row].c_date,Crime_records[row].cr_name,Crime_records[row].cr_id,Crime_records[row].victim_name, Crime_records[row].victim_age);
    }
    fclose(fptr);
}
//Add new record function ends here
//Admin login Function starts from here
void adminlogin(void)
{
    char name[20],temp;
    char pswd[6];
    int id;
    char ch;
    int counter=1;
    int i,j;
     do
    {
         if(counter>3)
        {
            exit(0);
        }
    gotoxy(55,5); //right side second line
    for(i=0; i<20; i++)
    {
        if(i==0)
        {
            printf("");
        }
        else
            printf("\t\t\t\t\t\t\t\t\t\t\t    *");
        printf("\n");
    }
    gotoxy(30,5); //upside 1st row
    for(i=0; i<32; i++)
    {
        printf("*");
        printf(" ");
    }
    gotoxy(60,5);  //right side inside row 2nd row
    for(i=0; i<20; i++)
    {
        if(i==0)
        {
            printf("");
        }
        else
            printf("\t\t\t\t\t\t\t\t\t\t\t *");
        printf("\n");
    }
    gotoxy(30,6);  //upside second row
    for(i=0; i<30; i++)
    {
        printf("*");
        printf(" ");
    }

    gotoxy(40,6);     //left side second row
    for(i=0; i<=18; i++)
    {
        if(i==0 || i== 18)
        {
            printf("");
        }
        else
            printf("\t\t\t\t*");
        printf("\n");
    }



    printf("\n\n\n\n\n\n");
    gotoxy(30,23);

    for(i=0; i<30; i++) // downside inside row
    {
        printf("*");
        printf(" ");
    }
    gotoxy(1,6); //left side 1st row
    for(j=0; j<=18; j++)
    {
        printf("\t\t\t      *\n");

    }
    gotoxy(30,24); //downside 2nd row


    for(i=0; i<32; i++)
    {
        printf("*");
        printf(" ");
    }

    printf("\n\n\n");
        gotoxy(35,3);
        printf("-----Welcome to Cyber Management System By SAAB-------");

        gotoxy(20,8);
        printf("\n\t\t\t\t\t\t      LOG IN HERE\n\t\t\t\t      Say Hi to Sir Khaalid then Login in your account");
        gotoxy(45,11);
        printf("\n\t\t\t\t\tEnter ID number: \n");
        gotoxy(40,13);
        scanf("%d",&id);
        gotoxy(40,15);
        printf("Enter your name: \n");
        gotoxy(40,17);
        scanf("%c",&temp);
        scanf("%[^\n]",&name);
        gotoxy(40,19);
        printf("Enter password: \n");

        int n=40;
        for(i=0; i<5; i++)
        {
            gotoxy(n,21);
            ch = getch();
            pswd[i] = ch;
            ch = '*' ;
            printf("%c",ch);
            n++;
        }
        counter++;
    }
    while(match(id, name, pswd));
}
//Admin login into into account function starts from here
// Matching admin data function starts from here
// Match function will match the admin login data to a saved data of admin login
int match(int* id, char* name,char* pswd)
{
    for(i=0; (i<15); i++)
    {
        if((strcmp(admin_record[i].aname,name)==0) && (strcmp(admin_record[i].a_password,pswd)==0) && id==admin_record[i].a_id)
        {
            loading();
            gotoxy(60,27);
            printf("\n\t\t\t\t\tYou are successfully login");
            success_login=1;
            printf("\n\t\t\t\t\tPress any key to continue");
            getch();
            system("cls");
            return 0;
        }
    }
    gotoxy(40,27);
    printf("     Invalid login detail! Try again(3Chances)");
     printf("\n\t\t\t\t\t\tPress any key to Try");
            getch();
            system("cls");
    return 1;
}
// Matching admin data function starts from here
//Loading for admin login function starts from here
void loading(void)
{
    gotoxy(50,27);
    printf("Loading...");
    gotoxy(40,27);
    for(i=1; i<=20; i++)
    {
        for(j=0; j<=100000000; j++);
        printf("%c",177);
    }
}
//Loading for admin login function ends here
//search record function starts from here
void searchrecord(void)
{
    int code_num,check=0;
    int row, number_records=15,select;
    char c_name[20];
    char temp;
    int select1;
    char c_n[20],c_nic[15],c_add[20];
    int c_id,c_age;

    printf("\t\t\t\t\t\tWelcome to Search \n\n");
    do
    {
        printf("\nWHAT DO YOU WANT SEARCH?\nPRESS\n1 TO SEARCH CRIME DATA\n2 TO SEARCH CRIMINAL DATA\n3 TO EXIT\n");
        scanf("%d", &select1);
        if(select1==1)
        {
            printf("\n\nHow do you want to search?\nPRESS\n1 TO SEARCH BY CODE \n2 TO SEARCH BY NAME\n");
            scanf("%d", &select);
            switch(select)
            {
            case 1:
                printf("\nPlease enter Crime code number to find Punishement: ");
                scanf("%d", &code_num);
                for(row=0; row<number_records; row++)
                {
                    if(code_num==crime_data[row].crime_code)
                    {
                        check++;
                        printf("Crime code\tCrime Name\tPunishment");
                        printf("\n%d\t\t%s\t\t%s\n", crime_data[row].crime_code,crime_data[row].crime_name,crime_data[row].crime_pusishment);
                    }
                }
                if(check==0)
                {
                    printf("Not Found:\n");
                }
                break;
            case 2:
                printf("Please enter crime name to find Punishement: ");
                scanf("%c", &temp);
                scanf("%[^\n]", &c_name);
                for(row=0; row<number_records; row++)
                {
                    if(strcmp(c_name,crime_data[row].crime_name)==0)
                    {
                        check++;
                        printf("Crime code\tCrime Name\tPunishment");
                        printf("\n%d\t\t%s\t\t%s\n", crime_data[row].crime_code,crime_data[row].crime_name,crime_data[row].crime_pusishment);
                    }
                }
                if(check==0)
                {
                    printf("Not Found:\n");
                }
                break;
            }
        }
        if(select1==2)
        {
            printf("\n\n\nHow do you want to search?\nPRESS\n1 TO SEARCH BY NAME \n2 TO SEARCH BY ID\n3 TO SEARCH BY AGE \n4 TO SEARCH BY NIC\n5 TO SEARCH BY ADDRESS\n");
            scanf("%d", &select);
            switch(select)
            {
            case 1:
                printf("\nPlease enter NAME to find the details: ");
                scanf("%c", &temp);
                scanf("%[^\n]", &c_n);
                check=0;
                for(row=0; row<number_records; row++)
                {
                    if(strcmp(c_n,criminal_record[row].criminal_name)==0)
                    {
                        if(check==0)
                        {
                            check++;
                            printf("Name\t\tID\t\tAGE\t\t\tNIC\t\t\t\tADDRESS");
                        }
                        printf("\n%s\t\t%d\t\t%d\t\t\t%s\t\t\t%s\n", criminal_record[row].criminal_name,criminal_record[row].criminal_id,criminal_record[row].criminal_age,criminal_record[row].criminal_NIC,criminal_record[row].criminal_adress);
                    }
                }
                if(check==0)
                {
                    printf("Not Found:\n");
                }
                break;
            case 2:
                printf("Please enter ID to find the details: ");

                scanf("%d", &c_id);
                check=0;
                for(row=0; row<number_records; row++)
                {
                    if(c_id==criminal_record[row].criminal_id)
                    {
                        if(check==0)
                        {
                            check++;
                            printf("Name\t\tID\t\tAGE\t\t\tNIC\t\t\t\tADDRESS");
                        }
                        printf("\n%s\t\t%d\t\t%d\t\t\t%s\t\t\t%s\n", criminal_record[row].criminal_name,criminal_record[row].criminal_id,criminal_record[row].criminal_age,criminal_record[row].criminal_NIC,criminal_record[row].criminal_adress);
                    }
                }
                if(check==0)
                {
                    printf("Not Found:\n");
                }
                break;
            case 3:
                printf("Please enter age to find the details: ");

                scanf("%d", &c_age);
                check=0;
                for(row=0; row<number_records; row++)
                {
                    if(c_age==criminal_record[row-1].criminal_age)
                    {
                        if(check==0)
                        {
                            check++;
                            printf("Name\t\tID\t\tAGE\t\t\tNIC\t\t\t\tADDRESS");
                        }
                        printf("\n%s\t\t%d\t\t%d\t\t\t%s\t\t\t%s\n", criminal_record[row].criminal_name,criminal_record[row].criminal_id,criminal_record[row].criminal_age,criminal_record[row].criminal_NIC,criminal_record[row].criminal_adress);
                    }
                }
                if(check==0)
                {
                    printf("Not Found:\n");
                }
                break;
            case 4:
                printf("\nPlease enter NIC to find the details: ");
                scanf("%c", &temp);
                scanf("%[^\n]", &c_nic);
                check=0;
                for(row=0; row<number_records; row++)
                {
                    if(strcmp(c_nic,criminal_record[row-1].criminal_NIC)==0)
                    {
                        if(check==0)
                        {
                            check++;
                            printf("Name\t\tID\t\tAGE\t\t\tNIC\t\t\t\tADDRESS");
                        }
                        printf("\n%s\t\t%d\t\t%d\t\t\t%s\t\t\t%s\n", criminal_record[row].criminal_name,criminal_record[row].criminal_id,criminal_record[row].criminal_age,criminal_record[row].criminal_NIC,criminal_record[row].criminal_adress);
                    }
                }
                if(check==0)
                {
                    printf("Not Found:\n");
                }
                break;
            case 5:
                printf("\nPlease enter ADDRESS to find the details: ");
                scanf("%c", &temp);
                scanf("%[^\n]", &c_add);
                check=0;
                for(row=0; row<number_records; row++)
                {
                    if(strcmp(c_add,criminal_record[row-1].criminal_adress)==0)
                    {
                        if(check==0)
                        {
                            check++;
                            printf("Name\t\tID\t\tAGE\t\t\tNIC\t\t\t\tADDRESS");
                        }
                        printf("\n%s\t\t%d\t\t%d\t\t\t%s\t\t\t%s\n", criminal_record[row].criminal_name,criminal_record[row].criminal_id,criminal_record[row].criminal_age,criminal_record[row].criminal_NIC,criminal_record[row].criminal_adress);
                    }
                }
                if(check==0)
                {
                    printf("Not Found:\n");
                }
                break;
            }
        }
    }
    while(select1!=3);
}
//search record function ends here
void main(void)
{

    int choice;
    system("COLOR F1");
    storeadmindata();
    adminlogin();
    do
    {
        system("cls");
    if(success_login=1)
    {
        optiondisplay();
    }
    printf("\t\t\t\t\t\t\t");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        storecrimerecord();
        addrecord();
        break;
    case 2:
        storecrimedata();
        storecriminaldata();
        searchrecord();
        break;
    case 5:
        exit(0);
    default:
        printf("Invalid key");

    }
    }while(choice!=5);
}
