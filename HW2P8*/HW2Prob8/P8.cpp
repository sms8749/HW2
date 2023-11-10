//  P8.cpp
//  HW2Prob8
//
//  Created by Serin Santhosh on 11/7/23.
//
#include "hw2_functions.h"
#include "HW2_Visualizer.h"
#include "SDL2/SDL.h"

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
// Question 5: added const so variables were stored correctly
Airliner::Airliner(const string& Airline, const string& from, const string& to) : Plane(from, to), Airline(Airline)
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
// Question 5: added const so variables were stored correctly
GeneralAviation::GeneralAviation (const string& from, const string& to) : Plane(from, to)
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

// Question 6
// Create a class “ATC” has the following members and implementations
// Public members of ATC class functions

// ATC: Public: Empty Constructor
ATC::ATC()
{
    
};

// ATC: Public: Empty Deconstructor
ATC::~ATC()
{
    
};

// A function named “register_plane” that takes in an airplane object to store in the container (a private variable member above). Hint: Pointers or References may be used to ensure that the input object and the one stored in the container are the same
//choose void since its just storing informaiton, not returning anything is needed
void ATC::register_plane (Plane * plane)
{
    //stores information in a vector!
    registered_planes.push_back(plane);
}

// A function named “control_traffic” that contains the following flowchart. Hint: Utilize the container. Any variables not being this class members are local variables within this function
void ATC::control_traffic()
{
    // starting vaules - flowchart
    int landed_planes;
    landed_planes = 0;
    int i ;
    i = 0;
    
    // first condition
    if ( i < registered_planes.size() )
    {
        //update the landed_planes by adding the number of planes at SCE of the plane i
        landed_planes += registered_planes[i] -> get_at_SCE();
        
        // then add one to i
        i++;
    }
    else if (landed_planes >= MAX_LANDED_PLANE_NUM)
    {
        // set i equal to 0
        i = 0;
        
        //another set if if statements
        if ( i < registered_planes.size() )
        {
            // another another if statement
            // checks from flow chart
            // 1 - for plane i, at_sce == 0 and distance to sce <= airspace distance and loiter time = 0
            if (registered_planes[i]->get_at_SCE() == 0 && registered_planes[i] -> distance_to_SCE() <= ATC::AIRSPACE_DISTANCE && registered_planes[i]-> get_loiter_time() == 0)
            {
                // if check is true then set the loiter time for the specific plane at 100
                registered_planes[i] -> set_loiter_time(100);
                
                // then update i and add one!
                i++;
            }
        }
    }
}

// Question 8:
// Use int main( int argc, char** argv ) instead of int main() for your main function
int main (int argc, char** argv)
{
    // use a modified way to store the distnaces into the container from question...
    // the way i did it origianlly didnt work so i had to adjust it to use in oop method
    // Question 1
    map<string, map<string, int>> flight_distance;
        flight_distance["SCE"]["PHL"] = 160;
        flight_distance["SCE"]["ORD"] = 640;
        flight_distance["SCE"]["EWR"] = 220;
        
    // Question 5
    // instantiate seven objects that represent aircraft in the table. Four of them are airliners, two of which are American Airline, the other two are United Airline. The remaining three are general aviation.
    
    // When instantiate objects from the “Airliner” class, use string “AA” and “UA” for American Airline and United Airline, respectively.

    //Use the set function for “vel” to set the speed of each airplane according to the table. Note: The speed in the table is in miles per hour
    // convert hours to seconds!
    
        Airliner American_1("AA", "SCE", "PHL");
        American_1.set_vel(470 * 0.00027778);

        Airliner United_1("UA", "SCE", "ORD");
        United_1.set_vel(515 * 0.00027778);

        Airliner United_2("UA", "SCE", "EWR");
        United_2.set_vel(480 * 0.00027778);

        Airliner American_2("AA", "SCE", "ORD");
        American_2.set_vel(500 * 0.00027778);

        GeneralAviation General_Aviation_1("SCE", "PHL");
        General_Aviation_1.set_vel(140 * 0.00027778);

        GeneralAviation General_Aviation_2("SCE", "EWR");
        General_Aviation_2.set_vel(160 * 0.00027778);

        GeneralAviation General_Aviation_3("SCE", "ORD");
        General_Aviation_3.set_vel(180 * 0.00027778);

    //store the vectors in aircrafts to have an more simple while (true) loop for each aircraft
    
        vector<Plane *> aircrafts;
        aircrafts.push_back(&American_1);
        aircrafts.push_back(&United_1);
        aircrafts.push_back(&United_2);
        aircrafts.push_back(&American_2);
        aircrafts.push_back(&General_Aviation_1);
        aircrafts.push_back(&General_Aviation_2);
        aircrafts.push_back(&General_Aviation_3);
    
    // Pick a timestep between [10, 100], and create a while (true) statement, then call the “operate” function member for each airplane object with timestep being an input. You may also set “loiter_time” and “wait_time” to see if the flowchart in Question 3 was implemented correctly. Print out the position of all airplanes at each timestep.

    //Question 7
    //before the while (true) statement created in Question 5, instantiate an object “atc” from the class “ATC” of Question 6. Then, register all airplane objects to this “atc” object using the “registered_planes” function
    
    // instantiate an object “atc” from the class “ATC” of Question 6
    ATC atc;
    
    //register all airplane objects to this “atc” object using the “registered_planes” function
    atc.register_plane(&American_1);
    atc.register_plane(&United_1);
    atc.register_plane(&United_2);
    atc.register_plane(&American_2);
    atc.register_plane(&General_Aviation_1);
    atc.register_plane(&General_Aviation_2);
    atc.register_plane(&General_Aviation_3);
    

    //Question 8
    // Instantiate an object named “viz” from a class “HW2_VIZ” at the beginning of the main function, and call the “visualize_plane” function of this “viz” object, with plane type, origin, destination, and position as inputs, after the “operate” and the “control_traffic” functions
    
    //Instantiate an object named “viz” from a class “HW2_VIZ” at the beginning of the main function,
    
    HW2_VIZ viz;
    
    
    // Pick a timestep between [10, 100]
        int time = 20;
        
    //create a while (true) statement
       while (true)
        {
            //for (Plane* plane : aircrafts)
            for( Plane * plane : atc.get_registered_plane() )
            {
                // then call the “operate” function member for each airplane object with timestep being an input
                plane->operate(time);

                // Question 7
                //Inside, the while (true) statement, call the “control_traffic” function right after the “operate” function of every airplane
                atc.control_traffic();
                
                // You may also set “loiter_time” and “wait_time” to see if the flowchart in Question 3 was implemented correctly
                
                // Question 6: will comment out since cout is not needed for this question
                // Print out the position of all airplanes at each timestep.
                //cout << "For Plane: " << plane->plane_type() << endl;
                //cout << "Origin: " << plane->get_origin() << " Destination: " << plane->get_destination() <<endl;
                //cout << "Position in miles: " << plane->get_pos() << endl;

                //Question 7
                //Print out the position of all airplanes at each timestep to check if the flowchart in Question 6 was implemented correctly
                //cout << "For Plane: " << plane->plane_type() << endl;
                //cout << "Origin: " << plane->get_origin() << " Destination: " << plane->get_destination() <<endl;
                //cout << "Position in miles: " << plane->get_pos() << endl;
                
                //Question 8
                //comment out all print/cout statements
                
                //call the “visualize_plane” function of this “viz” object, with plane type, origin, destination, and position as inputs, after the “operate” and the “control_traffic” functions
                viz.visualize_plane(plane->plane_type(), plane ->get_origin(), plane->get_destination(), plane->get_pos());
                
                // Also, call the “update” function of this “viz” object inside (at the end) of the while (true) statement, given the timestep from Question 5 as an input argument. Hint: Read the source code in HW2_Visualizer.cpp.
                viz.update(time);
                
            }
         }
        

    return 0;
}
