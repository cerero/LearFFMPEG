#include <stdio.h>
#include <libavformat/avformat.h>
#include <libavutil/log.h>

int main(int argc, char *argv[]) {
  int ret = 0;
  av_log_set_level(AV_LOG_DEBUG);

  char *openDir = "./";
  AVIODirContext *ctx = NULL;
  ret = avio_open_dir(&ctx, openDir, NULL);

  if (ret < 0) {
    av_log(NULL, AV_LOG_ERROR, "failed to open dir:%s\n", av_err2str(ret));
    return ret;
  }
  av_log(NULL, AV_LOG_DEBUG, "Success to open dir:%s\n", openDir);

  AVIODirEntry *entry = NULL;
  while (1) {
    ret = avio_read_dir(ctx, &entry);
    if (ret < 0) {
      //read error
      av_log(NULL, AV_LOG_ERROR, "failed to read dir:%s\n", av_err2str(ret));
      goto END;
    }

    if (entry == NULL) {
      //no more entries
      break;
    }

    av_log(NULL, AV_LOG_INFO, "type:%d, fileName:%s, size:%lld\n", entry->type, entry->name, entry->size);
    avio_free_directory_entry(&entry);
  }

END:
  if (ctx) {
    avio_close_dir(&ctx);
  }
  return ret;
}
