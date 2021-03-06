// Copyright (c) 2019 by Robert Bosch GmbH. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef TYPES__ICEORYX_SUBSCRIPTION_HPP_
#define TYPES__ICEORYX_SUBSCRIPTION_HPP_

#include "iceoryx_posh/popo/subscriber.hpp"

#include "rmw/rmw.h"
#include "rmw/types.h"

#include "rmw_iceoryx_cpp/iceoryx_type_info_introspection.hpp"

struct IceoryxSubscription
{
  IceoryxSubscription(
    const rosidl_message_type_support_t * type_supports,
    iox::popo::Subscriber * const iceoryx_receiver)
  : type_supports_(*type_supports),
    iceoryx_receiver_(iceoryx_receiver),
    is_fixed_size_(rmw_iceoryx_cpp::iceoryx_is_fixed_size(type_supports)),
    message_size_(rmw_iceoryx_cpp::iceoryx_get_message_size(type_supports))
  {}

  rosidl_message_type_support_t type_supports_;
  iox::popo::Subscriber * const iceoryx_receiver_;
  bool is_fixed_size_;
  size_t message_size_;
};

#endif  // TYPES__ICEORYX_SUBSCRIPTION_HPP_
