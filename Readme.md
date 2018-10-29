
# Integer data storage and median calculator

A data structure for storing integers with the ability to calculate the median value of the sequence.

## Dependencies

The project depends on the CPPUnit library for unit testing. The project has been developed and tested on Ubuntu linux on which the needed dependency package is called libcppunit-dev. That packages should be installed before running the cmake step described below.

## Install

* Clone the project.
* Create a directory inside the project, for example called 'debug'.
* While inside 'debug' do 'cmake ..' to generate a Makefile.
* Build the project binary along with the unit tests with the command 'make'

## Usage

One can run the program ./median to enter integers one by one. After each input, the current median value of the sequence will be outputed.

## Unit tests

You can execute the unit test by running ./UnitTests

## Development design

A set data structure was chosen for the storage of the integers. It provides an insert complexity of O(log(n)) due to its internal implementation as a balanced binary search tree. An iterator is kept to the current median which allows for a O(1) complexity of the getMedian() operation.

