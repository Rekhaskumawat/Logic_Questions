////////////////////////////////////////////////////////////////////////////////////////////////
//
//     required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

#pragma pack(1)

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name    : Stacknode
//  Input         : data of stack
//  Output        : Nothing
//  Description   : Structure of stack
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

class Stacknode
{
    public:
        int data;
        Stacknode*next;

        Stacknode(int no)
        {
            this->data = no;
            this->next = NULL;
        }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name    : Stack
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Prototype of function
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

class Stack
{
    private:
        Stacknode*first;
        int iCount;

    public:
        Stack();
        void Push(int);                                      
        int Pop();                                           
        int Peep();
        void Display();
        int Count();

};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Stack
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Initialization of members (Constructor)
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

Stack :: Stack()
{
    cout<<"Stack gets created succesfully...\n";
    this->first = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Push
//  Input         : data of stack
//  Output        : Nothing
//  Description   : Used to insert element into stack
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void Stack :: Push(int no)
{
    Stacknode*newn = NULL;
    newn = new Stacknode(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}  

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Pop
//  Input         : Nothing
//  Output        : Removed element from stack
//  Description   : Remove element from the stack
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

int Stack :: Pop()
{
    int Value = 0;
    Stacknode*temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is Empty\n";
        return -1;
    }
    Value = this->first->data;

    this->first = this->first->next;
    delete temp ;

    this->iCount--;

    return Value;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Peep
//  Input         : Nothing
//  Output        : Return the element from of the stack
//  Description   : Return the topmodt element of the stack
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

int Stack :: Peep()
{
    int Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is Empty\n";
        return -1;
    }

    Value = this->first->data;

    return Value;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Display the element of the stack
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void Stack ::  Display()
{
    Stacknode*temp = NULL;
    temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is Empty.\n";
        return;
    }

    while (temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }

}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Used to count number of element in the stack
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

int Stack :: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//    Entry point function
//
//////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Stack*sobj = new Stack();

    sobj->Push(11);
    sobj->Push(21);
    sobj->Push(51);
    sobj->Push(101);
    sobj->Display();
    cout<<"\nNumber of Elements in Stack are :"<<sobj->Count()<<"\n";

    cout<<"Return value of peep is :"<<sobj->Peep()<<"\n";
    sobj->Display();
    cout<<"\nNumber of Elements in Stack are :"<<sobj->Count()<<"\n";

    cout<<"Poped element is :"<<sobj->Pop()<<"\n";
    sobj->Display();
    cout<<"\nNumber of Elements in Stack are :"<<sobj->Count()<<"\n";

    cout<<"Poped element is :"<<sobj->Pop()<<"\n";
    sobj->Display();
    cout<<"\nNumber of Elements in Stack are :"<<sobj->Count()<<"\n";

    sobj->Push(121);
    sobj->Display();
    cout<<"\nNumber of Elements in Stack are :"<<sobj->Count()<<"\n";

    
    delete sobj;

    return 0 ;
}