//
//  hw2_functions.h
//  HW2Prob5
//
//  Created by Serin Santhosh on 11/5/23.
//
#pragma once

#include <iostream>
#include <string>
#include <map>
#include <random>
using namespace std;

class Plane
{
    //protected members:
protected:
    //double variable named "wait_time"
    double wait_time;

    //private members:
private:
    //Double variables named “pos”, “vel”, “distance”, and “loiter_time”
    double pos, vel, distance, loiter_time;
    
    //A boolean variable named “at_SCE”
    bool at_SCE;
    
    //String variables named “origin” and “destination”
    string origin, destination;
    
    //A container from Question 1
    map<string, map<string, int>> flight_distance;

    //Public members
public:
    //A constructor that takes in two strings “from” and “to” as input arguments
    Plane(const string& from, const string& to);

    //A virtual deconstructor
    virtual ~Plane();

    //A function named “operate” with a double variables “dt” as an input, and return nothing
    void operate(double dt);

    
    //get function for “pos” variable
    double get_pos() const;

    //get functions for “vel” variable
    double get_vel() const;

    //get functions for “loiter_time” variable
    double get_loiter_time() const;

    //get function for “origin” variable
    string get_origin() const;

    //get function for “destination” variable
    string get_destination() const;

    //get function for “at_SCE” variable
    bool get_at_SCE() const;

    //set functions for “vel” variable
    void set_vel(double vel2);

    //set functions for “loiter_time” variable
    void set_loiter_time(double loiter_time2);

    //A function named “distance_to_SCE” that returns double
    double distance_to_SCE();

    //A virtual function named “time_on_ground”
    virtual double time_on_ground();

    //A virtual function named “plane_type” that returns string
    virtual string plane_type();

    //A static function named “draw_from_normal_dist” that takes in two double variables (mean and standard deviation), and returns back a random number from a normal distribution.
    static double draw_from_normal_dist(double mean, double std_dev);

};

// Question 4:

// Create two classes named “Airliner” and “GeneralAviation”, in which both are derived/inherited from the class “Plane”
class Airliner: public Plane
{
    // private members
private:
    // string variable named “Airline”
    string Airline;
    
    //public members
public:
    // A constructor that takes in three strings “Airline”, “from” and “to” as input arguments. It stores the input string “Airline” in “Airline” variable, and passes the inputs “from” and “to” to a constructor of a class “Plane”
    // didnt work when using airline, so changed to airliner
    // Question 5: added const so variables were stored correctly
    Airliner (const string &Airline, const string&from, const string& to);
    
    // An empty deconstructor
    virtual ~Airliner();
    
    // An overridden function “plane_type” that returns “Airline”
    //use string since plane types are names!
    virtual string plane_type() override;
    
    //An overridden function “time_on_ground” that returns “wait_time”, which is drawn from the “draw_from_normal_dist” function using a mean and a standard deviation of 1800 and 600, respectively
    //use double for time_on_ground since numbers!
    virtual double time_on_ground() override;
};

// other class “GeneralAviation” has the following members and implementations
class GeneralAviation: public Plane
{
    //public members
public:
    //A constructor that takes in two strings “from” and “to” as input arguments passes these inputs “from” and “to” to a constructor of a class “Plane”
    // Question 5: added const so variables were stored correctly 
    GeneralAviation(const string& from, const string& to);
    
    // An empty deconstructor
    ~GeneralAviation();
    
    // An overridden function “time_on_ground” that returns “wait_time”, which is drawn from the “draw_from_normal_dist” function using a mean and a standard deviation of 600 and 60, respectively
    //use double since time_on_ground will use numbers!
    virtual double time_on_ground() override;
};
