/*
 * Copyright (C) 2020 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/


#include <ignition/plugin/Register.hh>
#include "HelloWorld.hh"


// Include a line in your source file for each interface implemented.
IGNITION_ADD_PLUGIN(
    hello_world::HelloWorld,
    ignition::gazebo::System,
    hello_world::HelloWorld::ISystemPostUpdate)
//! [registerSampleSystem]
//! [implementSampleSystem]
using namespace hello_world;

HelloWorld::HelloWorld()
{
}

HelloWorld::~HelloWorld()
{
}

void HelloWorld::PostUpdate(const ignition::gazebo::UpdateInfo &_info,
    const ignition::gazebo::EntityComponentManager &_ecm)
{
  ignmsg << "HelloWorld::PostUpdate" << std::endl;
}
//! [implementSampleSystem]


