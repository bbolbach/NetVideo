/*
  Customer.cpp

  Definition file for Customer class
*/

#include "Customer.hpp"
#include "Video.hpp"

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// constructor
Customer::Customer(const std::string& name)
    : name(name)
{ }

// customer name
std::string Customer::getName() const {

    return name;
}

// add a rental to this customer
void Customer::addRental(const Rental& rental) {

    rentals.push_back(rental);
}

//calculates the amount of the rental
double Customer::amountFor(const Rental& rent){
	double thisAmount = 0;
    switch(rent.getVideo().getCode()) {

        case Video::REGULAR:
            thisAmount += 2;
            if (rent.getDaysRented() > 2)
                thisAmount += (rent.getDaysRented() - 2) * 1.5;
        break;

        case Video::NEW_RELEASE:
            thisAmount += rent.getDaysRented() * 3;
        break;

        case Video::CHILDRENS:
            thisAmount += 1.5;
            if (rent.getDaysRented() > 3)
                thisAmount += (rent.getDaysRented() - 3) * 1.5;
        break;
        }
	return 0;
}

// customer rental statement
std::string Customer::statement() const {

    // customer name
    std::string result("Rental Record for ");
    result += getName();
    result += "\n";

    // rentals
    double totalAmount = 0;
    int frequentRenterPoints = 0;
    for (std::vector<Rental>::const_iterator it = rentals.begin(); it != rentals.end(); ++it) {

        // every rental is a rental point
        ++frequentRenterPoints;

        // new releases rented for more then one day gives a bonus rental point
        if (it->getVideo().getCode() == Video::NEW_RELEASE &&
            it->getDaysRented() > 1 )
            ++frequentRenterPoints;

        // title of rental
        result += "\t";
        result += it->getVideo().getTitle();
        result += "\t";

        

        // amount of rental
        std::ostringstream out_str_stream;
        out_str_stream << thisAmount;
        result += out_str_stream.str();
        result += "\n";

        totalAmount += thisAmount;
    }

    // total amount owed
    result += "Amount owed is: ";
    std::ostringstream out_str_stream;
    out_str_stream << totalAmount;
    result += out_str_stream.str();
    result += "\n";

    // frequent renter points earned
    result += "You earned: ";
    std::ostringstream out_str_stream2;
    out_str_stream2 << frequentRenterPoints;
    result += out_str_stream2.str();
    result += " frequent renter points\n";

    return result;
}
