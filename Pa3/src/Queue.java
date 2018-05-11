public class Queue implements QueueInterface {

    private class Node{
        Object item;
        Node next;

        Node(Object x){
            item = x;
            next = null;
        }

    }

    private Node head;
    private int numItems;

    public Queue(){
        head = null;
        numItems = 0;
    }

    @Override
    public boolean isEmpty() {
        if(numItems <= 0){
            return true;
        }
        return false;
    }

    @Override
    public int length() {
        return numItems;
    }

    @Override
    public void enqueue(Object newItem) {
        if (head == null){
            head = new Node(newItem);
        } else {
            Node current = head;
            for(int i = 0; i<=numItems;i++){//iterates numItems-1
                current = current.next;
            }
            current.next = new Node(newItem);
        }

        numItems++;
    }

    @Override
    public Object dequeue() throws QueueEmptyException {
        if(numItems ==0){
            throw new QueueEmptyException("cannot dequeue() empty queue");
        }
        Node theOne;


        return null;
    }

    @Override
    public Object peek() throws QueueEmptyException {
        return null;
    }

    @Override
    public void dequeueAll() throws QueueEmptyException {

    }
}
