import java.io.*;

class Queue{
    private int size;
    private int queueArr[];
    private int front,rear;

    Queue(int size){            //constructor
        this.size = size;
        this.queueArr = new int[size];
        this.front = this.rear=-1;
    } 
    boolean enqueue(int elem){
        if(rear == size - 1 )
            return false;

        if(front == -1)
            front = 0;

        rear++;
        queueArr[rear] = elem;
        return true;
        
    }

    Integer dequeue(){
        if(front == -1)
            return null;
        
        int temp= queueArr[front];

        if(front == rear)
            front = rear = -1;
        else    
            front++;
        return temp;
    }
}

public class Queue_constrcutor{
    public static void main(String args[]){
        Integer num,option;
        DataInputStream din = new DataInputStream(System.in);
        Queue queue = null;

        try{
            System.out.println("Enter the queue size : ");
            int size = Integer.parseInt(din.readLine());
            queue = new Queue(size);
            do {
                    System.out.println("\n\n1.Enqueue. \n2.Dequeue.\n3.Exit.\nEnter your choice :  ");
                    option = Integer.parseInt(din.readLine());
                    
                    switch (option) {
                        case 1:
                            System.out.println("Enter element to enqueue: ");
                            num = Integer.parseInt(din.readLine());
                            if (queue.enqueue(num)) {
                                System.out.println("Enqueued");
                            }
                            else {
                                System.out.println("Queue Full.Cannot Enqueue");
                            }
                            break;
    
                        case 2:
                            num = queue.dequeue();
                            if (num == null)
                                System.out.println("Queue empty");
                            else
                                System.out.println("Dequeued : " + num);
    
                            break;
    
                        case 3:
                            return;
    
                        default:
                            System.out.println("Wrong choice try again \n\n");
                    }
                
            } while (true);

        }
        catch(Exception e){
            System.out.println("Error : "+e);
        }
    }
}
