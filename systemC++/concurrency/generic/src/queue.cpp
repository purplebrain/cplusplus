#include "queue.hpp"

QUEUE::QUEUE()
{
  cout << "In Constructor #1" << endl;
  this->m_size = 0;
  this->m_ptrQ = nullptr;
  this->m_ptrHead = nullptr;
  this->m_ptrTail = nullptr;
  this->m_size_threshold = 8;
  this->m_operation_cnt = 0;
}

QUEUE::QUEUE(int _max_size)
{
  cout << "In Constructor #2" << endl;
  this->m_size = 0;
  this->m_ptrQ = nullptr;
  this->m_ptrHead = nullptr;
  this->m_ptrTail = nullptr;
  this->m_size_threshold = _max_size;
  this->m_operation_cnt = 0;
}

QUEUE::~QUEUE()
{
  cout << "In Destructor" << endl;
  this->m_size = 0;
  QNODE* ptrTmp = this->m_ptrTail;
  QNODE* ptrTmpNext = nullptr;
  for (int i = 0; i < this->m_size; i++) {
    ptrTmpNext = ptrTmp->m_ptrNext;
    delete ptrTmp;
    ptrTmp = ptrTmpNext;
  }
}

int 
QUEUE::getOperationCnt(void) const
{
  unique_lock<mutex> uLock_OperCnt(this->m_mutex_OperCnt);
  return (this->m_operation_cnt);
}

int
QUEUE::getSize(void) const
{
  return (this->m_size);
}

void
QUEUE::push(int _x)
{
  unique_lock<mutex> uLock_Q(this->m_mutex_Q, defer_lock);
  QNODE* ptrTmp = new QNODE(_x);
  int intTmp = _x;

  uLock_Q.lock();
  if (!this->getSize()) {
    this->m_ptrHead = ptrTmp;
    this->m_ptrTail = this->m_ptrHead;
  } else {
    this->m_ptrHead->m_ptrNext = ptrTmp;
    this->m_ptrHead = ptrTmp;
    this->m_ptrHead->m_ptrNext = nullptr;
  }
  this->m_size++;
  uLock_Q.unlock();

  unique_lock<mutex> uLock_OperCnt(this->m_mutex_OperCnt);
  this->m_operation_cnt++;
  uLock_OperCnt.unlock();

  uLock_Q.lock();
  cout << "Enqued data : " << intTmp << endl;
  uLock_Q.unlock();
  this->m_cond_Q.notify_all();
  
  return;
}

QNODE*
QUEUE::pop(void)
{
  unique_lock<mutex> uLock_Q(this->m_mutex_Q, defer_lock);
  QNODE* ptrTmp = nullptr;
  int intTmp;

  uLock_Q.lock();
  m_cond_Q.wait(uLock_Q, [this](){
                                return (this->getSize());
                             });
  ptrTmp = this->m_ptrTail;
  intTmp = ptrTmp->m_data;
  this->m_ptrTail = ptrTmp->m_ptrNext;
  this->m_size--;
  uLock_Q.unlock();

  unique_lock<mutex> uLock_OperCnt(this->m_mutex_OperCnt);
  this->m_operation_cnt--;
  uLock_OperCnt.unlock();

  uLock_Q.lock();
  cout << "Dequed data : " << intTmp << endl;
  uLock_Q.unlock();  

  return(ptrTmp);
}
