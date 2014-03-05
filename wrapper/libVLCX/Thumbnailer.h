/*****************************************************************************
* Copyright © 2013 VideoLAN
*
* Authors: Kellen Sunderland
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU Lesser General Public License as published by
* the Free Software Foundation; either version 2.1 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU Lesser General Public License for more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this program; if not, write to the Free Software Foundation,
* Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
*****************************************************************************/

#pragma once

#include <vlc/vlc.h>
#include <exception>

using namespace Windows::Foundation;
using namespace Windows::Storage;

namespace libVLCX {
    public ref class Thumbnailer sealed
    {
    public:
                       Thumbnailer();
        void           TakeScreenshot(Platform::String^ mrl, int width, int height);
        virtual        ~Thumbnailer();

    private:
        libvlc_instance_t        *p_instance;
    };
}

