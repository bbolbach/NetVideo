/*
  Customer.hpp

  Include file for Customer class
*/

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Rental.hpp"

#include <string>
#include <vector>

class Customer {
public:

    // constructor
    Customer(const std::string& name);

    // customer name
    std::string getName() const;

    // add a new rental
    void addRental(const Rental& rental);

    // customer rental statement
    std::string statement() const;
	
	//creats output string
	std::string createOutputString(std::string beginText, double amount, std::string endText) const;
	
	double calculateFee(double baseFee, int daysRented, int daysToOver, double overdueFee);
	
	double forAmount() const;

private:
    std::string name;
    std::vector<Rental> rentals;
};

#endif
