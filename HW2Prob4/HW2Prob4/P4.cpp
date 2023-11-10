// P4.cpp
//  HW2Prob4
//  Created by Serin Santhosh on 11/5/23.

#include "hw2_functions.h"

using namespace std;

Plane::Plane(const string& from, const string& to)
{
    //Question 1
    flight_distance["SCE"]["PHL"] = 160;
    flight_distance["SCE"]["ORD"] = 640;
    flight_distance["SCE"]["EWR"] = 220;
    
    //Question 3:
    // In a constructor:
    //Store the input string “from” in “origin” variable
    origin = from;
    
    // In a constructor:
    //Store the input string “to” in “destination” variable
    destination = to;
    // In a constructor:
    //Set the value of “distance” to the distance between the origin and the destination airports (Hint: use your container from Question 1)
    distance = flight_distance[origin][destination];
    
    // In a constructor:
    // Initialize the value of “pos”, “vel”, “wait_time”, “loiter_time”, and “at_SCE” variables to zero
    double pos, vel, wait_time, loiter_time, at_SCE;
    pos = 0;
    vel = 0;
    wait_time = 0;
    loiter_time = 0;
    at_SCE = 0;
}

    //virtual deconstructor left empty
    Plane::~Plane()
    {
        // empty
    }

    // Question 3:
    //A function named “operate” with a double variables “dt” as an input, and return the flowchart.
    void Plane::operate(double dt)
    {
        // Start:
        
        // loiter_time is not equal (!=) to 0 then...
            if (loiter_time != 0)
            {
                // Set loiter_time to subtract dt from the loiter_time
                loiter_time -= dt;
            }
        
            // No to loiter_time is not equal (!=) to 0
            // and it wait_time is not equal (!=) to 0...
            else if (wait_time != 0)
            {
                // Set wait_time to subtract dt from the wait_time
                wait_time -= dt;
            }
        // No to loiter_time is not equal (!=) to 0 and no to wait_time is not equal (!=) to 0
        // If pos < distance...
            else if (pos < distance)
            {
                // add vel* dt to pos value
                pos += vel * dt;
                
                // then set at_SCE to 0 and end this branch
                at_SCE = 0;
            }
        //if no to: loiter_time is not equal (!=) to 0, wait_time is not equal (!=) to 0 and pos < distance
        // and yes to the destination equal to SCE
            else if (destination == "SCE")
            {
                // set at_SCE equal to 1
                at_SCE = 1;
                
                // Then call time on ground() function
                time_on_ground();

                // Swap the value of "origin" and "destination"
                string change;
                change = origin;
                origin = destination;
                destination = change;

                // after swapping the values set pos equal to 0.0
                pos = 0.0;
            }
        // if none of the other statments are true use the else statement...
            else
            {
                // Call time_on_ground() function
                time_on_ground();

                
                // Swap the value of "origin" and "destination"
                string change;
                change = origin;
                origin = destination;
                destination = change;

                // after swapping the values set pos equal to 0.0
                pos = 0.0;
            }
    }

//Question 3:

    //get function for “pos” variable
    double Plane::get_pos() const
    {
        // All get functions return the value of their variable
        return pos;
    }

    //get functions for “vel” variable
    double Plane::get_vel() const
    {
        // All get functions return the value of their variable
        return vel;
    }

    //get functions for “loiter_time” variable
    double Plane::get_loiter_time() const
    {
        // All get functions return the value of their variable
        return loiter_time;
    }

    //get function for “origin” variable
    string Plane::get_origin() const
    {
        // All get functions return the value of their variable
        return origin;
    }

    //get function for “destination” variable
    string Plane::get_destination() const
    {
        // All get functions return the value of their variable
        return destination;
    }

    //get function for “at_SCE” variable
    bool Plane::get_at_SCE() const
    {
        // All get functions return the value of their variable
        return at_SCE;
    }

    //set functions for “vel” variable
    void Plane::set_vel(double vel2)
    {
        //All set functions set the value of their variable based on an input
        vel = vel2;
        //void will not return anything
    }

    //set functions for “loiter_time” variable
    void Plane::set_loiter_time(double loiter_time2)
    {
        //All set functions set the value of their variable based on an input
        loiter_time = loiter_time2;
        //void will not return anything
    }

    //A function named “distance_to_SCE” that returns double
//A “distance_to_SCE” function returns the difference between “distance” and “pos” variables if and only if “destination” is a string “SCE”
    double Plane::distance_to_SCE()
    {
        if (destination == "SCE")
        {
            double difference;
            difference = distance - pos;
            return difference;
            
        }
        // if the destination is not equal to "SCE" will return nothing
        else
        {
            return 0;
        }
    }

    //A virtual function named “time_on_ground”
    double Plane::time_on_ground()
    {
        //must return a value to run
        return 0;
    }

    //A virtual function named “plane_type” that returns a string "GA"
    string Plane::plane_type()
    {
        //must return a string to run
        return "GA";
    }

    //A static function named “draw_from_normal_dist” that takes in two double variables (mean and standard deviation), and returns back a random number from a normal distribution.
    double Plane::draw_from_normal_dist(double mean, double std_dev)
    {
        // used question 3 to create the random distributions!
        random_device rd{};
        mt19937 gen{ rd() };
        normal_distribution<> d{ mean, std_dev };
        return d(gen);
    }

// Question 4:

// Create two classes named “Airliner” and “GeneralAviation”, in which both are derived/inherited from the class “Plane”

// class “Airliner” has the following members and implementations

// A constructor that takes in three strings “Airline”, “from” and “to” as input arguments. It stores the input string “Airline” in “Airline” variable, and passes the inputs “from” and “to” to a constructor of a class “Plane”
Airliner::Airliner(string& Airline, string& from, string& to) : Plane(from, to), Airline(Airline)
{
    
}

//An empty deconstructor
Airliner::~Airliner()
{
    
};

// An overridden function “plane_type” that returns “Airline”
//use string since airliner will be a name
string Airliner::plane_type()
{
    return Airline;
}

//An overridden function “time_on_ground” that returns “wait_time”, which is drawn from the “draw_from_normal_dist” function using a mean and a standard deviation of 1800 and 600, respectively
// used double since numbers are involved
double Airliner::time_on_ground()
{
    return draw_from_normal_dist(1800, 600);
}

// the other class “GeneralAviation” has the following members and implementations

// A constructor that takes in two strings “from” and “to” as input arguments passes these inputs “from” and “to” to a constructor of a class “Plane”
GeneralAviation::GeneralAviation (string& from, string& to) : Plane(from, to)
{
    
}

// An empty deconstructor
GeneralAviation::~GeneralAviation()
{
    
};

// An overridden function “time_on_ground” that returns “wait_time”, which is drawn from the “draw_from_normal_dist” function using a mean and a standard deviation of 600 and 60, respectively.
double GeneralAviation::time_on_ground()
{
    return draw_from_normal_dist(600, 60);
}

int main ()
{
    // use a modified way to store the distnaces into the container from question...
    // the way i did it origianlly didnt work so i had to adjust it to use in oop method
    // Question 1
    map<string, map<string, int>> flight_distance;
        flight_distance["SCE"]["PHL"] = 160;
        flight_distance["SCE"]["ORD"] = 640;
        flight_distance["SCE"]["EWR"] = 220;
    return 0;
}
