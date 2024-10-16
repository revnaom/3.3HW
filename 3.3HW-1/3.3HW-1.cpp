#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Address {
private:
    string city;
    string street;
    int house_number;
    int apartment_number;

public:
    Address(const string& city, const string& street, int house_number, int apartment_number) :
        city(city), street(street), house_number(house_number), apartment_number(apartment_number) {}

    string get_output_address() const {
        return city + ", " + street + ", " + to_string(house_number) + ", " + to_string(apartment_number);
    }
};

int main() {
    ifstream input_file("in.txt");
    ofstream output_file("out.txt");

    if (!input_file.is_open() || !output_file.is_open()) {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }

    int count_addresses;
    input_file >> count_addresses;

    vector<Address*> addresses;

    for (int i = 0; i < count_addresses; ++i) {
        string city, street;
        int house_number, apartment_number;

        input_file >> city; 
        input_file >> street; 
        input_file >> house_number;
        input_file >> apartment_number;

        Address* address = new Address(city, street, house_number, apartment_number);
        addresses.push_back(address);
    }

    output_file << count_addresses << endl;

    for (int i = count_addresses - 1; i >= 0; --i) {
        output_file << addresses[i]->get_output_address() << endl;
    }

    for (Address* address : addresses) {
        delete address;
    }

    input_file.close();
    output_file.close();

    return 0;
}
