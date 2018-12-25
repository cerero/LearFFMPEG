#include <stdio.h>
#include <libavformat/avformat.h>
#include <libavutil/log.h>

int main(int argc, char *argv[]) {
  int ret = 0;
  char *fileName = "./aa.txt";
  av_log_set_level(AV_LOG_DEBUG);
  ret = avpriv_io_delete(fileName);
  if (ret < 0) {
    av_log(NULL, AV_LOG_ERROR, "failed to delete file:%s, error: %d\n", fileName, ret);
    return ret;
  }
  av_log(NULL, AV_LOG_DEBUG, "Success to delete file:%s\n", fileName);

  char *srcFile = "1.txt";
  char *destFile = "1.txt_bak";

  ret = avpriv_io_move(srcFile, destFile);
  if (ret < 0) {
    av_log(NULL, AV_LOG_ERROR, "failed to move srcfile:%s, destFile:%s, error: %d\n", srcFile, destFile, ret);
    return ret;
  }
  av_log(NULL, AV_LOG_DEBUG, "Success to move srcfile:%s, destFile:%s\n", srcFile, destFile);

  return ret;
}
