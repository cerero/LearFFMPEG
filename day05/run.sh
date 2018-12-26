#测试log功能
clang -g -o dm01_ffmpeg_log dm01_ffmpeg_log.c  -lavutil

#测试删除移动文件
clang -g -o dm03_ffmpeg_file dm03_ffmpeg_file.c  -lavutil -lavformat
clang -g -o dm03_ffmpeg_file dm03_ffmpeg_file.c `pkg-config --libs libavformat libavutil`

#测试读目录
clang -g -o dm04_ffmpeg_dir dm04_ffmpeg_dir.c `pkg-config --libs libavformat libavutil`

#dump流信息
clang -g -o dm04_ffmpeg_mediainfo dm04_ffmpeg_mediainfo.c -I /usr/local/Cellar/ffmpeg/4.1_1/include -L /usr/local/Cellar/ffmpeg/4.1_1/lib -lavutil -lavformat
clang -g -o dm04_ffmpeg_mediainfo dm04_ffmpeg_mediainfo.c `pkg-config --libs libavformat libavutil`

#抽取音频流
clang -g -o dm04_ffmpeg_extract_audio dm04_ffmpeg_extract_audio.c `pkg-config --libs libavformat libavutil`
./dm04_ffmpeg_extract_audio eason.mp4 eason.aac
