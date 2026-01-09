////////////////////////////////////////////////////////////////////////////////////////////////
//
//                            STACK USING GENERIC APPROACH
//
//////////////////////////////////////////////////////////////////////////////////////////////

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

template <class T>
class Stacknode
{
    public:

        T data;
        Stacknode<T>*next;

        Stacknode(T no)
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

template <class T>
class Stack
{
    private:

        Stacknode<T>*first;
        int iCount;

    public:

        Stack();
        void Push(T);                                        
        T Pop();                                            
        T Peep();
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

template <class T>
Stack<T> :: Stack()
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

template <class T>
void Stack<T>:: Push(T no)
{
    Stacknode<T>*newn = NULL;
    newn = new Stacknode<T>(no);

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

template <class T>
T Stack<T> :: Pop()
{
    T Value = 0;
    Stacknode<T>*temp = this->first;

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

template <class T>
T Stack<T> :: Peep()
{
    T Value = 0;

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

template <class T>
void Stack<T> ::  Display()
{
    Stacknode<T>*temp = NULL;
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

template <class T>
int Stack<T> :: Count()
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
    Stack<char>*sobj = new Stack<char>();

    sobj->Push('A');
    sobj->Push('B');
    sobj->Push('C');
    sobj->Push('D');
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

    sobj->Push('E');
    sobj->Display();
    cout<<"\nNumber of Elements in Stack are :"<<sobj->Count()<<"\n";

    
    delete sobj;

    return 0 ;
}