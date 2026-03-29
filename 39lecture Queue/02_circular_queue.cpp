#include<iostream>
using namespace std;

class circular_queue
{
    int front;
    int rear;
    int* arr;
    int size;


    public:
    circular_queue(int size)
    {
        front =rear =-1;
        arr =new int[size];
        this->size = size;   // FIX: store size
    }
    bool empty()
    {
        return front ==-1&&rear ==-1;
    }
    bool full()
    {
        return front ==(rear+1)&size;
    }

    void push(int data)
    { 
      if(empty())
      {
        front = rear = 0;
        arr[rear] = data;
        return; 
      }
      else if(full())
      {
        cout<<"queue is full\n";
        return;
      }
      else
      {
        rear =(rear+1)%size; // circular increment
        arr[rear] = data;
        return;
      }
    }
    void pop()
    {
        if(empty())
        {
            cout<<"queue is empty\n";
            return;
        }
        else if(front == rear)
        {
            cout<<"element is poped"<<arr[front]<<endl;
            front = rear = -1; // reset to empty state
            return;
        }
        else
        {
            cout<<"element is poped"<<arr[front]<<endl;
            front =(front+1)%size; // circular increment
            return;
        }

    }

};
int main()
{
    circular_queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(20);
    q.pop();
    q.push(20); 
    q.push(20); 

    return 0;
}