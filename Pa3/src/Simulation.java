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

    public static void printStatus(int processors, int time, PrintWriter writer, Queue Q, Queue finishedQueue){
        writer.println("time="+time);
        writer.print("0: ");
        printContentsOfQ(writer, Q);
        printContentsOfQ(writer, finishedQueue);
        writer.print("\n");
        for(int i = 0; i<processors; i++) {
            writer.print((i+1)+": ");
            printContentsOfQ(writer, allTheQueues[i]);
            writer.print("\n\n");
        }

    }

    public static void whichQueueGetsIt(Object theItem, int processors){
        int lowest = processors-1;
        for(int i = processors-1; i>=0; i--){
            if(allTheQueues[i].length()<=allTheQueues[lowest].length()){
                lowest = i;
            }
        }
        allTheQueues[lowest].enqueue(theItem);
    }

    public static Queue printProcess(PrintWriter writer, Queue Q, int processors){
        int time = 0;

        writer.println("*****************************");
        if(processors == 1) {
            writer.println("1 processor:");
        } else{
            writer.println(processors+" processors:");
        }
        writer.println("*****************************");


        Queue finishedQueue = new Queue();

        printStatus(processors,time,writer,Q,finishedQueue);

        time++;
        boolean booleanPrint = false;

        int numberOfJobs = Q.length();



        while(finishedQueue.length() != numberOfJobs ){//while Q isn't empty


            //if(!actualQueue.isEmpty()) {//if actual queue has something
            for(int i = 0; i<allTheQueues.length;i++) {
                //for (int i = 0; i < 1; i++) {
                if (!allTheQueues[i].isEmpty()) {
                    if (time == ((Job) allTheQueues[i].peek()).getFinish()) {
                        finishedQueue.enqueue(allTheQueues[i].dequeue());
                        booleanPrint = true;
                    }
                }
            }

                //}

            //}

            //if(actualQueue.length()<1) {
            if(!Q.isEmpty()) {
                if (time == ((Job) Q.peek()).getArrival()) {

                    whichQueueGetsIt(Q.dequeue(), processors);

                    booleanPrint = true;
                    continue;//incase of overlap
                }
            }

            for(int i = 0; i<allTheQueues.length;i++) {
                if (!allTheQueues[i].isEmpty()) {
                    if (((Job) allTheQueues[i].peek()).getFinish() == -1) {
                        ((Job) allTheQueues[i].peek()).computeFinishTime(time);
                    }
                }
            }
            //}



                //if (actualQueue.length() < 1) {
                  //  continue;
                //}





            System.out.print("time: "+time+ "  ");
            System.out.println(Q.length());

            if(booleanPrint) {
                printStatus(processors,time, writer, Q,  finishedQueue);
            }

            booleanPrint = false;
            time++;
            if(time == 100){
                break;
            }

        }

        return finishedQueue;

    }


    private static Queue[] allTheQueues;
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

        allTheQueues = new Queue[Q.length()-1];
        for(int i = 0; i<allTheQueues.length; i++){
            allTheQueues[i] = new Queue();
        }
        //
        int iterations = Q.length();

        for(int i = 1; i<4; i++) {

            Q = printProcess(writer,Q, i);

            if(i == 3){
                break;
            }
            for(int j = 0; j<iterations; j++){
                System.out.println("BING BONG");
                ((Job) Q.peek(j)).resetFinishTime();
            }
        }






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
