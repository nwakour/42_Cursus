#!bin/bash
if ps | grep sshd | grep -vc grep; then exit 0; else exit 1 ; fi