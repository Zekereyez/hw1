#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

/**
	* Adds a new value to the back of the list
	*   - MUST RUN in O(1)
	*/
void ULListStr::push_back(const std::string& val) {
	// sum like dat yeyeye
	// we need to increment the tail pointer 
	// and then we can insert the value into the 
	// linked list array...
	if (!head_) {
		// we need to create a new list atp
		// and I can insert anywhere MUAHAHA reality can be whatever i want
		Item* freshItem = new Item();
		head_ = freshItem;
		head_->val[head_->first] = val;
		head_->last++;
	}

	// empty list case
	if (size_ == 0) {
		// we can just insert in the first spot
		// but we have two val labels smh 
		// so how tf do we make sure we are inserting into 
		// the val array with the val string so wtf
		head_->val[head_->first] = val;

	}
	if (head_->last < size_) {
		// we need to check that the array is not full
		// if not full we can then just insert into the array
		// if full then we need to make another array...
		
		// check if tail is not full or has enough space
		// from there we can insert into the array
		
	}
}

/**
	* Removes a value from the back of the list
	*   - MUST RUN in O(1)
	*/
void ULListStr::pop_back() {
	// same as pop_front but from the tails perspective
	if (!tail_) {
		return;
	}
	size_--;

}

/**
	* Adds a new value to the front of the list.
	* If there is room before the 'first' value in
	* the head node add it there, otherwise, 
	* allocate a new head node.
	*   - MUST RUN in O(1)
	*/
void ULListStr::push_front(const std::string& val) {
	// use the heads pointer here eazzzy
	if (!head_) {
		// we need to create a new item for head
		Item* freshItem = new Item();
		head_ = freshItem;
		head_->val[head_->first] = val;
		head_->last++;
	}
	if (head_->first > 0) {
		head_->first--;
		head_->val[head_->first] = val;
	}
	else if (head_->first == 0) {
		// we need to create a new item so we can add 
		// the element 
		Item* newItem = new Item();
		newItem->next = head_;
		head_->prev = newItem;
		// assign head now to the new item 
		// crown the king...
		head_ = newItem;
		tail_ = newItem->next;
		// now we need to insert the push_front item to 
		// the back of the linked list val array
		head_->first = ARRSIZE - 1;
		head_->last = ARRSIZE;
		head_->val[head_->first] = val;
		// we can safely decrement since we have made 
		// a new item with 10 elements
		head_->first--;
	}
}

/**
	* Removes a value from the front of the list
	*   - MUST RUN in O(1)
	*/
void ULListStr::pop_front() {
	// fast user head pointer for access
	// we need to delete the string in the first
	// index so how do I do that
	if (!head_) {
		return;
	}
	head_->val[head_->first] = "";
	if (head_->first < ARRSIZE) {
		head_->first++;
	}
	if (head_->first >= ARRSIZE) {
		Item *temp = head_;
		// lone item with no next so we delete
		if (!head_->next) {
			delete temp;
			head_ = nullptr;
			tail_ = nullptr;
		}
		// else there is a next 
		else {
			head_ = head_->next;
			head_->prev = nullptr;
			if (head_->next) {
				head_->next->prev = head_;
			}
			delete temp;
		}
	}
	size_--;
}

/**
	* Returns a const reference to the back element
	*   - MUST RUN in O(1)
	*/
std::string const & ULListStr::back() const {
	// const reference to the last item kinda like a peek
	return tail_->val[tail_->last - 1];
}

/**
	* Returns a const reference to the front element
	*   - MUST RUN in O(1)
	*/
std::string const & ULListStr::front() const {
	// const reference to the first element this is peek
	// we need to use head_->first because the first/last 
	// aren't within scope 
	return head_->val[head_->first];
}

/** 
* Returns a pointer to the item at index, loc,
*  if loc is valid and NULL otherwise
*   - MUST RUN in O(n) 
*/
std::string* ULListStr::getValAtLoc(size_t loc) const {
	
}