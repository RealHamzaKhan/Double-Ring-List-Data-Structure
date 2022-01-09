#include <iostream>

using namespace std;
struct node
{
    int data;
    node *next;
    node *previous;
};
class doublering
{
private:
    node *head,*temp,*temp1;
    int key;
public:

    doublering()
    {
            head=temp=temp1=NULL;
    }
    void add()
    {
        if(head==NULL)
        {
            head=new node;
            cout<<"What you want to add?";
            cin>>head->data;
            head->next=head;
            head->previous=head;
            return;
        }
        else
        {
            temp=head;
            cout<<"After which element you want to insert?";
            cin>>key;
            cout<<"What you want to add?";
            while(temp->next!=head)
            {
                if(temp->data==key)
                {
                    temp1=new node;
                    cin>>temp1->data;
                    temp1->next=temp->next;
                    temp1->previous=temp;
                    temp->next=temp1;
                    temp1->next->previous=temp1;


                }
                temp=temp->next;
            }
            if(temp->data==key)
                {
                    temp1=new node;
                    cin>>temp1->data;
                    temp1->next=temp->next;
                    temp1->previous=temp;
                    temp->next=temp1;
                    temp1->next->previous=temp1;
                    temp=temp->next;

                }
        }
    }
    void remove_Element()
    {
        if(head==NULL)
        {
            cout<<"Nothing to delete ";
            return;
        }


        else
        {

            cout<<"What to do you want to delete?";
            cin>>key;
            if(head->next==head && head->previous==head && head->data==key)
        {
            head=NULL;
            return;
        }

            temp=head;
            while(temp->next!=head)
            {
               if(temp==head && temp->data==key)
               {
                   temp->previous->next=temp->next;
                temp->next->previous=temp->previous;
                head=temp->next;
                temp1=temp;
                temp=head;
               }
               if(temp!=head && temp->data==key)
               {
                   temp->previous->next=temp->next;
                   temp->next->previous=temp->previous;
                   temp1=temp;
                   temp=temp->next;
                   delete temp1;

               }



            temp=temp->next;
            }
            if(temp!=head && temp->data==key)
               {
                   temp->previous->next=temp->next;
                   temp->next->previous=temp->previous;
                   temp1=temp;
                   temp=temp->next;
                   delete temp1;
               }

        }
    }
    void print()
    {
        temp=head;
        while(temp->next!=head)
        {
            cout<<temp->data<<"  ";
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }
};

int main()
{
    int i;
    doublering r;
    cout<<"Options:";
    cin>>i;
    while(i!=4)
    {
        if(i==1)
            r.add();
        if(i==2)
            r.print();
        if(i==3)
            r.remove_Element();
        cout<<"Options:";
        cin>>i;

    }
}
