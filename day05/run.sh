clang -g -o dm01_ffmpeg_log dm01_ffmpeg_log.c  -lavutil

clang -g -o dm03_ffmpeg_file dm03_ffmpeg_file.c  -lavutil -lavformat
clang -g -o dm03_ffmpeg_file dm03_ffmpeg_file.c `pkg-config --libs libavformat libavutil`

clang -g -o dm04_ffmpeg_dir dm04_ffmpeg_dir.c `pkg-config --libs libavformat libavutil`

clang -g -o dm04_ffmpeg_mediainfo dm04_ffmpeg_mediainfo.c -I /usr/local/Cellar/ffmpeg/4.1_1/include -L /usr/local/Cellar/ffmpeg/4.1_1/lib -lavutil -lavformat
