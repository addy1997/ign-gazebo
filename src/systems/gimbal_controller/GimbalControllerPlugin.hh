/*
 * Copyright (C) 2021 Open Source Robotics Foundation
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

#ifndef _IGNITION_GAZEBO_GIMBAL_CONTROLLER_PLUGIN_HH_
#define _IGNITION_GAZEBO_GIMBAL_CONTROLLER_PLUGIN_HH_

#include <memory>

#include <ignition/gazebo/System.hh>

namespace ignition
{
namespace gazebo
{
// Inline bracket to help doxygen filtering.
inline namespace IGNITION_GAZEBO_VERSION_NAMESPACE {
namespace systems
{
    // Forward declaration
    class GimbalControllerPluginPrivate;

    /// \brief Plugin for controlling a 3-link gimbal or similar system.
    /// This plugin, in response to the String messages coming from 
    /// OnYawStringMsg, OnRollStringMsg, and OnPitchStringMsg functions,
    /// tilts the corresponding joints at a particular rate.
    ///
    /// This system processes the following sdf parameters:
    ///
    /// #Parameters
    ///
    /// '<joint_yaw></joint_yaw>': Name of the link linking the yaw_joint 
    ///                            to it's parent link.
    /// 
    /// '<joint_roll></joint_roll>': Name of the link linking the roll_joint 
    ///                              to it's parent link.
    /// 
    /// '<joint_pitch></joint_pitch>': Name of the link linking the pitch_joint 
    ///                                to it's parent link.

    class GimbalControllerPlugin :
        public System,
        public ISystemConfigure,
        public ISystemPreUpdate
    {
       /// \brief Constructor
       public: GimbalControllerPlugin();

       /// \brief Destructor.
       public: ~GimbalControllerPlugin();

       // Documentation inherited
       public: void Configure(const Entity &_entity,
                              const std::shared_ptr<const sdf::Element> &_sdf,
                              EntityComponentManager &_ecm,
                              EventManager &_eventMgr) final;

       /// Documentation inherited
       public: void PreUpdate(const UpdateInfo &_info,
                           EntityComponentManager &_ecm) final;

       /// \brief Private data pointer
       private: std::unique_ptr<GimbalControllerPluginPrivate> dataPtr;
    };
    }
}
}
}
#endif
