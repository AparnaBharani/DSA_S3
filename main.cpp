#include "FixedSizeStackApp.hpp"
#include "StackApp.hpp"
#include "QueueApp.hpp"
#include "PriorityQueueApp.hpp"

int main()
{
  StackSpace::Demo();
  QueueSpace::Demo();
  FixedSizeStackSpace::Demo(); 
  PriorityQueueSpace::Demo();

  return 0; 
}

