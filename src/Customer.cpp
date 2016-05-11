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

//figures out what the calculation parameters should be
double Customer::amountFor(const Rental& rent){
    double thisAmount = 0;
    switch(rent.getVideo().getCode()) {

        case Video::REGULAR:
			thisAmount = (2, rent.getDaysRented(), 2, 1.5);
        break;

        case Video::NEW_RELEASE:
			//we can do this with a little trickery. if it's rented for more than 0 days the "overdue fee" will be multiplied by the days
			thisAmount = (0, rent.getDaysRented(), 0, 3);
        break;

        case Video::CHILDRENS:
			thisAmount = (1.5, rent.getDaysRented(), 3, 1.5)
        break;
     }
     return thisAmount;
}

//does all the calculation for the fee
double Customer::calculateFee(double baseFee, int daysRented, int daysToOver, double overdueFee){
	double feeAmount = baseFee;
	if (daysRented > daysToOver){
		feeAmount += (daysRented - daysToOver) * overdueFee;
	}
	return feeAmount;
	
}

// create strings for output_iterator
std::string Customer::createOutputString(std::string beginText, double amount, std::string endText) const{
	std::string result
	result = beginText;
    std::ostringstream out_str_stream;
    out_str_stream << amount;
    result += out_str_stream.str();
    result += endText;
	result += "\n";
	return result;
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

        
		double thisAmount = amountFor(*it);
		
        // amount of rental
        std::ostringstream out_str_stream;
        out_str_stream << thisAmount;
        result += out_str_stream.str();
        result += "\n";

        totalAmount += thisAmount;
    }

    // total amount owed
    result += createOutputString("Amount owed is: ", totalAmount, "");
	// frequent renter points earned
	result += createOutputString("You earned: ", frequentRenterPoints, " frequent renter points");

    return result;
}
