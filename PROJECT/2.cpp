#include <iostream>
#include "defination_of_h2.cpp"//user defined header file included

using namespace std;

int main() {
    // Allocate memory for the array of tours
    Tour* tours;//poiter made for Tour datatype
    int tourCount = 0;
    tours = new Tour[MAX_TOURS];//dynamic memory allocation
    string filename = "tours_data2.txt";//file name to store data of structure

    // Load tour data from the file at the beginning
    loadFromFile(tours, tourCount, filename);

    while (true) {
        menu(tours, tourCount,filename);//menu function call
        cout << "=============================================";
    }

    // Deallocate memory for the array of tours
    delete[] tours;

    return 0;
}
