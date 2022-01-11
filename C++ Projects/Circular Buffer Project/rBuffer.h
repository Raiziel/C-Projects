/*
    Name: Nicholas Munoz, 2000781568, 1004, ASSIGNMENT_7
    Description: Program creates circular buffer
    Input: pointer size
    Output: Pointer Values
*/
#ifndef RBUFFER_H
#define RBUFFER_H
#include <iostream>

template <class T>
class rBuffer {
    T* buffer_p;
    T* read_p;
    T* write_p;
    int size;
    bool full;
    bool empty;
public:
    rBuffer(int = 8);
    rBuffer(const rBuffer<T>&);
    ~rBuffer();
    T read();
    void write(T);
    bool resize(int);
    void clear();
    void print() const;
    template <class A, class B>
    friend rBuffer<A> joinBuffers(const rBuffer<A>&, const rBuffer<B>&);
};


// DO NOT CHANGE THE PRINT FUNCTION.
template <class T>
void rBuffer<T>::print() const 
{
    std::cout << " | ";
    for (int i = 0; i < size; i++) {
        if (buffer_p + i == read_p)
            std::cout << "*";
        if (buffer_p + i == write_p)
            std::cout << "+";
        std::cout << buffer_p[i] << " | ";
    }
    std::cout << "\n";
}
template <class T>
rBuffer<T>:: rBuffer(int newSize)
{   
    if (newSize < 1)
    {   // default size
        size = 8;
    }
    else
    {   // passed size
        size = newSize;
    }

        empty = true;
        full = false;
        buffer_p = new T[size];
        for (int i = 0; i < size; i++)
        {
            buffer_p[i] = 0;
        }
        read_p = buffer_p;
        write_p = buffer_p;




    

}
template <class T>
rBuffer<T>::rBuffer(const rBuffer<T> & rhs)
{
    size = rhs.size;
    empty = rhs.empty;
    full = rhs.full;
    write_p = rhs.write_p;
    read_p = rhs.read_p;

    buffer_p = new T[size];
    for (int i = 0; i < size; i++)
    {
        buffer_p[i] = rhs.buffer_p[i];
    }
   
}
template <class T>
// destructor
// resets everything
rBuffer<T> :: ~rBuffer()
{
    if (buffer_p != nullptr)
    {
        delete[] buffer_p;//reset
        size = 0;//reset
        empty = true;//reset
        full = false;//reset
        buffer_p = nullptr;//reset
        write_p = nullptr;//reset
        read_p = nullptr; //reset

    }
  
}
// function that writes the buffer
template <class T>
void rBuffer<T>::write(T item)
{
    if(buffer_p==nullptr)
    {
        return; // return nothing
    }

    *write_p = item;
    empty = false; // empty to false
    
    if(write_p==(buffer_p+(size-1)))
    {
        full = true;
        write_p = buffer_p;
    }
    else
    {   // increment write_p
        write_p++;
    }

}
template <class T>
// this function will resize the buffer
// to the passed value
bool rBuffer<T>::resize(int rez)
{
    int readDist, writeDist;
    T* temp = nullptr; // allocate T 

    if (rez < 1)

    { // return false if rez<1
        return false;
    }

    if (rez == size)

    {   // return true
        return true;
    }

    if (rez < size && full== true)

    {   // return false
        return false;
    }

    // set writeDist between write_P and buffer_P
    writeDist = write_p - buffer_p;
    // set readDist between read_P and buffer_P
    readDist = read_p - buffer_p;

    if (rez < writeDist)

    {
        return false; // returns false if rez<writeDist
    }

    temp = new T[rez];
    for (int i = 0; i < rez; i++)
    {   // set all index of temp to 0
        temp[i] = 0;
    }



    // copy every index before write_p
    //(check this)

    if (rez < size && full == false)
    {   
        for (int i = 0;i<writeDist; i++)
        {   
            temp[i] = buffer_p[i];
        }
        delete[] buffer_p;
        buffer_p = temp;
        read_p = buffer_p + readDist;
        if (writeDist == rez)
        {
            write_p = buffer_p + writeDist - 1;
        }
        else
        {
            write_p = buffer_p + writeDist;
        }
        size = rez; // new size
    }

    if (rez > size)
    {
        for (int i = 0; i < size; i++)
        {   // set temp to all buffer index
            temp[i] = buffer_p[i];
        }
        delete[] buffer_p;
        buffer_p = temp;
        if (writeDist == size - 1)
        {
            write_p = buffer_p + writeDist + 1;
        }
        else
        {
            write_p = buffer_p + writeDist;
        }
        read_p = buffer_p + readDist;
        size = rez; // new size
        full = false; // full to false
    }
    return true;
}
template <class T>
void rBuffer<T>::clear()
{
    
    T* temp; // initialize T
    temp = new T[size]; // allocate T
    for (int i = 0; i < size; i++)
    {   // set all index to 0
        temp[i] = 0;
    }
    // reset everything
    delete[]buffer_p;
    full = false;
    empty = true;
    buffer_p = temp;// sets to temp
    read_p = temp; // sets to temp
    write_p = temp; // sets to temp



}
template <class T>
T rBuffer<T> :: read()
{
   

    if (empty == true) 
    {
        throw "Cannot read from empty buffer!"; // throw back error message
    }
    
    if (read_p == write_p && read_p==buffer_p) // conditional
    {   // return last index
        return *(buffer_p+(size-1);
    }
    if (read_p == write_p) // conditional
    {   // return
        return *(read_p - 1); 
    }

    T temp = *(read_p); // point to read_p

    if(read_p==buffer+size-1) // conditional
    {   // return
        read_p = (buffer_p+0); 
    }
    else {
        read_p++;}  // increment read_p++
    return temp;

}
// this function joins two buffer that may or may note be full 
// if A isn't full then the buffer will write before write_p
// and then once it has written A buffer
// it will write 
// the B buffer
template<class A, class B>
rBuffer<A> joinBuffers(const rBuffer<A>& buffA, const rBuffer<B>& buffB)
{
    int rez = buffA.size + buffB.size;
    rBuffer<A>temp(rez);
    if (buffA.empty == false)// check if buffB is empty
    {

        if (buffA.full==true) // check if full

        {
            for (int i = 0; i < buffA.size; i++)// loop through buffer 
            {
                temp.write(buffA.buffer_p[i]);// write to temp
            }
        }
        else

        {
            int AwriteDist = buffA.write_p - buffA.buffer_p;// set write dist
            for (int i = 0; i <AwriteDist; i++)// loop before write_p
            {
                temp.write(buffA.buffer_p[i]);// write to temp
            }

        }

        if (buffB.empty == false)// check if buffB is empty
        {

            if (buffB.full == true) // check if full
            {
                for (int i = 0; i < buffB.size; i++) // loop through buffer 
                {
                    temp.write(buffB.buffer_p[i]); // write to temp
                }
            }
            else

            {
                int BwriteDist = buffB.write_p - buffB.buffer_p; 
                // set write dist
                for (int i = 0; i < BwriteDist; i++) // loop before write_p
                {
                    temp.write(buffB.buffer_p[i]); // write to temp
                }
            }

        }

       

    }
    return temp; // return temp
}


#endif