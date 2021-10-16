#ifndef ENGINE_H_
#define ENGINE_H_

static const int IDLE_RPM = 900;

struct Engine {
  int rpm;
} engine;

void engine_start();

#endif // ENGINE_H_