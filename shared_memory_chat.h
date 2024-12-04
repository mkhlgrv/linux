
#ifndef SHARED_MEMORY_CHAT_H
#define SHARED_MEMORY_CHAT_H

#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/interprocess/sync/named_semaphore.hpp> 

const int MAX_MESSAGE_LENGTH = 256;

struct ChatMessage {

    char message[MAX_MESSAGE_LENGTH];

    bool is_empty;

};

#endif
