#ifndef LIST_INTERFACE_H
#define LIST_INTERFACE_H

template <typename T>
class ListInterface
{

     public:

     /**
     * @post All memory allocated by the implementing class should be freed.
     *       This, as with all virtual destrucors, is an empty definition since we
     *       have no knowledge of specific implementation details.
     */
     virtual ~ListInterface(){}

     /**
     *@return 1 or 0
     **/
     virtual bool isEmpty() const = 0;

     /**
     *@return length.
     **/
     virtual int getLength() const = 0;

     /**
     * @pre The position is between 1 and the list's length+1
     * @post add the entry at the given position
     * @param position:  1<= position <= length+1
     * @param Entry: A new entry to put in the list
     * @throw std::runtime_error if the position is invalid.
     **/
     virtual void insert(int position, T entry) throw (std::runtime_error) = 0;

     /**
     * @pre The position is between 1 and the list's length
     * @post Remove the entry at the given position
     * @param position:  1<= position <= length
     * @throw std::runtime_error if the position is invalid.
     **/
     virtual void remove(int position) throw (std::runtime_error) = 0;
     virtual void clear() = 0;

     /**
     * @pre The position is between 1 and the list's length
     * @post Show the entry at the given position
     * @param position:  1<= position <= length
     * @throw std::runtime_error if the position is invalid.
     **/
     virtual T getEntry(int position) const throw (std::runtime_error) = 0;

     /**
     * @pre The position is between 1 and the list's length
     * @post The entry at the given position is replaced with the new entry
     * @param position:  1<= position <= length
     * @param newEntry: A new entry to put in the list
     * @throw std::runtime_error if the position is invalid.
     **/
     virtual void replace(int position, T newEntry) throw (std::runtime_error) = 0;
};
#endif
