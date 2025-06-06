//Name: Imad Farhat
#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() 
    :head(nullptr)
{
    //Nothing here...
}

DoublyLinkedList::~DoublyLinkedList()
{
    DoublyLinkedListNode* Current = head;
    while (Current != nullptr) {
        DoublyLinkedListNode* temp = Current;
        Current = Current->Next;
        delete temp;
    }
    head = nullptr;
    //loops through linked list, moves node up while deleting current value
    //then head stops pointing to deleted nodes

}

void DoublyLinkedList::push_front(short value)
{
    DoublyLinkedListNode* temp = new DoublyLinkedListNode(value);
    temp->Next = head;
    if (head != nullptr) {
        head->Previous = temp;
    }
    head = temp;
    //sets the old head to be the next node, and sets the new value
    //as the head
}

void DoublyLinkedList::pop_front()
{
   
    if (size() > 1) {
        DoublyLinkedListNode* temp = head;
        head = head->Next;
        if (head != nullptr) {
            head->Previous = nullptr;
        }
        delete temp;
    }
    //moves old head up while deleting the previous head, does nothing if list is empty
}

void DoublyLinkedList::insert(int positionIndex, short value)
{
    if (positionIndex == 0 || head == nullptr) {
        push_front(value);
        //if its inserted at head, just reuses push_front
    }
    else {
        int tempcount = 0;
        DoublyLinkedListNode* Current = head;
        while (Current->Next  != nullptr && tempcount < positionIndex - 1) {
            Current = Current->Next;
            tempcount++;
            //loops through list and incriments count until its at the position
        }

        DoublyLinkedListNode* temp = new DoublyLinkedListNode(value);

        if (Current->Next == nullptr || tempcount > size()) {
            Current->Next = temp;
            temp->Previous = Current;
            //adds to back of list if the index is greater than the size
        } 
        else {
            temp->Next = Current->Next;
            temp->Previous = Current;
            
            if (Current->Next != nullptr) {
                Current->Next->Previous = temp;
                //if the current is not the last node, it makes sure that the previous node
                //points to temp backwards
            }
        }
        Current->Next = temp;

        //stores value as a node, inserts a node in between next and previous and makes sure
        //they both point to new node

    }

}

bool DoublyLinkedList::empty()
{
    return (head == nullptr);
    //returns if head is a nullptr, meaning list is empty
}

int DoublyLinkedList::size()
{
    DoublyLinkedListNode* Current = head;
    int size = 0;
    while (Current != nullptr) {
        size++;
        Current = Current->Next;
    }
    return size;
    //loops through list to count size, keeps track and increments by 1
    //until loop ends
}

void DoublyLinkedList::erase(int positionIndex)
{
    if (head == nullptr) {
        throw std::out_of_range("Error! List is empty");
        //throws exception if list is empty
    }
    if (positionIndex == 0) {
        pop_front();
        //reuses popfront if position is at head
    }
    else {
        DoublyLinkedListNode* Current = head;
        int tempCount = 0;

        while (Current != nullptr && tempCount < positionIndex) {
            Current = Current->Next;
            tempCount++;
            //loops through list until it lands on index
        }
        if (Current == nullptr) {
            throw std::out_of_range("Error! Index is out of bounds");
            //throws exception if index to be erased doesn't exist
        }
        if (Current->Previous != nullptr) {
            Current->Previous->Next = Current->Next;
        }

        if (Current->Next != nullptr) {
            Current->Next->Previous = Current->Previous;
        }
        //makes sure previous and next stop pointing to node
        delete Current;
        //deletes node
    }
}

int DoublyLinkedList::find(short value)
{
    int index = 0;
    DoublyLinkedListNode* Current = head;
    while (Current != nullptr) {
        if (Current->data == value) {
            return index;
        }
         Current = Current->Next;
         index++;
         //keeps looping through array until value is found
         //or until list ends
    }

    return -1;
    //returns -1 if value was never found

}

short DoublyLinkedList::operator[](int index)
{
    int tempcount = 0;
    DoublyLinkedListNode* Current = head;
    while (Current != nullptr && tempcount < index) {
        Current = Current->Next;
        tempcount++;
    }
    if (Current != nullptr) {
        return Current->data;
    }
    //loops through array until the index given, returns data if data exists at node index
    return std::numeric_limits<short>::min();
    //returns this if index doesn't exist 
}

std::ostream& operator<<(std::ostream& ostr, const DoublyLinkedList& rhs)
{
    DoublyLinkedListNode* Current = rhs.head;
    while (Current != nullptr) {
        std::cout << Current->data << " ";
        Current = Current->Next;
    }
    //loops through list, printing data from node each time 
    return ostr;
}
