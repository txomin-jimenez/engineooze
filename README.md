# Enginooze

This is an experiment to build a DIY sports exhaust sound generator using an esp32 board. Work in progress.

### WAV to C header
11025 mono 8-bit wav sound file:

```
sox sample.wav -t raw -r 11025 -b 8 -c 1 -L -e unsigned-integer sample.raw
xxd -i sample.raw > sample.h
```