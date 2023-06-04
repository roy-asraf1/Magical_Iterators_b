#pragma one

#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
#include <stdexcept>

using namespace std;
namespace ariel
{

    class MagicalContainer
    {
    private:
        std::vector<int> numbers;
        

    public:
        bool isPrime(int);
        void addElement(int);
        void removeElement(int);
        std::vector<int> getElement();
        std::vector<int> getnumbersPrime();
        int size();
        void printContainer();

        class AscendingIterator
        {
        private:
            MagicalContainer *container;
            int index;

        public:
            AscendingIterator(MagicalContainer *, int);
            AscendingIterator(MagicalContainer &);
            AscendingIterator();
            ~AscendingIterator(){};
            AscendingIterator begin();
            AscendingIterator end();

            AscendingIterator &operator++();
            AscendingIterator &operator=(const AscendingIterator &);
            bool operator==(const AscendingIterator &) const;
            bool operator!=(const AscendingIterator &) const;
            bool operator>(const AscendingIterator &) const;
            bool operator<(const AscendingIterator &) const;
            AscendingIterator &operator<<(int);
            AscendingIterator &operator>>(int);

            int operator*() const;
            void sortAscendingIterator(MagicalContainer *);
        };

        class SideCrossIterator
        {
        private:
            MagicalContainer *container;
            int index;
            int direct;
            std::vector<int> sidecros;

        public:
            SideCrossIterator();
            SideCrossIterator(MagicalContainer *, int, int);
            SideCrossIterator(MagicalContainer &);
            ~SideCrossIterator(){};

            SideCrossIterator begin();
            SideCrossIterator end();

            SideCrossIterator &operator++();
            SideCrossIterator &operator=(const SideCrossIterator &other);
            bool operator==(const SideCrossIterator &) const;
            bool operator!=(const SideCrossIterator &) const;
            bool operator>(const SideCrossIterator &) const;
            bool operator<(const SideCrossIterator &) const;
            SideCrossIterator &operator<<(int);
            SideCrossIterator &operator>>(int);
            void sortSideCrossIterator(MagicalContainer *);
            MagicalContainer getContainer();
            int operator*() const;
        };

        class PrimeIterator
        {
        private:
            MagicalContainer *container;
            int index;
            std::vector<int> numbersPrime;
            
            

        public:
            PrimeIterator();
            PrimeIterator(MagicalContainer *, int);
            PrimeIterator(MagicalContainer &);
            ~PrimeIterator(){};

            PrimeIterator begin();
            PrimeIterator end();

            PrimeIterator &operator++();
            PrimeIterator &operator=(const PrimeIterator &other);
            bool operator==(const PrimeIterator &) const;
            bool operator!=(const PrimeIterator &) const;
            bool operator>(const PrimeIterator &) const;
            bool operator<(const PrimeIterator &) const;
            PrimeIterator &operator<<(int);
            PrimeIterator &operator>>(int);
            int operator*() const;
            void sortPrimeIterator(MagicalContainer *);
            int getcountPrimes(MagicalContainer* container);
            std::vector<int> getnumbersPrime();

        };
    };

}
