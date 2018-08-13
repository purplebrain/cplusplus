
#include "autoptr.hpp"
#include "resource.hpp"

template<class T>
Auto_ptr3<T>::Auto_ptr3(T* ptr) : m_ptr(ptr)
{

}
 
template<class T>
Auto_ptr3<T>::~Auto_ptr3()
{
	delete m_ptr;
}

template<class T>
Auto_ptr3<T>::Auto_ptr3(const Auto_ptr3& a)
{
	m_ptr = new T;
	*m_ptr = *a.m_ptr;
}

template<class T>
Auto_ptr3<T>&
Auto_ptr3<T>::operator=(const Auto_ptr3& a)
{
	// Self-assignment detection
	if (&a == this)
		return *this;

	// Release any resource we're holding
	delete m_ptr;

	// Copy the resource
	m_ptr = new T;
	*m_ptr = *a.m_ptr;

	return *this;
}

template<class T>
bool 
Auto_ptr3<T>::isNull() const 
{ 
  return (m_ptr == nullptr); 
}

template class Auto_ptr3<Resource>;
