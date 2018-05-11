public class QueueTest {
    public static void main(String[] args){
        Job k= new Job(1,2);

        Queue Q = new Queue();

        Q.enqueue(k);
        Q.enqueue(new Job(2,3));

        Q.enqueue(new Job(5,2));
        Q.enqueue(new Job(5,2));
        Q.enqueue(new Job(5,2));
        Q.enqueue(new Job(5,2));
        Q.enqueue(new Job(5,2));
        Q.enqueue(new Job(5,2));

        System.out.println(Q.isEmpty());
        System.out.println(Q.dequeue());
        System.out.println(Q.length());
        System.out.println(Q.peek());
        Q.dequeueAll();
        System.out.println(Q.length());
        System.out.println(Q.isEmpty());
    }
}
