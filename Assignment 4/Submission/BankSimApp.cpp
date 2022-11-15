/*  BankSimApp.cpp -> Bank Simulation App class implementation file
 *   Author: Rohan Parmar
 *   Date: 3/11/2022
 *
 *
 *
 */

#include "Queue.cpp"
#include "PriorityQueue.cpp"
#include "EmptyDataCollectionException.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

unsigned int totalWaitTime = 0;

void processArrival(Event &nextCustomer, PriorityQueue<Event> &eventPriorityQueue, Queue<Event> &bankLine, bool &tellerAvailable)
{
    //get time for next customer
    int customerTime = nextCustomer.getTime();
    //print customer time
    cout << "Processing an arrival event at time:" << setw(5) << right << customerTime << endl;
    //dequeue event
    eventPriorityQueue.dequeue();
    if (tellerAvailable && bankLine.isEmpty())
    {
        tellerAvailable = false;
        customerTime = nextCustomer.getTime();
        // totalWaitTime += customerTime;
        Event departure = Event(Event::DEPARTURE, customerTime + nextCustomer.getLength());
        eventPriorityQueue.enqueue(departure);
    }
    else
    {
        //enqueue nextCustomer to bankline queue
        bankLine.enqueue(nextCustomer);
    }
}

void processDeparture(Event &nextCustomer, PriorityQueue<Event> &eventPriorityQueue, Queue<Event> &bankLine, bool &tellerAvailable)
{
    int customerTime = nextCustomer.getTime();
    int currentTime = nextCustomer.getTime();
    cout << "Processing a departure event at time:" << setw(4) << right << customerTime << endl;
    // totalWaitTime += customerTime;
    eventPriorityQueue.dequeue();
    //cout << "Dequeued an event from eventPriorityQueue" << endl;

    int departureTime;

    if (!bankLine.isEmpty())
    {
        try
        {
            Event newCustomer = bankLine.peek();
            totalWaitTime = totalWaitTime + customerTime - newCustomer.getTime();
            bankLine.dequeue();
            // customerTime = newCustomer.getTime();
            departureTime = customerTime + newCustomer.getLength();
            Event departure = Event(Event::DEPARTURE, departureTime);
            eventPriorityQueue.enqueue(departure);
        }
        catch (EmptyDataCollectionException &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }
    else
    {
        tellerAvailable = true;
    }
}

int main()
{
    cout << "Simulation Begins" << endl;

    // unsigned int customerTime = 0;
    // unsigned int totalWaitTime = 0;
    unsigned int numCustomers = 0;

    bool tellerAvailable = true;

    string aLine = "";
    string delimiter = " ";
    string arrivalData = "";
    string lengthData = "";

    Queue<Event> bankLine = Queue<Event>();
    PriorityQueue<Event> eventPriorityQueue = PriorityQueue<Event>();
    Event newCustomer;

    // Read the data from the input files provided in the command line
    // and store them in the priority queue PQ
    while (getline(cin, aLine))
    {
        // Separate input line into arrival time and length of transaction
        arrivalData = aLine.substr(0, aLine.find(delimiter));
        lengthData = aLine.substr(aLine.find(delimiter) + 1, aLine.length());

        // Call the constructor of Event class to create an event
        // using the arrival time and length of transaction in integer format
        newCustomer = Event();
        newCustomer.setTime(stoi(arrivalData));
        newCustomer.setLength(stoi(lengthData));
        eventPriorityQueue.enqueue(newCustomer);
        numCustomers++;
    }

    int arrivalCount = 0;
    int departureCount = 0;

    // Process the events in the priority queue CustomerPriority
    while (!eventPriorityQueue.isEmpty())
    {
        try
        {
            Event nextCustomer = eventPriorityQueue.peek();
            if (nextCustomer.getType() == Event::ARRIVAL)
            {
                arrivalCount++;
                //cout << "Processing Arrival Event " << arrivalCount << endl;
                processArrival(nextCustomer, eventPriorityQueue, bankLine, tellerAvailable);
                //cout << "Arrival Event " << arrivalCount << " processed" << endl
                 //    << endl;
            }
            else
            {
                departureCount++;
                //cout << "Processing Departure Event " << departureCount << endl;
                processDeparture(nextCustomer, eventPriorityQueue, bankLine, tellerAvailable);
                //cout << "Departure Event " << departureCount << " processed" << endl
                 //    << endl;
            }
        }
        catch (EmptyDataCollectionException &e)
        {
            cout << "Error: " << e.what() << endl;
        }
    }

    // Print statistics
    cout << "Simulation Ends" << endl;
    cout << endl;
    cout << "Final Statistics: " << endl;
    cout << endl;
    cout << "    Total number of people processed:  " << numCustomers << endl;
    cout << "    Average amount of time spent waiting: " << (float)totalWaitTime / (float)numCustomers << endl;
}