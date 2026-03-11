#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>
#include <vector>
#include <iostream>

    /**
     * @class   Vector
     * @brief   A templated Dynamic array
     * @brief   Used to create a dynamic templated array so it can utilize any data type and grow and shrink on demand.
     *
     * @author  William Halling
     * @date    May 2024
     * @version 0.4
     * @note    Updated and converted previous Dynamic Array Vector to a templated std::vector
     */
template <class T>
class Vector
{
    public:
            /**
             * @brief Vector()
             * Vector Constructor
             */
        Vector();


            /**
             * @brief Vector()
             * Parameterized constructor that contains na integer for the size
             *
             *
             * @param int numItems - size of the vector
             */
        Vector(int numItems);


            /**
             * @brief Copy Constructor
             * Creates a new vector Deep copies the elements of this vector into a new Vector
             *
             * @param newRecords const
             */
        Vector(const Vector& newRecords);


            /**
             * @brief Destructor
             * Used to delete the Vector and free up resources
             */
        ~Vector();


            /**
             * @brief Assignment operator for the vector
             * Used to perform deep copy allowing us to keep all data from pointers.
             *
             * @param  Vector  of oldRecords
             * @return const Vector<T> the vector that is assigned data
             */
        const Vector<T>& operator=(const Vector<T>& oldRecords);


            /**
             * @brief operator[]
             * Used to grant access to the vector at a given number
             *
             * @param  unsigned recordNumber
             * @return T& the value stored at the index[]
             */
        T& operator[](unsigned recordNumber);


            /**
             * @brief const operator[]
             * Used to grant access to the vector at a given number
             *
             * @param  unsigned recordNumber
             * @return const T&
             */
        const T& operator[](unsigned recordNumber) const;


            /**
             * @brief size
             * Used to get the size of the vector
             *
             * @return the size of the vector as an int
             */
        int size() const;


            /**
             * @brief  push_back
             * @brief  used to push an item onto the vector
             *
             * @param  const T newRecord
             */
        void push_back(const T& newRecord);


            /**
             * @brief clear()
             * Used to clear the the vector of its data
             */
        void clear();

            /**
             * @brief resize()
             * @param bewsize the new size of the vector
             * Used to resize the the vector
             */
        void resize(int newSize);

    private:

        std::vector<T> m_Records; ///m_Records an instance of a std::vector accepting of any type
};


template <class T>
Vector<T>::Vector() {}



template<class T>
Vector<T>::Vector(int numItems) : m_Records(numItems)
{}


template <class T>
Vector<T>::Vector(const Vector<T>& newData) : m_Records(newData.m_Records)
{}


template<class T>
Vector<T>::~Vector(){}



template<class T>
void Vector<T>::resize(int newSize)
{
    m_Records.resize(newSize);
}


template<class T>
const Vector<T>& Vector<T>::operator=(const Vector<T>& oldRecords)
{
    if (this != &oldRecords)
    {
        m_Records = oldRecords.m_Records;
    }
    return *this;
}


template<class T>
T& Vector<T>::operator[](unsigned itemNumber)
{
    if(itemNumber < 0 || itemNumber >= m_Records.size())
    {
        std::cout << "Value is out of range";
    }
    return m_Records[itemNumber];
}


template<class T>
const T& Vector<T>::operator[](unsigned itemNumber) const
{
    if(itemNumber < 0 || itemNumber >= m_Records.size())
    {
        std::cout << "Value is out of range";
    }

    return m_Records[itemNumber];
}


template<class T>
int Vector<T>::size() const
{
    return m_Records.size();
}


template<class T>
void Vector<T>::push_back(const T& newRecord)
{
    m_Records.push_back(newRecord);
}


template<class T>
void Vector<T>::clear()
{
    m_Records.clear();
}

#endif // VECTOR_H
