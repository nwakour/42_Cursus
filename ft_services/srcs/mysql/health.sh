#! /bin/sh
if ps | grep mysqld | grep -vc grep; then exit 0; else exit 1 ; fi