#pragma once

#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
#include <stdexcept>

using namespace std;
static int instanceoff =0;
namespace ariel
{

    class MagicalContainer
    {
    private:
        std::vector<int> numbers;
    
        
    public:
        bool isPrime(int); // check for the primes
        void addElement(int); //add element to the vector
        void removeElement(int); // remove element from the vector
        std::vector<int> getElement(); // get the pointer of the vector
        int size(); //get the size of the vector
        void printContainer();
        MagicalContainer();
        

        class AscendingIterator
        {
        private:
            MagicalContainer *container;
            int index;

        public:
            AscendingIterator(MagicalContainer *, int);
            AscendingIterator(MagicalContainer &); // the adress of the container 
            AscendingIterator(); //deafoult
            AscendingIterator(AscendingIterator&&) noexcept;
            AscendingIterator(const AscendingIterator& ); 
            ~AscendingIterator(){};
            
            AscendingIterator& operator=(AscendingIterator&&) noexcept;
            AscendingIterator begin();
            AscendingIterator end();

            AscendingIterator &operator++();
            AscendingIterator &operator=(const AscendingIterator &);
            bool operator==(const AscendingIterator &) const;
            bool operator!=(const AscendingIterator &) const;
            bool operator>(const AscendingIterator &) const;
            bool operator<(const AscendingIterator &) const;


            int operator*() const; //get the val of the container
            void helperAscendingIterator(MagicalContainer *);
        };

        class SideCrossIterator
        {
        private:
            MagicalContainer *container;
            int index;
            int direct;
            

        public:
            SideCrossIterator();
            SideCrossIterator(MagicalContainer *, int, int);
            SideCrossIterator(MagicalContainer &);
            SideCrossIterator(const SideCrossIterator& ); 
            SideCrossIterator(SideCrossIterator&&) noexcept;
            ~SideCrossIterator(){};

            SideCrossIterator begin();
            SideCrossIterator end();

            SideCrossIterator &operator++();
            SideCrossIterator &operator=(const SideCrossIterator &other);
            bool operator==(const SideCrossIterator &) const;
            bool operator!=(const SideCrossIterator &) const;
            bool operator>(const SideCrossIterator &) const;
            bool operator<(const SideCrossIterator &) const;
            void helperSideCrossIterator(MagicalContainer *);
            MagicalContainer getContainer();
            int operator*() const;

            
            SideCrossIterator& operator=(SideCrossIterator&&) noexcept;
        };

        class PrimeIterator
        {
        private:
            int index;
            int newindex;
            MagicalContainer *container;
            std::vector<int> numbersPrime; // new vector for the primes numbers

        public:
            PrimeIterator();
            PrimeIterator(MagicalContainer* , int ,int,std::vector<int>);
            PrimeIterator(MagicalContainer& );
            PrimeIterator(const PrimeIterator& ); 
            PrimeIterator(PrimeIterator&& ) noexcept; 
            ~PrimeIterator(){};

            PrimeIterator begin();
            PrimeIterator end();

            PrimeIterator &operator++();
            PrimeIterator &operator=(const PrimeIterator &);
            bool operator==(const PrimeIterator &) const;
            bool operator!=(const PrimeIterator &) const;
            bool operator>(const PrimeIterator &) const;
            bool operator<(const PrimeIterator &) const;
            int operator*() const;
            void helperPrimeIterator(MagicalContainer *);
            int sizeprimes();
            void myprint();
            
            PrimeIterator& operator=(PrimeIterator&&) noexcept;
            
            

        };
    };

}
