#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;

void MagicalContainer::printContainer()
{
    for (const auto &num : numbers)
    {
        std::cout << num << " ,";
    }
    std::cout << std::endl;
}
bool MagicalContainer::isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}

vector<int> MagicalContainer::getElement()
{
    return numbers;
}

void MagicalContainer::addElement(int elem)
{
    numbers.emplace_back(elem);
}

void MagicalContainer::removeElement(int elem)
{
    bool found = false;
    for (auto it = numbers.begin(); it != numbers.end(); ++it)
    {
        if (*it == elem)
        {
            numbers.erase(it);
            found = true;
            break;
        }
    }

    if (!found)
    {
        throw std::runtime_error("Number does not exist in the container!");
    }

    cout << "removing..." << endl;
    for (const auto &num : numbers)
    {
        cout << num << ", ";
    }
    cout << endl;
    cout << "end removing..." << endl;
    cout << endl;

    if (!numbers.empty())
    {
        int num = numbers.back();
        cout << "end = " << num << endl;
    }
}

int MagicalContainer::size()
{
    return numbers.size();
}

void MagicalContainer::AscendingIterator::sortAscendingIterator(MagicalContainer *container)
{
    std::sort(container->numbers.begin(), container->numbers.end());
}
void MagicalContainer::SideCrossIterator::sortSideCrossIterator(MagicalContainer *container)
{
    std::sort(container->numbers.begin(), container->numbers.end());
    unsigned long size = (unsigned long)container->size();
    unsigned long i = 0;
    vector<int> elements2;
    int temp2;

    unsigned long x = 0, y = 1;
    for (i = 0; i < size; i++)
    {
        if (i % 2 == 0)
        {
            temp2 = container->numbers.at(x);
            elements2.emplace_back(temp2);

            x++;
        }
        else
        {
            temp2 = container->numbers.at(size - y);
            elements2.emplace_back(temp2);
            y++;
        }
    }

    container->numbers.swap(elements2);
}

// sorting and after that checking i prime number

void MagicalContainer::PrimeIterator::sortPrimeIterator(MagicalContainer* container) {
    std::vector<int> elements = container->getElement();
    numbersPrime.clear();

    // Filter out the prime numbers and add them to numbersPrime
    for (int num : elements) {
        if (container->isPrime(num)) {
            numbersPrime.push_back(num);
        }
    }

    // Sort the prime numbers in ascending order
    std::sort(numbersPrime.begin(), numbersPrime.end());

    // Reset the iterator index to the beginning
    index = 0;
    
}


int MagicalContainer::PrimeIterator::getcountPrimes(MagicalContainer *container)
{
    int count = 0;
    for (int num : container->getElement())
    {
        if (container->isPrime(num))
        {
            count++;
        }
    }
    cout << "Number of prime numbers in the container: " << count << endl;
    return count;
}

// constructors of MagicalContainer - AscendingIterator
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer *container, int index)
    : container(container), index(index) {}
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
    : container(&container), index(0)
{
    sortAscendingIterator(&container);
}
MagicalContainer::AscendingIterator::AscendingIterator()
    : container(), index(0) {}
// end constructors of MagicalContainer - AscendingIterator

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : container(&container), index(0)
{
    sortSideCrossIterator(&container);
}
MagicalContainer::SideCrossIterator::SideCrossIterator()
    : container(nullptr), index(0), direct(1) {}
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer *container, int index, int direct)
    : container(container), index(index), direct(direct) {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container) : container(&container), index(0)
{
    sortPrimeIterator(&container);
}
MagicalContainer::PrimeIterator::PrimeIterator() : container(), index(0) {}
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer *container, int index) : container(container), index(0) {}

//------------------------------operator ++ ---------------------------------
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    if (index == container->size())
    {
        throw runtime_error("last index");
    }
    ++index;
    return *this;
}
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{
    if (index == container->size())
    {
        throw std::runtime_error("No more index to iterate.");
    }

    ++index; // Increment the index for the next iteration

    return *this; // Return the updated iterator
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    if (index >= numbersPrime.size()) {
    index =0;
    throw std::runtime_error("Iterator is already at the end");

    }

    ++index;
    while (index < container->size())
    {
        unsigned long jhg = static_cast<unsigned long>(index);
        if (container->isPrime(container->numbers[jhg]))
        {
            break;
        }
        ++index;
    }
    return *this;


}
//------------------------------operator = ---------------------------------
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    if (this != &other)
    {
        if (container != other.container)
        {
            throw std::runtime_error("Iterators are pointing to different containers");
        }
        index = other.index;
    }
    return *this;
}
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &other)
{
    if (this != &other)
    {
        if (container != other.container)
        {
            throw std::runtime_error("Iterators are pointing to different containers");
        }
        index = other.index;
    }
    return *this;
}
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const PrimeIterator &other)
{
    if (this != &other)
    {
        if (container != other.container)
        {
            throw std::runtime_error("Iterators are pointing to different containers");
        }
        index = other.index;
    }
    return *this;
}
//------------------------------operator == ---------------------------------
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &other) const
{
    return other.index == index;
}
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &other) const
{
    return other.index == index;
}
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &other) const
{
    return index == other.index;
}
//------------------------------operator != ---------------------------------
bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &other) const
{
    return other.index != index;
}
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &other) const
{
    return other.index != index;
}
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &other) const
{
    return other.index != index;
}
//------------------------------operator > ---------------------------------
bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &other) const
{
    return index > other.index;
}
bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &other) const
{
    return index > other.index;
}
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &other) const
{
    return other.index > index;
}
//------------------------------operator < ---------------------------------
bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &other) const
{
    return index < other.index;
}
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &other) const
{
    return index < other.index;
}
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &other) const
{
    return index < other.index;
}
//------------------------------operator << --------------------------------
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator<<(int steps)
{
    index = index - steps;
    return *this;
}
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator<<(int steps)
{
    index -= steps * direct;
    return *this;
}
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator<<(int steps)
{
    int i = 0;
    for (; i < steps && index >= 0; --index)
    {
        unsigned long val = static_cast<unsigned long>(index);
        if (container->isPrime(container->numbers[val]))
        {
            ++i;
        }
    }
    return *this;
}
//------------------------------operator >> ---------------------------------
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator>>(int steps)
{
    index = index + steps;
    return *this;
}
MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator>>(int steps)
{
    index += steps * direct;
    return *this;
}
MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator>>(int steps)
{
    int i = 0;
    unsigned long jhg;
    for (; i < steps; ++index)
    {
        jhg = static_cast<unsigned long>(index);
        if (container->isPrime(container->numbers[jhg]))
        {
            ++i;
        }
    }
    return *this;
}
//------------------------------operator * ---------------------------------
int MagicalContainer::AscendingIterator::operator*() const
{
    unsigned long val = static_cast<unsigned long>(index);
    return container->numbers[val];
}
int MagicalContainer::SideCrossIterator::operator*() const
{
    unsigned long val = static_cast<unsigned long>(index);
    return container->numbers[val];
}
int MagicalContainer::PrimeIterator::operator*() const
{
    unsigned long val = static_cast<unsigned long>(index);
    return container->numbers[val];
    
    
}
//------------------------------ begin and end--------------------------------
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
    return SideCrossIterator(container, 0, 1);
}
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
    return SideCrossIterator(container, container->size(), 1);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{
    
    return PrimeIterator(container, 0);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
    return PrimeIterator(container, numbersPrime.size());
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    return AscendingIterator(container, 0);
}
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{

    return AscendingIterator(container, container->size());
}
// std::vector<int> MagicalContainer::PrimeIterator::getnumbersPrime() {
//     return numbersPrime;
// }
