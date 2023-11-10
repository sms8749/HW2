// P2.cpp
//  HWProb2
//  Created by Serin Santhosh on 10/21/23.
//
//create class named "Plane" with specific classes

#include <iostream>
#include <string>
#include <map>
#include <random>
#include "hw2_functions.h"

using namespace std;

Plane::Plane(const string& from, const string& to)
    {
        //Question 1:
        flight_distance["SCE"]["PHL"] = 160;
        flight_distance["SCE"]["ORD"] = 640;
        flight_distance["SCE"]["EWR"] = 220;
    }

    //virtual deconstructor left empty
    Plane::~Plane() 
    {
        // empty
    }

    //A function named “operate” with a double variables “dt” as an input, and return nothing
    void Plane::operate(double dt)
    {
        //returns nothing
    }

    //get function for “pos” variable
    double Plane::get_pos() const
    {
        //must return a value to run
        return 0;
    }

    //get functions for “vel” variable
    double Plane::get_vel() const
    {
        //must return a value to run
        return 0;
    }

    //get functions for “loiter_time” variable
    double Plane::get_loiter_time() const
    {
        //must return a value to run
        return 0;
    }

    //get function for “origin” variable
    string Plane::get_origin() const
    {
        //must return a string to run
        return 0;
    }

    //get function for “destination” variable
    string Plane::get_destination() const
    {
        //must return a string to run
        return 0;
    }

    //get function for “at_SCE” variable
    bool Plane::get_at_SCE() const
    {
        //must return 0 or 1 to run
        return 0;
    }

    //set functions for “vel” variable
    void Plane::set_vel(double vel2)
    {
        //void will not return anything
    }

    //set functions for “loiter_time” variable
    void Plane::set_loiter_time(double loiter_time2)
    {
        //void will not return anything
    }

    //A function named “distance_to_SCE” that returns double
    double Plane::distance_to_SCE()
    {
        //must return a value to run
            return 0;
    }

    //A virtual function named “time_on_ground”
    double Plane::time_on_ground()
    {
        //must return a value to run
        return 0;
    }

    //A virtual function named “plane_type” that returns string
    string Plane::plane_type()
    {
        //must return a string to run
        return 0;
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

int main()
{
    // use a modified way to store the distnaces into the container from question...
    // the way i did it origianlly didnt work so i had to adjust it to use in oop method
    //Question 1
    map<string, map<string, int>> flight_distance;
        flight_distance["SCE"]["PHL"] = 160;
        flight_distance["SCE"]["ORD"] = 640;
        flight_distance["SCE"]["EWR"] = 220;
    return 0;
}
