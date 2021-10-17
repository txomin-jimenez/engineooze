#ifndef ENGINE_H_
#define ENGINE_H_

static const int IDLE_RPM = 900;

struct Engine {
  int rpm;
} engine;

int engine_read_rpm();
void engine_on_update(int rpm);

#endif // ENGINE_H_