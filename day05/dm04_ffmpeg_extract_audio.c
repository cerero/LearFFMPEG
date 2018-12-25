#include <libavutil/log.h>
#include <libavformat/avformat.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  int ret = 0;
  int audio_index;
  char *src = NULL;
  char *dst = NULL;
  AVFormatContext *fmt_ctx = NULL;
  AVPacket pkt;

  av_log_set_level(AV_LOG_INFO);
  av_register_all();

  if (argc < 3) {
    av_log(NULL, AV_LOG_ERROR, "the count of params should be more than three!\n");
    return -1;
  }

  src = argv[1];
  dst = argv[2];

  if (!src || !dst) {
    av_log(NULL, AV_LOG_ERROR, "src or dst is null!\n");
    ret = -1;
    goto END;
  }

  ret = avformat_open_input(&fmt_ctx, src, NULL, NULL);
  if (ret < 0) {
    av_log(NULL, AV_LOG_ERROR, "Can't open file: %s\n", av_err2str(ret));
    ret = -1;
    goto END;
  }

  FILE *dst_fd = fopen(dst, "wb");
  if (!dst_fd) {
    av_log(NULL, AV_LOG_ERROR, "Can't open file:%s !\n", dst);
    ret = -1;
    goto END;
  }
  av_dump_format(fmt_ctx, 0, src, 0);

  //2 get stream
  ret = av_find_best_stream(fmt_ctx, AVMEDIA_TYPE_AUDIO, -1, -1, NULL, 0);
  if (ret < 0) {
    av_log(NULL, AV_LOG_ERROR, "Can't find best stream: %s\n", av_err2str(ret));
    ret = -1;
    goto END;
  }

  audio_index = ret;
  av_init_packet(&pkt);
  while(av_read_frame(fmt_ctx, pkt) >= 0) {
    if (pkt.stream_index == audio_index) {
      len = fwrite(pkt.data, 1, pkt.size, dst_fd);
      if (len != pkt.size) {
        av_log(NULL, AV_LOG_WARNING, "warning, length of data is not equal the size of pkt!\n");
      }
    }

    av_packet_unref(&pkt);
  }
END:
  if (dst_fd) {
      fclose(dst_fd);
  }

  if (fmt_ctx) {
      avformat_close_input(&fmt_ctx);
  }

  return ret;
}
