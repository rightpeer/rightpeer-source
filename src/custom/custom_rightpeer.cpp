// Copyright (c) RightPeer Limited RightPeer
// RightPeer code distributed under the GPLv3 license, see COPYING file.

#include "rightpeer/rightpeer.h"

void* custom_get_blockchain_default(const char *param,int* size,void *param_in)
{
    *size=0;
    
    return NULL;
}

