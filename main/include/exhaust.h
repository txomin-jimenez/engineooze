struct Exhaust {
  void (*sound_device_play)(void);
} exhaust;

void exhaust_init(void (*sound_device_play)(void));
void exhaust_on_update(int rpm);