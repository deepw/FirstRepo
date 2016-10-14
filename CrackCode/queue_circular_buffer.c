

http://stackoverflow.com/questions/4062126/can-2-pthread-condition-variables-share-the-same-mutex
/* This was asked at Cloudera */

mutex queue_mutex; 
cond queue_is_not_full_cond;
cond queue_is_not_empty_cond;

push() 
   lock(queue_mutex)
      while(queue is full)
        wait(queue_is_not_full_cond,mutex);
      do push...
      signal(queue_is_not_empty_cond)
   unlock(queue_mutex)

pop() 
   lock(queue_mutex)
      while(queue is empty)
        wait(queue_is_not_empty_cond,mutex);
      do pop...
      signal(queue_is_not_full_cond)
   unlock(queue_mutex)
