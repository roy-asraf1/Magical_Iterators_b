#include "MagicalContainer.hpp"

using namespace std;
using namespace ariel;

// for check the pointer of the sortPrimeIterator function
bool MagicalContainer::isPrime(int n) {
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0)
            return false;
    }
    return true;
}
// return the main container
vector<int> MagicalContainer::getElement()
{
    return numbers;
}



// add elment to the container
void MagicalContainer::addElement(int elem)
{
    if (instanceoff == 1)
    {
        
        if(numbers.empty()){
            numbers.push_back(elem);
        }
        else if(numbers.size()==1)
        {
            
            
            if(numbers.front() < elem)
                numbers.emplace_back(elem);
            else if(numbers.front() > elem){
                numbers.push_back(elem);
            }

            
        }
        else
        {
            
            int temp;
            for (unsigned long i = 0; i < numbers.size()-1; i++)
            {
                
                
                if(elem<numbers.front())
                {
                    numbers.insert(numbers.begin(),elem); 
                    break;  
                }
                else if (numbers.at(i) < elem && elem < numbers.at(i+1))
                {
                    
                    temp=i+1;
                    numbers.insert(numbers.begin()+temp,elem);
                    break;
                }
                else if(elem>numbers.back())
                {
                    numbers.emplace_back(elem);
                    break;
                }

            } 
        }
        
    }
    else if (instanceoff == 2)
    {
        unsigned long size = (unsigned long)numbers.size();
        numbers.push_back(elem); 

    }
    else if(instanceoff == 3)
    {
        if(isPrime(elem))
        {
            
            if(numbers.empty()){
            numbers.push_back(elem);
            }
            else if(numbers.size()==1)
            {
                
                
                if(numbers.front() < elem)
                    numbers.emplace_back(elem);
                else if(numbers.front() > elem){
                    numbers.push_back(elem);
                }

                
            }
            else
            {
            
                int temp;
                for (unsigned long i = 0; i < numbers.size()-1; i++)
                {
                    
                    
                    if(elem<numbers.front())
                    {
                        numbers.insert(numbers.begin(),elem); 
                        break;  
                    }
                    else if (numbers.at(i) < elem && elem < numbers.at(i+1))
                    {
                        
                        temp=i+1;
                        numbers.insert(numbers.begin()+temp,elem);
                        break;
                    }
                    else if(elem>numbers.back())
                    {
                        numbers.emplace_back(elem);
                        break;
                    }

                } 
            }
        }
    }
    else
    {
        numbers.push_back(elem); 
    }
        
    
}

//remove element from the container
void MagicalContainer::removeElement(int elem)
{
    bool found = false;
    auto it = numbers.begin();
    while (it != numbers.end())
    {
        if (*it == elem)
        {
            it = numbers.erase(it);
            found = true;
            break;
        }
        else
        {
            ++it;
        }
    }

    if (!found)
    {
        throw std::runtime_error("Number does not exist in the container!");
    }

    cout << "removing..." << endl;
    auto numIt = numbers.begin();
    while (numIt != numbers.end())
    {
        cout << *numIt << ", ";
        ++numIt;
    }
    cout << endl;
    cout << "end removing..." << endl;
    cout << endl;

    if (!numbers.empty())
    {
        auto it = numbers.end();
        --it;
        int num = *it;
        cout << "end = " << num << endl;
    }

}
//return the size of the container
int MagicalContainer::size()
{
    return numbers.size();

    
}


int MagicalContainer::PrimeIterator::sizeprimes()
{
    return numbersPrime.size(); //return only the sizes of the prime numbers
}
//----------------------- constructors MagicalContainer  ---------------------------
MagicalContainer::MagicalContainer()
    {
      instanceoff=0;  
    }
//----------------------- constructors of MagicalContainer - AscendingIterator ---------------------------------

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer *container, int index)
    : container(container), index(index) {
        instanceoff=1;
    }
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
    : container(&container), index(0)
{
    instanceoff=1;
    helperAscendingIterator(&container);
}
MagicalContainer::AscendingIterator::AscendingIterator()
    : container(), index(0) {
    instanceoff=1;
    }





//-----------------------constructors of MagicalContainer - SideCrossIterator ---------------------------------
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container) : container(&container), index(0)
{
    helperSideCrossIterator(&container);
    instanceoff=2;
}
MagicalContainer::SideCrossIterator::SideCrossIterator()
    : container(nullptr), index(0), direct(1) {
        instanceoff=2;
    }
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer *container, int index, int direct)
    : container(container), index(index), direct(direct) {
        instanceoff=2;
    }

//------------------------------constructors of MagicalContainer - PrimeIterator  ---------------------------------

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer& container)
   : container(&container), index(0), newindex(0)
{
    instanceoff = 3;
    if (container.getElement().empty())
    { // check if we use before the primesnumbers vector
        numbersPrime.clear();
        index = 0;
        newindex = 0;
    }
    else
    {
        helperPrimeIterator(&container); // the helper function to dort the prime numbers
    }
        
}

MagicalContainer::PrimeIterator::PrimeIterator() : container(), index(0) {
    instanceoff = 3;
}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer* container, int index,int newindex,std::vector<int> elem)
    : container(container), index(index),newindex(newindex),numbersPrime(elem)  {
        instanceoff = 3;
    }
MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other) 
{
    container = other.container;
    index = other.index;
    instanceoff = 3;
}

MagicalContainer::PrimeIterator::PrimeIterator(PrimeIterator&& other) noexcept 
{
    container = other.container;
    index = other.index;
    other.container = nullptr;
    other.index = 0;
    instanceoff = 3;
}

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


MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() 
{
    if(index >= container->size())
    {
       throw runtime_error("no more index");
    }
    if(newindex == sizeprimes())
    {
        throw runtime_error("no more index");
    }
    ++newindex;
    ++index;
    return *this;
}

//------------------------------operator = ---------------------------------
MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator=(const AscendingIterator &other)
{
    if (this != &other)
    {
        if (container != other.container)
        {
            throw std::runtime_error("Iterators are pointing for different containers");
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
            throw std::runtime_error("Iterators are pointing for different containers");
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
            throw std::runtime_error ("Iterators are pointing for different containers");
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
    return index > other.index ;
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

//------------------------------operator * ---------------------------------
//
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
    unsigned long val=  static_cast<unsigned long>(newindex);
   
            return numbersPrime[val];
    
    
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

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
    return PrimeIterator(container, 0,0,numbersPrime);
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    return PrimeIterator(container,numbersPrime.size(),numbersPrime.size(),numbersPrime);
}


MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    return AscendingIterator(container, 0);
}
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{

    return AscendingIterator(container, container->size());
}
void MagicalContainer::PrimeIterator:: myprint()
{

    for (auto a :numbersPrime){
        cout<<a<<",   ";
    }
}
//------------------------------ helpers  ---------------------------------
//helper function for everything

void MagicalContainer::AscendingIterator::helperAscendingIterator(MagicalContainer *container)
{
    std::sort(container->numbers.begin(), container->numbers.end());
}
void MagicalContainer::SideCrossIterator::helperSideCrossIterator(MagicalContainer *container)
{
    std::sort(container->numbers.begin(), container->numbers.end());
    unsigned long size = (unsigned long)container->size();
    unsigned long idx = 0;
    vector<int> SideCrossNumbers; // the real values we need will push this vector
    int temp;

    unsigned long start = 0, end = 1;
    while (idx < size)
    {
        if (idx % 2 == 0) // all the non odd numbers will be in the start
        {
            temp = container->numbers.at(start);
            SideCrossNumbers.emplace_back(temp);

            start++;
        }
        else
        {
            temp = container->numbers.at(size - end); // all the  odd numbers will be in the end
            SideCrossNumbers.emplace_back(temp);
            end++;
        }

        idx++;
    }

    container->numbers.swap(SideCrossNumbers); //swap with pointers according the task with o(1)
}
// sorting and after that checking i prime number
void MagicalContainer::PrimeIterator::helperPrimeIterator(MagicalContainer* container) {

    for(int i: container->getElement()){ // for each check if prime
        if(container->isPrime(i)){
            numbersPrime.emplace_back(i); // insert to the another vector of the only primes numbers
        }
    }
}
void MagicalContainer::printContainer()
{
    for (const auto &num : numbers)
    {
        std::cout << num << " ,";
    }
    std::cout << std::endl;
}
