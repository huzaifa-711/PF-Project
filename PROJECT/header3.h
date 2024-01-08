#pragma once//header guard helps to prevent header files from being included multiple times.

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const int MAX_TOURS = 20; // Maximum number of tours

struct Tour {//struct made for Tours
    string name;
    string destination;
    string day;
    string time;
};



// Function prototypes
void menu(Tour* tours, int& tourCount, string filename);
void loadFromFile(Tour* tours, int& tourCount, string filename);
void file_merge(Tour* tours, int& tourCount, ifstream& nameFile, ifstream& destinationFile);
void saveToFile(Tour* tours, int& tourCount, string filename);
void add_tour(Tour* tours, int& tourCount, string filename);
void view_tours(Tour* tours, int& tourCount);
void find_tour(Tour* tours, int& tourCount);
void replace_tour(Tour* tours, int& tourCount, string filename);
void delete_tour(Tour* tours, int& tourCount, string filename);

