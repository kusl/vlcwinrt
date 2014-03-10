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

#include "pch.h"
#include "Thumbnailer.h"

using namespace libVLCX;

Thumbnailer::Thumbnailer()
{
    const char *argv[] = {
        "-I", "dummy",            // Only use options needed for snapshots
        "--vout", "dummy",
        "--no-osd",
        "--verbose=5",
        "--no-video-title-show",
        "--no-stats",
        "--no-audio"
    };
    p_instance = libvlc_new(sizeof(argv) / sizeof(*argv), argv);
    if (!p_instance) {
        throw ref new Platform::Exception(-1,"Could not initialise libvlc!");
        return;
    }
}

void Thumbnailer::TakeScreenshot(Platform::String^ mrl, int width, int height)
{
    libvlc_media_player_t* mp;

    auto localFolder = ApplicationData::Current->LocalFolder;

   /* size_t len1 = WideCharToMultiByte(CP_UTF8, 0, localFolder->Path->Data, -1, NULL, 0, NULL, NULL);
    char* localPath = new char[len1];
    WideCharToMultiByte(CP_UTF8, 0, mrl->Data(), -1, localPath, len1, NULL, NULL);*/

    size_t len2 = WideCharToMultiByte(CP_UTF8, 0, mrl->Data(), -1, NULL, 0, NULL, NULL);
    char* mrl_str = new char[len2];
    WideCharToMultiByte(CP_UTF8, 0, mrl->Data(), -1, mrl_str, len2, NULL, NULL);

    if (p_instance){
        libvlc_media_t* m = libvlc_media_new_location(this->p_instance, mrl_str);
        mp = libvlc_media_player_new_from_media(m);
        libvlc_media_release(m);

        if (mp)
        {
            int result = libvlc_video_take_snapshot(mp, 1, "C:\\Users\\Kellen\\AppData\\Local\\Packages\\9519ba58-7ad6-4c4e-97ed-bfc2135a0d19_hj88em4th0swa\\LocalState\\vlc\\output.bmp" , 200, 50);
            libvlc_media_player_release(mp);
        }
    }

    delete[](mrl_str);
    //delete[](localPath);
}

Thumbnailer::~Thumbnailer(){
    libvlc_release(p_instance);
}