//  hw2_functions.hpp
//  HW2Prob3
//  Created by Serin Santhosh on 11/5/23.

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
