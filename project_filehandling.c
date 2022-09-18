#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
void gotoxy(int, int);
void menu();
void add();
void view();
void search();
void modified();
void deleterec();
struct student
{
    char name[20];
    char mobile[10];
    char rollno[20];
    char course[20];
    char branch[20];
};
int main()
{
    gotoxy(15,8);
    printf("<--: Student Record Management System:-->\n");
    gotoxy(19,10);
    printf("Press any key to continue.");
    getch();
    menu();
    return 0;
}
void menu()
{
    int choice;
    system("cls");
    gotoxy(10,3);
    printf("<--:Menu:-->");
    gotoxy(10,5);
    printf("Enter the appropriate number to perform following task.");
    gotoxy(10,7);
    printf("1 : Add Record.");
    gotoxy(10,8);
    printf("2 : View Record.");
    gotoxy(10,9);
    printf("3 : Search Record.");
    gotoxy(10,10);
    printf("4: Modify Record.");
    gotoxy(10,11);
    printf("5: Delete.");
    gotoxy(10,12);
    printf("6 : Exit.");
    gotoxy(10,15);
    printf("Enter your choice : ");
    scanf("%d", &choice);
    switch(choice)
    {
        case 1:
        add();
        break;

        case 2:
        view();
        break;

        case 3:
        search();
        break;

        case 4:
        modified();
        break;

        case 5:
        deleterec();
        break;

        case 6:
        exit(1);
        break;

        default:
        gotoxy(10,17);
        printf("Invalid Choice.");
    }
}
void add()
{
    FILE *fp;
    struct student std;
    char another = 'y';
    system("cls");

    fp = fopen("record.txt","ab+");
    if(fp==NULL)
    {
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(10,3);
        printf("<--:ADD RECORD:-->");
        gotoxy(10,5);
        printf("Enter the details of students.");
        gotoxy(10,7);
        printf("Enter the name : ");
        gets(std.name);
        gotoxy(10,8);
        printf("Enter the mobile number : ");
        gets(std.mobile);
        gotoxy(10,9);
        printf("Enter the Roll No : ");
        scanf("%d",&std.rollno);
        fflush(stdin);
        gotoxy(10,10);
        printf("Enter Course : ");
        gets(std.course);
        gotoxy(10,11);
        printf("Enter Branch : ");
        gets(std.branch);
        fwrite(&std, sizeof(std),1,fp);
        gotoxy(10,15);
        printf(" Want to add another records? then press 'y' or 'n' : ");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);

    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue.");
    getch();
    menu();
}
void view()
{
    FILE *fp;
    int i = 1,j;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--: VIEW RECORD:-->");
    gotoxy(10,5);
    printf("S.No  Name of student   Mobile no  Rollno   course   branch");
    gotoxy(10,6);
    printf("--------------------------------------------------------------");
    fp = fopen("record.txt","rb++");
    if(fp == NULL)
    {
        gotoxy(10,8);
        printf("Error opening file");
        exit(1);
    }
    j=7;
    while(fread(&std, sizeof(std),1,fp) == 1)
    {
        gotoxy(10,j);
        printf("%-7d%-18s%-12d%-9s%-10s%-10s \n",i, std.name,std.mobile,std.rollno, std.course,std.branch);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(10,j+3);
    printf("press any key to continue.");
    getch();
    menu();
}

void search()
{
  FILE *fp;
  struct student std;
  char stname[20];
  system("cls");
  gotoxy(10,3);
  printf("<--: Search Record:-->");
  gotoxy(10,5);
  printf("Enter the name : ");
  fflush(stdin);
  gets(stname);
  fp = fopen("record.txt", "rb++");
  if(fp == NULL)
  {
    gotoxy(10,6);
    printf("Error file opening");
    exit(1);
  }  
  while (fread(&std,sizeof(std),1,fp)==1)
  {
    if (strcmp(stname,std.name)==0)
    {
        gotoxy(10,8);
        printf("Name : %s",std.name);
        gotoxy(10,9);
        printf("Mobile Number : %s",std.mobile);
        gotoxy(10,10);
        printf("Roll No : %s",std.rollno);
        gotoxy(10,11);
        printf("Course : %s",std.course);
        gotoxy(10,11);
        printf("Branch : %s",std.branch);
    }
  }
  fclose(fp);
  gotoxy(10,16);
  printf("Press any key to continue.");
  getch();
  menu();
}

void modified()
{
  char stname[20];
  FILE *fp;
  struct student std;
  system("cls");
  gotoxy(10,3);
  printf("<--: MODIFIED RECORD:-->");
  gotoxy(10,5);
  printf("Enter the name of student to modify : ");
  fflush(stdin);
  gets(stname);
  fp = fopen("record.txt","rb++");
  if(fp == NULL)
  {
    gotoxy(10,6);
    printf("Error opening file.");
    exit(1);
  }
  rewind(fp);
  fflush(stdin);
  while(fread(&std, sizeof(std),1,fp) == 1)
  {
    if(strcmp(stname, std.name) == 0)
    {
        gotoxy(10,7);
        printf("Enter the name : ");
        gets(std.name);
        gotoxy(10,8);
        printf("Enter the mobile number : ");
        gets(std.mobile);
        gotoxy(10,9);
        printf("Enter the roll no : ");
        gets(std.rollno);
        gotoxy(10,10);
        printf("Enter the course : ");
        gets(std.course);
        gotoxy(10,11);
        printf(" Enter the branch : ");
        gets(std.branch);
        fseek(fp, sizeof(std),SEEK_CUR);
        fwrite(&std,sizeof(std),1,fp);
        break;
    }
  }
  fclose(fp);
  gotoxy(10,16);
  printf("Press any key to continue.");
  getch();
  menu();
}

void deleterec()
{
  char stname[20];
  FILE *fp, *ft;
  struct student std;
  system("cls");
  gotoxy(10,3);
  printf("<--: DELETE RECORD:-->");
  gotoxy(10,5);
  printf("Enter the name of student to delete : ");
  fflush(stdin);
  gets(stname);
  fp = fopen("record.txt","rb++");
  if(fp == NULL)
  {
    gotoxy(10,6);
    printf("Error opening file.");
    exit(1);
  }
  ft = fopen("temp.txt","wb++");
  if(ft == NULL)
  {
    gotoxy(10,6);
    printf("Error opening file.");
    exit(1);
  }
  
  while(fread(&std, sizeof(std),1,fp) == 1)
  {
    if(strcmp(stname, std.name) != 0)
    {
        fwrite(&std,sizeof(std),1,fp);
    }
  }
  fclose(fp);
  fclose(ft);
  remove("record.txt");
  rename("temp.txt","record.txt");
  gotoxy(10,16);
  printf("Press any key to continue.");
  getch();
  menu();
}
void gotoxy(int x, int y)
{
    COORD c;
    c.X= x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}