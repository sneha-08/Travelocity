
#include<iostream>
#include<string.h>
#include<cstdio>
#include<time.h>
#include<stdlib.h>
using namespace std;

/*label references
l-main menu
l1-password
l2-state selection
l3-travel info */

//stores the original password
string passwd="travel";

//stores the no.of states
int m=3;

// the no.of columns for storing the info about the states
int n=5;

//variables for cab queue
int a[10];
int Front =0;
int rear=0;

//defining a struct node
struct node
 {
    char data[25];
    node *right, *down;
};
node *head;

//  function to create a new node with given data
// c-columns
node* newNode(int c)
{
    system("color E4");
    char d[25];
    switch(c)
    {
        case 0:cout<<"\n\nEnter the name of a state: ";
                break;
        case 1:cout<<"\nEnter siteseeing for DAY 1: ";
                break;
        case 2:cout<<"\nEnter siteseeing for DAY 2: ";
                break;
        case 3:cout<<"\nEnter the famous hotel name: ";
                break;
        case 4:cout<<"\nEnter their famous food: ";
                break;
    }
    cin>>d;
    node* temp = new node;
    strcpy(temp->data,d);
    temp->right = temp->down = NULL;
    return temp;
}

/* function which constructs the linked list with  m rows and  n columns
 and returns the head pointer of the linked list */
node* construct_itinerary(int m, int n)
{
    // stores the head of the linked list
    node* mainhead = NULL;

    // stores the head of linked lists of each row
    node* head[m];
    node *righttemp, *newptr;

    // Firstly, we create m linked lists
    // by setting all the right nodes of every row
    for (int i = 0; i < m; i++)
    {

        // initially set the head of ith row as NULL
        head[i] = NULL;
        for (int j = 0; j < n; j++)
        {
            newptr = newNode(j);

            /* stores the first node as
            the mainhead of the linked list*/
            if (!mainhead)
                mainhead = newptr;

            if (!head[i])
                head[i] = newptr;
            else
                righttemp->right = newptr;

            righttemp = newptr;
        }
    }

    // Then, for every ith and (i+1)th list, we set the down pointers of
    // every node of ith list with its corresponding
    // node of (i+1)th list
    for (int i = 0; i < m - 1; i++)
    {

        node *temp1 = head[i], *temp2 = head[i + 1];

        while (temp1 && temp2)
        {

            temp1->down = temp2;
            temp1 = temp1->right;
            temp2 = temp2->right;
        }
    }

    // return the mainhead pointer of the linked list
    return mainhead;
}

//  function to print the linked list pointed to by head pointer
void display_itinerary(node* head)
{
    node *rp, *dp = head;

    // loop until the down pointer is not NULL
    while (dp)
     {
        rp = dp;

        // loop until the right pointer is not NULL
        while (rp)
        {
            cout <<"\t\t"<< rp->data ;
            rp = rp->right;
        }
        cout <<"\n\n";
        dp = dp->down;
        cout<<"\n";
    }
}

//function to display a single row
void displayrow(node *head,int m)
{
    node *ptr=head;
    int j=1;
    for(int i=0;i<m;i++)
    {
        ptr=ptr->down;
    }
    while(ptr)
    {
        cout<<j<<"\t\t"<<ptr->data<<endl;
        ptr=ptr->right;
    }
}

//function to display a single column
void displaycolumn(node *head,int n)
{
     node *ptr=head;
     int j=1;
    for(int i=0;i<n;i++)
    {
        ptr=ptr->right;
    }
    while(ptr)
    {
        cout<<"\n\n\t\t"<<j<<"\t\t"<<ptr->data;
        ptr=ptr->down;
        j++;
    }
}

void displaycab()
{
    system("color 04");
    int i;
    if(Front==0 && rear==0)
        cout<<"\n No cabs have been booked yet\n";
    else
    {
    cout<<"\n The list of booked cabs \n";
    for(i=Front;i<rear;i++)
    cout<<a[i]<<"\n\n";
    }
}
void bookcab(int no)
{
    system("color 04");
   int t;
   t=rand()%10000;
   while(t)
   {
       if(t>=1000&&t<=9999)
        break;
    else
        t=rand()%10000;
   }
    if(rear==10)
    cout<<"\n\n\t\t\tSorry!There is no availability of cab right now !!";
    else
    {
        cout<<"\n\n\n\t\t\tYour booking number is  "<<no <<"\n";
        cout<<"\n\n\t\t\tYour car number is  "<<t<<"\n";
     a[rear]=t;
        rear++;
      //  cout<<"\n value in "<<top<<"array is "<<a[top]<<"\n";
    //cout<<"\n valueof top is "<<top<<"\n";
    }
}
void endcab()
{

    int temp;
    if(Front==10)
        cout<<"\n\n\t\t\tThere is no cars in the booked list\n";
    else
    {
    temp=a[Front];
    Front++;
    cout<<"\n\n\t\t\tYour car no was : "<<temp<<"\n\n\t\t\tThank you for your journey !!!\n";
    cout<<"\n\n\t\t\tChoose us again!!!\n";
    }
}

//function to do all the admin operations
void admin()
{
    system("cls");
    system("color 0D");
    //stores the password entered by the user
    string inputpass;

    //stores the no.of trials for entering the password
    int t=1;

    /*allows the user to try out the password for three times
    if failed,exits the program*/
    l1: cout<<"\n\n\t\t\tEnter the password: ";
    cin>>inputpass;
    if(inputpass!=passwd)
    {
        if(t<3)
        {
            cout<<"\n\n\t\t\tINVALID PASSWORD\n\n\t\t\tTRY AGAIN";
            t++;
            goto l1;
        }
        else
        {
            cout<<"\n\n\t\t\tSorry, Wrong password again\n\nTry again later";
            exit(0);
        }

    }
    else
    {
         //here the admin can enter all the details about the trips and view them
        int f;
        char ch;
        do
        {
            system("cls");
            system("color E4");
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\t\tWELCOME ADMIN\n\n";
            cout<<"\n\n\t\t\t\t\t\t\t1.CREATE ITINERARY\n\n\t\t\t\t\t\t\t2.VIEW ITINERARY\n\n\t\t\t\t\t\t\t3.NO.OF CABS AVAILABLE NOW\n\n\t\t\t\t\t\t\t4.CAB BOOKED ORDER\n\n\t\t\t\t\t\t\t5.RETURN TO MAIN MENU\n\n\t\t\t\t\t\t\t6.EXIT";
            cout<<"\n\n\t\t\tEnter your choice: ";
            cin>>f;
            system("cls");
            switch(f)
            {
            case 1: /*cout<<"\nEnter the number of states: ";
                        cin>>m;*/
                        head = construct_itinerary( m, n);
                        cout<<"\n\n\t\t\tSUCCESSFULLY CREATED";
                        break;

                case 2:cout<<"\n\n\t\t\t\tTHE ITINERARY\n\n";
                        cout<<"\n\n\t\tSTATES\t\tDAY 1\t\tDAY 2\t\tFOOD\t\tHOTEL"<<"\n\n";
                        display_itinerary(head);
                        break;

                case 3:cout<<"\n\n\t\t\tThe Number of cars available now is "<<10-(rear-Front);
                        break;

                case 4:displaycab();
                        break;

                case 5:ch='n';
                        break;

                case 6:exit(0);

                default:cout<<"\n\n\t\t\tINVALID ENTRY";
            }
            if(f!=5)
            {
                cout<<"\n\n\t\t\tDo you want to return to Admin menu ? y-yes n-no : ";
                cin>>ch;
            }
        }while(ch=='y' || ch=='Y');
    }
}

//function to do all the customer opertions
void customer()
{
    int b;
    char ch1,ch2;
    do
    {
        system("cls");
        system("color 09");
        cout<<"\n\n\n\t\t\t\t\t\t1.TOURS AND TRIPS\n\n\t\t\t\t\t\t2.CAB BOOKING\n\n\t\t\t\t\t\t3.TRAVEL INFO\n\n\t\t\t\t\t\t4.RETURN TO MAIN MENU\n\n\t\t\t\t\t\t5.EXIT";
        cout<<"\n\n\n\t\t\tEnter your choice: ";
        cin>>b;
        system("cls");
        switch(b)
        {
            case 1:{
                        int u;
                        displaycolumn(head,0);
                        l2:cout<<"\n\n\nEnter your choice: ";
                        cin>>u;
                        system("cls");
                        switch(u)
                        {
                            case 1:displayrow(head,0);
                                    break;
                            case 2:displayrow(head,1);
                                    break;
                            case 3:displayrow(head,2);
                                    break;
                            case 4:displayrow(head,3);
                                    break;
                            case 5:displayrow(head,4);
                                    break;
                            default:cout<<"\n\n\t\t\tINVALID ENTRY";
                                    goto l2;
                        }
                        cout<<"\n\n\t\t\tDo you want to book the trip ? y-yes n-no  : ";
                        cin>>ch1;
                        if(ch1=='y' || ch1=='Y')
                        {
                            cout<<"\n\n\t\t\tBOOKED SUCCESSFULLY!";
                        }
                        else
                        {
                            cout<<"\n\n\t\t\tHOPEFULLY NEXT TIME :)";
                        }
                        break;
                    }

            case 2:{
                        int t,cc;
                        char ch4;
                        srand(time(0));
                        do
                        {
                            system("cls");
                            cout<<"\n\n\t\t\t\t\t You have now accessed cab facility!!\n";
                            cout<<"\n\n\t\t\t\t\t\tChoose any one of the option below to avail the facilities\n";
                            cout<<"\n\n\n\t\t\t1.Book a car\n";
                            cout<<"\n\n\t\t\t2.End your journey\n";
                            cout<<"\n\n\t\t\t3.Exit\n";
                            cout<<"\n\n\nEnter your choice: ";
                            cin>>cc;
                            switch(cc)
                            {
                                case 1:t=rear+1;
                                        bookcab(t);
                                        break;

                                case 2:endcab();
                                        break;

                                case 3: exit(0);
                                        break;
                            }
                             cout<<"\n\n\t\t\tDo you want to return to Cab menu? y-yes n-no : ";
                            cin>>ch4;
                        }while(ch4=='y' || ch4=='Y');
                        break;
                    }

            case 3:{
                        char ch3;
                        int v;
                        do
                        {
                            l3:system("cls");
                            cout<<"\n\t\t\t\t\t\t\tTRAVEL INFORMATION ";
                            cout<<"\n\n\n\t\t\t\t\t1.Trip available states\n\n\t\t\t\t\t2.Famous tourist spots\n\n\t\t\t\t\t3.Famous foods\n\n\t\t\t\t\t4.Our hotels ";
                            cout<<"\n\n\n\t\t\tEnter your choice: ";
                            cin>>v;
                            system("cls");
                            switch(v)
                            {
                                case 1: cout<<"\n\nThe states in which our service is available are ";
                                        displaycolumn(head,0);
                                        break;

                                case 2:cout<<"\n\nThe Famous tourist spots of the southern region are ";
                                        displaycolumn(head,1);
                                        displaycolumn(head,2);
                                        break;

                                case 3:cout<<"\n\nThe Famous foods of the southern region are ";
                                        displaycolumn(head,4);
                                        break;

                                case 4:cout<<"\n\nHotels in tie up with us across the southern region";
                                        displaycolumn(head,3);
                                        break;

                                default:cout<<"\n\nINVALID ENTRY";
                                        goto l3;
                            }
                            cout<<"\n\n\nDo you want to return  Travel info? y-yes n-no : ";
                            cin>>ch3;
                        }while(ch3=='y' || ch3=='Y');
                        break;
                    }

            case 4:ch2='n';
                    break;

            case 5:exit(0);
        }
        if(b!=4)
        {
            cout<<"\n\n\nDo you want to return to Customer menu? y-yes n-no  : ";
            cin>>ch2;
        }
    }while(ch2=='y' || ch2=='Y');
}

int main()
{
    int b;
    l:system("cls");
     system("Color 0A");
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t\tWELCOME TO TRAVELOCITY"<<endl;
    cout<<"\n\n\n\t\t\t\t\t\t\t\t\t\t\t1.ADMIN\n\n\t\t\t\t\t\t\t\t\t\t\t2.CUSTOMER\n\n\t\t\t\t\t\t\t\t\t\t\t3.EXIT";
    cout<<"\n\n\n\t\t\tEnter your choice: ";
    cin>>b;
    switch(b)
    {
        case 1: admin();
                goto l;
                break;

        case 2:customer();
                goto l;
                break;

        case 3:exit(0);

        default:cout<<"\nINVALID ENTRY";
                goto l;
    }
}

