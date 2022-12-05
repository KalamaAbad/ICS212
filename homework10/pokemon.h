/*****************************************************************
//
//  NAME:        Kalama Abad
//
//  HOMEWORK:    Homework 10
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        December 4, 2022
//
//  FILE:        pokemon.h
//
//  DESCRIPTION:
//   This header file contains functions and variables for a pokemon.
//
****************************************************************/

#include <string>
#include <iostream>

class Pokemon
{
    public:
        Pokemon();
        virtual ~Pokemon();
        virtual void printData();

    protected:
        std::string type;
        float weight;
};