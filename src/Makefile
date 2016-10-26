#############################################################################
# VideoStore
#

OBJS=VideoStore.o Video.o Rental.o Customer.o
TOBJS=Video_t.o Rental_t.o Customer_t.o
EXE=VideoStore Video_t Rental_t Customer_t

GCC= g++
CFLAGS=-Wall

.PHONY : all
all : $(EXE) test

# VideoStore
.PHONY : run
run : VideoStore
	@./VideoStore

VideoStore : $(OBJS)
	$(GCC) $^ -o $@

VideoStore.o: NetVideo.cpp Video.hpp Rental.hpp Customer.hpp
	$(GCC) $(CFLAGS) -c $<

# Video
Video.o: Video.cpp Video.hpp
	$(GCC) $(CFLAGS) -c $<

Video_t : Video_t.o Video.o
	$(GCC) $^ -o $@

Video_t.o: Video_t.cpp Video.hpp
	$(GCC) $(CFLAGS) -c $<

# Rental
Rental.o: Rental.cpp Rental.hpp Video.hpp
	$(GCC) $(CFLAGS) -c $<

Rental_t : Rental_t.o Rental.o Video.o
	$(GCC) $^ -o $@

Rental_t.o: Rental_t.cpp Rental.hpp
	$(GCC) $(CFLAGS) -c $<

# Customer
Customer.o: Customer.cpp Customer.hpp Video.hpp Rental.hpp
	$(GCC) $(CFLAGS) -c $<

Customer_t : Customer_t.o Customer.o Rental.o Video.o
	$(GCC) $^ -o $@

Customer_t.o: Customer_t.cpp Customer.hpp
	$(GCC) $(CFLAGS) -c $<

# clean
.PHONY : clean
clean : cleanobjects
	rm -f $(EXE)

.PHONY : cleanobjects
cleanobjects :
	rm -f $(OBJS) $(TOBJS)

# unit testing
.PHONY : test
test : Video_t Rental_t Customer_t
	@./Video_t
	@./Rental_t
	@./Customer_t
