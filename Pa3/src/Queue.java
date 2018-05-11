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
        if(numItems == 0){
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
            for(int i = 0; i<numItems-1;i++){//iterates numItems-1
                current = current.next;
            }
            current.next = new Node(newItem);
        }

        numItems++;
    }

    @Override
    public Object dequeue() throws QueueEmptyException {
        if(numItems == 0){
            throw new QueueEmptyException("cannot dequeue() empty queue");
        }
        if(numItems == 1){
            Node onlyOne = head;
            head = null;
            numItems--;
            return onlyOne.item;
        }
        Node theOne = head;
        head = head.next;
        numItems--;
        return theOne.item;

    }

    @Override
    public Object peek() throws QueueEmptyException {
        if(numItems == 0){
            throw new QueueEmptyException("cannot peek() empty queue");
        }
        return head.item;
    }

    public Object peek(int k) throws QueueEmptyException{
        if(numItems == 0){
            throw new QueueEmptyException("cannot peek() empty queue");
        }
        Node current = head;
        for(int i = 0; i<k; i++){//iterates k times
            current = current.next;
        }
        return current.item;

    }

    @Override
    public void dequeueAll() throws QueueEmptyException {
        if(numItems == 0){
            throw new QueueEmptyException("cannot dequeueAll() empty queue");
        }
        System.out.println(numItems);
        int k = length();
        for(int i = 0; i<k; i++){
            //System.out.println(i);
            //System.out.println("num: "+numItems);
            dequeue();
        }

    }
}
