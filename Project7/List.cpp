//===================================================
// Ethan Tecson
// 2023 April 5
// List.cpp
// This file contains the implementation for the
// Class List
//===================================================

#include "List.h"
#include <iomanip>
#include <math.h>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;

/*******************Constructors********************/

//===================================================
// Constructor
// PARAMETERS: none
// RETURN VALUE: Instance of List<T> Class
//===================================================

template <class T>
List<T>::List(void)
{
    capacity = DEFAULT_LIST_CAPACITY; // Set capacity to DEFAULT_LIST_CAPACITY (10)
    list = new T[capacity];           // Create dynamically allocated array with set capacity
    size = 0;                         // Set size = 0 since there are no items
}

//===================================================
// Deep Copy Constructor
// PARAMETERS: Instance of List<T> Class
// RETURN VALUE: Returns instance of List<T> Class that
// has same values as instance taken as the argument
//===================================================

template <class T>
List<T>::List(const List<T> &mylist)
{
    capacity = mylist.capacity; // Set capacity = to argument instance capacity
    size = mylist.size;         // Set size = to argument instance size

    list = new T[capacity]; // Create new dynamically allocated array with capacity size of instance argument

    for (int i = 0; i < size; i++) // For loop to copy values from instance argument
    {
        list[i] = mylist.list[i];
    }
}

//===================================================
// Deconstructor
// PARAMETERS: none
// RETURN VALUE: Deletes dynamically allocated data
//===================================================

template <class T>
List<T>::~List(void)
{
    delete[] list;
}

/*******************Methods*******************/

//===================================================
// to_string
// PARAMETERS: none
// RETURN VALUE: dynamcially allocated array values in string variable
//===================================================

template <class T>
string List<T>::to_string(void) const
{

    stringstream result; // Create stringstream vairable to store values in

    for (int i = 0; i < size; i++)
    {
        result << list[i] << " "; // For loop to put dynamically allocated array values into string variable, result
    }

    return result.str(); // Return result as string
}

//===================================================
// append
// PARAMETERS: item wanting to be appended to dynamically allocated array
// RETURN VALUE: none
//===================================================

template <class T>
void List<T>::append(const T &item)
{
    if (size == capacity) // If size of array = capacity of array, we double the capacity
    {
        capacity *= 2;
    }

    T *new_list = new T[capacity]; // Create new dynamcially allocated array

    for (int i = 0; i < size; i++) // For loop that stores list private member values into new array
    {
        new_list[i] = list[i];
    }

    delete[] list;   // Delete list member
    list = new_list; // Set new list member = to new_list

    list[size] = item; // Add item to end of array
    size++;            // Increase number of items in list by 1
}

//===================================================
// insert
// PARAMETERS: item wanting to be inputed and index
// that item will be inputed to
// RETURN VALUE: none
//===================================================

template <class T>
void List<T>::insert(const T &item, int index)
{
    if (index >= capacity) // If index we are trying to put item into is greater than capacity, double capacity size
    {
        capacity *= 2;
    }

    T *new_list = new T[capacity]; // Create new dynamically allocated array

    for (int i = 0; i < size; i++) // For loop that stores list private member values into new array
    {
        new_list[i] = list[i];
    }

    delete[] list;   // Delete list member
    list = new_list; // Set new list member = to new_list

    for (int i = size; i > index; i--) // Shift all values down so there's room for new indexed value
    {
        list[i] = list[i - 1];
    }

    list[index] = item; // Put item in index
    size++;             // Incrase numbers of items in list by 1
}

//===================================================
// remove
// PARAMETERS: index wanting to be removed
// RETURN VALUE:
//===================================================

template <class T>
void List<T>::remove(int index)
{
    if (index > 0 || index <= size) // If index is in range, reduce size and shift values in array
    {
        for (int i = index; i < size - 1; i++)
        {
            list[i] = list[i + 1];
        }

        size--;
    }
    else // If index is out of range, throw
    {
        throw("Index out of range");
    }
}

//===================================================
// length
// PARAMETERS: none
// RETURN VALUE: returns size (which is the length) of the array
//===================================================

template <class T>
int List<T>::length(void) const
{
    return size;
}

//===================================================
// isEmpty
// PARAMETERS: none
// RETURN VALUE: Returns flase if array is not empty, returns true otherwise
//===================================================

template <class T>
bool List<T>::isEmpty(void) const
{
    if (size > 0)
        return false;
    else
        return true;
}

//===================================================
// clear
// PARAMETERS: none
// RETURN VALUE: none
//===================================================

template <class T>
void List<T>::clear(void)
{
    size = 0; // sets number of items in array = 0 thus clearing the array
}

/*******************Operator Overloads********************/

//===================================================
// operator overload []
// PARAMETERS: index
// RETURN VALUE: returns index of array
//===================================================

template <class T>
T &List<T>::operator[](int index)
{

    if (index > 0 || index <= size)
    {
        return list[index]; // If index is in range, return index of array
    }
    else
    {
        throw("Index out of range"); // If index is out of range, throw
    }
}

//===================================================
// operator overlaod =
// PARAMETERS: Dynamcially allocated array instance
// RETURN VALUE: returns manipulated object
//===================================================

template <class T>
List<T> List<T>::operator=(const List<T> &mylist)
{

    size = mylist.size;         // Set size = argument list size
    capacity = mylist.capacity; // Set capacityt = argument list capacity

    delete[] list; // Delete original list

    list = new T[capacity]; // Set new list with capacity of argument list

    for (int i = 0; i < size; i++) // Add argument list values into new list
    {
        list[i] = mylist.list[i];
    }

    return *this; // Reutrn new list object
}

//===================================================
// operator overload +
// PARAMETERS: Dynamcially allocated array instance
// RETURN VALUE: returns new_array which is the two arrays concatanated
//===================================================

template <class T>
List<T> List<T>::operator+(const List<T> &mylist) const
{
    int new_size = size + mylist.size;             // Set new size = size of original list + argument list size
    int new_capacity = capacity + mylist.capacity; // Set new capacity = capacity of original list + argument list capacity

    if (new_size > new_capacity) // If new_size is greater than the new capacity, double the capacity
    {
        new_capacity *= 2;
    }

    List new_list; // Create new instance, new_list, with constructor

    new_list.size = new_size;         // Set new_list size = to new_size
    new_list.capacity = new_capacity; // Set new_list capacity = to new_capacity

    for (int i = 0; i < size; i++) // Add original list values to new list
    {
        new_list[i] = list[i];
    }

    for (int i = 0; i < mylist.size; i++) // Add argument list values into new_list
    {
        new_list[size + i] = mylist.list[i];
    }

    return new_list; // Return variable that holds the concatanated list
}