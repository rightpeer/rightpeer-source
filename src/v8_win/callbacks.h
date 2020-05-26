// Copyright (c) RightPeer Limited RightPeer
// RightPeer code distributed under the GPLv3 license, see COPYING file.

#ifndef RIGHTPEER_CALLBACKS_H_
#define RIGHTPEER_CALLBACKS_H_

#include <map>
#include <v8.h>

namespace mc_v8
{
extern std::map<std::string, v8::FunctionCallback> callbackLookup;

} // namespace mc_v8

#endif /* RIGHTPEER_CALLBACKS_H_ */
