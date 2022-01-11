/*
    Sample main.cpp for Assignment 7.
    Feel free to modify and use to test your program.
*/

#include <iostream>
#include "rBuffer.h"

int main() {
    rBuffer<int> a(2);          // Initialize an integer buffer.
    rBuffer<double> b(4);       // Initialize a double buffer.

    // This code will test if the read function throws an exception
    // if the buffer is empty.
    try {
        a.read();
    } catch (const char* e) {
        std::cout << "EXCEPTION: " << e << "\n";
    }

    // Write a bunch of data to the buffer and print it to see changes.
    a.write(12);
    a.print();
    a.write(11);
    a.print();
    a.write(14);
    a.print();

    // Test the resize function.
    if (a.resize(6)) std::cout << "Resize successful\n";
    else std::cout << "Resize failed\n";
    a.print();
    if (a.resize(5)) std::cout << "Resize successful\n";
    else std::cout << "Resize failed\n";

    // Call read a bunch of times to check if read pointer is working.
    // This will also call print to check pointer location after each call.
    std::cout << "Read: " << a.read() << "\n";
    a.print();
    std::cout << "Read: " << a.read() << "\n";
    a.print();
    std::cout << "Read: " << a.read() << "\n";
    a.print();

    // Write another piece of data and test read again.
    a.write(5);
    a.print();
    std::cout << "Read: " << a.read() << "\n";
    a.print();

    // Write more data to fill the buffer and test looping.
    a.write(2);
    a.print();
    a.write(9);
    a.print();

    // Test if read loops correctly.
    std::cout << "Read: " << a.read() << "\n";
    a.print();
    std::cout << "Read: " << a.read() << "\n";
    a.print();
    std::cout << "Read: " << a.read() << "\n";
    a.print();

    // Test resizing for a full buffer
    if (a.resize(3)) std::cout << "Resize successful\n";
    else std::cout << "Resize failed\n";
    a.print();

    // Writing more data!
    a.write(15);
    a.print();

    // Write some data to buffer b.
    b.write(2.5);
    b.write(1.1);
    b.print();

    // Test the join function
    rBuffer<double> c = joinBuffers(b, a);
    std::cout << "Join successful\n";
    c.print();

    // Test the clear function
    a.clear();
    a.print();
    // This will check if the empty flag was cleared by the clear function.
    try {
        a.read();
    } catch (const char* e) {
        std::cout << "EXCEPTION: " << e << "\n";
    }
}