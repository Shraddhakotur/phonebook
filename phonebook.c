#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<time.h>
#define MAX_CONTACTS 100
struct contact
{
     char name[50];
     char phone_no[15];
     char email_id[40];
     char datetime[50];
};
struct contact phoneBook[MAX_CONTACTS];
int contactCount=0;

void getCurrentTime(char* buffer)
{
    time_t currentTime;
    time(&currentTime);
    strcpy(buffer,ctime(&currentTime));
}
void writeData(const char *filename)
{
    FILE *file = fopen(filename,"wb");
    if (file == NULL)
        {
        printf("Error opening file for writing.\n");
        return;
        }
    fwrite(&phoneBook, sizeof(struct contact), contactCount,file);
    printf("Data written to file successfully.\n");
    fclose(file);
}
    void readData(const char *filename)
     {
     FILE *file = fopen(filename,"rb");
    if (file == NULL)
         {
        printf("Error opening file for reading.\n");
        return;
        }
     fread(&phoneBook,sizeof(struct contact), contactCount, file);
     }

     void writecontactcount()
     {
         FILE *file = fopen("globalvar.txt", "w"); // Open file for writing

        if (file == NULL)
        {
        printf("Error opening file");
        return;
        }
      fprintf(file, "%d\n", contactCount); // Write integer to file
      fclose(file);
     }


     void readcontactcount()
     {
        FILE *file = fopen("globalvar.txt", "r"); // Open file for reading

       if (file == NULL) {
        printf("Error opening file");
        return ;}
       fscanf(file, "%d", &contactCount);
       fclose(file); // Close the file
     }
//Function  to add a contact
void addcontact()
{
     if(contactCount<MAX_CONTACTS)
     {
        printf("Enter name:");
        scanf("%s",phoneBook[contactCount].name);
        printf("Enter phone_no:");
        scanf("%s",phoneBook[contactCount].phone_no);
        printf("Enter email_id:");
        scanf("%s",phoneBook[contactCount].email_id);
        getCurrentTime(phoneBook[contactCount].datetime);
        printf("Datetime:%s\n",phoneBook[contactCount].datetime);
        contactCount++;
        printf("contact added successfully!\n");
     }
     else
     {
        printf("phonebook is full:\n");
     }
}

//Function of view contacts
void viewcontact()
{
    if(contactCount !=0)
    {
        for(int i=0;i<contactCount;i++)
       {
         printf("\n");
         printf(" serial_no:%d\t phone_no:%s\t name:%s\t email_id:%s\t datetime:%s\t",i,phoneBook[i].phone_no, phoneBook[i].name,phoneBook[i].email_id,phoneBook[i].datetime);
         printf("\n");
       }
    }
    else
        {
        printf("contact not found!\n");
    }

    return 0;
}
//Function of delete contacts
void deletecontact()
{
    int serial_no,total;
    printf("Enter the  serial_no to delete:");
    scanf("%d",&serial_no);
    printf("\n");
    for(int i=serial_no;i<contactCount;i++)
    {
        phoneBook[i]=phoneBook[i+1];
    }
       contactCount--;
       printf("contact deleted successfully\n");
}

//Function of update contact
void updatecontact()
{
       char name[50];
       int serial_no=0;
       printf("Enter serial_no of the contact to update:");
       scanf("%d",&serial_no);
       printf("Enter the new name to be updated\n");
       scanf("%s",phoneBook[serial_no].name);
       printf("Enter the new phone_no to be updated\n");
       scanf("%s",phoneBook[serial_no].phone_no);
       printf("contact updated successfully:\n");
}
//main menu()
int main()
{
   int choice;
   const char *filename = "phoneBook.txt";
   readcontactcount();
   readData(filename);
   do
   {
       printf("\nphoneBook application\n");
       printf("1.create contact\n");
       printf("2.view contact\n");
       printf("3.delete contact\n");
       printf("4.update contact\n");
       printf("5.exit contact\n");
       printf("Enter your choice:");
       scanf("%d",&choice);
switch(choice)
{
case 1:
   addcontact();
   break;
case 2:
   viewcontact();
   break;
case 3:
   deletecontact();
   break;
case 4:
   updatecontact();
   break;
case 5:
    writecontactcount();
    writeData(filename);
    printf("existing the application\n:");
    break;
    default:
    printf("invalid choice!please try again:\n");
}
   }
   while(choice!=5);
}
int filepointer()
{
   FILE*filepointer;
   filepointer=fopen("output.text","w");
   if(filepointer=NULL)
   {
      printf("error opening file:\n");
      return 1;
   }
fprintf(filepointer,"this output will be saved permanently in the file.\n");
fprintf(filepointer,"you can add more lines like this one.\n");
fclose(filepointer);
printf("data has been written to the file.\n");
return 0;
}
