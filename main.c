#include "window.h"

int main(){
  init_window(640,480, "Testing");

  sleep(1);
  destroy_window();
  return 0;
}
