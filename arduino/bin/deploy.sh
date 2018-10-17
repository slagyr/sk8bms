#!/usr/bin/env bash

pio run --target clean
pio run --target upload
sleep 1
pio device monitor