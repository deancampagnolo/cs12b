//-----------------------------------------------------------------------------
// Simulation.java
//-----------------------------------------------------------------------------

import java.io.*;
import java.util.Scanner;

public class Simulation{

//-----------------------------------------------------------------------------
//
// The following function may be of use in assembling the initial backup and/or
// storage queues.  You may use it as is, alter it as you see fit, or delete it
// altogether.
//
//-----------------------------------------------------------------------------

    public static Job getJob(Scanner in) {
        String[] s = in.nextLine().split(" ");
        int a = Integer.parseInt(s[0]);
        int d = Integer.parseInt(s[1]);
        return new Job(a, d);
    }

//-----------------------------------------------------------------------------
//
// The following stub for function main contains a possible algorithm for this
// project.  Follow it if you like.  Note that there are no instructions below
// which mention writing to either of the output files.  You must intersperse
// those commands as necessary.
//
//-----------------------------------------------------------------------------

    public static void printContentsOfQ(PrintWriter writer, Queue Q){
        for(int i = 0; i<Q.length(); i++){
            writer.print(Q.peek(i)+ " ");
        }
    }

    public static void printStatus(int time, PrintWriter writer, Queue Q, Queue actualQueue, Queue finishedQueue){
        writer.println("time="+time);
        writer.print("0: ");
        printContentsOfQ(writer, Q);
        printContentsOfQ(writer, finishedQueue);
        writer.print("\n");
        writer.print("1: ");
        printContentsOfQ(writer, actualQueue);
        writer.print("\n\n");

    }

    public static void printProcess1(PrintWriter writer, Queue Q){
        int time = 0;

        Queue actualQueue = new Queue();
        Queue finishedQueue = new Queue();

        printStatus(time,writer,Q,actualQueue,finishedQueue);

        time++;
        boolean booleanPrint;

        int numberOfJobs = Q.length();

        while(finishedQueue.length() != numberOfJobs ){//while Q isn't empty
            booleanPrint = false;

            //if(actualQueue.length()<1) {
            if(!Q.isEmpty()) {
                if (time == ((Job) Q.peek()).getArrival()) {
                    actualQueue.enqueue(Q.dequeue());


                    printStatus(time, writer, Q, actualQueue,finishedQueue);
                    continue;//incase of overlap
                }
            }

            if(!actualQueue.isEmpty())
            if (((Job) actualQueue.peek()).getFinish() == -1) {
                ((Job) actualQueue.peek()).computeFinishTime(time);
            }
            //}

            if(!actualQueue.isEmpty()) {
                for (int i = 0; i < 1; i++) {
                    System.out.println("aaa"+time);
                    System.out.println("BBB" + ((Job) actualQueue.peek(i)).getFinish());
                    if (time == ((Job) actualQueue.peek(i)).getFinish()) {
                        finishedQueue.enqueue(actualQueue.dequeue());
                    }
                }
            }

                //if (actualQueue.length() < 1) {
                  //  continue;
                //}





            System.out.print("time: "+time+ "  ");
            System.out.println(Q.length());

            time++;

            if(time == 40){
                break;
                //Q.dequeueAll();
            }
        }


    }



    public static void main(String[] args) throws IOException{

        Queue Q = new Queue();
        File file = new File(args[0]);
        try{
            Scanner scan = new Scanner(file);
            int m = scan.nextInt();
            System.out.println(m);


            for(int i = 0; i<m; i++){
                Q.enqueue(new Job (scan.nextInt(),scan.nextInt()));
            }

            scan.close();

        } catch(FileNotFoundException e){
            e.printStackTrace();
        }

        PrintWriter writer = new PrintWriter(args[0]+".trc");//TODO write this in try catch

        writer.println("Trace file: ex1.trc");
        writer.println(Q.length() + " Jobs:");
        printContentsOfQ(writer,Q);
        writer.print("\n\n");

        writer.println("*****************************");
        writer.println("1 processor:");
        writer.println("*****************************");

        printProcess1(writer,Q);


        writer.println("*****************************");
        writer.println("2 processors:");
        writer.println("*****************************");





        writer.close();


//    1.  check command line arguments
//
//    2.  open files for reading and writing
//
//    3.  read in m jobs from input file
//
//    4.  run simulation with n processors for n=1 to n=m-1  {
//
//    5.      declare and initialize an array of n processor Queues and any
//            necessary storage Queues
//
//    6.      while unprocessed jobs remain  {
//
//    7.          determine the time of the next arrival or finish event and
//                update time
//
//    8.          complete all processes finishing now
//
//    9.          if there are any jobs arriving now, assign them to a processor
//                Queue of minimum length and with lowest index in the queue array.
//
//    10.     } end loop
//
//    11.     compute the total wait, maximum wait, and average wait for
//            all Jobs, then reset finish times
//
//    12. } end loop
//
//    13. close input and output files

    }
}
