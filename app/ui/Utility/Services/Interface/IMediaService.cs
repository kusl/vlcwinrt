﻿using System;
using System.Threading.Tasks;
using VLC_WINRT.Utility.Services.Interface;
using VLC_WINRT.Utility.Services.RunTime;
using Windows.Storage;


namespace VLC_WINRT.Utility.Services.Interface
{
    public interface IMediaService
    {
        bool IsPlaying { get; }

        /// <summary>
        /// Navigates to the Audio Player screen with the requested file a parameter.
        /// </summary>
        /// <param name="file">The file to be played.</param>
        Task PlayAudioFile(StorageFile file);
        /// <summary>
        /// Navigates to the Video Player screen with the requested file a parameter.
        /// </summary>
        /// <param name="file">The file to be played.</param>
        Task PlayVideoFile(StorageFile file);

        /// <summary>
        /// Sets the path of the file to played.
        /// </summary>
        /// <param name="fileUri">The path of the file to be played.</param>
        void SetPath(string filePath);

        void Play();
        void Pause();
        void Stop();
        void FastForward();
        void Rewind();
        void SkipAhead();
        void SkipBack();

        float GetPosition();
        void SetPosition(float position);

        event EventHandler MediaEnded;
        event EventHandler<VlcService.MediaPlayerState> StatusChanged;
    }
}