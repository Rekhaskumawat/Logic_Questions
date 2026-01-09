////////////////////////////////////////////////////////////////////////////////////////////////
//
//                  QUEUE USING GENERIC APPROACH
//
//////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////
//
//    required header file
//
//////////////////////////////////////////////////////////////////////////////////////////////


#include<iostream>
using namespace std;

#pragma pack(1)

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name    : Queuenode
//  Input         : Data of Queue
//  Output        : Nothing
//  Description   : structure of queue
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Queuenode
{
    public:

        T data;
        Queuenode<T>*next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name    : Queue
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Prototype of functions
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Queue
{
    private:

        Queuenode<T> *first;
        Queuenode<T> *last;
        int iCount;

    public:

        Queue();
        void enqueue(T);                                                  
        T dequeue();                                                   
        void Display();
        int Count();

};

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Queue
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Intialization of members(Constructor)
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
Queue<T> :: Queue()
{
    cout<<"Queue gets created succesfully...\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : enqueue
//  Input         : data for queue
//  Output        : Nothing
//  Description   : Insert the element in the queue
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T> :: enqueue(T no)
{
    Queuenode<T>*newn = NULL;
    newn = new Queuenode<T>(no);

    if(this->first == NULL && this->last ==NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
    }
    
    this->iCount++;
}  

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : dequeue
//  Input         : Nothing
//  Output        : Return the removed element from queue
//  Description   : Remove element from queue
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T Queue<T> :: dequeue()
{
    T Value = 0;
    Queuenode<T>*temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is Empty\n";
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
//  Function Name : Display
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Display elements of queue
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 07/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T> ::  Display()
{
    Queuenode<T>*temp = NULL;
    temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is Empty.\n";
        return;
    }

    while (temp != NULL)
    {
        cout<<"| "<<temp->data<<" |-";
        temp = temp->next;
    }
    cout<<"\n";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Input         : Nothing
//  Output        : Nothing
//  Description   : Count number of elements into queue
//  Author        : Rekha Shankarlal Kumawat
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int Queue<T> :: Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
//                  Entry point function
//
//////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    Queue<double>*qobj = new Queue<double>();

    qobj->enqueue(11.32333);
    qobj->enqueue(21.56743);
    qobj->enqueue(51.234643);
    qobj->enqueue(101.35634);
    qobj->Display();
    cout<<"\nNumber of Elements in Queue are :"<<qobj->Count()<<"\n";

    cout<<"Removed element is :"<<qobj->dequeue()<<"\n";
    qobj->Display();
    cout<<"\nNumber of Elements in Queue are :"<<qobj->Count()<<"\n";

    cout<<"Removed element is :"<<qobj->dequeue()<<"\n";
    qobj->Display();
    cout<<"\nNumber of Elements in Queue are :"<<qobj->Count()<<"\n";

    qobj->enqueue(121.56789);
    qobj->Display();
    cout<<"\nNumber of Elements in Queue are :"<<qobj->Count()<<"\n";

    delete qobj;

    return 0 ;
}