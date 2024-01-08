#include "defination_of_3.cpp"//user defined header file included
#include <iostream>
using namespace std;



int main() {
    Tour* tours; // Pointer to store tour data
    string filename = "tour_data3.txt";
    int tourCount=0;
    
    tours = new Tour[MAX_TOURS];//dynamic memory allocation

    // Load tour data from the file at the beginning
    loadFromFile(tours, tourCount, filename);//file name to store data of structure

    while (true) {
        menu(tours, tourCount, filename);//menu function call
        cout << "=============================================";
    }

    // Deallocate memory for the array of tours
    delete[] tours;

    return 0;
}