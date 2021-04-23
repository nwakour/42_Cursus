#!bin/bash
if ps | grep influxd | grep -vc grep; then exit 0; else exit 1 ; fi
if ps | grep telegraf | grep -vc grep; then exit 0; else exit 1 ; fi