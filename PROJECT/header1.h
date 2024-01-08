#pragma once//header guard helps to prevent header files from being included multiple times.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_TOURS = 10; // Maximum number of tours

struct Tour {//struct made for Tours
    string name;
    string location;
    string mode;
    int days;
};
//function prototype decleration
void saveToFile(Tour* tours, int& tourCount, const string filename);
void loadFromFile(Tour* tours, int& tourCount, const string filename);
void add_tour(Tour* tours, int& tourCount, const string filename);
void view_tours(Tour* tours, int& tourCount);
void find_Tour(Tour* tours, int& tourCount);
void delete_tour(Tour* tours, int& tourCount, const string filename);
void replace_tour(Tour* tours, int& tourCount, const string filename);
void menu(Tour* tours, int& tourCount, const string filename);
